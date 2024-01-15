#include "ros2_interface.hpp"

ROS2Interface::ROS2Interface(BusinessLogic bl)
    : Node("my_node"), bl_(bl)
{
    my_service_ = create_service<std_srvs::srv::Empty>(
        "my_service", std::bind(
            &ROS2Interface::myService, this, std::placeholders::_1, std::placeholders::_2));

    my_subscription_ = create_subscription<std_msgs::msg::Bool>(
        "my_topic", 10, std::bind(&ROS2Interface::mySubscription, this, std::placeholders::_1));
}

void ROS2Interface::mySubscription(const std_msgs::msg::Bool & msg)
{
    RCLCPP_INFO_STREAM(get_logger(), "mySubscription callback is called !");
    // read topic
    msg.data;

    // call business logic
    bl_.mySubscriptionLogic();
    RCLCPP_INFO_STREAM(get_logger(), "mySubscription callback is ended !");
}

void ROS2Interface::myService(
    const std::shared_ptr<std_srvs::srv::Empty::Request> request,
    std::shared_ptr<std_srvs::srv::Empty::Response> response)
{
    RCLCPP_INFO_STREAM(get_logger(), "myService is called !");
    // read request
    request;

    // call business logic
    bl_.myServiceLogic();
    RCLCPP_INFO_STREAM(get_logger(), "myService is ended !");
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  BusinessLogic bl(rclcpp::get_logger("my_node_business_logic"));
  rclcpp::spin(std::make_shared<ROS2Interface>(bl));
  rclcpp::shutdown();
  return 0;
}