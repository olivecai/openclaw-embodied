from launch import LaunchDescription
from launch.actions import ExecuteProcess


def generate_launch_description():
    # Use the console_scripts entry points directly
    return LaunchDescription([
        ExecuteProcess(
            cmd=['openclaw_agent'],
            output='screen',
            name='openclaw_agent'
        ),
        ExecuteProcess(
            cmd=['openclaw_monitor'],
            output='screen',
            name='openclaw_monitor'
        ),
        # Add action/status nodes or lightweight VLM nodes here as needed.
    ])
