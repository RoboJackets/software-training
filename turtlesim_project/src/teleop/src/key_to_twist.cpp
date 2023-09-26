#include "key_to_twist.hpp"

namespace key_to_twist
{

KeyToTwist::KeyToTwist(const rclcpp::NodeOptions & options)
: rclcpp::Node("key_to_twist", options)
{
  _cmd_publisher = create_publisher<geometry_msgs::msg::Twist>(
    "turtle1/cmd_vel",
    rclcpp::SystemDefaultsQoS());

  _key_press_subscriber = create_subscription<std_msgs::msg::String>(
    "/char_pressed", rclcpp::SystemDefaultsQoS(), [this](const std_msgs::msg::String msg)
    {keyPressCallback(msg);});
}

void KeyToTwist::keyPressCallback(const std_msgs::msg::String & msg)
{
  /**
   * @brief This function is called whenever a key is pressed.
   * @param msg The message contains the key that was pressed.
   *
   * This function should publish a Twist msg to the cmd_vel topic
   * corresponding to the key that was pressed.
   *
   * The Twist message has both linear and angular velocity fields
   * which should be set as follows:
   *  - If the "w" key is pressed, set linear velocity to 1.0.
   *  - If the "a" key is pressed, set angular velocity to 1.0.
   *  - If the "s" key is pressed, set linear velocity to -1.0.
   *  - If the "d" key is pressed, set angular velocity to -1.0.
   */

  double linear = 0;
  double angular = 0;

  // Your code here. Set linear and angular to the appropriate values before publishing the Twist message.

  auto twist = geometry_msgs::msg::Twist();
  twist.angular.z = angular;
  twist.linear.x = linear;
  _cmd_publisher->publish(twist);
}
}

RCLCPP_COMPONENTS_REGISTER_NODE(key_to_twist::KeyToTwist)
