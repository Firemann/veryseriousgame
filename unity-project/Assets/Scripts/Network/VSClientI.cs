using UnityEngine;
using System;
using vsm;
using vsm.network;

public class VSClientI : VSClient {

    private ClientType clientType;

    public VSClientI(ClientType clientType)
    {
        this.clientType = clientType;
    }

    public override ClientType getClientType(Ice.Current current__)
    {
        return clientType;
    }
}

