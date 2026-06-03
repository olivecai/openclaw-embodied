# OpenClaw Embodied

**LLM-powered robotic manipulation agent** with real-time monitoring and skill composition.

OpenClaw uses Claude Opus to plan high-level manipulation tasks, breaking them into individual skills that are executed via GR00t. A lightweight monitor observes execution and triggers replanning on failures.

## Quick Overview

- **Agent** (`openclaw/agent.py`): LLM planner that decides which skill to execute
- **Monitor** (`monitor/monitor_node.py`): Lightweight VLM observer that flags failures  
- **Skills** (`skills/*.yaml`): Reusable robotic actions (pick, place, search, etc.)
- **ROS 2**: Communication backbone (pub/sub for actions and status)

## Architecture

```
┌─────────────┐
│   OpenClaw  │  Claude Opus planning node
│   Agent     │  - Receives goal
└──────┬──────┘  - Queries available skills
       │         - Publishes skill to execute
       │
    [ROS Topic: /openclaw/action]
       │
       ▼
┌─────────────┐
│   GR00t     │  Lightweight model → robot control
│   Bridge    │  (receives skill prompt)
└─────────────┘
       │
       ▼
    [ROBOT]
       │
       ▼
┌─────────────┐
│  Monitor    │  Observes execution
│   Node      │  - Pulls sensor data
└──────┬──────┘  - Runs lightweight VLM
       │         - Publishes status
       │
    [ROS Topic: /openclaw/task_status]
       │
       ▼
   [Agent replans if low confidence or blocker detected]
```

## Installation

### ⚠️ Current Issue: ROS Repository Certificate

The ROS 2 apt repository (`packages.ros.org`) currently has a **TLS certificate mismatch** on Ubuntu 24.04 noble, preventing package downloads.

**Workarounds:**
1. **Docker** (Recommended): Use the official ROS Docker image
   ```bash
   docker run -it ros:rolling bash
   ```
2. **VPN/Network**: Try a different network that can resolve packages.ros.org correctly
3. **Build from Source**: Clone ROS 2 repositories and build manually (advanced)

### Install via Docker (Easiest)

```bash
# 1. Start a ROS container
docker run -it -v ~/openclaw-embodied:/workspace ros:rolling bash

# 2. Inside the container
cd /workspace
source /opt/ros/rolling/setup.bash
colcon build
source install/setup.bash

# 3. Launch
ros2 launch openclaw openclaw.launch.py
```

### Install Native (Once ROS is available)

```bash
source /opt/ros/rolling/setup.bash
cd ~/openclaw-embodied
./quickstart.sh
```

or manually:
```bash
colcon build
source install/setup.bash
ros2 launch openclaw openclaw.launch.py
```

## Usage

### Launch All Nodes
```bash
ros2 launch openclaw openclaw.launch.py
```

### Run Individual Nodes
```bash
# Terminal 1: Agent
ros2 run openclaw openclaw_agent

# Terminal 2: Monitor  
ros2 run openclaw_monitor openclaw_monitor
```

### Test Skill Loading
```bash
python3 -c "
from openclaw.skill_loader import SkillLoader
loader = SkillLoader('skills/')
for skill in loader.list_all():
    print(f\"- {skill['name']}: {skill['description']}\")
"
```

## Project Structure

```
openclaw-embodied/
├── openclaw/
│   ├── __init__.py
│   ├── agent.py              # Main LLM planner
│   ├── skill_loader.py       # YAML → Skill dataclass
│   ├── prompts.py            # System prompt templates
│   ├── ros_bridge.py         # ROS pub/sub utilities
│   ├── openclaw.launch.py    # ROS 2 launch config
│   ├── package.xml           # ROS package manifest
│   ├── setup.py              # Python packaging
│   └── resource/             # ROS resource marker
│
├── monitor/
│   ├── __init__.py
│   ├── monitor_node.py       # Status observation node
│   ├── confidence.py         # Confidence utilities
│   ├── package.xml
│   ├── setup.py
│   └── resource/
│
├── skills/
│   ├── pick_up_cup.yaml
│   ├── facial_recognition.yaml
│   └── search_for_object.yaml
│
├── run-agent.sh              # Quick launch script
├── docker-dev.sh             # Docker helper
├── build.sh                  # Build script
├── quickstart.sh             # Quick start script
├── SETUP.md                  # Setup instructions
└── README.md                 # This file
```

## Customization

### Add a New Skill

Create `skills/my_skill.yaml`:
```yaml
name: move_to_pose
description: Move arm to a target 6D pose
groot_prompt: "Move the arm end-effector to the specified pose using inverse kinematics."
preconditions:
  - arm calibrated
  - target reachable
tags:
  - manipulation
  - motion
```

The agent will automatically discover and use it.

### Modify the Agent Prompt

Edit `openclaw/prompts.py` and change `build_planning_prompt()`:
```python
def build_planning_prompt(goal, skills, history):
    # Customize the system message, skill formatting, history display, etc.
    ...
```

### Customize Monitor Logic

Edit `monitor/monitor_node.py`:
- `get_sensor_snapshot()`: Pull data from your sensors
- `run_monitor_model()`: Call your VLM or rule engine

## ROS Messages

### Custom Message: `openclaw_msgs/TaskStatus`
```
string prompt      # Natural language status ("Cannot see the cup", "Task complete", etc.)
float64 confidence # Confidence 0.0–1.0
```

You'll need to create this message package or mock it locally for now.

## Environment Variables

```bash
export ANTHROPIC_API_KEY="sk-..."        # Claude API key
export ROS_DOMAIN_ID=0                   # ROS 2 domain (for multi-robot)
export ROS_LOCALHOST_ONLY=0              # Enable network communication
```

## Troubleshooting

### "Package 'openclaw' not found"
Make sure you've built and sourced the install space:
```bash
cd ~/openclaw-embodied
colcon build
source install/setup.bash
```

### "Cannot import anthropic"
Install the SDK:
```bash
pip install anthropic
```

### "YAML error" when loading skills
Check skill YAML syntax:
```bash
python3 -c "import yaml; yaml.safe_load(open('skills/pick_up_cup.yaml'))"
```

### ROS 2 repository certificate fails
Use Docker (see Installation section) or wait for the ROS infrastructure to be fixed.

## Next Steps

1. **Create `openclaw_msgs` package**: Define the `TaskStatus` message type
2. **Implement GR00t bridge**: Connect skill execution to your robot
3. **Add monitor logic**: Integrate a lightweight VLM for task observation
4. **Expand skills**: Add domain-specific skills for your robot
5. **Test locally**: Mock the ROS topics and run the agent
6. **Deploy**: Run on real hardware with GR00t and robot sensors

## References

- [ROS 2 Documentation](https://docs.ros.org)
- [Anthropic Claude API](https://docs.anthropic.com)
- [ROS 2 Python Packages](https://docs.ros.org/en/rolling/Concepts/Basic/About-Packages.html)

## License

MIT

## Contact

OpenClaw Team — dev@example.com
