#include "sum_ifStubImpl.hpp"

#include <iostream>
#include <cmath>
#include <ctime>
#include <time.h>
#include <sys/time.h>

#include "mytime.hpp"

sum_ifStubImpl::sum_ifStubImpl() {
	call_cnt = 0;
    print_time(__FILE__, __FUNCTION__, __LINE__);
}


sum_ifStubImpl::~sum_ifStubImpl() {
}


void sum_ifStubImpl::add2(const std::shared_ptr<CommonAPI::ClientId> _client, double _num1, double _num2, add2Reply_t _reply)
{
        std::cout << __FILE__ <<"::"<< __FUNCTION__<<" : "<< __LINE__ << " ==> " << _num1 << " + " << _num2 << "\n";
        _reply( _num1 + _num2 );
        print_time(__FILE__, __FUNCTION__, __LINE__);

        call_cnt++;
}


void sum_ifStubImpl::my_signal_handler(int sig)
{
        exit(1);
}


int sum_ifStubImpl::getCallCount() {
        return call_cnt;
}
