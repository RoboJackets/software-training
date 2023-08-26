#include "key_to_twist.hpp"

namespace key_to_twist
{

  KeyToTwist::KeyToTwist(const rclcpp::NodeOptions &options)
      : rclcpp::Node("key_to_twist", options)
  {
    _cmd_publisher = create_publisher<geometry_msgs::msg::Twist>(
        "~/cmd_vel",
        rclcpp::SystemDefaultsQoS());

    _key_press_subscriber = create_subscription<std_msgs::msg::String>(
        "~/char_pressed", rclcpp::SystemDefaultsQoS(), [this](const std_msgs::msg::String msg)
        { keyPressCallback(msg); });
  }

  void KeyToTwist::keyPressCallback(const sensor_msgs::msg::Joy &msg)
  {
    // You have been provided a basic template for filling out the msg to be published.

    auto cmd_vel = geometry_msgs::msg::Twist();
    cmd.header.stamp = this->get_clock()->now();
  }
}

RCLCPP_COMPONENTS_REGISTER_NODE(key_to_twist::KeyToTwist)
