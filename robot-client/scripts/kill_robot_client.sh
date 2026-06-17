#!/bin/bash

# Instructions for OpenClaw Agent: this bash script kills the robot client and disables torque on the neck servos. This is useful for resetting the robot client or safely powering down the robot.
# Example usage: a task is completed and the agent wants to reset the robot client for the next task, or the agent wants to safely power down the robot by disabling torque on the neck servos.

ssh kibub@kibub 'pkill -f robot_client; export PYTHONPATH=$PWD/python-st3215:$PYTHONPATH; python /home/kibub/kibub-neck-servos/disable_arms_torque.py'