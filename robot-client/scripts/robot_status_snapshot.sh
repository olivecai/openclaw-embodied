#!/bin/bash

echo "Capturing robot status and environment information."


ssh kibub@kibub "source ~/miniforge3/etc/profile.d/conda.sh && conda run -n lerobot python -m lerobot.async_inference.robot_client \
    --robot.type=bi_so_follower  \
    --robot.left_arm_config.port=/dev/follower_left  \
    --robot.right_arm_config.port=/dev/follower_right  \
    --robot.top_cameras=\"{ top_realsense_color: {type: opencv, index_or_path: /dev/top_realsense_color, width: 640, height: 480, fps: 30}, top_realsense_depth: {type: opencv, index_or_path: /dev/top_realsense_depth, width: 640, height: 480, fps: 30}, top_webcam: {type: opencv, index_or_path: /dev/top_webcam, width: 640, height: 480, fps: 30}}\" \
    --robot.right_arm_config.cameras=\"{ wrist: {type: opencv, index_or_path: /dev/wrist_right, width: 640, height: 480, fps: 30}}\"  \
    --robot.left_arm_config.cameras=\"{ wrist: {type: opencv, index_or_path: /dev/wrist_left, width: 640, height: 480, fps: 30}}\" \
    --server_address=10.145.8.86:8080  \
    --robot.id=follower \
    --get_current_status=True" &