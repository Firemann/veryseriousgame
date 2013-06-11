// **********************************************************************
//
// Copyright (c) 2003-2013 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.5.0
//
// <auto-generated>
//
// Generated from file `network.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __G__slicecpp_network_h__
#define __G__slicecpp_network_h__

#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/Incoming.h>
#include <Ice/Direct.h>
#include <Ice/FactoryTableInit.h>
#include <IceUtil/ScopedArray.h>
#include <IceUtil/Optional.h>
#include <Ice/StreamF.h>
#include "vsm.h"
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 305
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 0
#       error Ice patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace vsm
{

namespace network
{

class VSClient;
void __read(::IceInternal::BasicStream*, ::IceInternal::ProxyHandle< ::IceProxy::vsm::network::VSClient>&);
::IceProxy::Ice::Object* upCast(::IceProxy::vsm::network::VSClient*);

class VSServer;
void __read(::IceInternal::BasicStream*, ::IceInternal::ProxyHandle< ::IceProxy::vsm::network::VSServer>&);
::IceProxy::Ice::Object* upCast(::IceProxy::vsm::network::VSServer*);

}

}

}

namespace vsm
{

namespace network
{

class VSClient;
bool operator==(const VSClient&, const VSClient&);
bool operator<(const VSClient&, const VSClient&);
::Ice::Object* upCast(::vsm::network::VSClient*);
typedef ::IceInternal::Handle< ::vsm::network::VSClient> VSClientPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::vsm::network::VSClient> VSClientPrx;
void __patch(VSClientPtr&, const ::Ice::ObjectPtr&);

class VSServer;
bool operator==(const VSServer&, const VSServer&);
bool operator<(const VSServer&, const VSServer&);
::Ice::Object* upCast(::vsm::network::VSServer*);
typedef ::IceInternal::Handle< ::vsm::network::VSServer> VSServerPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::vsm::network::VSServer> VSServerPrx;
void __patch(VSServerPtr&, const ::Ice::ObjectPtr&);

}

}

namespace vsm
{

namespace network
{

enum ClientType
{
    UNITY,
    NETWORKSIMULATOR
};

class AlreadyConnectedException : public ::Ice::UserException
{
public:

    AlreadyConnectedException() {}
    explicit AlreadyConnectedException(const ::std::string&);
    virtual ~AlreadyConnectedException() throw();

    virtual ::std::string ice_name() const;
    virtual AlreadyConnectedException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string reason;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    #ifdef __SUNPRO_CC
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
    #endif
};

static AlreadyConnectedException __AlreadyConnectedException_init;

}

}

namespace Ice
{
template<>
struct StreamableTraits< ::vsm::network::ClientType>
{
    static const StreamHelperCategory helper = StreamHelperCategoryEnum;
    static const int minValue = 0;
    static const int maxValue = 1;
    static const int minWireSize = 1;
    static const bool fixedLength = false;
};

template<>
struct StreamableTraits< ::vsm::network::AlreadyConnectedException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

}

namespace vsm
{

namespace network
{

class Callback_VSClient_getClientType_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_VSClient_getClientType_Base> Callback_VSClient_getClientTypePtr;

class Callback_VSServer_register_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_VSServer_register_Base> Callback_VSServer_registerPtr;

}

}

namespace IceProxy
{

namespace vsm
{

namespace network
{

class VSClient : virtual public ::IceProxy::Ice::Object
{
public:

