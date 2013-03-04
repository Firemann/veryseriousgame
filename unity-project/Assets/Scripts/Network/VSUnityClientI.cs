using UnityEngine;
using System;
using Ice;
using vsm;
using vsm.network;
using vsm.component;

namespace vsm.network
{
    public class VSUnityClientI : VSUnityClient
    {
        private ClientType clientType;
        private VSTransform vsTransform;

        public VSUnityClientI(ClientType clientType, Transform transform)
        {
            this.clientType = clientType;
            vsTransform = new VSTransformI(transform);
        }

        public override vsm.component.VSTransformPrx getTransform(Ice.Current current__)
        {
            Identity myId = VSNetworkManager.communicator().stringToIdentity(System.Guid.NewGuid().ToString());
            VSNetworkManager.adapter.add(vsTransform, myId);
            return VSTransformPrxHelper.checkedCast(VSNetworkManager.adapter.createProxy(myId));
            //ObjectAdapter adapter = Ice.Application.communicator().createObjectAdapterWithEndpoints("UnityTransform", "default -p 10002");
            //adapter.add(vsTransform, Ice.Application.communicator().stringToIdentity("UnityTransform"));
            //adapter.activate();
            //return VSTransformPrxHelper.uncheckedCast(
            //    adapter.createProxy(Ice.Application.communicator().stringToIdentity("UnityTransform")));
        }

        public override ClientType getClientType(Ice.Current current__)
        {
            return clientType;
        }
    }
}

