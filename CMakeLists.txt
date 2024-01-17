cmake_minimum_required(VERSION 3.5)
project(testable_ros2_node_example)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
  rclcpp
  std_msgs
  std_srvs
)

include_directories(include)

add_executable(my_node src/ros2_interface.cpp src/business_logic.cpp)
ament_target_dependencies(my_node ${THIS_PACKAGE_INCLUDE_DEPENDS})

install(TARGETS
  my_node
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)

  ament_add_gtest(unit_test test/unit_test.cpp src/business_logic.cpp)
  ament_target_dependencies(unit_test ${THIS_PACKAGE_INCLUDE_DEPENDS})
endif()

ament_package()