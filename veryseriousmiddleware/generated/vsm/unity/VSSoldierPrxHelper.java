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
// Generated from file `VSSoldierPrxHelper.java'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

package vsm.unity;

public final class VSSoldierPrxHelper extends Ice.ObjectPrxHelperBase implements VSSoldierPrx
{
    public void
    crounch()
    {
        crounch(null, false);
    }

    public void
    crounch(java.util.Map<String, String> __ctx)
    {
        crounch(__ctx, true);
    }

    private void
    crounch(java.util.Map<String, String> __ctx, boolean __explicitCtx)
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
                __delBase = __getDelegate(false);
                _VSSoldierDel __del = (_VSSoldierDel)__delBase;
                __del.crounch(__ctx);
                return;
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

    private static final String __crounch_name = "crounch";

    public Ice.AsyncResult begin_crounch()
    {
        return begin_crounch(null, false, null);
    }

    public Ice.AsyncResult begin_crounch(java.util.Map<String, String> __ctx)
    {
        return begin_crounch(__ctx, true, null);
    }

    public Ice.AsyncResult begin_crounch(Ice.Callback __cb)
    {
        return begin_crounch(null, false, __cb);
    }

    public Ice.AsyncResult begin_crounch(java.util.Map<String, String> __ctx, Ice.Callback __cb)
    {
        return begin_crounch(__ctx, true, __cb);
    }

    public Ice.AsyncResult begin_crounch(Callback_VSSoldier_crounch __cb)
    {
        return begin_crounch(null, false, __cb);
    }

    public Ice.AsyncResult begin_crounch(java.util.Map<String, String> __ctx, Callback_VSSoldier_crounch __cb)
    {
        return begin_crounch(__ctx, true, __cb);
    }

