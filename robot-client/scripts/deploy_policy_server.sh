#!/bin/bash

# Instructions for OpenClaw Agent: This bash script initializes the policy server to host the robot client. Specifying 'device' and 'preload_models_path' is optional, but can speed up the first inference call by preloading all models within the preload_models_path json file onto the specified device. 

conda run --no-capture-output -n lerobot python -u -m lerobot.async_inference.policy_server \
    --host=0.0.0.0 \
    --port=8080 \
    --policy_type=groot \
    --device=cuda \
    --preload_models_path=/home/ocai/openclaw-embodied/robot-client/groot_prompt.json