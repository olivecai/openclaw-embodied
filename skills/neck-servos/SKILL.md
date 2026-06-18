---
name: neck-servos
description: "Control the robot's neck servos to adjust the camera angle."
---
# Neck Servos Skill

## When to Use This Skill

Use this neck-servos skill whenever:
- You need to adjust the camera angle to get a better view.
- You want to position the camera for optimal tracking or recognition.

## How to Use

When you invoke the neck-servos skill, it will:
1. Adjust the neck servos to the desired position.
2. Allow the images at the endpoints http://127.0.0.1:8001/images/top_webcam, http://127.0.0.1:8001/images/top_realsense_color, and http://127.0.0.1:8001/images/top_realsense_depth to reflect the new camera angle.

## Setup and Usage

### Set up the terminal environment:
Prior to running the neck-servos skill, run the following command:
`ssh kibub@kibub "export PYTHONPATH=/home/kibub/kibub-neck-servos/python-st3215:$PYTHONPATH"`


### Neck servo positions:
The neck servos have step counts between 0 and 4095, where 2048 is the center position. The yaw servo is centered at 2048, with lower values turning left and higher values turning right. The pitch servo is also centered at 2048, with higher values tilting down and lower values tilting up. To see the table, set pitch = 2600. To see a person standing, set pitch = 1900. To look about 45 degrees to the left, set yaw = 1700. To look about 45 degrees to the right, set yaw = 2300.  

### Get current servo positions:
To get the current servo positions, set AXIS=yaw or AXIS=pitch and run `ssh kibub@kibub "export PYTHONPATH=/home/kibub/kibub-neck-servos/python-st3215:$PYTHONPATH; source ~/miniforge3/etc/profile.d/conda.sh && conda run -n lerobot python /home/kibub/kibub-neck-servos/get-servo-pos.py --axis $AXIS"`.

### Adjust the neck servos:
Then you can run the script to adjust the neck servos: set AXIS=yaw or AXIS=pitch, and specify the amount to move or nudge using either '--moveto' or '--nudge' followed by the amount. If you would like to move the head to a certain location, use '--moveto' followed by the amount. If you would instead like to adjust the neck servos, use 'nudge' followed by the amount. 

For example, to nudge the yaw by 10 steps, run `ssh kibub@kibub "export PYTHONPATH=/home/kibub/kibub-neck-servos/python-st3215:$PYTHONPATH; source ~/miniforge3/etc/profile.d/conda.sh && conda run -n lerobot python /home/kibub/kibub-neck-servos/servo_controller.py --axis yaw --nudge 10"`.
For example, to move the pitch to step position 2148, run `ssh kibub@kibub "export PYTHONPATH=/home/kibub/kibub-neck-servos/python-st3215:$PYTHONPATH; source ~/miniforge3/etc/profile.d/conda.sh && conda run -n lerobot python /home/kibub/kibub-neck-servos/servo_controller.py --axis pitch --moveto 2148"`.


## Example

> Robot detects a person but the face is not fully visible. It invokes the neck-servos skill to adjust the camera angle for a better view.
> Robot says: "Let me adjust my camera angle to see you better."
> Agent executes command to bring the pitch to position 1900: `ssh kibub@kibub "export PYTHONPATH=/home/kibub/kibub-neck-servos/python-st3215:$PYTHONPATH; source ~/miniforge3/etc/profile.d/conda.sh && conda run -n lerobot python /home/kibub/kibub-neck-servos/servo_controller.py --axis pitch --moveto 1900"`
> Robot successfully adjusts the neck servos, likely by tilting the pitch of the neck up, and now has a clear view of the person's face for identification or interaction.

> Robot is trying to find an object for a pick-and-place task but cannot see it. It invokes the neck-servos skill to reposition the camera.
> Robot says: "I'm losing sight of the object. Let me adjust my camera to keep tracking it."
> Agent executes command to look to the right by nudging the yaw by 100 steps: `ssh kibub@kibub "export PYTHONPATH=/home/kibub/kibub-neck-servos/python-st3215:$PYTHONPATH; source ~/miniforge3/etc/profile.d/conda.sh && conda run -n lerobot python /home/kibub/kibub-neck-servos/servo_controller.py --axis yaw --nudge 100"`
> Robot looks for the object but still cannot find it. It invokes the neck-servos skill again to reposition the camera.
> Agent executes command to look to the left by nudging the yaw by -200 steps: `ssh kibub@kibub "export PYTHONPATH=/home/kibub/kibub-neck-servos/python-st3215:$PYTHONPATH; source ~/miniforge3/etc/profile.d/conda.sh && conda run -n lerobot python /home/kibub/kibub-neck-servos/servo_controller.py --axis yaw --nudge -200"`
> Robot can now see the object, and proceeds to plan the pick-and-place task successfully.
