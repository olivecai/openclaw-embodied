# HEARTBEAT.md - Periodic Robot Status Check

On each heartbeat, execute skill `evaluate-status` to observe the robot's current state and decide what to do next.

## Step 1: Check the Stream

```bash
curl -s http://10.145.8.86:8001/status
```

- `has_observation: false` → Run `./robot-client/scripts/robot_status_snapshot.sh` to fire a single observation, then re-query `/status`. If still false, report "No observation received after snapshot." Do not execute skills.
- Timestamp stale (>30s) → Report "Stream appears paused or disconnected." Do not execute skills.
- Stream live → Proceed.

## Step 2: Get the Image

```bash
curl -s http://10.145.8.86:8001/images/top_color --output robot_top_color.jpg
```

If `top_color` is unavailable, use `/image` to get the first available camera. Analyze the image with the vision tool.

## Step 3: Decide

| Scene | Action |
|-------|--------|
| Arms mid-motion / object grasped | Wait, re-evaluate after brief delay. |
| Task SUCCESS visible | Log completion. Report to operator. |
| Task FAILED (dropped, missed) | Diagnose cause. Retry if safe. |
| Robot idle, task obvious | Pick the best skill and execute it. |
| Robot idle, scene ambiguous | Pan neck to scan (`neck-servos`), then re-evaluate. |
| API unreachable | Report unavailable. Take no motor actions. |

## Step 4: Log

Append to `logs/heartbeat.log`:
```
[TIMESTAMP] has_obs=<bool> | Scene: <1-sentence> | Action: <what you did>
```

## Hard Rules

- **Do not hallucinate Groot VLA deploy commands.** Always read the `SKILL.md` in `skills/<skill-name>/` before executing a Groot skill.
- Always export `SKILL`, `TASK`, and `REPO` before running `bash $DEPLOY_GROOT_PROMPT_SCRIPT`.
- Do not trigger any motor commands if the robot stream is stale — physical state is unknown.
- Do not run skills that use robot arms without first confirming a live, fresh observation.
