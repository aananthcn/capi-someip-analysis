#if !defined(add_apiStubImpl_H_)
#define add_apiStubImpl_H_

#include <CommonAPI/CommonAPI.hpp>
#include <signal.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <v1_0/math/sum/sum_ifStubDefault.hpp>

class add_apiStubImpl: public v1_0::math::sum::sum_ifStubDefault
{
public:
	add_apiStubImpl();
	virtual ~add_apiStubImpl();
	virtual void add2(const std::shared_ptr<CommonAPI::ClientId> _client, double _num1, double _num2, add2Reply_t _reply);
	static void my_signal_handeler(int sig);
	int getCallCount();

private:
	int call_cnt;
};



#endif