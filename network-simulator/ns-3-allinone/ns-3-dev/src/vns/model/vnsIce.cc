#include <Ice/Ice.h>
#include "vnsIce.h"


VnsIceCommunicator::VnsIceCommunicator()
{
	try {
        ic = Ice::initialize();

        Ice::ObjectPrx base = ic->stringToProxy("VerySeriousMiddleware:default -h 192.168.1.137 -p 5432");
        if (!base)
            throw "Could not create proxy";

        server = vsm::network::VSServerPrx::checkedCast(base);
		if (!server)
			throw "Invalid proxy";
			
		adapter = ic->createObjectAdapterWithEndpoints("NS-3", "default -p 10001");
		adapter->activate();

    } catch (const Ice::Exception& ex) {
        cerr << ex << endl;
        exit(1);
    } catch (const char* msg) {
        cerr << msg << endl;
        exit(1);
    }
}

VnsIceCommunicator::~VnsIceCommunicator()
{
	if (ic)
		ic->destroy();
}

Ice::ObjectAdapterPtr
VnsIceCommunicator::getAdapter() {
	return adapter;
}

vsm::network::VSServerPrx 
VnsIceCommunicator::getServer() {
	return server;
}

Ice::CommunicatorPtr
VnsIceCommunicator::getCommunicator() {
	return ic;
}

/**
 * VSNetworkSimulatorI
 */
namespace vsm {
	namespace networksimulator {

		VSNetworkSimulatorI::VSNetworkSimulatorI(VnsIceCommunicator *ice, vector<node>* antennasToCreate, vector<node>* clientsToCreate, vector<string>* toDestroy, vector<string>* activated, vector<node>* toMove) {
			
			this->antennasToCreate=antennasToCreate;
			this->clientsToCreate=clientsToCreate;
			this->toDestroy=toDestroy;
			this->activated=activated;
			this->toMove=toMove;

			this->ice = ice;
			ice->getAdapter()->add(this, ice->getCommunicator()->stringToIdentity("NS-3"));
			vsm::network::VSClientPrx clientPrx = vsm::network::VSClientPrx::uncheckedCast(
				ice->getAdapter()->createProxy(ice->getCommunicator()->stringToIdentity("NS-3")));
			ice->getServer()->_cpp_register(clientPrx);
		}
		
		VSNetworkSimulatorI::~VSNetworkSimulatorI() {
			
		}

		::vsm::networksimulator::VSNodePrx
		VSNetworkSimulatorI::createNode(const ::std::string& name, const ::vsm::VSVector3& pos, ::vsm::networksimulator::VSNodeType type, const Ice::Current&) {
			// Id creation
			boost::uuids::uuid u = gen();
			const std::string uuidStr = boost::lexical_cast<std::string>(u);
			Ice::Identity myId = ice->getCommunicator()->stringToIdentity(uuidStr);
			
			// NodeI Instanciation
            Ice::ObjectPtr nodeI = new vsm::networksimulator::VSNodeI(this, name, pos, type);
            
            // Add to adapter
            ice->getAdapter()->add(nodeI, myId);
            
            // Return Node Prx
            return ::vsm::networksimulator::VSNodePrx::checkedCast(ice->getAdapter()->createProxy(myId));
		}
		
		void
		VSNetworkSimulatorI::destroyNode(const ::vsm::networksimulator::VSNodePrx& node, const Ice::Current&) {
			toDestroy->push_back(node->getName());
		}
		
		vsm::network::ClientType
		VSNetworkSimulatorI::getClientType(const Ice::Current&) {
			return vsm::network::NETWORKSIMULATOR;
		}
		
		vector<node>*
		VSNetworkSimulatorI::getAntennasToCreateVector() {
			return this->antennasToCreate;
		}
		
		vector<node>*
		VSNetworkSimulatorI::getClientsToCreateVector() {
			return this->clientsToCreate;
		}
		
		vector<string>*
		VSNetworkSimulatorI::getToDestroyVector() {
			return this->toDestroy;
		}
		
		vector<string>*
		VSNetworkSimulatorI::getActivatedVector() {
			return this->activated;
		}
		
		vector<node>*
		VSNetworkSimulatorI::getToMoveVector() {
			return this->toMove;
		}

	}
}

/**
 * VSNetworkSimulatorI
 */
namespace vsm {
	namespace networksimulator {
	
		VSNodeI::VSNodeI(VSNetworkSimulatorI *networkSimulator, const ::std::string& name, const ::vsm::VSVector3& pos, ::vsm::networksimulator::VSNodeType type) {
			this->name = name;
			this->pos = pos;
			this->type = type;
			this->sim = networkSimulator;
			
			// Create structure
			coordinates c = {pos.x, pos.y, pos.z};
			node n = {name, c};
			
			// Add to create list
			switch (type) {
			case vsm::networksimulator::ANTENA:
				networkSimulator->getAntennasToCreateVector()->push_back(n);
				break;
			case vsm::networksimulator::CLIENT:
				networkSimulator->getClientsToCreateVector()->push_back(n);
				break;
			}
		}
		
		VSNodeI::~VSNodeI() {
			
		}
		
		void
		VSNodeI::moveNode(const ::vsm::VSVector3& coord, const Ice::Current& cur) {
			coordinates c = {coord.x, coord.y, coord.z};
			node n = {name, c};
			sim->getToMoveVector()->push_back(n);
		}
		
		bool
		VSNodeI::getActivated(const Ice::Current& cur) {
			for (vector<string>::iterator i = sim->getActivatedVector()->begin(); i != sim->getActivatedVector()->end(); ++i) {
				if(*i == name)
					return true;
			}	
			return false;
		}
		
		::std::string
		VSNodeI::getName(const Ice::Current& cur) {
			return name;
		}
		
		::vsm::VSVector3
		VSNodeI::getPosition(const Ice::Current& cur) {
			return pos;
		}
				
		::vsm::networksimulator::VSNodeType
		VSNodeI::getType(const Ice::Current& cur) {
			return type;
		}
		
	}
}
