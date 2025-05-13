#include "ros/ros.h"
/* 

需求:实现参数服务器参数的增删改查操作。set robot shared parameters，classes， 
radius（0.15m），thenchange it to 0.2m

在 C++ 中实现参数服务器数据的增删改查，可以通过两套 API 实现:

ros::NodeHandle
      setParam(“key”，value)

ros::param
      set(“key”，value)
      所以说修改只需要继续调用，保留一样的建，修改值
*/

int main(int argc, char *argv[])
{
    //初始化ros节点
    ros::init(argc,argv,"set_param_c");
    //创建ros节点句柄
    ros::NodeHandle nh;

    //参数增---------------------------
    //方案1：nh
    nh.setParam("type","xiaoHuang");
    nh.setParam("radius",0.15);

    //方案2：ros：：param
    ros::param::set("type_param","xiaobai");
    ros::param::set("radius_param",0.15 );

    //参数改---------------------------
    //方案1：nh,建重合，参数覆盖
    nh.setParam("radius",0.2);

    //方案2：ros：：param

    ros::param::set("radius_param",0.25);


    return 0;

}