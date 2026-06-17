---
name: stack-cup
description: "Stack a cup on top of another cup using the robot's arm and gripper

---
# Stack Cup Skill

## When to Use This Skill

Use this stack-cup skill whenever:
- You see two cups on the table and need to stack one on top of the other.
- You want to manipulate the cups for further processing or serving.

## How to Use

When you invoke the stack-cup skill, it will:
1. Locate the cups on the table. Decide which arm to use based on the cups' positions and the robot's configuration. If the cup is on the right side, use the right arm; if it's on the left side, use the left arm.
2. Plan a path for the robot's arm to reach the cups.
3. Execute the motion to stack the cups.

## Behavior Based on Result

| Result | Your Action |
|--------|-------------|
| skill evaluate-status returned SUCCESS | Confirm the cup is securely held. If so, proceed to the next step in your task. If not, attempt to adjust the grip or reposition and try picking up again. |
| skill evaluate-status returned IN_PROGRESS | Wait for the robot to complete the current action. |
| skill evaluate-status returned FAILED | Attempt to reposition the cup or adjust the robot's approach and try again. |
| skill evaluate-status returned UNCLEAR | Investigate the situation further before proceeding. |

## Setup


Set up the stack-cup skill:
```bash
export SKILL="stack-cup" 
export TASK=$(python3 -c "import json; d=json.load(open('$PROMPT_FILE')); print(d['$SKILL']['task'])")
export REPO=$(python3 -c "import json; d=json.load(open('$PROMPT_FILE')); print(d['$SKILL']['repo-id'])")
```

Then deploy:

```bash
bash $DEPLOY_GROOT_PROMPT_SCRIPT
```


## Example

> Robot detects two cups on the table and invokes the stack-cup skill.
> Robot plans the motion and successfully stacks one cup on top of the other.
> Robot says: "I've stacked the cups. What would you like me to do with them next?"

> Robot is asked to stack cups, but one of the cups is out of reach.
> Robot says: "I see the cups, but one of them is out of my reach. Could you please move it closer to me?"

> Robot attempts to stack the cups but fails to position them correctly.
> Robot says: "I had trouble stacking the cups. Let me try adjusting my position and attempt again."
> Robot tries again and successfully stacks the cups.
> Robot says: "I've adjusted my position and successfully stacked the cups. What would you like me to do with them next?"
