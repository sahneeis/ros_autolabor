#include "ros/ros.h"

/* 

    ros::NodeHandle
        deleteParam("键")
        根据键删除参数，删除成功，返回 true，否则(参数不存在)，返回 false

    ros::param
        del("键")
        根据键删除参数，删除成功，返回 true，否则(参数不存在)，返回 false
*/

int main(int argc, char *argv[])
{   
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"param_del_c");
    ros::NodeHandle nh;
    //方案一
    bool flag1 = nh.deleteParam("type");
    if (flag1)
    {
        ROS_INFO("删除成功");
    }
    else{
        ROS_INFO("删除失败");
    }
    //方案二
    bool flag2 = ros::param::del("type_param");
    if (flag2)
    {
        ROS_INFO("删除成功");
    }
    else{
        ROS_INFO("删除失败");
    }
    return 0;
}
