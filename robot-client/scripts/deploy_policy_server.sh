 python -m lerobot.async_inference.policy_server \
    --host=0.0.0.0 \
    --port=8080 \
    --policy_type=groot \
    --device=cuda \
    --preload_models_path=/home/ocai/openclaw-embodied/robot-client/groot_prompt.json