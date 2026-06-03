#!/bin/bash
# Build script for OpenClaw Embodied

echo "=== OpenClaw Embodied Build Script ==="
echo ""

# Check if we're in the right directory
if [ ! -f "package.xml" ] && [ ! -f "openclaw/package.xml" ]; then
    echo "❌ Error: Not in openclaw-embodied root directory!"
    echo "Please run from: ~/openclaw-embodied or /workspace (in Docker)"
    exit 1
fi

# Check if ROS 2 is sourced
if [ -z "$ROS_DISTRO" ]; then
    echo "❌ ROS 2 not sourced. Please run:"
    echo "   source /opt/ros/rolling/setup.bash"
    exit 1
fi

echo "✓ ROS 2 Distro: $ROS_DISTRO"
echo "✓ Working Directory: $(pwd)"
echo ""

# Check for required tools
if ! command -v colcon &> /dev/null; then
    echo "❌ colcon not found. Install it with:"
    echo "   sudo apt install -y python3-colcon-common-extensions"
    exit 1
fi

# Install Python dependencies
echo "📦 Installing Python dependencies..."
pip install -q pyyaml anthropic 2>/dev/null && echo "✓ Dependencies installed" || echo "⚠️ Some dependencies may need manual install"

# Clean previous builds (optional)
if [ "$1" == "clean" ]; then
    echo ""
    echo "🧹 Cleaning previous builds..."
    rm -rf build/ install/ log/
    echo "✓ Clean complete"
fi

# Build with colcon
echo ""
echo "🔨 Building OpenClaw packages..."
if colcon build --symlink-install; then
    echo ""
    echo "✅ Build complete!"
    echo ""
    echo "To use the packages, run:"
    echo "   source install/setup.bash"
    echo ""
    echo "Then launch the agent:"
    echo "   ros2 launch openclaw openclaw.launch.py"
else
    echo ""
    echo "❌ Build failed. Check the output above for errors."
    exit 1
fi
