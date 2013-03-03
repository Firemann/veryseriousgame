// **********************************************************************
//
// Copyright (c) 2003-2011 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.4.2
//
// <auto-generated>
//
// Generated from file `VSClientPrxHelper.java'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

package vsm.network;

public final class VSClientPrxHelper extends Ice.ObjectPrxHelperBase implements VSClientPrx
{
    public ClientType
    getClientType()
    {
        return getClientType(null, false);
    }

    public ClientType
    getClientType(java.util.Map<String, String> __ctx)
    {
        return getClientType(__ctx, true);
    }

    private ClientType
    getClientType(java.util.Map<String, String> __ctx, boolean __explicitCtx)
    {
        if(__explicitCtx && __ctx == null)
        {
            __ctx = _emptyContext;
        }
        int __cnt = 0;
        while(true)
        {
            Ice._ObjectDel __delBase = null;
            try
            {
                __checkTwowayOnly("getClientType");
                __delBase = __getDelegate(false);
                _VSClientDel __del = (_VSClientDel)__delBase;
                return __del.getClientType(__ctx);
            }
            catch(IceInternal.LocalExceptionWrapper __ex)
            {
                __handleExceptionWrapper(__delBase, __ex);
            }
            catch(Ice.LocalException __ex)
            {
                __cnt = __handleException(__delBase, __ex, null, __cnt);
            }
        }
    }

    private static final String __getClientType_name = "getClientType";

    public Ice.AsyncResult begin_getClientType()
    {
        return begin_getClientType(null, false, null);
    }

    public Ice.AsyncResult begin_getClientType(java.util.Map<String, String> __ctx)
    {
        return begin_getClientType(__ctx, true, null);
    }

    public Ice.AsyncResult begin_getClientType(Ice.Callback __cb)
    {
        return begin_getClientType(null, false, __cb);
    }

    public Ice.AsyncResult begin_getClientType(java.util.Map<String, String> __ctx, Ice.Callback __cb)
    {
        return begin_getClientType(__ctx, true, __cb);
    }

    public Ice.AsyncResult begin_getClientType(Callback_VSClient_getClientType __cb)
    {
        return begin_getClientType(null, false, __cb);
    }

    public Ice.AsyncResult begin_getClientType(java.util.Map<String, String> __ctx, Callback_VSClient_getClientType __cb)
    {
        return begin_getClientType(__ctx, true, __cb);
    }

    private Ice.AsyncResult begin_getClientType(java.util.Map<String, String> __ctx, boolean __explicitCtx, IceInternal.CallbackBase __cb)
    {
        __checkAsyncTwowayOnly(__getClientType_name);
        IceInternal.OutgoingAsync __result = new IceInternal.OutgoingAsync(this, __getClientType_name, __cb);
        try
        {
            __result.__prepare(__getClientType_name, Ice.OperationMode.Normal, __ctx, __explicitCtx);
            IceInternal.BasicStream __os = __result.__os();
            __os.endWriteEncaps();
            __result.__send(true);
        }
        catch(Ice.LocalException __ex)
        {
            __result.__exceptionAsync(__ex);
        }
        return __result;
    }

    public ClientType end_getClientType(Ice.AsyncResult __result)
    {
        Ice.AsyncResult.__check(__result, this, __getClientType_name);
        if(!__result.__wait())
        {
            try
            {
                __result.__throwUserException();
            }
            catch(Ice.UserException __ex)
            {
                throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
            }
        }
        ClientType __ret;
        IceInternal.BasicStream __is = __result.__is();
        __is.startReadEncaps();
        __ret = ClientType.__read(__is);
        __is.endReadEncaps();
        return __ret;
    }

    public static VSClientPrx
    checkedCast(Ice.ObjectPrx __obj)
    {
        VSClientPrx __d = null;
        if(__obj != null)
        {
            try
            {
                __d = (VSClientPrx)__obj;
            }
            catch(ClassCastException ex)
            {
                if(__obj.ice_isA(ice_staticId()))
                {
                    VSClientPrxHelper __h = new VSClientPrxHelper();
                    __h.__copyFrom(__obj);
                    __d = __h;
                }
            }
        }
        return __d;
    }

    public static VSClientPrx
    checkedCast(Ice.ObjectPrx __obj, java.util.Map<String, String> __ctx)
    {
        VSClientPrx __d = null;
        if(__obj != null)
        {
            try
            {
                __d = (VSClientPrx)__obj;
            }
            catch(ClassCastException ex)
            {
                if(__obj.ice_isA(ice_staticId(), __ctx))
                {
                    VSClientPrxHelper __h = new VSClientPrxHelper();
                    __h.__copyFrom(__obj);
                    __d = __h;
                }
            }
        }
        return __d;
    }

    public static VSClientPrx
    checkedCast(Ice.ObjectPrx __obj, String __facet)
    {
        VSClientPrx __d = null;
        if(__obj != null)
        {
            Ice.ObjectPrx __bb = __obj.ice_facet(__facet);
            try
            {
                if(__bb.ice_isA(ice_staticId()))
                {
                    VSClientPrxHelper __h = new VSClientPrxHelper();
                    __h.__copyFrom(__bb);
                    __d = __h;
                }
            }
            catch(Ice.FacetNotExistException ex)
            {
            }
        }
        return __d;
    }

    public static VSClientPrx
    checkedCast(Ice.ObjectPrx __obj, String __facet, java.util.Map<String, String> __ctx)
    {
        VSClientPrx __d = null;
        if(__obj != null)
        {
            Ice.ObjectPrx __bb = __obj.ice_facet(__facet);
            try
            {
                if(__bb.ice_isA(ice_staticId(), __ctx))
                {
                    VSClientPrxHelper __h = new VSClientPrxHelper();
                    __h.__copyFrom(__bb);
                    __d = __h;
                }
            }
            catch(Ice.FacetNotExistException ex)
            {
            }
        }
        return __d;
    }

    public static VSClientPrx
    uncheckedCast(Ice.ObjectPrx __obj)
    {
        VSClientPrx __d = null;
        if(__obj != null)
        {
            try
            {
                __d = (VSClientPrx)__obj;
            }
            catch(ClassCastException ex)
            {
                VSClientPrxHelper __h = new VSClientPrxHelper();
                __h.__copyFrom(__obj);
                __d = __h;
            }
        }
        return __d;
    }

    public static VSClientPrx
    uncheckedCast(Ice.ObjectPrx __obj, String __facet)
    {
        VSClientPrx __d = null;
        if(__obj != null)
        {
            Ice.ObjectPrx __bb = __obj.ice_facet(__facet);
            VSClientPrxHelper __h = new VSClientPrxHelper();
            __h.__copyFrom(__bb);
            __d = __h;
        }
        return __d;
    }

    public static final String[] __ids =
    {
        "::Ice::Object",
        "::vsm::network::VSClient"
    };

    public static String
    ice_staticId()
    {
        return __ids[1];
    }

    protected Ice._ObjectDelM
    __createDelegateM()
    {
        return new _VSClientDelM();
    }

    protected Ice._ObjectDelD
    __createDelegateD()
    {
        return new _VSClientDelD();
    }

    public static void
    __write(IceInternal.BasicStream __os, VSClientPrx v)
    {
        __os.writeProxy(v);
    }

    public static VSClientPrx
    __read(IceInternal.BasicStream __is)
    {
        Ice.ObjectPrx proxy = __is.readProxy();
        if(proxy != null)
        {
            VSClientPrxHelper result = new VSClientPrxHelper();
            result.__copyFrom(proxy);
            return result;
        }
        return null;
    }
}
