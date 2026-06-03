'''
For now, the code must be very maintainable and simple. 

When the agent is initialized, ask 'Give Joe a cup'.
The agent then decomposes this more complex task into a series of mini tasks:
1. Identify joe via facial recognition
2. Pick up a cup
3. Give it to Joe

These sub tasks are waiting in the queue. Job 1 is dispatched to the Action node. We get a Status node update: robot is in motion.
We wait for the next Status node update, which gives us two fields of information: status_score: float from 0 to 1, and reason: str describing what happened.
0 == total failure
1 == total success.
If status_score >= SUCCESS_THRESHOLD then: dispatch job 2 to the Action node.
Else: based on the reason, rethink what we should do.

'''

class OpenClawAgent:
    def __init__(self):
        self.