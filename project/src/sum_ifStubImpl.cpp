#include "sum_ifStubImpl.hpp"

#include <iostream>
#include <cmath>
#include <ctime>
#include <time.h>
#include <sys/time.h>

#include "mytime.hpp"

add_apiStubImpl::add_apiStubImpl() {
    print_time(__FILE__, __FUNCTION__, __LINE__);
}


add_apiStubImpl::~add_apiStubImpl() {
    print_time(__FILE__, __FUNCTION__, __LINE__);
}


void add_apiStubImpl::add2(const std::shared_ptr<CommonAPI::ClientId> _client, double _num1, double _num2, add2Reply_t _reply)
{
        std::cout << __FILE__ <<"::"<< __FUNCTION__<<" : "<< __LINE__ << " ==> " << _num1 << " + " << _num2 << "\n";
        _reply( _num1 + _num2 );
        print_time(__FILE__, __FUNCTION__, __LINE__);

        call_cnt++;
}


void add_apiStubImpl::my_signal_handeler(int sig)
{
        exit(1);
}


int add_apiStubImpl::getCallCount() {
        return call_cnt;
}
