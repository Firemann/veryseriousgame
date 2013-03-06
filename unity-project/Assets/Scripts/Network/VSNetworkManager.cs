using UnityEngine;
using System;
using vsm;
using vsm.network;
using vsm.component;
using Ice;
using System.Diagnostics;
using System.IO;

namespace vsm.network
{

    public class VSNetworkManager : Ice.Application
    {

        public static ObjectAdapter adapter;

        private Transform unityTransform;

        public VSNetworkManager(Transform transformTest) : base()
        {
            this.unityTransform = transformTest;
        }

        public override int run(string[] args)
        {
            Ice.ObjectPrx obj = communicator().stringToProxy("VerySeriousMiddleware:default -p 10000");

            VSServerPrx server = VSServerPrxHelper.checkedCast(obj);
            if (server == null)
                throw new ApplicationException("Invalid proxy");
            MonoBehaviour.print("Server link ok");

            adapter = communicator().createObjectAdapterWithEndpoints("Unity", "default -p 10001");
            VSClient client = new VSUnityClientI(ClientType.UNITY, unityTransform);
            adapter.add(client, communicator().stringToIdentity("Unity"));
            adapter.activate();
            VSClientPrx clientPrx = VSClientPrxHelper.uncheckedCast(
                adapter.createProxy(communicator().stringToIdentity("Unity")));
            server.register(clientPrx);
            MonoBehaviour.print("Client Registered");

            communicator().waitForShutdown();

            return 0;
        }
    }

}
