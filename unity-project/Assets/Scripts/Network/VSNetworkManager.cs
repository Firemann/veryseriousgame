using UnityEngine;
using System;
using vsm;
using vsm.network;
using Ice;
using System.Diagnostics;
using System.IO;

namespace vsm.network
{
    public class VSNetworkManager : Ice.Application
    {

        public override int run(string[] args)
        {
            Ice.ObjectPrx obj = communicator().stringToProxy("VerySeriousMiddleware:default -p 10000").ice_twoway().ice_timeout(-1).ice_secure(false);

            VSServerPrx server = VSServerPrxHelper.checkedCast(obj);
            if (server == null)
                throw new ApplicationException("Invalid proxy");
            MonoBehaviour.print("Server link ok");
            ObjectAdapter adapter = communicator().createObjectAdapterWithEndpoints("Unity", "default -p 10001");
            MonoBehaviour.print("Client Proxy (0)");
            VSClient client = new VSClientI(ClientType.UNITY);
            MonoBehaviour.print("Client Proxy (1)");
            adapter.add(client, communicator().stringToIdentity("Unity"));
            MonoBehaviour.print("Client Proxy (2)");
            adapter.activate();
            MonoBehaviour.print("Client Proxy (3)");
            VSClientPrx clientPrx = VSClientPrxHelper.uncheckedCast(
                adapter.createProxy(communicator().stringToIdentity("Unity")));
            MonoBehaviour.print("Client Proxy created");
            server.register(clientPrx);
            MonoBehaviour.print("Done");

            return 0;
        }
    }

}
