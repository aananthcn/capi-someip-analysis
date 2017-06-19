/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.3.v201507280808.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef IPC_MATH_add_api_STUB_HPP_
#define IPC_MATH_add_api_STUB_HPP_

#include <functional>




#include <v1_0/ipc_math/add_api.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <vector>

#include <CommonAPI/Stub.hpp>
#include <iostream>
#include <ctime>
#include <time.h>
#include <sys/time.h>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1_0 {
namespace ipc_math {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service add_api. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class add_apiStubAdapter
    : virtual public CommonAPI::StubAdapter,
      public add_api {
 public:



    virtual void deactivateManagedInstances() = 0;
protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */
};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for add_api.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class add_apiStubRemoteEvent
{
public:
    virtual ~add_apiStubRemoteEvent() {
      struct timeval tv;
      struct tm  tm_;
      gettimeofday(&tv,NULL);
      tm_=*localtime(&tv.tv_sec);

         std::cout << "\n" << __FILE__ << "\t" << __FUNCTION__<< '\t' << __LINE__ << '\t' << tm_.tm_hour <<":"<< tm_.tm_min << ":" << tm_.tm_sec << '.' << tv.tv_usec <<"\n";
   }

};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service add_api to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class add_apiStub
    : public virtual CommonAPI::Stub<add_apiStubAdapter, add_apiStubRemoteEvent>
{
public:
    typedef std::function<void (double _result)>addReply_t;

    virtual ~add_apiStub() {
      struct timeval tv;
      struct tm  tm_;
      gettimeofday(&tv,NULL);
      tm_=*localtime(&tv.tv_sec);

         std::cout << "\n" << __FILE__ << "\t" << __FUNCTION__<< '\t' << __LINE__ << '\t' << tm_.tm_hour <<":"<< tm_.tm_min << ":" << tm_.tm_sec << '.' << tv.tv_usec <<"\n";
   }
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> clientId) = 0;


    /// This is the method that will be called on remote calls on the method add.
    virtual void add(const std::shared_ptr<CommonAPI::ClientId> _client, double _num1, double _num2, double _call_no, addReply_t _reply) = 0;

    using CommonAPI::Stub<add_apiStubAdapter, add_apiStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<add_apiStubAdapter, add_apiStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<add_apiStubAdapter, add_apiStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef add_apiStubRemoteEvent RemoteEventType;
    typedef add_api StubInterface;
};

} // namespace ipc_math
} // namespace v1_0

#endif // IPC_MATH_add_api_STUB_HPP_
