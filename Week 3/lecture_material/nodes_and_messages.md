# ROS Basics: Nodes, Messages, and Topics

A ROS system can be thought of as a distributed system that can be visualized as a **graph**. 

Each **node** in this graph is a "subsystem" that is responsible for a *single, modular* purpose (for example, publishing data from a joystick).
Each node can send and receive data (called **messages**). A full robotic system may contain *many* nodes processing data simultaneously.

![The ROS Graph](ros-graph.png)

Nodes exchange messages via **topics**. A node may publish and subscribe to any number of topics simultaneously.