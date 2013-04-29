#ifndef _UNITY_ICE
#define _UNITY_ICE

#include <vsm.ice>
#include <vsm/network.ice>

module vsm {
	module unity {
	
		class VSSoldier {
			void move(VSDirection direction);
			void run(bool isRunning);
			void crounch();
			VSVector3 getPosition();
		};
		
		class VSUnityClient extends VSObject implements vsm::network::VSClient {
			int getPlayersNumber();
			VSSoldier* getSoldier(int playerNumber);
			VSSoldier* instantiateSoldier();
			void destroySoldier(VSSoldier* solider);
		};

	};
};

#endif
