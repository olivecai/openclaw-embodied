---
name: pick-up-cup
description: "Pick up a cup from the table using the robot's arm and gripper."
---
# Pick Up Cup Skill

## When to Use This Skill

Use this pick-up-cup skill whenever:
- You see a cup on the table and need to retrieve it.
- You want to manipulate the cup for further processing or serving.

## How to Use

When you invoke the pick-up-cup skill, it will:
1. Locate the cup on the table. Decide which arm to use based on the cup's position and the robot's configuration. If the cup is on the right side, use the right arm; if it's on the left side, use the left arm.
2. Plan a path for the robot's arm to reach the cup.
3. Execute the motion to pick up the cup by the handle.

## Behavior Based on Result

| Result | Your Action |
|--------|-------------|
| skill evaluate-status returned SUCCESS | Confirm the cup is securely held. If so, proceed to the next step in your task. If not, attempt to adjust the grip or reposition and try picking up again. |
| skill evaluate-status returned IN_PROGRESS | Wait for the robot to complete the current action. |
| skill evaluate-status returned FAILED | Attempt to reposition the cup or adjust the robot's approach and try again. |
| skill evaluate-status returned UNCLEAR | Investigate the situation further before proceeding. |

## Setup


If the cup is expected to be on the right side, set up the right arm pick-up-cup skill:
```bash
export SKILL="pick-up-cup-right-arm" 
export TASK=$(python3 -c "import json; d=json.load(open('$PROMPT_FILE')); print(d['$SKILL']['task'])")
export REPO=$(python3 -c "import json; d=json.load(open('$PROMPT_FILE')); print(d['$SKILL']['repo-id'])")
```

Else, if the cup is expected to be on the left side, set up the left arm pick-up-cup skill:
```bash
export SKILL="pick-up-cup-left-arm"
export TASK=$(python3 -c "import json; d=json.load(open('$PROMPT_FILE')); print(d['$SKILL']['task'])")
export REPO=$(python3 -c "import json; d=json.load(open('$PROMPT_FILE')); print(d['$SKILL']['repo-id'])")
``` 

Then deploy:

```bash
bash ./skills/robot-client/scripts/deploy_groot_prompt.sh
```


## Example

> Robot detects a cup on the table and invokes the pick-up-cup skill.
> Robot plans the motion and successfully picks up the cup by the handle.
> Robot says: "I've picked up the cup. What would you like me to do with it next?"

> Robot is asked to pick up a cup, but the cup is out of reach.
> Robot says: "I see the cup, but it's out of my reach. Could you please move it closer to me?"

> Robot attempts to pick up the cup but fails to grasp it properly.
> Robot says: "I had trouble picking up the cup. Let me try adjusting my grip and attempt again."
> Robot tries again and successfully picks up the cup.
> Robot says: "I've adjusted my grip and successfully picked up the cup. What would you like me to do with it next?"
