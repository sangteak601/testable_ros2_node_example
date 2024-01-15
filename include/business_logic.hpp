#ifndef BUSINESS_LOGIC_HPP_
#define BUSINESS_LOGIC_HPP_

#include <rclcpp/rclcpp.hpp>

class BusinessLogic
{
  public:
    BusinessLogic(rclcpp::Logger logger);   // Is there any other ways to log without using ros logger ?
    bool myServiceLogic();
    void mySubscriptionLogic();

  private:
    rclcpp::Logger logger_;
};

#endif