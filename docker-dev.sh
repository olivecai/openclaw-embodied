#!/bin/bash
# Docker helper script for OpenClaw development

USAGE="
Usage: $0 [command]

Commands:
  build     - Build the project in Docker
  launch    - Launch the agent in Docker (interactive shell)
  clean     - Remove build artifacts
  help      - Show this message

Examples:
  # First time setup:
  $0 build

  # Interactive development:
  $0 launch

  # Clean and rebuild:
  $0 clean && $0 build
"

if [ "$1" == "help" ] || [ "$1" == "-h" ]; then
    echo "$USAGE"
    exit 0
fi

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
COMMAND="${1:-launch}"

case "$COMMAND" in
    build)
        echo "🐳 Building OpenClaw in Docker container..."
        docker run --rm -v "$PROJECT_DIR:/workspace" ros:rolling bash -c \
            "cd /workspace && source /opt/ros/rolling/setup.bash && ./build.sh"
        echo ""
        echo "✅ Build complete! To launch interactively, run:"
        echo "   $0 launch"
        ;;
    
    launch)
        echo "🐳 Launching OpenClaw development container..."
        echo ""
        echo "Once inside the container, run:"
        echo "  source /opt/ros/rolling/setup.bash"
        echo "  ./build.sh          # First time only"
        echo "  source install/setup.bash"
        echo "  ros2 launch openclaw openclaw.launch.py"
        echo ""
        docker run -it -v "$PROJECT_DIR:/workspace" ros:rolling bash -c \
            "cd /workspace && bash"
        ;;
    
    clean)
        echo "🧹 Cleaning build artifacts..."
        rm -rf "$PROJECT_DIR/build" "$PROJECT_DIR/install" "$PROJECT_DIR/log"
        echo "✅ Clean complete"
        ;;
    
    *)
        echo "❌ Unknown command: $COMMAND"
        echo ""
        echo "$USAGE"
        exit 1
        ;;
esac
