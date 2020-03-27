/*
 * Enway GmbH - All Rights reserved.
 * Proprietary & confidential.
 */
#ifndef SOCKETCAN_TO_TOPIC_NODELET_CPP_H
#define SOCKETCAN_TO_TOPIC_NODELET_CPP_H

#include "socketcan_bridge/socketcan_to_topic.h"

#include <socketcan_interface/threading.h>

#include <nodelet/nodelet.h>
#include <ros/ros.h>

#include <memory>
#include <string>

namespace socketcan_bridge
{
class SocketcanToTopicNodelet : public nodelet::Nodelet
{
  public:
    SocketcanToTopicNodelet() = default;
    virtual ~SocketcanToTopicNodelet();
    void onInit() final;

  private:
    can::ThreadedSocketCANInterfaceSharedPtr driver_; 
    std::unique_ptr<socketcan_bridge::SocketCANToTopic> to_topic_bridge_ptr_;
};
} //namespace socketcan_bridge
#endif //SOCKETCAN_TO_TOPIC_NODELET_CPP_H
