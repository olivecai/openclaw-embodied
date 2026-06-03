from setuptools import find_packages
from setuptools import setup

setup(
  name='openclaw_msgs',
  version='0.1.0',
  packages=find_packages(
      include=('openclaw_msgs', 'openclaw_msgs.*')),
)
