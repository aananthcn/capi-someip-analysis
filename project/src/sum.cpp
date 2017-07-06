#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>

#include "sum_ifStubImpl.hpp"
#include "mytime.hpp"

#include <ctime>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>



int main()
{
        signal(SIGINT, add_apiStubImpl::my_signal_handeler);

        print_time(__FILE__, __func__, __LINE__); // time initialized in constructor of other classes
        std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
        std::shared_ptr<add_apiStubImpl> myService = std::make_shared<add_apiStubImpl>();
        std::cout << "registering stub implementation...\n";
        runtime->registerService("local", "test", myService);
        std::cout << "registered stub implementation!\n";
        print_time(__FILE__, __func__, __LINE__);

        std::cout << "Waiting for the remote client (proxy) to call this stub...\n";
        while (myService->getCallCount() <= 150) {
                usleep(100*1000); // check for call count every 100 ms
        }

        return 0;
}
