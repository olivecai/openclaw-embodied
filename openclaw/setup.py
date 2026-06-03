from setuptools import find_packages, setup

package_name = 'openclaw'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name, ['openclaw.launch.py']),
    ],
    install_requires=['setuptools', 'pyyaml', 'anthropic'],
    zip_safe=True,
    maintainer='OpenClaw Team',
    maintainer_email='dev@example.com',
    description='OpenClaw: LLM-based robotic manipulation planner',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'openclaw_agent = openclaw.agent:main',
        ],
    },
)
