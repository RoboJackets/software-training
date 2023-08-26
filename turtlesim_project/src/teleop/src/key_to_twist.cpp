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

  void KeyToTwist::keyPressCallback(const std_msgs::msg::String &msg)
  {
    /**
     * @brief This function is called whenever a key is pressed.
     * @param msg The message contains the key that was pressed.
     *
     * This function should publish a Twist msg to the cmd_vel topic
     * corresponding to the key that was pressed.
     */

    auto cmd_vel = geometry_msgs::msg::Twist();
  }
}

RCLCPP_COMPONENTS_REGISTER_NODE(key_to_twist::KeyToTwist)
