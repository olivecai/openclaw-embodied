---
name: press-red-button
description: "Press the red button."
---
# Press Red Button Skill

## When to Use This Skill

Use this press-red-button skill whenever:
- You see the red button and need to press it.
- You want to activate a feature or trigger an action by pressing the button.

## How to Use

When you invoke the press-red-button skill, it will:
1. Locate the red button.
2. Plan a path for the robot's arm to reach the button.
3. Execute the motion to press the button.

## Behavior Based on Result

| Result | Your Action |
|--------|-------------|
| skill evaluate-status returned SUCCESS | Confirm the button was pressed successfully. If so, proceed to the next step in your task. If not, attempt to adjust the position or try again. |
| skill evaluate-status returned IN_PROGRESS | Wait for the robot to complete the current action. |
| skill evaluate-status returned FAILED | Attempt to reposition the button or adjust the robot's approach and try again. |
| skill evaluate-status returned UNCLEAR | Investigate the situation further before proceeding. |

## Setup


Set up the press-red-button skill:
```bash
export SKILL="press-red-button"
export TASK=$(python3 -c "import json; d=json.load(open('$PROMPT_FILE')); print(d['$SKILL']['task'])")
export REPO=$(python3 -c "import json; d=json.load(open('$PROMPT_FILE')); print(d['$SKILL']['repo-id'])")
``` 

Then deploy:

```bash
bash $DEPLOY_GROOT_PROMPT_SCRIPT
```


## Example

> Robot detects the red button and invokes the press-red-button skill.
> Robot plans the motion and successfully presses the button.
> Robot says: "I've pressed the button. What would you like me to do next?"

> Robot is asked to press the red button, but it is out of reach.
> Robot says: "I see the button, but it's out of my reach. Could you please move it closer to me?"

> Robot attempts to press the button but fails to position itself correctly.
> Robot says: "I had trouble pressing the button. Let me try adjusting my position and attempt again."
> Robot tries again and successfully presses the button.
> Robot says: "I've adjusted my position and successfully pressed the button. What would you like me to do next?"
