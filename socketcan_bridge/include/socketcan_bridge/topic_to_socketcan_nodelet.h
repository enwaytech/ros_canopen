/*
 * Enway GmbH - All Rights reserved.
 * Proprietary & confidential.
 */
#ifndef TOPIC_TO_SOCKETCAN_NODELET_CPP_H
#define TOPIC_TO_SOCKETCAN_NODELET_CPP_H

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
    TopicToSocketcanNodelet();
    virtual ~TopicToSocketcanNodelet();
    void onInit() final;
  //protected:

  //private:

  
};

} //namespace socketcan_bridge

#endif //TOPIC_TO_SOCKETCAN_NODELET_CPP_H