#include "ros/ros.h"

/* 
    ROS中日志：
    演示不同级别日志的基本使用
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hello_log");
    ros::NodeHandle nh;
    //日至输出
    ROS_DEBUG("调试信息,DEBUG"); //不会输出在控制台
    ROS_INFO("一般信息,INFO"); //默认白色字体
    ROS_WARN("警告信息,WARN"); //默认黄色字体
    ROS_ERROR("错误信息,ERROR");//默认红色字体
    ROS_FATAL("严重错误,FATAL");//默认红色字体

    return 0;
}