    ::vsm::network::ClientType getClientType()
    {
        return getClientType(0);
    }
    ::vsm::network::ClientType getClientType(const ::Ice::Context& __ctx)
    {
        return getClientType(&__ctx);
    }
#ifdef ICE_CPP11
    ::Ice::AsyncResultPtr
    begin_getClientType(const ::IceInternal::Function<void (::vsm::network::ClientType)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_getClientType(0, response, exception, sent);
    }
    ::Ice::AsyncResultPtr
    begin_getClientType(const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_getClientType(0, ::Ice::newCallback(completed, sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_getClientType(const ::Ice::Context& ctx, const ::IceInternal::Function<void (::vsm::network::ClientType)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_getClientType(&ctx, response, exception, sent);
    }
    ::Ice::AsyncResultPtr
    begin_getClientType(const ::Ice::Context& ctx, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_getClientType(&ctx, ::Ice::newCallback(completed, sent));
    }
    
private:

    ::Ice::AsyncResultPtr __begin_getClientType(const ::Ice::Context* ctx, const ::IceInternal::Function<void (::vsm::network::ClientType)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception, const ::IceInternal::Function<void (bool)>& sent)
    {
        class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
        {
        public:

            Cpp11CB(const ::std::function<void (::vsm::network::ClientType)>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
                ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
                _response(responseFunc)
            {
                CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
            }

            virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
            {
                ::vsm::network::VSClientPrx __proxy = ::vsm::network::VSClientPrx::uncheckedCast(__result->getProxy());
                ::vsm::network::ClientType __ret;
                try
                {
                    __ret = __proxy->end_getClientType(__result);
                }
                catch(::Ice::Exception& ex)
                {
                    Cpp11FnCallbackNC::__exception(__result, ex);
                    return;
                }
                if(_response != nullptr)
                {
                    _response(__ret);
                }
            }
        
        private:
            
            ::std::function<void (::vsm::network::ClientType)> _response;
        };
        return begin_getClientType(ctx, new Cpp11CB(response, exception, sent));
    }
    
public:
#endif

    ::Ice::AsyncResultPtr begin_getClientType()
    {
        return begin_getClientType(0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_getClientType(const ::Ice::Context& __ctx)
    {
        return begin_getClientType(&__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_getClientType(const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_getClientType(0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_getClientType(const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_getClientType(&__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_getClientType(const ::vsm::network::Callback_VSClient_getClientTypePtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_getClientType(0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_getClientType(const ::Ice::Context& __ctx, const ::vsm::network::Callback_VSClient_getClientTypePtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_getClientType(&__ctx, __del, __cookie);
    }

    ::vsm::network::ClientType end_getClientType(const ::Ice::AsyncResultPtr&);
    
private:

    ::vsm::network::ClientType getClientType(const ::Ice::Context*);
    ::Ice::AsyncResultPtr begin_getClientType(const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:
    
    ::IceInternal::ProxyHandle<VSClient> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_adapterId(const ::std::string& __id) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_locatorCacheTimeout(int __timeout) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_connectionCached(bool __cached) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_secure(bool __secure) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_preferSecure(bool __preferSecure) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_collocationOptimized(bool __co) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_twoway() const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_oneway() const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_batchOneway() const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_datagram() const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_batchDatagram() const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_compress(bool __compress) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_timeout(int __timeout) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_connectionId(const ::std::string& __id) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<VSClient> ice_encodingVersion(const ::Ice::EncodingVersion& __v) const
    {
        return dynamic_cast<VSClient*>(::IceProxy::Ice::Object::ice_encodingVersion(__v).get());
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class VSServer : virtual public ::IceProxy::vsm::VSObject
{
public:

    void _cpp_register(const ::vsm::network::VSClientPrx& client)
    {
        _cpp_register(client, 0);
    }
    void _cpp_register(const ::vsm::network::VSClientPrx& client, const ::Ice::Context& __ctx)
    {
        _cpp_register(client, &__ctx);
    }
#ifdef ICE_CPP11
    ::Ice::AsyncResultPtr
    begin_register(const ::vsm::network::VSClientPrx& client, const ::IceInternal::Function<void ()>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_register(client, 0, response, exception, sent);
    }
    ::Ice::AsyncResultPtr
    begin_register(const ::vsm::network::VSClientPrx& client, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_register(client, 0, ::Ice::newCallback(completed, sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_register(const ::vsm::network::VSClientPrx& client, const ::Ice::Context& ctx, const ::IceInternal::Function<void ()>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_register(client, &ctx, response, exception, sent);
    }
    ::Ice::AsyncResultPtr
    begin_register(const ::vsm::network::VSClientPrx& client, const ::Ice::Context& ctx, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_register(client, &ctx, ::Ice::newCallback(completed, sent));
    }
    
private:

    ::Ice::AsyncResultPtr __begin_register(const ::vsm::network::VSClientPrx& client, const ::Ice::Context* ctx, const ::IceInternal::Function<void ()>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception, const ::IceInternal::Function<void (bool)>& sent)
    {
        class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
        {
        public:

            Cpp11CB(const ::std::function<void ()>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
                ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
                _response(responseFunc)
            {
                CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
            }

            virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
            {
                ::vsm::network::VSServerPrx __proxy = ::vsm::network::VSServerPrx::uncheckedCast(__result->getProxy());
                try
                {
                    __proxy->end_register(__result);
                }
                catch(::Ice::Exception& ex)
                {
                    Cpp11FnCallbackNC::__exception(__result, ex);
                    return;
                }
                if(_response != nullptr)
                {
                    _response();
                }
            }
        
        private:
            
            ::std::function<void ()> _response;
        };
        return begin_register(client, ctx, new Cpp11CB(response, exception, sent));
    }
    
public:
#endif

    ::Ice::AsyncResultPtr begin_register(const ::vsm::network::VSClientPrx& client)
    {
        return begin_register(client, 0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_register(const ::vsm::network::VSClientPrx& client, const ::Ice::Context& __ctx)
    {
        return begin_register(client, &__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_register(const ::vsm::network::VSClientPrx& client, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_register(client, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_register(const ::vsm::network::VSClientPrx& client, const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_register(client, &__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_register(const ::vsm::network::VSClientPrx& client, const ::vsm::network::Callback_VSServer_registerPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_register(client, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_register(const ::vsm::network::VSClientPrx& client, const ::Ice::Context& __ctx, const ::vsm::network::Callback_VSServer_registerPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_register(client, &__ctx, __del, __cookie);
    }

    void end_register(const ::Ice::AsyncResultPtr&);
    
private:

    void _cpp_register(const ::vsm::network::VSClientPrx&, const ::Ice::Context*);
    ::Ice::AsyncResultPtr begin_register(const ::vsm::network::VSClientPrx&, const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:
    
    ::IceInternal::ProxyHandle<VSServer> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_adapterId(const ::std::string& __id) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_locatorCacheTimeout(int __timeout) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_connectionCached(bool __cached) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_secure(bool __secure) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_preferSecure(bool __preferSecure) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_collocationOptimized(bool __co) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_twoway() const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_oneway() const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_batchOneway() const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_datagram() const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_batchDatagram() const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_compress(bool __compress) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_timeout(int __timeout) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_connectionId(const ::std::string& __id) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<VSServer> ice_encodingVersion(const ::Ice::EncodingVersion& __v) const
    {
        return dynamic_cast<VSServer*>(::IceProxy::Ice::Object::ice_encodingVersion(__v).get());
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

}

namespace IceDelegate
{

namespace vsm
{

namespace network
{

class VSClient : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::vsm::network::ClientType getClientType(const ::Ice::Context*, ::IceInternal::InvocationObserver&) = 0;
};

class VSServer : virtual public ::IceDelegate::vsm::VSObject
{
public:

    virtual void _cpp_register(const ::vsm::network::VSClientPrx&, const ::Ice::Context*, ::IceInternal::InvocationObserver&) = 0;
};

}

}

}

namespace IceDelegateM
{

namespace vsm
{

namespace network
{

class VSClient : virtual public ::IceDelegate::vsm::network::VSClient,
                 virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::vsm::network::ClientType getClientType(const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

class VSServer : virtual public ::IceDelegate::vsm::network::VSServer,
                 virtual public ::IceDelegateM::vsm::VSObject
{
public:

    virtual void _cpp_register(const ::vsm::network::VSClientPrx&, const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

}

namespace IceDelegateD
{

namespace vsm
{

namespace network
{

class VSClient : virtual public ::IceDelegate::vsm::network::VSClient,
                 virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::vsm::network::ClientType getClientType(const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

class VSServer : virtual public ::IceDelegate::vsm::network::VSServer,
                 virtual public ::IceDelegateD::vsm::VSObject
{
public:

    virtual void _cpp_register(const ::vsm::network::VSClientPrx&, const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

}

namespace vsm
{

namespace network
{

class VSClient : virtual public ::Ice::Object
{
public:

    typedef VSClientPrx ProxyType;
    typedef VSClientPtr PointerType;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::vsm::network::ClientType getClientType(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getClientType(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    #ifdef __SUNPRO_CC
    using ::Ice::Object::__writeImpl;
    using ::Ice::Object::__readImpl;
    #endif
};

inline bool operator==(const VSClient& l, const VSClient& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const VSClient& l, const VSClient& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

class VSServer : public ::vsm::VSObject
{
public:

    typedef VSServerPrx ProxyType;
    typedef VSServerPtr PointerType;

    VSServer()
    {
    }

    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void _cpp_register(const ::vsm::network::VSClientPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___register(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    #ifdef __SUNPRO_CC
    using ::vsm::VSObject::__writeImpl;
    using ::vsm::VSObject::__readImpl;
    #endif
};

inline bool operator==(const VSServer& l, const VSServer& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const VSServer& l, const VSServer& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

}

}

namespace vsm
{

namespace network
{

template<class T>
class CallbackNC_VSClient_getClientType : public Callback_VSClient_getClientType_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)(::vsm::network::ClientType);

    CallbackNC_VSClient_getClientType(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::vsm::network::VSClientPrx __proxy = ::vsm::network::VSClientPrx::uncheckedCast(__result->getProxy());
        ::vsm::network::ClientType __ret;
        try
        {
            __ret = __proxy->end_getClientType(__result);
        }
        catch(::Ice::Exception& ex)
        {
            ::IceInternal::CallbackNC<T>::__exception(__result, ex);
            return;
        }
        if(response)
        {
            (::IceInternal::CallbackNC<T>::callback.get()->*response)(__ret);
        }
    }

    Response response;
};

template<class T> Callback_VSClient_getClientTypePtr
newCallback_VSClient_getClientType(const IceUtil::Handle<T>& instance, void (T::*cb)(::vsm::network::ClientType), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_VSClient_getClientType<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_VSClient_getClientTypePtr
newCallback_VSClient_getClientType(T* instance, void (T::*cb)(::vsm::network::ClientType), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_VSClient_getClientType<T>(instance, cb, excb, sentcb);
}

template<class T, typename CT>
class Callback_VSClient_getClientType : public Callback_VSClient_getClientType_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(::vsm::network::ClientType, const CT&);

    Callback_VSClient_getClientType(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::vsm::network::VSClientPrx __proxy = ::vsm::network::VSClientPrx::uncheckedCast(__result->getProxy());
        ::vsm::network::ClientType __ret;
        try
        {
            __ret = __proxy->end_getClientType(__result);
        }
        catch(::Ice::Exception& ex)
        {
            ::IceInternal::Callback<T, CT>::__exception(__result, ex);
            return;
        }
        if(response)
        {
            (::IceInternal::Callback<T, CT>::callback.get()->*response)(__ret, CT::dynamicCast(__result->getCookie()));
        }
    }

    Response response;
};

template<class T, typename CT> Callback_VSClient_getClientTypePtr
newCallback_VSClient_getClientType(const IceUtil::Handle<T>& instance, void (T::*cb)(::vsm::network::ClientType, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_VSClient_getClientType<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_VSClient_getClientTypePtr
newCallback_VSClient_getClientType(T* instance, void (T::*cb)(::vsm::network::ClientType, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_VSClient_getClientType<T, CT>(instance, cb, excb, sentcb);
}

template<class T>
class CallbackNC_VSServer_register : public Callback_VSServer_register_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_VSServer_register(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::vsm::network::VSServerPrx __proxy = ::vsm::network::VSServerPrx::uncheckedCast(__result->getProxy());
        try
        {
            __proxy->end_register(__result);
        }
        catch(::Ice::Exception& ex)
        {
            ::IceInternal::CallbackNC<T>::__exception(__result, ex);
            return;
        }
        if(response)
        {
            (::IceInternal::CallbackNC<T>::callback.get()->*response)();
        }
    }

    Response response;
};

template<class T> Callback_VSServer_registerPtr
newCallback_VSServer_register(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_VSServer_register<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_VSServer_registerPtr
newCallback_VSServer_register(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_VSServer_register<T>(instance, 0, excb, sentcb);
}

template<class T> Callback_VSServer_registerPtr
newCallback_VSServer_register(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_VSServer_register<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_VSServer_registerPtr
newCallback_VSServer_register(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_VSServer_register<T>(instance, 0, excb, sentcb);
}

template<class T, typename CT>
class Callback_VSServer_register : public Callback_VSServer_register_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_VSServer_register(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::vsm::network::VSServerPrx __proxy = ::vsm::network::VSServerPrx::uncheckedCast(__result->getProxy());
        try
        {
            __proxy->end_register(__result);
        }
        catch(::Ice::Exception& ex)
        {
            ::IceInternal::Callback<T, CT>::__exception(__result, ex);
            return;
        }
        if(response)
        {
            (::IceInternal::Callback<T, CT>::callback.get()->*response)(CT::dynamicCast(__result->getCookie()));
        }
    }

    Response response;
};

template<class T, typename CT> Callback_VSServer_registerPtr
newCallback_VSServer_register(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_VSServer_register<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_VSServer_registerPtr
newCallback_VSServer_register(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_VSServer_register<T, CT>(instance, 0, excb, sentcb);
}

template<class T, typename CT> Callback_VSServer_registerPtr
newCallback_VSServer_register(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_VSServer_register<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_VSServer_registerPtr
newCallback_VSServer_register(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_VSServer_register<T, CT>(instance, 0, excb, sentcb);
}

}

}

#endif
