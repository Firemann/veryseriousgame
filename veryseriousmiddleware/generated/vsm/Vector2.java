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
// Generated from file `Vector2.java'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

package vsm;

public class Vector2 implements java.lang.Cloneable, java.io.Serializable
{
    public float x;

    public float y;

    public Vector2()
    {
    }

    public Vector2(float x, float y)
    {
        this.x = x;
        this.y = y;
    }

    public boolean
    equals(java.lang.Object rhs)
    {
        if(this == rhs)
        {
            return true;
        }
        Vector2 _r = null;
        try
        {
            _r = (Vector2)rhs;
        }
        catch(ClassCastException ex)
        {
        }

        if(_r != null)
        {
            if(x != _r.x)
            {
                return false;
            }
            if(y != _r.y)
            {
                return false;
            }

            return true;
        }

        return false;
    }

    public int
    hashCode()
    {
        int __h = 0;
        __h = 5 * __h + java.lang.Float.floatToIntBits(x);
        __h = 5 * __h + java.lang.Float.floatToIntBits(y);
        return __h;
    }

    public java.lang.Object
    clone()
    {
        java.lang.Object o = null;
        try
        {
            o = super.clone();
        }
        catch(CloneNotSupportedException ex)
        {
            assert false; // impossible
        }
        return o;
    }

    public void
    __write(IceInternal.BasicStream __os)
    {
        __os.writeFloat(x);
        __os.writeFloat(y);
    }

    public void
    __read(IceInternal.BasicStream __is)
    {
        x = __is.readFloat();
        y = __is.readFloat();
    }
}
