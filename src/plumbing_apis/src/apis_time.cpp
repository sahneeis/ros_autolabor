#include "ros/ros.h"

/* 
需求1：演示时间相关操作（获取当求前时刻=设置制定时刻）
需求2：程序执行中停顿五秒
需求3：一直程序开始运行时刻，和程序运行的时间，求结束运行时的时刻
需求4：每个一秒钟，在控制台输出一段文本。用ros::Rate或者定时器
    * \brief 创建一个定时器，按照指定频率调用回调函数。
    * \param period 时间间隔
    * \param callback 回调函数
    * \param oneshot 如果设置为 true,只执行一次回调函数，设置为 false,就循环执行。
    * \param autostart 如果为true，返回已经启动的定时器,设置为 false，需要手动启动。
*/

void cb(const ros::TimerEvent& event){
    ROS_INFO("------");
    ROS_INFO("函数被调用和的时刻：%.2f",event.current_real.toSec());

}



int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //1.准备：头文件/节点初始化/nh
    ros::init(argc,argv,"hello_time");
    ros::NodeHandle nh;//必须有，佛则会导致时间API调用失败

    //2.获取当前时刻
    ros::Time right_now = ros::Time::now();//将当前时刻封装成对象
    ROS_INFO("当前时刻:%.2f",right_now.toSec());//.2f double获取距离 1970年01月01日 00:00:00 的秒数
    ROS_INFO("当前时刻:%d",right_now.sec);//d uint获取距离 1970年01月01日 00:00:00 的秒数
    //3.设置制定时刻
    ros::Time someTime(100,100000000);// 参数1:秒数  参数2:纳秒
    ROS_INFO("时刻:%.2f",someTime.toSec()); //100.10
    ros::Time someTime2(100.3);//直接传入 double 类型的秒数
    ROS_INFO("时刻:%.2f",someTime2.toSec()); //100.30

    //---------------------------------------------------
    ROS_INFO("-----------------持续时间--------------------");
    ros::Time start = ros::Time::now();
    ROS_INFO("开始休眠:%.2f",start.toSec());
    ros::Duration du(4.5);
    du.sleep();
    ros::Time end = ros::Time::now();
    ROS_INFO("休眠结束：%.2f",end.toSec());

    //---------------------------------------------------
    ROS_INFO("----------------时间运算--------------------");
    //获取开始执行的时刻
    ros::Time begin = ros::Time::now();
    //模拟运行时间N秒
    ros::Duration du1(4);

    //计算结束的时刻 = 开始+持续，当然减法也同理
    ros::Time stop = begin + du1;
    ROS_INFO("开始时间：%.2f",begin.toSec());
    ROS_INFO("结束时间：%.2f",stop.toSec());
    //时刻和时刻，持续和持续ok吗
    //ros::Time sum = begin + stop;//不可以相加,只能相减
    ros::Duration du2 = begin - stop;
    ROS_INFO("时刻相减：%.2f",du2.toSec());

    ros::Duration du3 = du1 + du2;
    ros::Duration du4 = du1 - du2;
    ROS_INFO("du1+du2=%.2f",du3.toSec());
    ROS_INFO("du1-du2=%.2f",du4.toSec());
    //--------------------------------------定时器
    ROS_INFO("---------------------定时器-------------");
    // ros::Timer timer = nh.createTimer(ros::Duration(1),cb,true);
    ros::Timer timer = nh.createTimer(ros::Duration(1),cb,false,false);
    timer.start();
    ros::spin();//对应void回调函数




    return 0;
}
