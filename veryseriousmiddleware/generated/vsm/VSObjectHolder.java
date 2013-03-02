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
// Generated from file `VSObjectHolder.java'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

package vsm;

public final class VSObjectHolder extends Ice.ObjectHolderBase<VSObject>
{
    public
    VSObjectHolder()
    {
    }

    public
    VSObjectHolder(VSObject value)
    {
        this.value = value;
    }

    public void
    patch(Ice.Object v)
    {
        try
        {
            value = (VSObject)v;
        }
        catch(ClassCastException ex)
        {
            IceInternal.Ex.throwUOE(type(), v.ice_id());
        }
    }

    public String
    type()
    {
        return VSObject.ice_staticId();
    }
}
