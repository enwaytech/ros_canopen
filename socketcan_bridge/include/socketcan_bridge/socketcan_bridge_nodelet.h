/*
 * Enway GmbH - All Rights reserved.
 * Proprietary & confidential.
 */
#ifndef SOCKETCAN_BRIDGE_NODELET_CPP_H
#define SOCKETCAN_BRIDGE_NODELET_CPP_H

#include <socketcan_interface/string.h>
#include <socketcan_interface/threading.h>

#include <nodelet/nodelet.h>
#include <ros/ros.h>

#include <string>

namespace socketcan_bridge
{
class SocketcanBridgeNodelet : public nodelet::Nodelet
{
  public:
    SocketcanBridgeNodelet();
    virtual ~SocketcanBridgeNodelet();
    void onInit() final;

  //protected:

  //private:

  
};

} //namespace socketcan_bridge

#endif //SOCKETCAN_BRIDGE_NODELET_CPP_H