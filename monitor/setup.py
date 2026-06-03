from setuptools import find_packages, setup

package_name = 'openclaw_monitor'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='OpenClaw Team',
    maintainer_email='dev@example.com',
    description='OpenClaw Monitor: Lightweight task status observer',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'openclaw_monitor = openclaw_monitor.monitor_node:main',
        ],
    },
)
