import json

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from openclaw_msgs.msg import TaskStatus

from .skill_loader import SkillLoader
from .prompts import build_planning_prompt
import anthropic


class OpenClawAgent(Node):
    def __init__(self):
        super().__init__('openclaw_agent')
        self.client = anthropic.Anthropic()
        self.skills = SkillLoader('skills/')
        self.current_goal = None
        self.task_history = []

        self.action_pub = self.create_publisher(String, '/openclaw/action', 10)

        self.status_sub = self.create_subscription(
            TaskStatus,
            '/openclaw/task_status',
            self.on_status_update,
            10
        )

    def execute_goal(self, goal: str):
        self.current_goal = goal
        self.task_history = []
        self.plan_and_dispatch()

    def plan_and_dispatch(self):
        prompt = build_planning_prompt(
            goal=self.current_goal,
            skills=self.skills.list_all(),
            history=self.task_history
        )
        response = self.client.messages.create(
            model="claude-opus-4-6",
            max_tokens=512,
            messages=[{"role": "user", "content": prompt}]
        )
        decision = json.loads(response.content[0].text)
        skill = self.skills.get(decision['skill'])

        self.get_logger().info(f"Dispatching: {skill.name} — {skill.groot_prompt}")
        self.task_history.append({
            "skill": skill.name,
            "reasoning": decision['reasoning']
        })

        msg = String()
        msg.data = skill.groot_prompt
        self.action_pub.publish(msg)

    def on_status_update(self, msg: TaskStatus):
        self.get_logger().info(
            f"Status: '{msg.prompt}' confidence={msg.confidence:.2f}"
        )
        if msg.confidence < 0.6 or self._is_blocker(msg.prompt):
            self.task_history.append({
                "interrupt": msg.prompt,
                "confidence": msg.confidence
            })
            self.get_logger().warn("Replanning due to interrupt...")
            self.plan_and_dispatch()

    def _is_blocker(self, prompt: str) -> bool:
        blockers = ["cannot see", "failed", "blocked", "unreachable", "dropped"]
        return any(b in prompt.lower() for b in blockers)


def main(args=None):
    rclpy.init(args=args)
    node = OpenClawAgent()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
