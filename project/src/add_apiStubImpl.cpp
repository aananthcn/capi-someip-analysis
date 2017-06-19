#include "add_apiStubImpl.hpp"

#include <iostream>
#include <cmath>
#include <ctime>
#include <time.h>
#include <sys/time.h>

void init_time(void);
void print_time(void);


add_apiStubImpl::add_apiStubImpl() {
        struct timeval tv;
        struct tm  tm_;
        gettimeofday(&tv,NULL);
        tm_=*localtime(&tv.tv_sec);

        std::cout << "\n" << __FILE__ << "\t" << __FUNCTION__<< '\t' << __LINE__ << '\t' << tm_.tm_hour <<":"<< tm_.tm_min << ":" << tm_.tm_sec << '.' << tv.tv_usec <<"\n";
}


add_apiStubImpl::~add_apiStubImpl() {
        struct timeval tv;
        struct tm  tm_;
        gettimeofday(&tv,NULL);
        tm_=*localtime(&tv.tv_sec);

        std::cout << "\n" << __FILE__ << "\t" << __FUNCTION__<< '\t' << __LINE__ << '\t' << tm_.tm_hour <<":"<< tm_.tm_min << ":" << tm_.tm_sec << '.' << tv.tv_usec <<"\n";
}


void add_apiStubImpl::add(const std::shared_ptr<CommonAPI::ClientId> _client, double _num1, double _num2, double _call_no, addReply_t _reply)
{
        std::cout << __FILE__ <<"::"<< __FUNCTION__<<" : "<< __LINE__ << " ==> " << _num1 << " + " << _num2 << "\n";
        init_time();
        _reply( _num1 + _num2 );
        print_time();

        call_cnt++;
}


void add_apiStubImpl::my_signal_handeler(int sig)
{
        exit(1);
}


int add_apiStubImpl::getCallCount() {
        return call_cnt;
}
