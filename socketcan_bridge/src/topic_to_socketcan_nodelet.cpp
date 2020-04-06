/*
 * Enway GmbH - All Rights reserved.
 * Proprietary & confidential.
 */
#include "socketcan_bridge/topic_to_socketcan_nodelet.h"

#include <pluginlib/class_list_macros.h>

PLUGINLIB_EXPORT_CLASS(socketcan_bridge::TopicToSocketcanNodelet, nodelet::Nodelet)

socketcan_bridge::TopicToSocketcanNodelet::~TopicToSocketcanNodelet()
{
  driver_->shutdown();
  driver_.reset();
}

void socketcan_bridge::TopicToSocketcanNodelet::onInit()
{
  ros::NodeHandle nh = getPrivateNodeHandle();
  std::string can_device;
  nh.param<std::string>("can_device", can_device, "can0");

  driver_ = boost::make_shared<can::ThreadedSocketCANInterface>s();
  if (!driver_->init(can_device, 0))  // initialize device at can_device, 0 for no loopback.
  {
    NODELET_FATAL("Failed to initialize can_device at %s", can_device.c_str());
    return;
  }
  else
  {
    NODELET_INFO("Successfully connected to %s.", can_device.c_str());
  }

  to_socketcan_bridge_ptr_ = std::make_unique<socketcan_bridge::TopicToSocketCAN>(&nh, &nh, driver_);
  to_socketcan_bridge_ptr_->setup();
}
