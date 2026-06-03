import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class ROSBridge(Node):
    def __init__(self, node_name='openclaw_bridge'):
        super().__init__(node_name)
        self.pub = self.create_publisher(String, '/openclaw/action', 10)
        self.sub = self.create_subscription(String, '/openclaw/status', self.on_status, 10)

    def on_status(self, msg: String):
        self.get_logger().info(f"Received status: {msg.data}")

    def publish_action(self, action_text: str):
        msg = String()
        msg.data = action_text
        self.pub.publish(msg)
