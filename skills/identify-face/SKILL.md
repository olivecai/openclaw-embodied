---
name: identify-face
description: Analyzes the current camera view to identify known people based on the local face database stored in ~/.openclaw/workspace/known_faces/.
---
# Face Identification Skill

## When to Use This Skill

Use this face identification skill whenever:
- You see a person in front of you and need to know who they are.
- You want to personalize your greeting or recall previous context about a specific person.
- You are starting a social interaction and need to address the individual by name.

## How to Use

When you invoke the face identification tool, it will:
1. Capture the current camera frame.
2. Compare the frame against all reference photos in `~/.openclaw/workspace/known_faces/`.
3. Return a JSON object: `{"name": "PersonName"}` or `{"name": "Unknown"}`.

## Behavior Based on Result

| Result | Your Action |
|--------|-------------|
| Known name returned | Greet the person by name. Recall any previous interactions or preferences you remember about them. |
| `"Unknown"` returned | Politely introduce yourself and ask for their name. Store the name if they provide it. |
| Error returned | Assume you cannot identify the person. Proceed with a generic, friendly greeting. |

## Setup

Reference images must be placed in the following structure:

```
~/.openclaw/workspace/known_faces/
├── Alice/
│   ├── alice_front.jpg
│   └── alice_side.jpg
└── Bob/
    └── bob.jpg
```

Each subfolder name becomes the person's identity label. Multiple images per person improve accuracy.

Run the helper script to initialize the directory structure:

```bash
bash robot/skills/identify-face/scripts/setup_known_faces.sh
```

## Example Interaction

> Robot sees a face and invokes the face identification skill.
> Tool returns `{"name": "Alice"}`.
> Robot says: "Hello Alice! Great to see you again."

> Robot sees a face and invokes the face identification skill.
> Tool returns `{"name": "Unknown"}`.
> Robot says: "Hi there! I'm KiBub. I don't think we've met before — what's your name?"
