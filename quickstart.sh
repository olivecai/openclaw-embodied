#!/bin/bash
# Quick start script - handles ROS environment and certificate issues

echo "=== OpenClaw Quick Start ==="
echo ""

# Navigate to workspace if in Docker
if [ "$HOSTNAME" != "cowmatch005" ] && [ ! -d "openclaw" ]; then
    if [ -d "/workspace" ]; then
        cd /workspace
        echo "📍 Switched to /workspace"
    fi
fi

# Check if we're in the right directory
if [ ! -f "openclaw/package.xml" ]; then
    echo "❌ Error: Not in openclaw-embodied root directory!"
    echo "Current directory: $(pwd)"
    echo ""
    echo "Please run from the project root:"
    echo "  cd ~/openclaw-embodied  # on host"
    echo "  cd /workspace           # in Docker container"
    exit 1
fi

echo "✓ Project directory: $(pwd)"
echo ""

# Step 1: Check for ROS
if ! command -v ros2 &> /dev/null; then
    echo "❌ ROS 2 not found!"
    echo ""
    echo "Please run Docker with volume mount:"
    echo "  docker run -it -v ~/openclaw-embodied:/workspace ros:rolling bash"
    echo ""
    echo "Then inside the container:"
    echo "  cd /workspace"
    echo "  source /opt/ros/rolling/setup.bash"
    echo "  ./quickstart.sh"
    exit 1
fi

# Step 2: Source ROS
if [ -z "$ROS_DISTRO" ]; then
    echo "📌 Sourcing ROS 2 environment..."
    source /opt/ros/rolling/setup.bash 2>/dev/null || {
        echo "❌ Failed to source ROS setup. Try manually:"
        echo "   source /opt/ros/rolling/setup.bash"
        exit 1
    }
fi

echo "✓ ROS Distro: $ROS_DISTRO"
echo ""

# Step 3: Install dependencies
echo "📦 Installing dependencies..."
pip install -q pyyaml anthropic 2>/dev/null && echo "✓ Dependencies installed" || {
    echo "⚠️ pip install had issues, but continuing..."
}
echo ""

# Step 4: Build
echo "🔨 Building packages..."
colcon build --symlink-install 2>&1 | tail -20 || {
    echo "❌ Build failed!"
    exit 1
}

# Step 5: Source install space
if [ -f "install/setup.bash" ]; then
    source install/setup.bash
    echo "✓ Install space sourced"
else
    echo "⚠️ Install space not found, skipping sourcing"
fi

echo ""
echo "✅ Setup complete!"
echo ""
echo "🚀 To launch the agent, run:"
echo "   ros2 launch openclaw openclaw.launch.py"
echo ""
echo "To test individual nodes:"
echo "   ros2 run openclaw openclaw_agent"
echo "   ros2 run openclaw_monitor openclaw_monitor"
echo ""
