---
name: evaluate-status
description: "Evaluate robot task progress from LeRobot observation API images."
---

# Evaluate Skill

Use this skill when asked to inspect, monitor, or evaluate the embodied robot task using the LeRobot policy server observation API.

## API

Base URL:

```text
http://10.145.8.86:8001
```

Available endpoints:

```text
GET /status
GET /observation
GET /images
GET /image
GET /images/{key}
```

The API is served from `policy_server.py` alongside the gRPC policy server. It exposes the latest raw observation received from the robot client.

## Workflow

1. Check stream status.

```bash
curl -s http://10.145.8.86:8001/status
```

2. Confirm `has_observation` is `true`.

If false, report:

```text
No robot observation has been received yet.
```

3. Check freshness.

Use `client_timestamp` and `server_timestamp`. If the latest timestamp appears stale, say the robot stream may be disconnected or paused.

4. Determine available camera keys.

Use `image_keys` from `/status` or `/images`.

```bash
curl -s http://10.145.8.86:8001/images
```

5. Download the best image for inspection.

Prefer `top_color` if available:

```bash
curl -s http://10.145.8.86:8001/images/top_color --output robot_top_color.jpg
```

Otherwise use the first available image:

```bash
curl -s http://10.145.8.86:8001/image --output robot_latest.jpg
```

6. Use the OpenClaw image tool on the downloaded image.

Example prompt:

```text
Analyze this latest robot camera image. The task is: "<TASK>". Determine whether the task is SUCCESS, IN_PROGRESS, FAILED, or UNCLEAR. Explain the visible evidence briefly. If this is a pick-and-place task, check whether the target object is grasped, moved, released, and located inside the target area/bin.
```

7. Report a concise verdict.

Use this format:

```text
Robot task status: SUCCESS | IN_PROGRESS | FAILED | UNCLEAR

Evidence:
- ...
- ...

Confidence: high | medium | low
```

Mention the endpoint checked and whether the frame appeared recent.

## Endpoint Details

### `/status`

Use first to check whether the robot is actively streaming observations.

```bash
curl -s http://10.145.8.86:8001/status
```

Useful fields:

- `has_observation`: whether the policy server has received at least one observation.
- `timestep`: latest observation timestep.
- `client_timestamp`: robot-client-side timestamp.
- `server_timestamp`: policy-server-side receive timestamp.
- `image_keys`: image-like fields available from the latest raw observation.
- `observation_keys`: all keys in the latest raw observation.

### `/observation`

Use to inspect summarized raw observation metadata without downloading full image arrays.

```bash
curl -s http://10.145.8.86:8001/observation
```

This is useful for debugging camera keys, state keys, tensor/array shapes, dtypes, and task strings.

### `/images`

Use to list image URLs for the latest observation.

```bash
curl -s http://10.145.8.86:8001/images
```

### `/image`

Use to fetch the first available image from the latest observation.

```bash
curl -s http://10.145.8.86:8001/image --output robot_latest.jpg
```

### `/images/{key}`

Use to fetch a specific camera image.

```bash
curl -s http://10.145.8.86:8001/images/top_color --output robot_top_color.jpg
curl -s http://10.145.8.86:8001/images/top_depth --output robot_top_depth.jpg
```

## Pick-and-Place Evaluation Criteria

### SUCCESS

Report `SUCCESS` if the image clearly shows:

- The target object has been moved from the start area.
- The target object is inside or on the intended destination.
- The gripper has released the object or is no longer obstructing final placement.
- The object is stable enough to count as placed.

### IN_PROGRESS

Report `IN_PROGRESS` if:

- The gripper is approaching the object.
- The object is currently grasped but not yet placed.
- The object is near the destination but still held.
- The robot appears to be mid-motion.

### FAILED

Report `FAILED` if:

- The object was dropped outside the target area.
- The object is not grasped after an attempted pick.
- The object is visibly misplaced.
- The robot is stuck, tangled, or pushing the object away from the goal.
- The scene shows a collision, unsafe posture, or impossible continuation.

### UNCLEAR

Report `UNCLEAR` if:

- The camera view is obstructed.
- The target object or destination is not visible.
- Lighting or blur prevents reliable judgment.
- The available camera is depth-only or otherwise hard to interpret.
- The latest observation appears stale.

## Notes

- Do not assume success from policy actions alone. Use visual evidence from the image endpoint.
- Prefer RGB/color cameras over depth cameras for semantic task evaluation.
- If `top_color` exists, use it as the default camera for task-level status.
- If the HTTP endpoint is unreachable, report that the observation API is unavailable.
- If `/status` works but `/image` fails, inspect `/images` to find valid camera keys.
- Keep downloaded images in the current workspace with descriptive names such as `robot_latest.jpg` or `robot_top_color.jpg`.
```