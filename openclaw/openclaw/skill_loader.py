import os
from dataclasses import dataclass
from typing import List

import yaml


@dataclass
class Skill:
    name: str
    description: str
    groot_prompt: str
    preconditions: List[str]
    tags: List[str]


class SkillLoader:
    def __init__(self, skills_dir: str):
        self.skills = {}
        for fname in os.listdir(skills_dir):
            if fname.endswith('.yaml'):
                with open(os.path.join(skills_dir, fname)) as f:
                    data = yaml.safe_load(f)
                    skill = Skill(**{k: data.get(k, []) for k in Skill.__dataclass_fields__})
                    self.skills[skill.name] = skill

    def list_all(self) -> List[dict]:
        return [{"name": s.name, "description": s.description, "tags": s.tags}
                for s in self.skills.values()]

    def get(self, name: str) -> Skill:
        return self.skills[name]
