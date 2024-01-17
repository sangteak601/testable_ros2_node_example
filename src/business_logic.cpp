#include "business_logic.hpp"

BusinessLogic::BusinessLogic(rclcpp::Logger logger)
    : logger_(logger)
{
    RCLCPP_INFO_STREAM(logger_, "Initializing business logic ...");

    // do something

    RCLCPP_INFO_STREAM(logger_, "Business logic has been successfully loaded !");
}

bool BusinessLogic::myServiceLogic()
{
    RCLCPP_INFO_STREAM(logger_, "myServiceLogic is called ! ");
    // do something
    RCLCPP_INFO_STREAM(logger_, "myServiceLogic is ended ! ");
    return true;
}

int BusinessLogic::mySubscriptionLogic(int msg_data)
{
    RCLCPP_INFO_STREAM(logger_, "mySubscriptionLogic is called ! ");
    // do something
    RCLCPP_INFO_STREAM(logger_, "mySubscriptionLogic is ended ! ");
    return msg_data;
}