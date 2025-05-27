#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hello");
    ros::NodeHandle nh;
    /* 
    使用ros::param这一API设置参数
    */
    //1.全局
    ros::param::set("/radiusA",100);
    //2.相对
    ros::param::set("radiusA",100);

    //3.私有
    ros::param::set("~radiusA",100);


    /* 
    使用Nodeandle设置参数，一有nh
    */
    //1.全局
    nh.setParam("/radius_nh_A",1000);
    //2.相对
    nh.setParam("radius_nh_B",1000);
    //3.私有,第一种错误的
    // nh.setParam("~radius_nh_C",1000);
    ros::NodeHandle nh_private("~");
    nh_private.setParam("radius_nh_C",1000);
    return 0;
}
