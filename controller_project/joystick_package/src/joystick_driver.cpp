#include "joystick_driver.hpp"

namespace joystick_driver
{

JoystickDriver::JoystickDriver(const rclcpp::NodeOptions & options)
: rclcpp::Node("joystick_driver", options)
{
  _cmd_publisher = create_publisher<joystick_msgs::msg::VelocityPair>(
    "~/motors",
    rclcpp::SystemDefaultsQoS());

  _joy_subscriber = create_subscription<sensor_msgs::msg::Joy>(
    "~/joy", rclcpp::SystemDefaultsQoS(), [this](const sensor_msgs::msg::Joy msg) {
      joyCallback(msg);
    });

  absoluteMaxVel = declare_parameter<double>("absoluteMaxVel");
  maxVel = declare_parameter<double>("maxVel");
  maxVelIncr = declare_parameter<double>("maxVelIncr");
  leftJoyAxis = declare_parameter<int>("leftJoyAxis");
  rightJoyAxis = declare_parameter<int>("rightJoyAxis");
  leftInverted = declare_parameter<bool>("leftInverted");
  rightInverted = declare_parameter<bool>("rightInverted");
}

void JoystickDriver::joyCallback(const sensor_msgs::msg::Joy & msg)
{
  /*
  What you need to implement:
  1. Increase maxVel if 'msg.buttons[3]' is true
  2. Decrease maxvel if 'msg.buttons[1]' is true
  3. Make sure 0.0 <= maxVel <= absoluteMaxVel
  4. Update the left and right velocity to be scaled by maxVel
  5. Update the right velocity to be scaled by maxVel
  6. Take into account leftInverted and rightInverted for velocity
  7. Publish cmd using _cmd_publisher

  You have been provided a basic template for filling out the msg to be published
  */

  auto cmd = joystick_msgs::msg::VelocityPair();
  cmd.left_velocity = msg.axes[leftJoyAxis]; // * your code
  cmd.right_velocity = msg.axes[rightJoyAxis]; // * your code
  cmd.header.stamp = this->get_clock()->now();
}
}

RCLCPP_COMPONENTS_REGISTER_NODE(joystick_driver::JoystickDriver)
