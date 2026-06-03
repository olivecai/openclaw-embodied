#!/bin/bash
# Launch OpenClaw agent in Docker with ROS environment pre-configured

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo "🚀 Launching OpenClaw in Docker..."
echo ""

# Use sudo if docker command fails without it
sudo docker run -it \
    -v "$PROJECT_DIR:/workspace" \
    -e ROS_LOCALHOST_ONLY=1 \
    ros:rolling \
    bash -c "
        cd /workspace
        source /opt/ros/rolling/setup.bash
        source install/setup.bash
        echo ''
        echo '✅ OpenClaw environment ready!'
        echo ''
        echo 'To launch the agent:'
        echo '  ros2 launch openclaw openclaw.launch.py'
        echo ''
        echo 'Or run individual nodes:'
        echo '  ros2 run openclaw openclaw_agent'
        echo '  ros2 run openclaw_monitor openclaw_monitor'
        echo ''
        bash
    "
