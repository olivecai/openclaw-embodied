#!/bin/bash

ssh kibub@kibub "pkill -f 'robot_client'" 
export PYTHONPATH=$PWD/python-st3215:$PYTHONPATH
python /home/kibub/kibub-neck-servos/disable_arms_torque.py