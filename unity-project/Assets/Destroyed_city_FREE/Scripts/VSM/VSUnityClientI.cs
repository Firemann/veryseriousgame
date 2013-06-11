using UnityEngine;
using System;
using Ice;
using vsm;
using vsm.network;
using vsm.component;
using vsm.unity;
using System.Collections.Generic;

namespace vsm.unity {
	
    public class VSUnityClientI : VSUnity
    {
        private ClientType clientType;
        private List<VSSoldierPrx> soldiersList;

        public VSUnityClientI() {
            soldiersList = new List<VSSoldierPrx>();
				
            VSNetworkManager.Adapter.add(this, VSNetworkManager.communicator().stringToIdentity("Unity"));
            VSClientPrx clientPrx = VSClientPrxHelper.uncheckedCast(
                VSNetworkManager.Adapter.createProxy(VSNetworkManager.communicator().stringToIdentity("Unity")));
            VSNetworkManager.Server.register(clientPrx);
        }

        public override ClientType getClientType(Ice.Current current__)
        {
            return ClientType.UNITY;
        }

        public override int getPlayersNumber(Current current__)
        {
            return soldiersList.Count;
        }

        public override void destroySoldier(VSSoldierPrx solider, Current current__)
        {
            throw new NotImplementedException();
        }

        public override VSSoldierPrx getSoldier(int playerNumber, Current current__)
        {
            return soldiersList[playerNumber];
        }

        public override VSSoldierPrx instantiateSoldier(Current current__)
        {
            Identity myId = VSNetworkManager.communicator().stringToIdentity(System.Guid.NewGuid().ToString());
            VSSoldierI soldierI = new VSSoldierI();
            VSNetworkManager.Adapter.add(soldierI, myId);
            return VSSoldierPrxHelper.checkedCast(VSNetworkManager.Adapter.createProxy(myId));
        }
    }
}

