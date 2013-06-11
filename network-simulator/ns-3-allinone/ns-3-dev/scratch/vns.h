#ifndef VNS_H
#define VNS_H

#include <iostream>
#include <cmath>
#include <math.h>
#include <time.h>

// ----- NS-3 related includes
#include <ns3/object.h>
#include "ns3/node-container.h"
#include "ns3/applications-module.h"
#include "ns3/nqos-wifi-mac-helper.h"
#include "ns3/ipv4-address-helper.h"
#include "ns3/wifi-module.h"
#include "ns3/mobility-module.h"
#include "ns3/core-module.h"
//#include "ns3/common-module.h"
#include "ns3/nqos-wifi-mac-helper.h"
#include "ns3/yans-wifi-helper.h"
#include "ns3/internet-stack-helper.h"
#include "ns3/names.h"
#include "ns3/constant-velocity-mobility-model.h"
#include "ns3/simulator.h"

#include "ns3/vns-app-client.h"
#include "ns3/vns-app-antenna.h"
#include "ns3/vns-app-helper.h"
#include "ns3/vnsIce.h"
#include "ns3/vsm.h"
#include "ns3/networksimulator.h"
#include "ns3/network.h"

#define PERIOD 1.0

using namespace std;
using namespace ns3;

struct coordinates{
  float x;
  float y;
  float z; 
};

struct node{
  string name;
  struct coordinates coordinates;
};

namespace ns3
{
  class VNS : public ns3::Object
  {
  public:
    vector<node> antennasToCreate;
    vector<node> clientsToCreate;
    vector<string> toDestroy;
    vector<string> activated;
    vector<node> toMove;
    VNS();
    virtual ~VNS();
    void run();
    void initialize();

    //TODO set protected
    void createClient(string name, coordinates coo);
    void createAntenna(string name, coordinates coo);
    void moveNode(string name, coordinates newCoo);
    void destroyNode(Ptr<Node> node);

  protected:
    void update();
    
    YansWifiChannelHelper channel;
    YansWifiPhyHelper phy;
    WifiHelper wifi;
    NqosWifiMacHelper mac;
    Ipv4AddressHelper address;
  };
}
#endif
