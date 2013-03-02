using UnityEngine;
using System;
using vsm;
using vsm.network;
using Ice;

public class VSNetworkManager : MonoBehaviour {

	void Start () {
        Ice.Communicator ic = null;
        try
        {
            ic = Ice.Util.initialize();
            Ice.ObjectPrx obj = ic.stringToProxy("VerySeriousMiddleware:default -p 10000");

            VSServerPrx server = VSServerPrxHelper.checkedCast(obj);
            if (server == null)
                throw new ApplicationException("Invalid proxy");
            VSClient client = new VSClientI(ClientType.UNITY);

            //server.register(proxy);
        }
        catch (Ice.Exception e)
        {
            print(e);
        }
        if (ic != null)
        {
            // Clean up
            //
            try
            {
                ic.destroy();
            }
            catch (Ice.Exception e)
            {
                print(e);
            }
        }
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
