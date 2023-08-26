#ifndef KEY_TO_TWIST_H
#define KEY_TO_TWIST_H

#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp_components/register_node_macro.hpp>

namespace key_to_twist
{
    class KeyToTwist : public rclcpp::Node
    {
    public:
        explicit KeyToTwist(const rclcpp::NodeOptions &options);

    private:
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr _cmd_publisher;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _key_press_subscriber;

        void keyPressCallback(const std_msgs::msg::String &msg);
    };
}

#endif
