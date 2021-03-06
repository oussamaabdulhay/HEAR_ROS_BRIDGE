#include "HEAR_ROS_BRIDGE/ROSUnit_InfoSubscriber.hpp"

ROSUnit_InfoSubscriber* ROSUnit_InfoSubscriber::_instance_ptr = NULL;
InfoMsg ROSUnit_InfoSubscriber::info_msg;
Port* ROSUnit_InfoSubscriber::_output_port_0 = new OutputPort(ports_id::OP_0, NULL);

ROSUnit_InfoSubscriber::ROSUnit_InfoSubscriber(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler)  {
    _sub_info = t_main_handler.subscribe("info", 2, callbackInfo);
    _instance_ptr = this;
    _ports = {_output_port_0};

}

ROSUnit_InfoSubscriber::~ROSUnit_InfoSubscriber() {

}

void ROSUnit_InfoSubscriber::callbackInfo(const hear_msgs::Info& msg){
    info_msg.armed = msg.armed;
    _output_port_0->receiveMsgData((DataMsg*) &info_msg); 
}