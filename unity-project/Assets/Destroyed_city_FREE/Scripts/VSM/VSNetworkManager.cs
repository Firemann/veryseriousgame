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

        public static ObjectAdapter Adapter;
        public static VSServerPrx Server;

        public VSNetworkManager() : base() {}

        public override int run(string[] args)
        {
            Ice.ObjectPrx obj = communicator().stringToProxy("VerySeriousMiddleware:default -p 10000");

            Server = VSServerPrxHelper.checkedCast(obj);
            if (Server == null)
                throw new ApplicationException("Invalid proxy");
            MonoBehaviour.print("Server link ok");

            Adapter = communicator().createObjectAdapterWithEndpoints("Unity", "default -p 10001");
            Adapter.activate();

            communicator().waitForShutdown();

            return 0;
        }
    }

}
