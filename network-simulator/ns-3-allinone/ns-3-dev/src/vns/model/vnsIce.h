#ifndef VNS_ICE_H
#define VNS_ICE_H

#include "vsm.h"
#include "networksimulator.h"
#include "network.h"
#include "../scratch/vns.h"

#include <Ice/Ice.h>
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include <boost/lexical_cast.hpp>


using namespace std;
using namespace vsm;
using namespace ns3;

typedef struct node node;
typedef struct coordinates coordinates;

class VnsIceCommunicator {
	public:
		VnsIceCommunicator();
		~VnsIceCommunicator();
		Ice::ObjectAdapterPtr getAdapter();
		vsm::network::VSServerPrx getServer();
		Ice::CommunicatorPtr getCommunicator();

	private:
		vsm::network::VSServerPrx server;
		Ice::ObjectAdapterPtr adapter;
		Ice::CommunicatorPtr ic;

};

namespace vsm {
	namespace networksimulator {

		class VSNetworkSimulatorI : virtual public vsm::networksimulator::VSNetworkSimulator {
			public:
				//Boa Constructor
				VSNetworkSimulatorI(VnsIceCommunicator *communicator, vector<node>* antennasToCreate, vector<node>* clientsToCreate, vector<string>* toDestroy, vector<string>* activated, vector<node>* toMove);
				~VSNetworkSimulatorI();
				virtual ::vsm::networksimulator::VSNodePrx createNode(const ::std::string& name, const ::vsm::VSVector3& pos, ::vsm::networksimulator::VSNodeType type, const Ice::Current&);
				virtual void destroyNode(const ::vsm::networksimulator::VSNodePrx& node, const Ice::Current&);
				virtual vsm::network::ClientType getClientType(const Ice::Current&);
				
				vector<node>* getAntennasToCreateVector();
				vector<node>* getClientsToCreateVector();
				vector<string>* getToDestroyVector();
				vector<string>* getActivatedVector();
				vector<node>* getToMoveVector();

			private:
				vector<node>* antennasToCreate;
				vector<node>* clientsToCreate;
				vector<string>* toDestroy;
				vector<string>* activated;
				vector<node>* toMove;
				VnsIceCommunicator *ice;
				boost::uuids::basic_random_generator<boost::mt19937> gen;
		};

		class VSNodeI : virtual public vsm::networksimulator::VSNode {
			public:
				VSNodeI(VSNetworkSimulatorI *networkSimulator, const ::std::string& name, const ::vsm::VSVector3& pos, ::vsm::networksimulator::VSNodeType type);
				~VSNodeI();
				virtual void moveNode(const ::vsm::VSVector3&, const Ice::Current&);
				virtual bool getActivated(const Ice::Current&);
				virtual ::std::string getName(const Ice::Current&);
				virtual ::vsm::VSVector3 getPosition(const Ice::Current&);
				virtual ::vsm::networksimulator::VSNodeType getType(const Ice::Current&);
				
			private:
				vsm::networksimulator::VSNetworkSimulatorI *sim;
				std::string name;
				vsm::VSVector3 pos;
				vsm::networksimulator::VSNodeType type;
		};

	}
}

#endif
