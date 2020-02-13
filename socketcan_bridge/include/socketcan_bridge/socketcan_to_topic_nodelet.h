/*
 * Enway GmbH - All Rights reserved.
 * Proprietary & confidential.
 */
#ifndef SOCKETCAN_TO_TOPIC_NODELET_CPP_H
#define SOCKETCAN_TO_TOPIC_NODELET_CPP_H

#include <socketcan_interface/string.h>
#include <socketcan_interface/threading.h>

#include <nodelet/nodelet.h>
#include <ros/ros.h>

#include <string>

namespace socketcan_bridge
{
class SocketcanToTopicNodelet : public nodelet::Nodelet
{
  public:
    SocketcanToTopicNodelet();
    virtual ~SocketcanToTopicNodelet();
    void onInit() final;

  //protected:

  //private:

  
};

} //namespace socketcan_bridge

#endif //SOCKETCAN_TO_TOPIC_NODELET_CPP_H