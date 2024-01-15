#ifndef ROS2_INTERFACE_HPP_
#define ROS2_INTERFACE_HPP_

#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/empty.hpp>
#include <std_msgs/msg/bool.hpp>

#include "business_logic.hpp"

class ROS2Interface : public rclcpp::Node
{
  public:
    ROS2Interface(BusinessLogic bl);

  private:
    void myService(const std::shared_ptr<std_srvs::srv::Empty::Request> request,
        std::shared_ptr<std_srvs::srv::Empty::Response> response);
    void mySubscription(const std_msgs::msg::Bool & msg);

    BusinessLogic bl_;
    rclcpp::Service<std_srvs::srv::Empty>::SharedPtr my_service_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr my_subscription_;
};

#endif