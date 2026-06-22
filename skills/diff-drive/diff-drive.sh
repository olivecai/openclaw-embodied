#!/bin/bash

export KIBUBIP=$(cat KIBUB_IP) 
ssh kibub@kibub "source ~/miniforge3/etc/profile.d/conda.sh && conda run -n lerobot python -u /home/kibub/kibub_diff_drive/diffdrive_host.py --robot.port=/dev/diff_drive" & python skills/diff-drive/diff-driver.py --x_vel=${DD_XVEL} --theta_vel=${DD_AVEL} --duration=${DD_DUR} --remote_ip=${KIBUBIP}; ssh kibub@kibub "pkill -f diffdrive_host.py || true"; echo "DiffDrive Done"
