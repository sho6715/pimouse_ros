#include <fstream>
#include <ros/ros.h>
#include <ros.package.h>
#include <std_msgs/String.h>

std::string buzzer_device_file = "/dev/rtbuzzer";

void write_freq(int hz){
    std::ofstream ofs(buzzer_device_file);
    ROS_INFO("write_freq");
    if (not ofs.is_open())
        return false;

    ofs << std::string(hz)+"\n" << std::endl;
    return true;
/*
    bfile = "/dev/rtbuzzer0";
    try:
        with open(bfile,"w") as f:
            f.write(str(hz)+"\n");
    except IOError:
        rospy.logerr("can't write to " + bfile);
*/
}

void recv_buzzer(int data){
    write_freq(data);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "raspimouse_buzzer_node");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");

    pnh.getParam("device_file", buzzer_device_file);

    int freq = 10;

    ros::Rate loop_rate(freq);


    ros::Subscriber sub = nh.subscribe("buzzer", 20, recv_buzzer);
    ros::spin();
//    loop_rate.sleep(); 

    return 0;
}