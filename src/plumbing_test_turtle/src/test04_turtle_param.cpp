#include"ros/ros.h"
/* 修改背景色的rgb参数
不一定要创建节点句柄，与后续API
有关
修改参数

*/

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"change_background");
    ros::param::set("/turtlesim/background_r",0);
    ros::param::set("/turtlesim/background_g",0);
    ros::param::set("/turtlesim/background_b",0);
    return 0;
}
