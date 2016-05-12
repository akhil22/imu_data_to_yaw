#include "ros/ros.h"
#include "sensor_msgs/Imu.h"
#include "iostream"
#include <cmath>
#include <tf/transform_datatypes.h>
using namespace std;
void callback(const sensor_msgs::Imu::ConstPtr& msg){
        tf::Quaternion q(msg->orientation.x,msg->orientation.y,msg->orientation.z,msg->orientation.w);
	tf::Matrix3x3 m(q);
	double roll,pitch,yaw;
	m.getRPY(roll,pitch,yaw);
//	double x = msg->orientation.w;
//	double yaw = 2*x*x-1;

        cout<<yaw*180/3.14<<endl;
}
int main(int argc, char** argv){
	ros::init(argc, argv, "listen_mag_field");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe(argv[1],1000,callback);
        ros::spin();
        return 0;
}
    
