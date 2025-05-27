#include "ros/ros.h"
#include "std_msgs/String.h"

/* 
演示不同类型的话题名称设置以及设置话题名称与命名空间
*/

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hello");
    // ros::NodeHandle nh;

    //核心：设置不同类型的话题
    //1.0全局:topic名称must需要以/开头（也可以设置自己的ns），和节点名字和namespace没有关系
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter",1000);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/chatter",1000);
    
    
    //2.0相对：和节点平集。非/开头
    // ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",1000);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",1000);

    //3.0私有:节点的子级：需要创建特定的nh,xxx/hello/chatter.if have /,then still 全局
    ros::NodeHandle nh("~");
    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",1000);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",1000);

    while(ros::ok())
    {

    }
    return 0;
}
