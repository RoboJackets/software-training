# ROS Basics: CLI

ROS has a really nice command line interface (CLI) that allows for rich introspection. We can print messages being passed between nodes onto the console, run ROS nodes in isolation, and even *record* the messages being passed. How cool is that?

Run this first: `sudo apt install ros-humble-turtlesim`.

Here's a list of the main CLI commands that you'll probably use over and over again.

**Nodes**
* The `ros2 run <package_name> <executable_name>` launches an executable from a package. Try running `ros2 run turtlesim turtlesim_node`! You should see a window appear. Note that we don't know the name of the node, yet.
* We can run `ros2 node list` to show the names of all running nodes. If you do it after running the turtlesim command from above, you should see `/turtlesim` as the only running node.
* What if we want to access more information about our node? We can use `ros2 node info <node_name>`. This will return a list of subscribers, publishers, and services that interact with `node_name`. Try running `ros2 node info /turtlesim` and examine the output.

**Topics**
* `ros2 topic list` can be used to return a list of all active topics on the system. If you append the handy `-t` flag, it will also print each topic's message type.
* We can also see the data being published on a topic using `ros2 topic echo <topic_name>`.
* If you want to see more information about a topic, you can use `ros2 topic info <topic_name>`. This will show the message type and number of nodes publishing and subscribing to that topic.
* We can also publish data to a topic from the command line using `ros2 topic pub <topic_name> <msg_type> "<args>"`. Where `<args>` should use YAML syntax. If you don't know what parameters the message type takes, you can run `ros2 interface show <msg_type>`.

There's a really nice tool to visualize all active nodes, topics, and connections in a system called `rqt_graph`. You can launch this by simply typing `rqt_graph` into your terminal. Try unchecking all checkboxes next to "Hide" and examine the graph after running `ros2 run turtlesim turtlesim_node` and `ros2 run turtlesim turtle_teleop_key`.

> Remember, we'll walk through all of this during training, so don't fret! Also, the ROS 2 documentation has [this](https://github.com/ubuntu-robotics/ros2_cheats_sheet/blob/master/cli/cli_cheats_sheet.pdf) great reference that outline the usage of these commands.

*Next up: Project!*