# Launching Nodes

While you launched nodes already, the process of launching them is not as simple as just typing in a command.
Nodes are launched using `.launch.py` files in `launch` directories provided in all ROS2 packages.

Launch files might also be `.launch` xml files in some RJ codebases, but this is an antipattern in ROS2 so we will not be addressing
it.

Open up `joystick.launch.py` in `controller_project/launch`. This is designed to launch the ROS2 node you just finished writing.

The syntax for the file might look complicated, but it is ultimately the same for almost every package. **If you ever have to write a new launch file, just copy an existing launch file and change the parameters!**

#### Explanation of the Relevant Parameters:
1. Package- the package you are in
2. Executable- Whatever you made the node called in the CMake
3. Parameters- Defines where the params yaml for the node is
4. Remappings- Advanced concept related to namespaces, only include if a senior member says so
