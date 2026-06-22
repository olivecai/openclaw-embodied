import sys
import time
import argparse
# # Point this at wherever you copied kibub-diff-drive on this machine
# sys.path.insert(0, "/home/ocai/openclaw-embodied/skills/diff-drive/kibub-diff-drive")

from kibub_diff_drive.easy_diffdrive import DiffDriveRemote

def main():
    
    parser = argparse.ArgumentParser(description='Differential Driver for Kibub')
    parser.add_argument('--x_vel', type=float, help='Linear velocity of Kibub', required=True)
    parser.add_argument('--theta_vel', type=float, help='Angular velocity of Kibub', required=True)
    parser.add_argument('--duration', type=float, help='Duration in seconds for wheels to drive', required=True)
    parser.add_argument('--remote_ip', type=str, default="10.145.8.176", help='IP address of the DiffDriveHost (robot)', required=False)
    args = vars(parser.parse_args())
    print("ARGS: ", args)

    x_vel = float(args["x_vel"])
    theta_vel = float(args["theta_vel"])
    duration = float(args["duration"])

    # remote_ip is the IP address of the ROBOT machine (the one running diffdrive_host.py).
    # If this script is running on the SAME machine as the host, use "localhost".

    print(f"DiffDriver: x-vel={x_vel}, theta-vel={theta_vel}, duration={duration}")

    with DiffDriveRemote(remote_ip=args["remote_ip"]) as wheels:
        print("Waiting for host to respond...")
        if not wheels.wait_until_reachable(timeout_s=5.0):
            print("Could not reach the host. Is diffdrive_host.py running on the robot?")
            sys.exit(1)

        print("Driving forward...")
        wheels.drive(x_vel=x_vel, theta_vel=theta_vel)  # 0.1 m/s forward, no turning
        time.sleep(duration)

        print("Stopping...")
        wheels.stop()

        state = wheels.get_state()
        print("Final state:", state)

if __name__ == "__main__":

    main()
