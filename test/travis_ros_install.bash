#!/bin/bash -xve

#required packages
sudo pip install --user catkin_pkg
sudo pip install --user empy
sudo pip install --user pyyaml
sudo pip install --user rospkg

#ros install
cd ..
git clone https://github.com/ryuichiueda/ros_setup_scripts_Ubuntu14.04_server.git
cd ./ros_setup_scripts_Ubuntu14.04_server
bash ./setup0.bash
bash ./setup1.bash

#catkin setup
mkdire -p ~/catkin_ws/src
cd ~/catkin_ws/src
source /opt/ros/indigo/setup.bash
cd ~/catkin_ws
catkin_make
