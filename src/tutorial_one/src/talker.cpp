#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

/*
 * This tutorial demonstrates simple sending of messages over the ROS system
 */

int main(int argc, char** argv) { 
	
   /*
    * Always call ros::init() before using any part of the ROS system
    */
    ros::init(argc, argv, "talker");

   /*
    * The first nodehandle constructed fully initializes the node
    * The last nodehandle destructed will close down the node
    */
    ros::NodeHandle n;

   /*
    * The first parameter is topic name
    * THe second parameter is the size of the message queue
    */
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000); 
	
    ros::Rate loop_rate(10);

    int count = 0;

    while(ros::ok()) {

        std_msgs::String msg;

        std::stringstream ss;

        ss << "Hello world: " << count;

        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        chatter_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();

        ++count;
    }
    return 0;
}
