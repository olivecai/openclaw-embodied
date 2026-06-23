# MEMORY.md - Kibub Long-Term Memory

Curated facts and lessons worth keeping across sessions. Raw logs go in `logs/`.

## Robot Configuration

- Robot name: **Kibub**
- Arms: Dual SO101 arms (left + right). Skills are arm-specific — read the SKILL.md carefully to choose the right arm based on object position.
- Wheels: Differential drive. Forward = `DD_XVEL=50, DD_AVEL=0`. Rotate CW = `DD_XVEL=0, DD_AVEL=-100`.
- Neck: Two servos (yaw + pitch). Range 0–4095, center = 2048. Pitch 2600 = looking at table. Pitch 1900 = looking at person. Yaw 1700 = 45° left, 2300 = 45° right.
- Camera API: `http://10.145.8.86:8001`. Prefer `top_color` for task evaluation. Fall back to `/image` if unavailable.
- SSH host for neck servos: `kibub@kibub`

## Startup Checklist

Before any session of embodied control:
1. `export USER=$(whoami)`
2. `cd /home/${USER}/lerobot/ && git pull origin main`
3. `cd /home/${USER}/openclaw-embodied/`
4. `export PROMPT_FILE="robot-client/groot_prompt.json"`
5. `export DEPLOY_GROOT_PROMPT_SCRIPT=robot-client/scripts/deploy_groot_prompt.sh`
6. `./robot-client/scripts/deploy_policy_server.sh &`

## Groot VLA Skill Deploy Pattern

All pick-and-place skills (pick-up-cup, stack-cup, press-red-button) follow the same pattern:
```bash
export SKILL="<skill-name>"
export TASK=$(python3 -c "import json; d=json.load(open('$PROMPT_FILE')); print(d['$SKILL']['task'])")
export REPO=$(python3 -c "import json; d=json.load(open('$PROMPT_FILE')); print(d['$SKILL']['repo-id'])")
bash $DEPLOY_GROOT_PROMPT_SCRIPT
```
Never construct these commands from memory — always verify against the skill's SKILL.md.

## Available Skills

| Skill | What it does |
|-------|-------------|
| `evaluate-status` | Get camera images + robot state from API. Use before and after every action. |
| `neck-servos` | Adjust yaw/pitch via SSH to `kibub@kibub`. Good for scanning the scene. |
| `diff-drive` | Move the robot base (forward, backward, rotate). |
| `pick-up-cup` | Pick up a cup. Left or right arm variant based on cup position. |
| `stack-cup` | Stack one cup on another. |
| `press-red-button` | Press the red button. |
| `identify-face` | Identify a person's face. |
| `hello-world` | Basic connectivity test. |

## Lessons Learned

_(Update this section as errors or surprising behaviors are observed.)_
