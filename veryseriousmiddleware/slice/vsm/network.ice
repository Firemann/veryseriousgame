#ifndef _NETWORK_ICE
#define _NETWORK_ICE

#include <vsm.ice>

module vsm {
	module network {

		enum ClientType {
			UNITY, NETWORKSIMULATOR
		};
	
		interface VSClient {
			ClientType getClientType();
		};

		exception AlreadyConnectedException {
			string reason;
		};
		
		class VSServer extends VSObject {
			void register(VSClient *client) throws AlreadyConnectedException;
		};
	
	};
};

#endif 
