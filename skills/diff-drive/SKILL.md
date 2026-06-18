---
name: diff-drive
description: "Control the robot's differential drive wheels to move the robot around its environment."
---
# Differential Drive Skill

## When to Use This Skill

Use this diff-drive skill whenever:
- You are too far away from something you would like to interact with and need to drive closer.
- You feel shy and want to slowly drive backwards.

## How to Use

When you invoke the diff-drive skill, it will:
1. Drive the robot to a the desired position using the differential drive wheels.
2. Allow the images at the endpoints http://127.0.0.1:8001/images/top_webcam, http://127.0.0.1:8001/images/top_realsense_color, and http://127.0.0.1:8001/images/top_realsense_depth to reflect the new robot position.

## Setup and Usage

Firstly, start up the differential drive host on the robot by running: `ssh kibub@kibub "source ~/miniforge3/etc/profile.d/conda.sh && conda run -n lerobot python /home/kibub/kibub_diff_drive/diffdrive_host.py --robot.port=/dev/diff_drive`

Then, wait a few seconds to ensure the differential driver host is running.

Decide the linear and angular velocities (m/s) of the robot and the duration (s) to send those velocities to the wheels. For example, to drive forward for 5 seconds:

```
DD_XVEL=2.0
DD_AVEL=0.0
DD_DUR=5.0


python skills/diff-drive/diff-driver.py --x_vel=${DD_XVEL} --theta_vel=${DD_AVEL} --duration=${DD_DUR}`
```

## Presets for linear and angular velocities: <TODO>

Drive forward: 

DD_XVEL=2.0
DD_AVEL=0.0
DD_DUR=5.0

Turn 90 degrees clockwise:

DD_XVEL=0.0
DD_AVEL=1.5
DD_DUR=5.0


## Example

> Robot can see the table but it is far away. It invokes the diff-driver skill to drive closer to the table.
> Robot says: "Let me drive closer to the table to interact with the objects on it."
> Agent executes command to drive straight forward: `ssh kibub@kibub "source ~/miniforge3/etc/profile.d/conda.sh && conda run -n lerobot python /home/kibub/kibub_diff_drive/diffdrive_host.py --robot.port=/dev/diff_drive; echo "Sleeping for 5 seconds to ensure the differential driver host can connect." ; sleep 5; python skills/diff-drive/diff-driver.py --x_vel=5 --theta_vel=0 --duration=5`
> Robot successfully comes closer to the table and can complete a pick and place task.
