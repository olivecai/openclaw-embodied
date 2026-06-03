'''
status_node.py

for now: there will exist a small random number generator to simulate the status of the requested task. 
status_node must understand the initial task ==> if asked to reach for the cup, it needs to evaluate: is cup reached? why or why not? (reason)

End goal: there will exist a lightweight model to view the scene and populate:
status: {success: float between [0,1], reason: "some string describing the scene"}
'''
from node import Node
import numpy as np
from const import *

class StatusNode(Node):
    '''
    Owner of this thread has 2 responsibilities:
    1. Use method set_task to set the needed task
    2. Poll evaluate to check status

    Lifetime of this node is continual 
    '''
    def __init__(self, evaluation_mode: str = DEPLOY):
        super().__init__()
        self.rng = np.random.default_rng(12345)
        self.current_success = None
        self.current_reason = None
        self.task = None
        self.evaluation_mode = evaluation_mode

    def get_status(self):
        return {"success": self.current_success, "reason": self.current_reason} #gets current, which is continually updated in evaluate

    def set_task(self, task: str): # the owner of the thread sets the task. always Action node sends the task.
        self.task = task

    def run_evaluation(self):
        if self.evaluation_mode == SIM:
            self.current_success = self.rng.random()
            if self.task == IDENTIFY_FACE:
                if self.current_success <= 0.5:
                    self.current_reason = "No face was detected."
                else:
                    self.current_reason = "Face was successfully detected."
        if self.evaluation_mode == DEPLOY:
            pass


    def evaluate(self):
        '''
        evaluate will be run by the thread to poll the status of the robot and its task
        '''
        self.run_evaluation()



def main():
    status = StatusNode(evaluation_mode = SIM)
    while True:
        status.set_task(IDENTIFY_FACE)
        status.evaluate()
        print(status.get_status())
        print(status.birthtime)
        import time
        time.sleep(1)

    



if __name__ == "__main__":
    main()