#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_msgs/PID_param.h>
#include <hear_msgs/MRFT_param.h>
#include <hear_msgs/BB_param.h>
#include <hear_msgs/Update_Controller_PID.h>
#include <hear_msgs/Update_Controller_MRFT.h>
#include <hear_msgs/Update_Controller_BB.h>
#include "HEAR_msg/ControllerMsg.hpp"

class ROSUnit_UpdateControllerSrv :  public ROSUnit{
private:
    static control_system _id;
    static ROSUnit_UpdateControllerSrv* _instance_ptr;
    static ControllerMsg _update_controller_msg; 
    ros::ServiceServer _srv_update_controller_pid;
    ros::ServiceServer _srv_update_controller_mrft;
    ros::ServiceServer _srv_update_controller_bb;

    static bool callbackUpdateControllerPID(hear_msgs::Update_Controller_PID::Request  &req, 
                                            hear_msgs::Update_Controller_PID::Response &res);
    static bool callbackUpdateControllerMRFT(hear_msgs::Update_Controller_MRFT::Request  &req, 
                                            hear_msgs::Update_Controller_MRFT::Response &res);
    static bool callbackUpdateControllerBB(hear_msgs::Update_Controller_BB::Request  &req, 
                                            hear_msgs::Update_Controller_BB::Response &res);
    static Port* _output_port_0;
    static Port* _output_port_1;
    static Port* _output_port_2;
public:
    enum ports_id {OP_0_PID, OP_1_MRFT, OP_2_BB};
    void process(DataMsg* t_msg, Port* t_port) {};
    // enum unicast_addresses {broadcast, pid, mrft, sm};
    ROSUnit_UpdateControllerSrv(ros::NodeHandle&);
    ~ROSUnit_UpdateControllerSrv();
};