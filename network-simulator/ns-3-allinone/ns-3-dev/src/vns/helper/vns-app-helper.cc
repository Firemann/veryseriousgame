#include "vns-app-helper.h"
#include "ns3/vns-app-antenna.h"
#include "ns3/vns-app-client.h"
#include "ns3/uinteger.h"
#include "ns3/integer.h"
#include "ns3/names.h"

namespace ns3 {

VnsAppClientHelper::VnsAppClientHelper (uint16_t port, int64_t activated)
{
  m_factory.SetTypeId (VnsAppClient::GetTypeId ());
  SetAttribute ("Port", UintegerValue (port));
  SetAttribute("Activated", IntegerValue(activated));
}

void 
VnsAppClientHelper::SetAttribute (
  std::string name, 
  const AttributeValue &value)
{
  m_factory.Set (name, value);
}

ApplicationContainer
VnsAppClientHelper::Install (Ptr<Node> node) const
{
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer
VnsAppClientHelper::Install (std::string nodeName) const
{
  Ptr<Node> node = Names::Find<Node> (nodeName);
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer
VnsAppClientHelper::Install (NodeContainer c) const
{
  ApplicationContainer apps;
  for (NodeContainer::Iterator i = c.Begin (); i != c.End (); ++i)
    {
      apps.Add (InstallPriv (*i));
    }

  return apps;
}

Ptr<Application>
VnsAppClientHelper::InstallPriv (Ptr<Node> node) const
{
  Ptr<Application> app = m_factory.Create<VnsAppClient> ();
  node->AddApplication (app);

  return app;
}

VnsAppAntennaHelper::VnsAppAntennaHelper (Address address, uint16_t port)
{
  m_factory.SetTypeId (VnsAppAntenna::GetTypeId ());
  SetAttribute ("RemoteAddress", AddressValue (address));
  SetAttribute ("RemotePort", UintegerValue (port));
}

VnsAppAntennaHelper::VnsAppAntennaHelper (Ipv4Address address, uint16_t port)
{
  m_factory.SetTypeId (VnsAppAntenna::GetTypeId ());
  SetAttribute ("RemoteAddress", AddressValue (Address(address)));
  SetAttribute ("RemotePort", UintegerValue (port));
}

VnsAppAntennaHelper::VnsAppAntennaHelper (Ipv6Address address, uint16_t port)
{
  m_factory.SetTypeId (VnsAppAntenna::GetTypeId ());
  SetAttribute ("RemoteAddress", AddressValue (Address(address)));
  SetAttribute ("RemotePort", UintegerValue (port));
}

void 
VnsAppAntennaHelper::SetAttribute (
  std::string name, 
  const AttributeValue &value)
{
  m_factory.Set (name, value);
}

void
VnsAppAntennaHelper::SetFill (Ptr<Application> app, std::string fill)
{
  app->GetObject<VnsAppAntenna>()->SetFill (fill);
}

void
VnsAppAntennaHelper::SetFill (Ptr<Application> app, uint8_t fill, uint32_t dataLength)
{
  app->GetObject<VnsAppAntenna>()->SetFill (fill, dataLength);
}

void
VnsAppAntennaHelper::SetFill (Ptr<Application> app, uint8_t *fill, uint32_t fillLength, uint32_t dataLength)
{
  app->GetObject<VnsAppAntenna>()->SetFill (fill, fillLength, dataLength);
}

ApplicationContainer
VnsAppAntennaHelper::Install (Ptr<Node> node) const
{
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer
VnsAppAntennaHelper::Install (std::string nodeName) const
{
  Ptr<Node> node = Names::Find<Node> (nodeName);
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer
VnsAppAntennaHelper::Install (NodeContainer c) const
{
  ApplicationContainer apps;
  for (NodeContainer::Iterator i = c.Begin (); i != c.End (); ++i)
    {
      apps.Add (InstallPriv (*i));
    }

  return apps;
}

Ptr<Application>
VnsAppAntennaHelper::InstallPriv (Ptr<Node> node) const
{
  Ptr<Application> app = m_factory.Create<VnsAppAntenna> ();
  node->AddApplication (app);

  return app;
}

} // namespace ns3
