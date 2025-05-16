#include"ros/ros.h"
#include"turtlesim/Pose.h"

/* 
    需求，订阅乌龟的位姿信息，并输出到控制台
    准备工作:
        1.获取话题名称 /turtle1/pose
        2.获取消息类型 turtlesim/Pose
        3.运行前启动 turtlesim_node 与 turtle_teleop_key 节点

    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建 ROS 句柄
        4.创建订阅者对象
        5.回调函数处理订阅的数据
        6.spin
*/
void doPose(const turtlesim::Pose::ConstPtr &pose){
    ROS_INFO("乌龟的位资信息：坐标(%.2f,%.2f),朝向（%.2f),线速度:%.2f,角速度:%.2f",
        pose->x,pose->y,pose->theta,pose->linear_velocity,pose->angular_velocity
    );
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    
    ros::init(argc,argv,"sub_pose");
    // 2.初始化 ROS 节点
    ros::NodeHandle nh;
    // 3.创建 ROS 句柄,doose是回调函数
    ros::Subscriber sub = nh.subscribe("/turtle1/pose",100,doPose);
    // 4.创建订阅者对象
    // 5.回调函数处理订阅的数据
    // 6.spin
    ros::spin();
    return 0;
}
