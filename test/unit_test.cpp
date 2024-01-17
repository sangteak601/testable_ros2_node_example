#include <gtest/gtest.h>
#include <rclcpp/rclcpp.hpp>
#include "business_logic.hpp"

class BusinessLogicTestFixture : public testing::Test
{
  protected:
    BusinessLogicTestFixture()
    {
        bl_ptr_ = std::make_unique<BusinessLogic>(rclcpp::get_logger("business_logic_test_fixture"));
    }
    std::unique_ptr<BusinessLogic> bl_ptr_;
};

TEST_F(BusinessLogicTestFixture, ServiceLogicTest)
{
    EXPECT_TRUE(bl_ptr_->myServiceLogic());
    EXPECT_FALSE(!bl_ptr_->myServiceLogic());
}

TEST_F(BusinessLogicTestFixture, SubscriptionLogicTest)
{
    EXPECT_EQ(bl_ptr_->mySubscriptionLogic(1), 1);
    EXPECT_EQ(bl_ptr_->mySubscriptionLogic(100), 100);
}