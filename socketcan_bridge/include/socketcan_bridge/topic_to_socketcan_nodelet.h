/*
 * Enway GmbH - All Rights reserved.
 * Proprietary & confidential.
 */
#ifndef TOPIC_TO_SOCKETCAN_NODELET_CPP_H
#define TOPIC_TO_SOCKETCAN_NODELET_CPP_H

#include "socketcan_bridge/topic_to_socketcan.h"

#include <socketcan_interface/string.h>
#include <socketcan_interface/threading.h>

#include <nodelet/nodelet.h>
#include <ros/ros.h>

#include <string>

namespace socketcan_bridge
{
class TopicToSocketcanNodelet : public nodelet::Nodelet
{
  public:
    TopicToSocketcanNodelet() = default;
    virtual ~TopicToSocketcanNodelet();
    void onInit() final;
  
  private:
    can::ThreadedSocketCANInterfaceSharedPtr driver_; 
    std::unique_ptr<socketcan_bridge::TopicToSocketCAN> to_socketcan_bridge_ptr_;
  
};

} //namespace socketcan_bridge

#endif //TOPIC_TO_SOCKETCAN_NODELET_CPP_H