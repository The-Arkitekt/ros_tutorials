cmake_minimum_required(VERSION 3.0.2)
project(tutorial_one)

find_package(catkin REQUIRED COMPONENTS  roscpp  rospy  std_msgs  genmsg)

## Generate messages in the 'msg' folder
add_message_files(DIRECTORY msg FILES Num.msg Student.msg)

## Generate services in the 'srv' folder
add_service_files(DIRECTORY srv FILES AddTwoInts.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## add include directories
include_directories(include ${catkin_INCLUDE_DIRS})

## add the executables to be made
add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker tutorial_one_generate_messages_cpp)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener tutorial_one_generate_messages_cpp)

add_executable(add_two_ints_server src/add_two_ints_server.cpp )
target_link_libraries(add_two_ints_server ${catkin_LIBRARIES})
add_dependencies(add_two_ints_server tutorial_one_gencpp)

add_executable(add_two_ints_client src/add_two_ints_client.cpp)
target_link_libraries(add_two_ints_client ${catkin_LIBRARIES})
add_dependencies(add_two_ints_client tutorial_one_gencpp)


