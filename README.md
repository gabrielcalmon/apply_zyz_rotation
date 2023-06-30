# apply_zyz_rotation
This repository was developed to accomplish the proposed challenge of to get a rotation matrix having the ZYZ rotation angles. Besides that, it was a pre-request the usage of C++, ROS2 and solve the problem through a server and client structure.

## Introduction
The sequence diagram of the solution is presented bellow:

![banner](https://github.com/gabrielcalmon/apply_zyz_rotation/blob/master/resources/apply_zyz_rotarion_diag_sequencia.png?raw=true)

The srv structure, available on the srv/ folder, was created as follow:
```bash
float64 z1
float64 y
float64 z2
---
float64[9] r
``` 

The composed rotation matrix can be defined as bellow:
![banner](https://github.com/gabrielcalmon/apply_zyz_rotation/blob/master/resources/zyz_rotation_matrix.png?raw=true)

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