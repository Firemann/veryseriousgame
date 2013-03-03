#ifndef _NETWORK_ICE
#define _NETWORK_ICE

#include <vsm.ice>
#include <vsm/component.ice>

module vsm {
	module network {

		enum ClientType {
			UNITY
		};
	
		interface VSClient {
			ClientType getClientType();
		};
	
		class VSUnityClient extends VSObject implements VSClient {
			vsm::component::VSTransform* getTransform();
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
