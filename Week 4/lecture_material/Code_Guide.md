# Code Guide

Today you will be working inside `controller project`. This is a collection of packages relating to publishing
messages that control the differential drive of a rover based on controller input.

These packages are based on real code used in [RoboNav's manual rover control](https://github.com/RoboJackets/urc-rover)

1. Open `joystick_package`

JoyCallback takes in a msg from a game controller, and outputs a custom message type that can be seen in the `joystick_msgs`
package. Custom messages in ROS work by having CMake generate the types using `rosidl`, then are exported for use in other packages.

You can view the raw message template in `msg/VelocityPair.msg` and the message generation in the `CMakeLists.txt`. 
***It is important to note that the name of any message will become snakecase after ROSIDL processing!***

2. Open `src/joystick_driver.cpp`

You will be writing your code in the `joyCallback` function. The comments will explain what needs to be done.

4. Open `package.xml`

This is where you specify all external packages and the name of your current package. Take a look to see all the external
packages needed for the node you just finished


5. Open `CMakeLists.txt`

Every ROS2 package has a root `CMakeLists.txt` that builds the package and sets up unit testing. 
**Go line by line through the CMake to get a sense of how it is generally written!**
Even veteran RJ members tend to have a rudimentary sense of how CMake works, so you should use the file as a helpful reference in the future!

6. Build and test your node with `colcon build && colcon test && colcon test-result --verbose`

If your node does not work, you should see stderr output. Since the unit tests have been written before you
have even begun development, this is an example of TDD! It can be very helpful for designing and building nodes
with simple and well-defined outputs.

The framework for writing unit tests will not be explaining in training, but can be viewed in `test`. It is one of the key uses
of rospy in several RJ codebases.