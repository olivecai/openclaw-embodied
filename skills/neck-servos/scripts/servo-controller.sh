#!/bin/bash
export PYTHONPATH=$PWD/python-st3215:$PYTHONPATH
export AXIS=$1
export MOVETO=$2
export
ssh kibub@kibub "source ~/miniforge3/etc/profile.d/conda.sh && conda run -n lerobot python /home/kibub/kibub-neck-servos/get_servo_pos.py"