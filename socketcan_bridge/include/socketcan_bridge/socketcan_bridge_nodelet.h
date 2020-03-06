/*
 * Enway GmbH - All Rights reserved.
 * Proprietary & confidential.
 */
#ifndef SOCKETCAN_BRIDGE_NODELET_CPP_H
#define SOCKETCAN_BRIDGE_NODELET_CPP_H

#include "socketcan_bridge/socketcan_to_topic.h"
#include "socketcan_bridge/topic_to_socketcan.h"

#include <socketcan_interface/threading.h>

#include <nodelet/nodelet.h>
#include <ros/ros.h>

#include <memory>
#include <string>

namespace socketcan_bridge
{
class SocketcanBridgeNodelet : public nodelet::Nodelet
{
  public:
    SocketcanBridgeNodelet() = default;
    virtual ~SocketcanBridgeNodelet();
    void onInit() final;

  private:
    can::ThreadedSocketCANInterfaceSharedPtr driver_; 
    std::unique_ptr<socketcan_bridge::TopicToSocketCAN> to_socketcan_bridge_ptr_;
    std::unique_ptr<socketcan_bridge::SocketCANToTopic> to_topic_bridge_ptr_;


  
};

} //namespace socketcan_bridge

#endif //SOCKETCAN_BRIDGE_NODELET_CPP_H