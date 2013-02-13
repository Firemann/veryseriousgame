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
// Generated from file `Printer.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//


using _System = global::System;
using _Microsoft = global::Microsoft;

#pragma warning disable 1591

namespace demo
{
    [_System.Runtime.InteropServices.ComVisible(false)]
    [_System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1704")]
    [_System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1707")]
    [_System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1709")]
    [_System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1710")]
    [_System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1711")]
    [_System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1715")]
    [_System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1716")]
    [_System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1720")]
    [_System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1722")]
    [_System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1724")]
    public partial interface Printer : Ice.Object, PrinterOperations_, PrinterOperationsNC_
    {
    }
}

namespace demo
{
    [_System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.4.2")]
    public delegate void Callback_Printer_printString();
}

namespace demo
{
    [_System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.4.2")]
    public interface PrinterPrx : Ice.ObjectPrx
    {
        void printString(string s);
        void printString(string s, _System.Collections.Generic.Dictionary<string, string> context__);

        Ice.AsyncResult<demo.Callback_Printer_printString> begin_printString(string s);
        Ice.AsyncResult<demo.Callback_Printer_printString> begin_printString(string s, _System.Collections.Generic.Dictionary<string, string> ctx__);

        Ice.AsyncResult begin_printString(string s, Ice.AsyncCallback cb__, object cookie__);
        Ice.AsyncResult begin_printString(string s, _System.Collections.Generic.Dictionary<string, string> ctx__, Ice.AsyncCallback cb__, object cookie__);

        void end_printString(Ice.AsyncResult r__);
    }
}

namespace demo
{
    [_System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.4.2")]
    public interface PrinterOperations_
    {
        void printString(string s, Ice.Current current__);
    }

    [_System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.4.2")]
    public interface PrinterOperationsNC_
    {
        void printString(string s);
    }
}

namespace demo
{
    [_System.Runtime.InteropServices.ComVisible(false)]
    [_System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.4.2")]
    public sealed class PrinterPrxHelper : Ice.ObjectPrxHelperBase, PrinterPrx
    {
        #region Synchronous operations

        public void printString(string s)
        {
            printString(s, null, false);
        }

        public void printString(string s, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            printString(s, context__, true);
        }

        private void printString(string s, _System.Collections.Generic.Dictionary<string, string> context__, bool explicitContext__)
        {
            if(explicitContext__ && context__ == null)
            {
                context__ = emptyContext_;
            }
            int cnt__ = 0;
            while(true)
            {
                Ice.ObjectDel_ delBase__ = null;
                try
                {
                    delBase__ = getDelegate__(false);
                    PrinterDel_ del__ = (PrinterDel_)delBase__;
                    del__.printString(s, context__);
                    return;
                }
                catch(IceInternal.LocalExceptionWrapper ex__)
                {
                    handleExceptionWrapper__(delBase__, ex__);
                }
                catch(Ice.LocalException ex__)
                {
                    handleException__(delBase__, ex__, true, ref cnt__);
                }
            }
        }

        #endregion

        #region Asynchronous operations

        public Ice.AsyncResult<demo.Callback_Printer_printString> begin_printString(string s)
        {
            return begin_printString(s, null, false, null, null);
        }

        public Ice.AsyncResult<demo.Callback_Printer_printString> begin_printString(string s, _System.Collections.Generic.Dictionary<string, string> ctx__)
        {
            return begin_printString(s, ctx__, true, null, null);
        }

        public Ice.AsyncResult begin_printString(string s, Ice.AsyncCallback cb__, object cookie__)
        {
            return begin_printString(s, null, false, cb__, cookie__);
        }

        public Ice.AsyncResult begin_printString(string s, _System.Collections.Generic.Dictionary<string, string> ctx__, Ice.AsyncCallback cb__, object cookie__)
        {
            return begin_printString(s, ctx__, true, cb__, cookie__);
        }

        private const string __printString_name = "printString";

        public void end_printString(Ice.AsyncResult r__)
        {
            end__(r__, __printString_name);
        }

        private Ice.AsyncResult<demo.Callback_Printer_printString> begin_printString(string s, _System.Collections.Generic.Dictionary<string, string> ctx__, bool explicitContext__, Ice.AsyncCallback cb__, object cookie__)
        {
            IceInternal.OnewayOutgoingAsync<demo.Callback_Printer_printString> result__ = new IceInternal.OnewayOutgoingAsync<demo.Callback_Printer_printString>(this, __printString_name, printString_completed__, cookie__);
            if(cb__ != null)
            {
                result__.whenCompletedWithAsyncCallback(cb__);
            }
            try
            {
                result__.prepare__(__printString_name, Ice.OperationMode.Normal, ctx__, explicitContext__);
                IceInternal.BasicStream os__ = result__.ostr__;
                os__.writeString(s);
                os__.endWriteEncaps();
                result__.send__(true);
            }
            catch(Ice.LocalException ex__)
            {
                result__.exceptionAsync__(ex__);
            }
            return result__;
        }

        private void printString_completed__(demo.Callback_Printer_printString cb__)
        {
            if(cb__ != null)
            {
                cb__();
            }
        }

        #endregion

        #region Checked and unchecked cast operations

        public static PrinterPrx checkedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            PrinterPrx r = b as PrinterPrx;
            if((r == null) && b.ice_isA(ice_staticId()))
            {
                PrinterPrxHelper h = new PrinterPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static PrinterPrx checkedCast(Ice.ObjectPrx b, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            PrinterPrx r = b as PrinterPrx;
            if((r == null) && b.ice_isA(ice_staticId(), ctx))
            {
                PrinterPrxHelper h = new PrinterPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static PrinterPrx checkedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA(ice_staticId()))
                {
                    PrinterPrxHelper h = new PrinterPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static PrinterPrx checkedCast(Ice.ObjectPrx b, string f, _System.Collections.Generic.Dictionary<string, string> ctx)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            try
            {
                if(bb.ice_isA(ice_staticId(), ctx))
                {
                    PrinterPrxHelper h = new PrinterPrxHelper();
                    h.copyFrom__(bb);
                    return h;
                }
            }
            catch(Ice.FacetNotExistException)
            {
            }
            return null;
        }

        public static PrinterPrx uncheckedCast(Ice.ObjectPrx b)
        {
            if(b == null)
            {
                return null;
            }
            PrinterPrx r = b as PrinterPrx;
            if(r == null)
            {
                PrinterPrxHelper h = new PrinterPrxHelper();
                h.copyFrom__(b);
                r = h;
            }
            return r;
        }

        public static PrinterPrx uncheckedCast(Ice.ObjectPrx b, string f)
        {
            if(b == null)
            {
                return null;
            }
            Ice.ObjectPrx bb = b.ice_facet(f);
            PrinterPrxHelper h = new PrinterPrxHelper();
            h.copyFrom__(bb);
            return h;
        }

        public static readonly string[] ids__ =
        {
            "::Ice::Object",
            "::demo::Printer"
        };

        public static string ice_staticId()
        {
            return ids__[1];
        }

        #endregion

        #region Marshaling support

        protected override Ice.ObjectDelM_ createDelegateM__()
        {
            return new PrinterDelM_();
        }

        protected override Ice.ObjectDelD_ createDelegateD__()
        {
            return new PrinterDelD_();
        }

        public static void write__(IceInternal.BasicStream os__, PrinterPrx v__)
        {
            os__.writeProxy(v__);
        }

        public static PrinterPrx read__(IceInternal.BasicStream is__)
        {
            Ice.ObjectPrx proxy = is__.readProxy();
            if(proxy != null)
            {
                PrinterPrxHelper result = new PrinterPrxHelper();
                result.copyFrom__(proxy);
                return result;
            }
            return null;
        }

        #endregion
    }
}

namespace demo
{
    [_System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.4.2")]
    public interface PrinterDel_ : Ice.ObjectDel_
    {
        void printString(string s, _System.Collections.Generic.Dictionary<string, string> context__);
    }
}

namespace demo
{
    [_System.Runtime.InteropServices.ComVisible(false)]
    [_System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.4.2")]
    public sealed class PrinterDelM_ : Ice.ObjectDelM_, PrinterDel_
    {
        public void printString(string s, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            IceInternal.Outgoing og__ = handler__.getOutgoing("printString", Ice.OperationMode.Normal, context__);
            try
            {
                try
                {
                    IceInternal.BasicStream os__ = og__.ostr();
                    os__.writeString(s);
                }
                catch(Ice.LocalException ex__)
                {
                    og__.abort(ex__);
                }
                bool ok__ = og__.invoke();
                if(!og__.istr().isEmpty())
                {
                    try
                    {
                        if(!ok__)
                        {
                            try
                            {
                                og__.throwUserException();
                            }
                            catch(Ice.UserException ex__)
                            {
                                throw new Ice.UnknownUserException(ex__.ice_name(), ex__);
                            }
                        }
                        og__.istr().skipEmptyEncaps();
                    }
                    catch(Ice.LocalException ex__)
                    {
                        throw new IceInternal.LocalExceptionWrapper(ex__, false);
                    }
                }
            }
            finally
            {
                handler__.reclaimOutgoing(og__);
            }
        }
    }
}

namespace demo
{
    [_System.Runtime.InteropServices.ComVisible(false)]
    [_System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.4.2")]
    public sealed class PrinterDelD_ : Ice.ObjectDelD_, PrinterDel_
    {
        [_System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1031")]
        public void printString(string s, _System.Collections.Generic.Dictionary<string, string> context__)
        {
            Ice.Current current__ = new Ice.Current();
            initCurrent__(ref current__, "printString", Ice.OperationMode.Normal, context__);
            IceInternal.Direct.RunDelegate run__ = delegate(Ice.Object obj__)
            {
                Printer servant__ = null;
                try
                {
                    servant__ = (Printer)obj__;
                }
                catch(_System.InvalidCastException)
                {
                    throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
                }
                servant__.printString(s, current__);
                return Ice.DispatchStatus.DispatchOK;
            };
            IceInternal.Direct direct__ = null;
            try
            {
                direct__ = new IceInternal.Direct(current__, run__);
                try
                {
                    Ice.DispatchStatus status__ = direct__.servant().collocDispatch__(direct__);
                    _System.Diagnostics.Debug.Assert(status__ == Ice.DispatchStatus.DispatchOK);
                }
                finally
                {
                    direct__.destroy();
                }
            }
            catch(Ice.SystemException)
            {
                throw;
            }
            catch(_System.Exception ex__)
            {
                IceInternal.LocalExceptionWrapper.throwWrapper(ex__);
            }
        }
    }
}

namespace demo
{
    [_System.Runtime.InteropServices.ComVisible(false)]
    [_System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.4.2")]
    public abstract class PrinterDisp_ : Ice.ObjectImpl, Printer
    {
        #region Slice operations

        public void printString(string s)
        {
            printString(s, Ice.ObjectImpl.defaultCurrent);
        }

        public abstract void printString(string s, Ice.Current current__);

        #endregion

        #region Slice type-related members

        public static new readonly string[] ids__ = 
        {
            "::Ice::Object",
            "::demo::Printer"
        };

        public override bool ice_isA(string s)
        {
            return _System.Array.BinarySearch(ids__, s, IceUtilInternal.StringUtil.OrdinalStringComparer) >= 0;
        }

        public override bool ice_isA(string s, Ice.Current current__)
        {
            return _System.Array.BinarySearch(ids__, s, IceUtilInternal.StringUtil.OrdinalStringComparer) >= 0;
        }

        public override string[] ice_ids()
        {
            return ids__;
        }

        public override string[] ice_ids(Ice.Current current__)
        {
            return ids__;
        }

        public override string ice_id()
        {
            return ids__[1];
        }

        public override string ice_id(Ice.Current current__)
        {
            return ids__[1];
        }

        public static new string ice_staticId()
        {
            return ids__[1];
        }

        #endregion

        #region Operation dispatch

        [_System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1011")]
        public static Ice.DispatchStatus printString___(Printer obj__, IceInternal.Incoming inS__, Ice.Current current__)
        {
            checkMode__(Ice.OperationMode.Normal, current__.mode);
            IceInternal.BasicStream is__ = inS__.istr();
            is__.startReadEncaps();
            string s;
            s = is__.readString();
            is__.endReadEncaps();
            obj__.printString(s, current__);
            return Ice.DispatchStatus.DispatchOK;
        }

        private static string[] all__ =
        {
            "ice_id",
            "ice_ids",
            "ice_isA",
            "ice_ping",
            "printString"
        };

        public override Ice.DispatchStatus dispatch__(IceInternal.Incoming inS__, Ice.Current current__)
        {
            int pos = _System.Array.BinarySearch(all__, current__.operation, IceUtilInternal.StringUtil.OrdinalStringComparer);
            if(pos < 0)
            {
                throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
            }

            switch(pos)
            {
                case 0:
                {
                    return ice_id___(this, inS__, current__);
                }
                case 1:
                {
                    return ice_ids___(this, inS__, current__);
                }
                case 2:
                {
                    return ice_isA___(this, inS__, current__);
                }
                case 3:
                {
                    return ice_ping___(this, inS__, current__);
                }
                case 4:
                {
                    return printString___(this, inS__, current__);
                }
            }

            _System.Diagnostics.Debug.Assert(false);
            throw new Ice.OperationNotExistException(current__.id, current__.facet, current__.operation);
        }

        #endregion

        #region Marshaling support

        public override void write__(IceInternal.BasicStream os__)
        {
            os__.writeTypeId(ice_staticId());
            os__.startWriteSlice();
            os__.endWriteSlice();
            base.write__(os__);
        }

        public override void read__(IceInternal.BasicStream is__, bool rid__)
        {
            if(rid__)
            {
                /* string myId = */ is__.readTypeId();
            }
            is__.startReadSlice();
            is__.endReadSlice();
            base.read__(is__, true);
        }

        public override void write__(Ice.OutputStream outS__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type demo::Printer was not generated with stream support";
            throw ex;
        }

        public override void read__(Ice.InputStream inS__, bool rid__)
        {
            Ice.MarshalException ex = new Ice.MarshalException();
            ex.reason = "type demo::Printer was not generated with stream support";
            throw ex;
        }

        #endregion
    }
}
