# Setup instructions for OpenClaw Embodied

This project is a ROS 2 Python-based robotic manipulation agent with LLM planning.

## Prerequisites

- Ubuntu 22.04 LTS or later (or use Docker)
- ROS 2 Humble/Iron/Rolling
- Python 3.10+
- Anthropic API key (for Claude Opus)

## Installation

### Option 1: Using Docker (Recommended for now)

```bash
docker run -it ros:rolling bash
```

Then inside the container:
```bash
cd /workspace
git clone https://github.com/your-org/openclaw-embodied
cd openclaw-embodied
source /opt/ros/rolling/setup.bash
colcon build
source install/setup.bash
```

### Option 2: Native ROS 2 Installation

Once ROS 2 is installed on your system:

```bash
cd ~/openclaw-embodied
source /opt/ros/rolling/setup.bash
colcon build
source install/setup.bash
```

## Running the Agent

### Launch both nodes:
```bash
ros2 launch openclaw openclaw.launch.py
```

### Or run individually:
```bash
# Terminal 1: Agent
ros2 run openclaw openclaw_agent

# Terminal 2: Monitor
ros2 run openclaw_monitor openclaw_monitor
```

## Project Structure

```
openclaw-embodied/
├── openclaw/              # Main agent package
│   ├── agent.py          # LLM planner node
│   ├── skill_loader.py   # Skill YAML loader
│   ├── prompts.py        # System prompt templates
│   ├── ros_bridge.py     # ROS pub/sub wrappers
│   ├── package.xml
│   └── setup.py
├── monitor/              # Monitor package
│   ├── monitor_node.py   # Status observer
│   ├── confidence.py     # Confidence utilities
│   ├── package.xml
│   └── setup.py
├── launch/
│   └── openclaw.launch.py  # ROS 2 launch file
└── skills/               # Skill definitions (YAML)
    ├── pick_up_cup.yaml
    ├── facial_recognition.yaml
    └── search_for_object.yaml
```

## Custom Message Types

The agent expects a custom ROS message `openclaw_msgs/TaskStatus`:
```
string prompt
float64 confidence
```

Create this in a separate package or mock it locally.

## Next Steps

1. **Install anthropic SDK**: `pip install anthropic`
2. **Add API key**: Set `ANTHROPIC_API_KEY` environment variable
3. **Customize skills**: Add more YAML skill definitions in `skills/`
4. **Implement monitor**: Attach your lightweight VLM to `monitor_node.py`
5. **Define action/status nodes**: Create ROS nodes for GR00t integration

## Troubleshooting

### ROS 2 not found
Check that you've sourced the setup script:
```bash
source /opt/ros/rolling/setup.bash
```

### Package not found during build
Ensure you're in the workspace root and have run `colcon build`:
```bash
cd ~/openclaw-embodied
colcon build
source install/setup.bash
```

### Import errors
Install dependencies:
```bash
pip install pyyaml anthropic rclpy
```