    private Ice.AsyncResult begin_crounch(java.util.Map<String, String> __ctx, boolean __explicitCtx, IceInternal.CallbackBase __cb)
    {
        IceInternal.OutgoingAsync __result = new IceInternal.OutgoingAsync(this, __crounch_name, __cb);
        try
        {
            __result.__prepare(__crounch_name, Ice.OperationMode.Normal, __ctx, __explicitCtx);
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

    public void end_crounch(Ice.AsyncResult __result)
    {
        __end(__result, __crounch_name);
    }

    public vsm.VSVector3
    getPosition()
    {
        return getPosition(null, false);
    }

    public vsm.VSVector3
    getPosition(java.util.Map<String, String> __ctx)
    {
        return getPosition(__ctx, true);
    }

    private vsm.VSVector3
    getPosition(java.util.Map<String, String> __ctx, boolean __explicitCtx)
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
                __checkTwowayOnly("getPosition");
                __delBase = __getDelegate(false);
                _VSSoldierDel __del = (_VSSoldierDel)__delBase;
                return __del.getPosition(__ctx);
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

    private static final String __getPosition_name = "getPosition";

    public Ice.AsyncResult begin_getPosition()
    {
        return begin_getPosition(null, false, null);
    }

    public Ice.AsyncResult begin_getPosition(java.util.Map<String, String> __ctx)
    {
        return begin_getPosition(__ctx, true, null);
    }

    public Ice.AsyncResult begin_getPosition(Ice.Callback __cb)
    {
        return begin_getPosition(null, false, __cb);
    }

    public Ice.AsyncResult begin_getPosition(java.util.Map<String, String> __ctx, Ice.Callback __cb)
    {
        return begin_getPosition(__ctx, true, __cb);
    }

    public Ice.AsyncResult begin_getPosition(Callback_VSSoldier_getPosition __cb)
    {
        return begin_getPosition(null, false, __cb);
    }

    public Ice.AsyncResult begin_getPosition(java.util.Map<String, String> __ctx, Callback_VSSoldier_getPosition __cb)
    {
        return begin_getPosition(__ctx, true, __cb);
    }

    private Ice.AsyncResult begin_getPosition(java.util.Map<String, String> __ctx, boolean __explicitCtx, IceInternal.CallbackBase __cb)
    {
        __checkAsyncTwowayOnly(__getPosition_name);
        IceInternal.OutgoingAsync __result = new IceInternal.OutgoingAsync(this, __getPosition_name, __cb);
        try
        {
            __result.__prepare(__getPosition_name, Ice.OperationMode.Normal, __ctx, __explicitCtx);
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

    public vsm.VSVector3 end_getPosition(Ice.AsyncResult __result)
    {
        Ice.AsyncResult.__check(__result, this, __getPosition_name);
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
        vsm.VSVector3 __ret;
        IceInternal.BasicStream __is = __result.__is();
        __is.startReadEncaps();
        __ret = new vsm.VSVector3();
        __ret.__read(__is);
        __is.endReadEncaps();
        return __ret;
    }

    public void
    move(vsm.VSDirection direction)
    {
        move(direction, null, false);
    }

    public void
    move(vsm.VSDirection direction, java.util.Map<String, String> __ctx)
    {
        move(direction, __ctx, true);
    }

    private void
    move(vsm.VSDirection direction, java.util.Map<String, String> __ctx, boolean __explicitCtx)
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
                __delBase = __getDelegate(false);
                _VSSoldierDel __del = (_VSSoldierDel)__delBase;
                __del.move(direction, __ctx);
                return;
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

    private static final String __move_name = "move";

    public Ice.AsyncResult begin_move(vsm.VSDirection direction)
    {
        return begin_move(direction, null, false, null);
    }

    public Ice.AsyncResult begin_move(vsm.VSDirection direction, java.util.Map<String, String> __ctx)
    {
        return begin_move(direction, __ctx, true, null);
    }

    public Ice.AsyncResult begin_move(vsm.VSDirection direction, Ice.Callback __cb)
    {
        return begin_move(direction, null, false, __cb);
    }

    public Ice.AsyncResult begin_move(vsm.VSDirection direction, java.util.Map<String, String> __ctx, Ice.Callback __cb)
    {
        return begin_move(direction, __ctx, true, __cb);
    }

    public Ice.AsyncResult begin_move(vsm.VSDirection direction, Callback_VSSoldier_move __cb)
    {
        return begin_move(direction, null, false, __cb);
    }

    public Ice.AsyncResult begin_move(vsm.VSDirection direction, java.util.Map<String, String> __ctx, Callback_VSSoldier_move __cb)
    {
        return begin_move(direction, __ctx, true, __cb);
    }

    private Ice.AsyncResult begin_move(vsm.VSDirection direction, java.util.Map<String, String> __ctx, boolean __explicitCtx, IceInternal.CallbackBase __cb)
    {
        IceInternal.OutgoingAsync __result = new IceInternal.OutgoingAsync(this, __move_name, __cb);
        try
        {
            __result.__prepare(__move_name, Ice.OperationMode.Normal, __ctx, __explicitCtx);
            IceInternal.BasicStream __os = __result.__os();
            direction.__write(__os);
            __os.endWriteEncaps();
            __result.__send(true);
        }
        catch(Ice.LocalException __ex)
        {
            __result.__exceptionAsync(__ex);
        }
        return __result;
    }

    public void end_move(Ice.AsyncResult __result)
    {
        __end(__result, __move_name);
    }

    public void
    run(boolean isRunning)
    {
        run(isRunning, null, false);
    }

    public void
    run(boolean isRunning, java.util.Map<String, String> __ctx)
    {
        run(isRunning, __ctx, true);
    }

    private void
    run(boolean isRunning, java.util.Map<String, String> __ctx, boolean __explicitCtx)
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
                __delBase = __getDelegate(false);
                _VSSoldierDel __del = (_VSSoldierDel)__delBase;
                __del.run(isRunning, __ctx);
                return;
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

    private static final String __run_name = "run";

    public Ice.AsyncResult begin_run(boolean isRunning)
    {
        return begin_run(isRunning, null, false, null);
    }

    public Ice.AsyncResult begin_run(boolean isRunning, java.util.Map<String, String> __ctx)
    {
        return begin_run(isRunning, __ctx, true, null);
    }

    public Ice.AsyncResult begin_run(boolean isRunning, Ice.Callback __cb)
    {
        return begin_run(isRunning, null, false, __cb);
    }

    public Ice.AsyncResult begin_run(boolean isRunning, java.util.Map<String, String> __ctx, Ice.Callback __cb)
    {
        return begin_run(isRunning, __ctx, true, __cb);
    }

    public Ice.AsyncResult begin_run(boolean isRunning, Callback_VSSoldier_run __cb)
    {
        return begin_run(isRunning, null, false, __cb);
    }

    public Ice.AsyncResult begin_run(boolean isRunning, java.util.Map<String, String> __ctx, Callback_VSSoldier_run __cb)
    {
        return begin_run(isRunning, __ctx, true, __cb);
    }

    private Ice.AsyncResult begin_run(boolean isRunning, java.util.Map<String, String> __ctx, boolean __explicitCtx, IceInternal.CallbackBase __cb)
    {
        IceInternal.OutgoingAsync __result = new IceInternal.OutgoingAsync(this, __run_name, __cb);
        try
        {
            __result.__prepare(__run_name, Ice.OperationMode.Normal, __ctx, __explicitCtx);
            IceInternal.BasicStream __os = __result.__os();
            __os.writeBool(isRunning);
            __os.endWriteEncaps();
            __result.__send(true);
        }
        catch(Ice.LocalException __ex)
        {
            __result.__exceptionAsync(__ex);
        }
        return __result;
    }

    public void end_run(Ice.AsyncResult __result)
    {
        __end(__result, __run_name);
    }

    public static VSSoldierPrx
    checkedCast(Ice.ObjectPrx __obj)
    {
        VSSoldierPrx __d = null;
        if(__obj != null)
        {
            try
            {
                __d = (VSSoldierPrx)__obj;
            }
            catch(ClassCastException ex)
            {
                if(__obj.ice_isA(ice_staticId()))
                {
                    VSSoldierPrxHelper __h = new VSSoldierPrxHelper();
                    __h.__copyFrom(__obj);
                    __d = __h;
                }
            }
        }
        return __d;
    }

    public static VSSoldierPrx
    checkedCast(Ice.ObjectPrx __obj, java.util.Map<String, String> __ctx)
    {
        VSSoldierPrx __d = null;
        if(__obj != null)
        {
            try
            {
                __d = (VSSoldierPrx)__obj;
            }
            catch(ClassCastException ex)
            {
                if(__obj.ice_isA(ice_staticId(), __ctx))
                {
                    VSSoldierPrxHelper __h = new VSSoldierPrxHelper();
                    __h.__copyFrom(__obj);
                    __d = __h;
                }
            }
        }
        return __d;
    }

    public static VSSoldierPrx
    checkedCast(Ice.ObjectPrx __obj, String __facet)
    {
        VSSoldierPrx __d = null;
        if(__obj != null)
        {
            Ice.ObjectPrx __bb = __obj.ice_facet(__facet);
            try
            {
                if(__bb.ice_isA(ice_staticId()))
                {
                    VSSoldierPrxHelper __h = new VSSoldierPrxHelper();
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

    public static VSSoldierPrx
    checkedCast(Ice.ObjectPrx __obj, String __facet, java.util.Map<String, String> __ctx)
    {
        VSSoldierPrx __d = null;
        if(__obj != null)
        {
            Ice.ObjectPrx __bb = __obj.ice_facet(__facet);
            try
            {
                if(__bb.ice_isA(ice_staticId(), __ctx))
                {
                    VSSoldierPrxHelper __h = new VSSoldierPrxHelper();
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

    public static VSSoldierPrx
    uncheckedCast(Ice.ObjectPrx __obj)
    {
        VSSoldierPrx __d = null;
        if(__obj != null)
        {
            try
            {
                __d = (VSSoldierPrx)__obj;
            }
            catch(ClassCastException ex)
            {
                VSSoldierPrxHelper __h = new VSSoldierPrxHelper();
                __h.__copyFrom(__obj);
                __d = __h;
            }
        }
        return __d;
    }

    public static VSSoldierPrx
    uncheckedCast(Ice.ObjectPrx __obj, String __facet)
    {
        VSSoldierPrx __d = null;
        if(__obj != null)
        {
            Ice.ObjectPrx __bb = __obj.ice_facet(__facet);
            VSSoldierPrxHelper __h = new VSSoldierPrxHelper();
            __h.__copyFrom(__bb);
            __d = __h;
        }
        return __d;
    }

    public static final String[] __ids =
    {
        "::Ice::Object",
        "::vsm::unity::VSSoldier"
    };

    public static String
    ice_staticId()
    {
        return __ids[1];
    }

    protected Ice._ObjectDelM
    __createDelegateM()
    {
        return new _VSSoldierDelM();
    }

    protected Ice._ObjectDelD
    __createDelegateD()
    {
        return new _VSSoldierDelD();
    }

    public static void
    __write(IceInternal.BasicStream __os, VSSoldierPrx v)
    {
        __os.writeProxy(v);
    }

    public static VSSoldierPrx
    __read(IceInternal.BasicStream __is)
    {
        Ice.ObjectPrx proxy = __is.readProxy();
        if(proxy != null)
        {
            VSSoldierPrxHelper result = new VSSoldierPrxHelper();
            result.__copyFrom(proxy);
            return result;
        }
        return null;
    }
}
