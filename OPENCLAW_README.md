# openclaw-embodied

Instructions for OpenClaw Agent:

## OpenClaw Agent Purpose
Integrate OpenClaw agent with a robotic system: a dual SO101 arm system named "Kibub". This repository contains a skills/ directory for OpenClaw to access, the LLM planner, a lightweight VLM for monitoring the success of the task, and ROS nodes for deploying messages. This code is designed to be robot and VLA agnostic.

## OpenClaw agent responsibilities:
1. Initialization responsibilities
2. Inferencing responsibilities

## Initialization responsibilities
Jobs to be performed prior to the OpenClaw embodiment:
1. Run `export USER=$(whoami)`
1. Run `cd /home/${USER}/lerobot/ ; git pull origin main;` 
1. Always execute scripts from the working directory `/home/${USER}/openclaw-embodied`: Run `cd /home/${USER}/openclaw-embodied/` 
2. Run `export PROMPT_FILE="robot-client/groot_prompt.json"` 
3. Run `export DEPLOY_GROOT_PROMPT_SCRIPT=robot-client/scripts/deploy_groot_prompt.sh`
2. Initialize the asynchronous server to host inferencing for the GR00t model by running `./robot-client/scripts/deploy_policy_server.sh &`


## Inferencing responsibilities
Jobs to be performed during the OpenClaw embodiment:

## Check the status of the robot and its environment
1. Get the current images and timestamp from the robot to see what tasks it can carry out; execute skill evaluate-status, which runs `./robot-client/scripts/robot_status_snapshot.sh and then retreieves observations at the endpoint http://127.0.0.1:8001.

## Execute a skill on the robot
1. To execute skills on the robot, follow the instructions in the SKILL.md in each skills/ directory. For skills that utilize the Groot VLA model to perform pick and place tasks, you will have to export bash variables REPO and TASK and initialize a robot client to deploy the policy.

## Kill the motors of the robot 
1. Disable torque in the robot arms: `./robot-client/scripts/kill_robot_client.sh` 
