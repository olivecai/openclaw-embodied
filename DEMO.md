

# deploy pick up cup 

## cow terminal 1:

conda run -n lerobot python -m lerobot.async_inference.policy_server   --host=0.0.0.0   --port=8080   --fps=30

## cow terminal 2: (takes 30 seconds or so for policy rollout)

TASK="Pick up the cup"
REPO=oliveoil8888/groot-pick-up-cup-left-arm
ssh kibub@kibub "source ~/miniforge3/etc/profile.d/conda.sh && conda run -n lerobot python -m lerobot.async_inference.robot_client \
    --robot.type=bi_so_follower  \
    --robot.left_arm_config.port=/dev/follower_left  \
    --robot.right_arm_config.port=/dev/follower_right  \
    --robot.top_cameras=\"{ top_realsense_color: {type: opencv, index_or_path: /dev/video4, width: 640, height: 480, fps: 30}, top_realsense_depth: {type: opencv, index_or_path: /dev/video2, width: 640, height: 480, fps: 30}, top_webcam: {type: opencv, index_or_path: /dev/video6, width: 640, height: 480, fps: 30}}\" \
    --robot.right_arm_config.cameras=\"{ wrist: {type: opencv, index_or_path: /dev/wrist_right, width: 640, height: 480, fps: 30}}\"  \
    --robot.left_arm_config.cameras=\"{ wrist: {type: opencv, index_or_path: /dev/wrist_left, width: 640, height: 480, fps: 30}}\" \
    --task=\"${TASK}\"  \
    --server_address=10.145.8.86:8080  \
    --policy_type=groot \
    --pretrained_name_or_path=${REPO}  \
    --policy_device=cuda   \
    --actions_per_chunk=16 \
    --debug_visualize_queue_size=true \
    --robot.id=follower" &

### to kill:

ssh kibub@kibub "pkill -f 'robot_client'" 
