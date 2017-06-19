        /*
        * This file was generated by the CommonAPI Generators.
        * Used org.genivi.commonapi.core 3.1.3.v201507280808.
        * Used org.franca.core 0.9.1.201412191134.
        *
        * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
        * If a copy of the MPL was not distributed with this file, You can obtain one at
        * http://mozilla.org/MPL/2.0/.
        */
        #include <v1_0/ipc_math/add_apiSomeIPProxy.hpp>

        #if !defined (COMMONAPI_INTERNAL_COMPILATION)
        #define COMMONAPI_INTERNAL_COMPILATION
        #endif

        #include <CommonAPI/SomeIP/AddressTranslator.hpp>
        #include <iostream>
        #include <ctime>
        #include <time.h>
        #include <sys/time.h>

        #undef COMMONAPI_INTERNAL_COMPILATION

        namespace v1_0 {
        namespace ipc_math {

        std::shared_ptr<CommonAPI::SomeIP::Proxy> createadd_apiSomeIPProxy(
                            const CommonAPI::SomeIP::Address &_address,
                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
                               struct timeval tv;
                               struct tm  tm_;
                               gettimeofday(&tv,NULL);
                               tm_=*localtime(&tv.tv_sec);

                              std::cout << "\n" << __FILE__ << "\t" << __FUNCTION__<< '\t' << __LINE__ << '\t' << tm_.tm_hour <<":"<< tm_.tm_min << ":" << tm_.tm_sec << '.' << tv.tv_usec <<"\n";
            return std::make_shared<add_apiSomeIPProxy>(_address, _connection);
        }

        INITIALIZER(registeradd_apiSomeIPProxy) {
           struct timeval tv;
           struct tm  tm_;
           gettimeofday(&tv,NULL);
           tm_=*localtime(&tv.tv_sec);

            std::cout << "\n" << __FILE__ << "\t" << __FUNCTION__<< '\t' << __LINE__ << '\t' << tm_.tm_hour <<":"<< tm_.tm_min << ":" << tm_.tm_sec << '.' << tv.tv_usec <<"\n";
            CommonAPI::SomeIP::AddressTranslator::get()->insert(
                "local:ipc_math.add_api:test",
                0x1234, 0x5678);
            CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
                add_api::getInterface(),
                &createadd_apiSomeIPProxy);
        }

        add_apiSomeIPProxy::add_apiSomeIPProxy(
                            const CommonAPI::SomeIP::Address &_address,
                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
              : CommonAPI::SomeIP::Proxy(_address, _connection )
        {
           struct timeval tv;
           struct tm  tm_;
           gettimeofday(&tv,NULL);
           tm_=*localtime(&tv.tv_sec);
           tm_.tm_sec += ( tv.tv_usec * (10E-6) );

            std::cout << "\n" << __FILE__ << "\t" << __FUNCTION__<< '\t' << __LINE__ << '\t' << tm_.tm_hour <<":"<< tm_.tm_min << ":" << tm_.tm_sec << '.' << tv.tv_usec <<"\n";
         }



        void add_apiSomeIPProxy::add(const double &_num1, const double &_num2, const double &_call_no, CommonAPI::CallStatus &_internalCallStatus, double &_result, const CommonAPI::CallInfo *_info) {

           struct timeval tv;
           struct tm  tm_;
           gettimeofday(&tv,NULL);
           tm_=*localtime(&tv.tv_sec);

            //std::cout << tm_.tm_hour <<":"<< tm_.tm_min << ":" << tm_.tm_sec << '.' << tv.tv_usec <<"  ";
            std::cout << tm_.tm_sec << '.' << tv.tv_usec <<"  ";
            CommonAPI::Deployable<double, CommonAPI::EmptyDeployment> deploy_num1(_num1, static_cast<CommonAPI::EmptyDeployment*>(nullptr));
            CommonAPI::Deployable<double, CommonAPI::EmptyDeployment> deploy_num2(_num2, static_cast<CommonAPI::EmptyDeployment*>(nullptr));
            CommonAPI::Deployable<double, CommonAPI::EmptyDeployment> deploy_call_no(_call_no, static_cast<CommonAPI::EmptyDeployment*>(nullptr));
            CommonAPI::Deployable<double, CommonAPI::EmptyDeployment> deploy_result(static_cast<CommonAPI::EmptyDeployment*>(nullptr));
            CommonAPI::SomeIP::ProxyHelper<
                CommonAPI::SomeIP::SerializableArguments<
                    CommonAPI::Deployable<
                        double,
                        CommonAPI::EmptyDeployment
                    >,
                    CommonAPI::Deployable<
                        double,
                        CommonAPI::EmptyDeployment
                    >,
                    CommonAPI::Deployable<
                        double,
                        CommonAPI::EmptyDeployment
                    >
                >,
                CommonAPI::SomeIP::SerializableArguments<
                    CommonAPI::Deployable<
                        double,
                        CommonAPI::EmptyDeployment
                    >
                >
            >::callMethodWithReply(
                *this,
                0x80e8,
                false,
                (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
                deploy_num1, deploy_num2, deploy_call_no,
                _internalCallStatus,
                deploy_result);
            _result = deploy_result.getValue();
        }
        std::future<CommonAPI::CallStatus> add_apiSomeIPProxy::addAsync(const double &_num1, const double &_num2, const double &_call_no, AddAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
           struct timeval tv;
           struct tm  tm_;
           gettimeofday(&tv,NULL);
           tm_=*localtime(&tv.tv_sec);

            std::cout << "\n" << __FILE__ << "\t" << __FUNCTION__<< '\t' << __LINE__ << '\t' << tm_.tm_hour <<":"<< tm_.tm_min << ":" << tm_.tm_sec << '.' << tv.tv_usec <<"\n";
            CommonAPI::Deployable<double, CommonAPI::EmptyDeployment> deploy_num1(_num1, static_cast<CommonAPI::EmptyDeployment*>(nullptr));
            CommonAPI::Deployable<double, CommonAPI::EmptyDeployment> deploy_num2(_num2, static_cast<CommonAPI::EmptyDeployment*>(nullptr));
            CommonAPI::Deployable<double, CommonAPI::EmptyDeployment> deploy_call_no(_call_no, static_cast<CommonAPI::EmptyDeployment*>(nullptr));
            CommonAPI::Deployable<double, CommonAPI::EmptyDeployment> deploy_result(static_cast<CommonAPI::EmptyDeployment*>(nullptr));
            return CommonAPI::SomeIP::ProxyHelper<
                CommonAPI::SomeIP::SerializableArguments<
                    CommonAPI::Deployable<
                        double,
                        CommonAPI::EmptyDeployment
                    >,
                    CommonAPI::Deployable<
                        double,
                        CommonAPI::EmptyDeployment
                    >,
                    CommonAPI::Deployable<
                        double,
                        CommonAPI::EmptyDeployment
                    >
                >,
                CommonAPI::SomeIP::SerializableArguments<
                    CommonAPI::Deployable<
                        double,
                        CommonAPI::EmptyDeployment
                    >
                >
            >::callMethodAsync(
                *this,
                0x80e8,
                false,
                (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
                deploy_num1, deploy_num2, deploy_call_no,
                [_callback] (CommonAPI::CallStatus _internalCallStatus, CommonAPI::Deployable<double, CommonAPI::EmptyDeployment> _result) {
                	_callback(_internalCallStatus, _result.getValue());
                },
                std::make_tuple(deploy_result));
        }



        void add_apiSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
           struct timeval tv;
           struct tm  tm_;
           gettimeofday(&tv,NULL);
           tm_=*localtime(&tv.tv_sec);

            std::cout << "\n" << __FILE__ << "\t" << __FUNCTION__<< '\t' << __LINE__ << '\t' << tm_.tm_hour <<":"<< tm_.tm_min << ":" << tm_.tm_sec<< '.' << tv.tv_usec <<"\n";
            ownVersionMajor = 1;
            ownVersionMinor = 0;
        }

        } // namespace ipc_math
        } // namespace v1_0