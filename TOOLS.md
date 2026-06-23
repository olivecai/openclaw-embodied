# TOOLS.md - Kibub Hardware & Environment Reference

Quick-reference cheat sheet for Kibub's physical setup. Details on how to *use* each tool live in `skills/<name>/SKILL.md`.

## Cameras

| Key | Description | Best for |
|-----|-------------|----------|
| `top_color` | Top overhead RGB (RealSense) | Task evaluation, object detection |
| `top_depth` | Top overhead depth (RealSense) | Depth/distance estimation |
| `top_webcam` | Top overhead standard webcam | Secondary view, wide angle |

Base URL: `http://10.145.8.86:8001`

- List all image keys: `GET /images`
- Download specific: `GET /images/{key}` (e.g. `top_color`)
- Download first available: `GET /image`

**Default:** Always try `top_color` first for semantic evaluation.

## Neck Servos

SSH target: `kibub@kibub`

| Axis | Center | Look left | Look right | Look down (table) | Look up (person) |
|------|--------|-----------|------------|-------------------|------------------|
| Yaw  | 2048   | ~1700     | ~2300      | —                 | —                |
| Pitch| 2048   | —         | —          | ~2600             | ~1900            |

- Use `--moveto <pos>` for absolute positioning.
- Use `--nudge <delta>` for relative adjustment.
- Script: `/home/kibub/kibub-neck-servos/servo_controller.py`
- Read current pos: `/home/kibub/kibub-neck-servos/get-servo-pos.py --axis <yaw|pitch>`

## Differential Drive

Variables to set before `./skills/diff-drive/diff-drive.sh`:

| Preset | DD_XVEL | DD_AVEL | DD_DUR |
|--------|---------|---------|--------|
| Forward | 50.0 | 0.0 | 5.0 |
| Turn CW 90° | 0.0 | -100.0 | 3.0 |
| Turn CCW / Dance | 0.0 | 100.0 | 10.0 |

## Robot Arms

- **Left arm** → use for objects on the left side of the workspace.
- **Right arm** → use for objects on the right side.
- Arm skills: `pick-up-cup-left-arm`, `pick-up-cup-right-arm`, `stack-cup`, `press-red-button`.

## Policy Server

- Start: `./robot-client/scripts/deploy_policy_server.sh &`
- Kill robot client (disable torque): `./robot-client/scripts/kill_robot_client.sh`
- Snapshot (single observation): `./robot-client/scripts/robot_status_snapshot.sh`
- Groot deploy: `bash $DEPLOY_GROOT_PROMPT_SCRIPT` (requires `SKILL`, `TASK`, `REPO` set)

## Key Files

| File | Purpose |
|------|---------|
| `robot-client/groot_prompt.json` | Task/repo mappings for all Groot VLA skills |
| `skills/<name>/SKILL.md` | Authoritative instructions for each skill |
| `logs/heartbeat.log` | Periodic status log |
