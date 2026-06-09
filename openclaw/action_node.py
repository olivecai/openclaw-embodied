'''
action_node.py

Action node sends mesages to two places: the Gr00t model for the Lanague prompt as part of the VLA, and the Status node to set the task for the status node to evaluate.
OWNER of action node polls the Status node continually to get the status of the robot and its task. The status is a dictionary with two keys: success, which is a float between [0,1], and reason, which is a string describing the scene. The action node will use the status to decide what to do next. For example, if the status is {"success": 0.8, "reason": "Face was successfully detected."}, the action node might decide to move on to the next task. If the status is {"success": 0.2, "reason": "No face was detected."}, the action node might decide to try again or to give up.

'''
from node import Node
import numpy as np
from const import *

class ActionNode(Node):
    '''
   
    '''
    def __init__(self, dispatch_mode: str = DEPLOY, inference_mode: str = DEPLOY):
        super().__init__()
        self.current_action = None
        self.groot_prompt = None
        self.dispatch_mode =dispatch_mode
        self.inference_mode = inference_mode

    def infer(self):
        if self.inference_mode == SIM:
            self.groot_prompt = SKILLS_TO_GROOT_PROMPT[self.current_action]
        if self.inference_mode == DEPLOY:
            pass

    def dispatch(self):
        if self.dispatch_mode == SIM:
        if self.dispatch_mode == DEPLOY:
            pass
        









        self.rng = np.random.default_rng(12345)
        self.current_success = None
        self.current_reason = None
        self.task = None
        self.action_mode = action_mode

    def get_status(self):
        return {"success": self.current_success, "reason": self.current_reason} #gets current, which is continually updated in evaluate

    def set_task(self, task: str): # the owner of the thread sets the task. always Action node sends the task.
        self.task = task

    def run_evaluation(self):
        if self.action_mode == SIM:
            self.current_success = self.rng.random()
            if self.task == IDENTIFY_FACE:
                if self.current_success <= 0.5:
                    self.current_reason = "No face was detected."
                else:
                    self.current_reason = "Face was successfully detected."
        if self.action_mode == DEPLOY:
            pass


    def evaluate(self):
        '''
        evaluate will be run by the thread to poll the status of the robot and its task
        '''
        self.run_evaluation()



def main():
    action = ActionNode(action_mode = SIM)
    while True:
        action.set_task(IDENTIFY_FACE)
        action.evaluate()
        print(action.get_status())
        print(action.birthtime)
        import time
        time.sleep(1)

    



if __name__ == "__main__":
    main()