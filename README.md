# apply_zyz_rotation
This repository was developed to accomplish the proposed challenge of get a rotation matrix having the ZYZ rotation angles. Besides that, it was a prerequest the use of C++, ROS2 and solve the problem through a server and client structure.

(WORK IN PROGRESS)

## Setup
First, create your workspace
```bash
$ mkdir ~/ros2_ws/src -p
``` 

Build the package
```bash
$ cd ~/ros2_ws
$ source install/setup.bash
``` 

## Usage
Start the server
```bash
$ ros2 run apply_zyz_rotation rotate_server
``` 

Run the client, passing the ZYZ rotations in degrees
```bash
$ ros2 run apply_zyz_rotation rotate_client <Z1> <Y> <Z2>
``` 