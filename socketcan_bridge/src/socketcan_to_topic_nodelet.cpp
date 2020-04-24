/*
 * Enway GmbH - All Rights reserved.
 * Proprietary & confidential.
 */

#include "socketcan_bridge/socketcan_to_topic_nodelet.h"

#include <pluginlib/class_list_macros.h>

PLUGINLIB_EXPORT_CLASS(socketcan_bridge::SocketcanToTopicNodelet, nodelet::Nodelet)

socketcan_bridge::SocketcanToTopicNodelet::~SocketcanToTopicNodelet()
{
  driver_->shutdown();
  driver_.reset();
}

void socketcan_bridge::SocketcanToTopicNodelet::onInit()
{
  ros::NodeHandle nh = getNodeHandle();
  ros::NodeHandle nh_param = getPrivateNodeHandle();
  std::string can_device;
  nh_param.param<std::string>("can_device", can_device, "can0");

  driver_ = boost::make_shared<can::ThreadedSocketCANInterface>();
  if (!driver_->init(can_device, 0))  // initialize device at can_device, 0 for no loopback.
  {
    NODELET_FATAL("Failed to initialize can_device at %s", can_device.c_str());
    return;
  }
  else
  {
    NODELET_INFO("Successfully connected to %s.", can_device.c_str());
  }

  to_topic_bridge_ptr_ = std::make_unique<socketcan_bridge::SocketCANToTopic>(&nh, &nh_param, driver_);
  to_topic_bridge_ptr_->setup(nh);
}
