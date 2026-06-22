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

Decide the linear and angular velocities (m/s) of the robot and the duration (s) to send those velocities to the wheels. For example, to drive forward for 5 seconds, run the following commands in the current working directory:

```
export DD_XVEL=30.0
export DD_AVEL=0.0
export DD_DUR=5.0

./skills/diff-drive/diff-drive.sh

```

## Presets for linear and angular velocities: 

Drive forward: 

export DD_XVEL=50.0
export DD_AVEL=0.0
export DD_DUR=5.0

Turn 90 degrees clockwise:

export DD_XVEL=0.0
export DD_AVEL=-100.0
export DD_DUR=3.0

To dance:
export DD_XVEL=0.0
export DD_AVEL=100.0
export DD_DUR=10.0


## Example

> Robot can see the table but it is far away. It invokes the diff-driver skill to drive closer to the table.
> Robot says: "Let me drive closer to the table to interact with the objects on it."
> Agent executes command to drive straight forward: `export DD_XVEL=50; export DD_AVEL=0; export DD_DUR=5.0; ./skills/diff-drive/diff-drive.sh`
> Robot successfully comes closer to the table and can complete a pick and place task.
