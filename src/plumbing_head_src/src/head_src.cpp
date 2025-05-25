#include "plumbing_head_src/hello.h"
#include "ros/ros.h"
/* 
这里是源文件，hello.h是头文件，接下来是可执行文件
*/

namespace hello_ns{

void MyHello::run(){

    ROS_INFO("源文件中的run函数...");
}
}