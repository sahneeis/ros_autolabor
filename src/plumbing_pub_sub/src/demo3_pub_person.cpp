/*
    需求: 循环发布人的信息

*/

#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"//0.包含头文件

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    //1.初始化 ROS 节点
    ros::init(argc,argv,"pub_person");

    //2.创建 ROS 句柄
    ros::NodeHandle nh;

    //3.创建发布者对象,包之下的名字要注意
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::Person>("chatter_person",1000);

    //4.组织被发布的消息，编写发布逻辑并发布消息
    plumbing_pub_sub::Person p;
    p.name = "悟空";
    p.age = 2024;
    p.height = 1.45;
    //设置frenze
    ros::Rate r(1);
    //循环发布
    while (ros::ok())
    {
        pub.publish(p);//核心
        p.age += 1;
        ROS_INFO("我叫:%s,今年%d岁,高%.2f米", p.name.c_str(), p.age, p.height);

        r.sleep();//休眠
        ros::spinOnce();//建议写
    }



    return 0;
}

