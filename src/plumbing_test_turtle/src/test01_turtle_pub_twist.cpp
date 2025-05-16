#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
/* 
    需求：发布速度消息
        话题：/turtle1/cmd/vel
        消息：geometry_msgs/Twist

    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建句柄
        4.创建发布者对象
        5.发布逻辑
        6.spinonce



*/

int main(int argc, char *argv[])
{
    // 2.初始化 ROS 节点
    ros::init(argc,argv,"my_own_control");
    // 3.创建句柄
    ros::NodeHandle nh;
    // 4.创建发布者对象
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
    // 5.发布逻辑
    ros::Rate rate(10);
    //组织发布消息
    geometry_msgs::Twist twist;
    twist.linear.x = 1.0;
    twist.linear.y = 0.0;
    twist.linear.z = 0.0;
    twist.angular.x = 0.0;
    twist.angular.y = 0.0;
    twist.angular.z = 1.0;
    //循环发布
    while(ros::ok())
    {
        pub.publish(twist);
        //休眠
        rate.sleep();
        //回头

        // 6.spinonce
        ros::spinOnce();



    }


    

    return 0;
}
