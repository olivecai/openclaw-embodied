---
name: neck-servos
description: "Control the robot's neck servos to adjust the camera angle."
---
# Neck Servos Skill

## When to Use This Skill

Use this neck-servos skill whenever:
- You need to adjust the camera angle to get a better view.
- You want to position the camera for optimal tracking or recognition.

## How to Use

When you invoke the neck-servos skill, it will:
1. Adjust the neck servos to the desired position.

## Behavior Based on Result



## Setup



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
