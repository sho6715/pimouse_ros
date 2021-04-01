#!/bin/bash -xve

#sync and make
rsync -av ./ ~/catkin_ws/src/pimouse_ros/
catkin_make
