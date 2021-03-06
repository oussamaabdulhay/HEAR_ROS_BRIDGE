#include "HEAR_ROS_BRIDGE/ROSUnit_RestNormSettings.hpp"

ROSUnit_RestNormSettings* ROSUnit_RestNormSettings::_instance_ptr = NULL;
RestrictedNormRefSettingsMsg ROSUnit_RestNormSettings::_settings_msg;

ROSUnit_RestNormSettings::ROSUnit_RestNormSettings(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _srv_rest_norm_settings = t_main_handler.advertiseService("restricted_norm_settings", callbackSettings);    
    _instance_ptr = this;
    this->_output_port = new OutputPort(ports_id::OP_0_DATA, this);
    _ports = {_output_port};
}   

ROSUnit_RestNormSettings::~ROSUnit_RestNormSettings() {

}

void ROSUnit_RestNormSettings::process(DataMsg* t_msg, Port* t_port){

}

DataMsg* ROSUnit_RestNormSettings::runTask(DataMsg* t_msg){
    this->_output_port->receiveMsgData(t_msg);
}

void ROSUnit_RestNormSettings::receiveMsgData(DataMsg* t_msg){

}

bool ROSUnit_RestNormSettings::callbackSettings(hear_msgs::Restricted_Norm_Settings::Request  &req, 
                                                hear_msgs::Restricted_Norm_Settings::Response &res){
    _settings_msg.enabled = req.enabled;
    _settings_msg.delete_existing_waypoints = req.delete_existing_waypoints;
    _settings_msg.max_norm = req.max_norm;
    _instance_ptr->runTask((DataMsg*) &_settings_msg);
    return true;
}