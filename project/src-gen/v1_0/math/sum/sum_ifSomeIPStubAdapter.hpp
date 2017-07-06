/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.3.v201507280808.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef MATH_SUM_SUM_IF_SOMEIP_STUB_ADAPTER_HPP_
#define MATH_SUM_SUM_IF_SOMEIP_STUB_ADAPTER_HPP_

#include <v1_0/math/sum/sum_ifStub.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Config.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1_0 {
namespace math {
namespace sum {

typedef CommonAPI::SomeIP::StubAdapterHelper<sum_ifStub> sum_ifSomeIPStubAdapterHelper;

class sum_ifSomeIPStubAdapterInternal
    : public virtual sum_ifStubAdapter,
      public sum_ifSomeIPStubAdapterHelper
{
public:
    sum_ifSomeIPStubAdapterInternal(
            const CommonAPI::SomeIP::Address &_address,
            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
            const std::shared_ptr<CommonAPI::StubBase> &_stub);

    ~sum_ifSomeIPStubAdapterInternal();




    const sum_ifSomeIPStubAdapterHelper::StubDispatcherTable& getStubDispatcherTable();
    const CommonAPI::SomeIP::StubAttributeTable& getStubAttributeTable();

    void deactivateManagedInstances();


static CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1_0::math::sum::sum_ifStub,
        CommonAPI::Version
        > getsum_ifInterfaceVersionStubDispatcher;



static CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
    ::v1_0::math::sum::sum_ifStub,
    std::tuple<double, double>,
    std::tuple<double>,
    std::tuple<CommonAPI::EmptyDeployment, CommonAPI::EmptyDeployment>,
    std::tuple<CommonAPI::EmptyDeployment>
> add2StubDispatcher;


 private:
    sum_ifSomeIPStubAdapterHelper::StubDispatcherTable stubDispatcherTable_;
    CommonAPI::SomeIP::StubAttributeTable stubAttributeTable_;
};

class sum_ifSomeIPStubAdapter
    : public sum_ifSomeIPStubAdapterInternal,
      public std::enable_shared_from_this<sum_ifSomeIPStubAdapter> {
public:
    sum_ifSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub) 
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          sum_ifSomeIPStubAdapterInternal(_address, _connection, _stub) {
    }
};

} // namespace sum
} // namespace math
} // namespace v1_0

#endif // MATH_SUM_sum_if_SOMEIP_STUB_ADAPTER_HPP_