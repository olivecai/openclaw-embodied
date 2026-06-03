import json


def build_planning_prompt(goal, skills, history):
    skills_block = json.dumps(skills, indent=2)
    history_block = json.dumps(history, indent=2) if history else "None yet."

    return f"""You are OpenClaw, a robotic manipulation agent.

GOAL: {goal}

AVAILABLE SKILLS:
{skills_block}

TASK HISTORY (including any interruptions):
{history_block}

Choose the single best skill to execute next given the goal and history.
If there was an interrupt, reason about what went wrong and pick a recovery skill.

Respond with ONLY valid JSON:
{{"skill": "<skill_name>", "reasoning": "<1 sentence why>"}}
"""
