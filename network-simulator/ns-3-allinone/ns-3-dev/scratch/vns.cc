#include "vns.h"

using namespace std;
using namespace ns3;

/*
  Main
*/
  int main (int argc, char** argv){
	
	VNS *vns= new VNS();
	vns->initialize();
	  
	VnsIceCommunicator communicator = VnsIceCommunicator();
	vsm::networksimulator::VSNetworkSimulatorI ice = 
		vsm::networksimulator::VSNetworkSimulatorI(&communicator, &(vns->antennasToCreate), &(vns->clientsToCreate), &(vns->toDestroy), &(vns->activated), &(vns->toMove));
	  
	cout << "Init Ice done" << endl;
	
	vns->run();

    return 0;

    /*vns->createClient("client1", (coordinates){150,150,0});
    vns->createAntenna("antenna1", (coordinates){100,100,0});
    vns->createClient("client2", (coordinates){0,0,0});
    vns->moveNode("antenna1", (coordinates){200,200,0});
    vns->destroyNode(Names::Find<Node>("antenna1"));*/
  }

namespace ns3{

  NS_LOG_COMPONENT_DEFINE ("VNS");
  NS_OBJECT_ENSURE_REGISTERED (VNS);

/*
 Constructor 
*/
  VNS::VNS() : antennasToCreate(), clientsToCreate(), toDestroy(), activated(), toMove()
  {
  }

/*
 Destructor 
*/
  VNS::~VNS(){
    //TODO Fermer communication avec ICE ?
  }

/*
 Initialize
*/
  void VNS::initialize(){
    GlobalValue::Bind ("SimulatorImplementationType", 
                     StringValue ("ns3::RealtimeSimulatorImpl"));

    channel = YansWifiChannelHelper::Default ();
    phy = YansWifiPhyHelper::Default ();
    phy.SetChannel (channel.Create ());

    wifi = WifiHelper::Default();
    wifi.SetStandard(WIFI_PHY_STANDARD_80211b);
    wifi.SetRemoteStationManager("ns3::AarfWifiManager");
   
    address.SetBase("10.0.0.0", "255.0.0.0");
   
    mac = NqosWifiMacHelper::Default();
    mac.SetType("ns3::AdhocWifiMac");
  }
  
/*
 moveNode
*/
  void VNS::moveNode(std::string name, coordinates newCoo){
    Ptr<Node> node=Names::Find<Node>(name);
    Vector3D vector(newCoo.x, newCoo.y, newCoo.z);
    node->GetObject<MobilityModel>()->SetPosition(vector);
  }

/*
 createClient
*/
  void VNS::createClient(std::string name, coordinates coo){
    NodeContainer node;
    node.Create(1);
    
    NetDeviceContainer devices = wifi.Install(phy, mac, node);

    InternetStackHelper stack;
    stack.Install(node);
    Ipv4InterfaceContainer wifiInterfaces;
    wifiInterfaces = address.Assign(devices);

    MobilityHelper mobility;
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    mobility.Install(node);
    Vector3D vector((double)coo.x, (double)coo.y, (double)coo.z);
    node.Get(0)->GetObject<MobilityModel>()->SetPosition(vector);
 
    VnsAppClientHelper client_app (9, (int64_t) &activated);
    ApplicationContainer app = client_app.Install (node.Get(0));
    app.Start (Seconds (0));

    Names::Add("Nodes", name, node.Get(0));

    cout << "Client created at position " << coo.x << " " << coo.y << " " << coo.z << " (IP address : " <<
node.Get(0)->GetObject<Ipv4>()->GetAddress(1,0).GetLocal() <<")" << endl;//TODO : remove
  }

/*
 createAntenna
*/
  void VNS::createAntenna(std::string name, coordinates coo){
    NodeContainer node;
    node.Create(1);
    
    NetDeviceContainer devices = wifi.Install(phy, mac, node);

    InternetStackHelper stack;
    stack.Install(node);
    Ipv4InterfaceContainer wifiInterfaces;
    wifiInterfaces = address.Assign(devices);

    MobilityHelper mobility;
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    mobility.Install(node);
    Vector3D vector((double)coo.x, (double)coo.y, (double)coo.z);
    node.Get(0)->GetObject<MobilityModel>()->SetPosition(vector);

    VnsAppAntennaHelper antenna_app (Ipv4Address("255.255.255.255"),9);//FIXME
    antenna_app.SetAttribute ("MaxPackets", UintegerValue (1));
    antenna_app.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
    antenna_app.SetAttribute ("PacketSize", UintegerValue (1024));
    ApplicationContainer app = antenna_app.Install (node.Get(0));
    app.Start (Seconds (0));

    Names::Add("Nodes", name, node.Get(0));

    cout << "Antenna created at position " << coo.x << " " << coo.y << " " << coo.z << endl;//TODO : remove
  }

/*
 destroyNode
*/
  void VNS::destroyNode(Ptr<Node> node){
      Ptr<Ipv4> ipv4 = node->GetObject<Ipv4>();

      for (uint32_t j = 0; j < node->GetNDevices(); ++j)
      {
        int32_t ifIndex = ipv4->GetInterfaceForDevice(node->GetDevice(j));
        ipv4->SetDown(ifIndex);
      }

      for (uint32_t i = 0; i < node->GetNApplications(); ++i)
      {
        node->GetApplication(i)->SetStopTime(Seconds(Simulator::Now())+Seconds(0.01));
        //node->GetApplication(i)->Dispose();//FIXME
      }

      //TODO
      /*Ptr<NetDevice> d = node->GetDevice(0);
      Ptr<WifiNetDevice> wd = DynamicCast<WifiNetDevice>(d);
      Ptr<YansWifiPhy> wp = wd->GetPhy();
      Ptr<YansWifiPhy> ywp = DynamicCast<YansWifiPhy>(wp);
      channel.Remove(ywp);*/

      cout << "Node destroyed" << endl;//TODO : remove
  }

/*
 update
*/
  void VNS::update(){

    for (vector<node>::iterator i = antennasToCreate.begin(); i != antennasToCreate.end(); ++i)
    {
      createAntenna(i->name, i->coordinates);
    }

    for (vector<node>::iterator i = clientsToCreate.begin(); i != clientsToCreate.end(); ++i)
    {
      createClient(i->name, i->coordinates);
    }

	for (vector<node>::iterator i = toMove.begin(); i != toMove.end(); ++i)
    {
      moveNode(i->name, i->coordinates);
    }

    for (vector<string>::iterator i = toDestroy.begin(); i != toDestroy.end(); ++i)
    {
      destroyNode(Names::Find<Node>(*i));
    }
    

    toMove.clear();
    antennasToCreate.clear();
    clientsToCreate.clear();
    toDestroy.clear();
    activated.clear();
    Simulator::Schedule(Seconds(PERIOD), &VNS::update, this);
  }  

/*
 Run
*/
  void VNS::run(){
    LogComponentEnable ("VnsAppClientApplication", LOG_LEVEL_INFO);
    LogComponentEnable ("VnsAppAntennaApplication", LOG_LEVEL_INFO);

    NS_LOG_FUNCTION(Simulator::Now().GetSeconds());

    Simulator::Schedule(Seconds(PERIOD), &VNS::update, this);
    Simulator::Run();
    Simulator::Stop();
  }
  
}
