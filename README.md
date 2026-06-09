# openclaw-embodied
Integrate OpenClaw agent with a robotic system. This repository contains a skills/ directory for OpenClaw to access, the LLM planner, a lightweight VLM for monitoring the success of the task, and ROS nodes for deploying messages. This code is designed to be robot and VLA agnostic.

Instructions for OpenClaw Agent:

USER=ocai

In home/${USER}

OpenClaw agent responsibilities:
1. Initialization responsibilities
2. Inferencing responsibilities

## Initialization responsibilities
Jobs to be performed prior to the OpenClaw embodiment:
1. Run `cd /home/${USER}/lerobot/ ; git pull;` 
1. Run `cd /home/${USER}/openclaw-embodied/` 
2. Initialize the asynchronous server to host inferencing for the GR00t model by running `conda run -n lerobot python -m lerobot.async_inference.policy_server   --host=0.0.0.0   --port=8080   --fps=30`
3. In a new terminal, run `ssh kibub@kibub`.

## Inferencing responsibilities
Jobs to be performed during the OpenClaw embodiment:

## Execute a skill on the robot
1. To execute a skill on the robot: in the kibub shell session using top and wrist cameras: `conda run -n lerobot python -m lerobot.async_inference.robot_client   --robot.type=bi_so_follower  --robot.left_arm_config.port=/dev/follower_left    --robot.right_arm_config.port=/dev/follower_right    --robot.top_cameras="{ top_realsense_color: {type: opencv, index_or_path: /dev/video4, width: 640, height: 480, fps: 30}, top_realsense_depth: {type: opencv, index_or_path: /dev/video2, width: 640, height: 480, fps: 30}, top_webcam: {type: opencv, index_or_path: /dev/video6, width: 640, height: 480, fps: 30}}"  --robot.right_arm_config.cameras="{ wrist_right: {type: opencv, index_or_path: /dev/wrist_right, width: 640, height: 480, fps: 30}}"   --robot.left_arm_config.cameras="{ wrist_left: {type: opencv, index_or_path: /dev/wrist_left, width: 640, height: 480, fps: 30}}"  --task=${TASK}   --server_address=10.145.8.86:8080   --policy_type=groot  --pretrained_name_or_path=${HF_USER}/${POLICY}-${REPO}   --policy_device=cuda   --actions_per_chunk=16 --debug_visualize_queue_size=true --robot.id=follower`

Usage for `python -m lerobot.async_inference.robot_client`:
```
usage:
robot_client.py [-h] [--config_path str] [--policy_type str] [--pretrained_name_or_path str] [--robot str]
                       [--robot.type {so100_follower,so101_follower,bi_so_follower,koch_follower,omx_follower}] [--left_arm_config str]
                       [--robot.left_arm_config.port str] [--robot.left_arm_config.disable_torque_on_disconnect str]
                       [--robot.left_arm_config.max_relative_target str] [--robot.left_arm_config.cameras str]
                       [--robot.left_arm_config.use_degrees str] [--right_arm_config str] [--robot.right_arm_config.port str]
                       [--robot.right_arm_config.disable_torque_on_disconnect str] [--robot.right_arm_config.max_relative_target str]
                       [--robot.right_arm_config.cameras str] [--robot.right_arm_config.use_degrees str] [--robot.top_cameras str]
                       [--robot.id str] [--robot.calibration_dir str] [--robot.port str] [--robot.disable_torque_on_disconnect str]
                       [--robot.max_relative_target str] [--robot.cameras str] [--robot.use_degrees str] [--actions_per_chunk str]
                       [--task str] [--server_address str] [--policy_device str] [--client_device str] [--chunk_size_threshold str]
                       [--fps str] [--aggregate_fn_name str] [--debug_visualize_queue_size str]
```

### Launch the asynchronous inference policy server to host the robot client:
Open a new shell terminal and run the following:
```
conda run -n lerobot  python -m lerobot.async_inference.policy_server   --host=0.0.0.0   --port=8080   --fps=30
```

### Evaluate the status of the task execution:
Use skill evaluate-status.

2. To monitor the status of the task: 

1. async server:
Expected output:
```
INFO 2026-06-05 09:17:00 y_server.py:767 {'fps': 30,
 'host': '0.0.0.0',
 'inference_latency': 0.03333333333333333,
 'obs_queue_timeout': 2,
 'port': 8080}
INFO 2026-06-05 09:17:00 y_server.py:757 Observation API started at http://0.0.0.0:8001
INFO 2026-06-05 09:17:00 y_server.py:778 PolicyServer started on 0.0.0.0:8080
```



