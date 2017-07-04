#include <iostream>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <vector>
#include <ctime>
#include <time.h>
#include <sys/time.h>
#include <v1_0/ipc_math/add_apiProxy.hpp>
#include <cmath>

#include "mytime.hpp"

using namespace v1_0::ipc_math;




int main()
{
        int i;
        // initialize time
        init_time();

        // initialize input vector 
        std::vector<double> vin;
        for (int i=1; i<=100; ++i) {
                vin.push_back(i);
        }

        std::shared_ptr <CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
        std::shared_ptr <add_apiProxy<>> myProxy = runtime->buildProxy <add_apiProxy> ("local", "test");

        i = 0;
        std::cout << "\n\nProxy is trying to connect to stub...\n";
        while (!myProxy->isAvailable()) {
            usleep(500*1000);
            i++;
            if (i > 2) {
                std::cout << "Error: Exiting average process as it cannot connect to sum process!!\n";
                exit(2);
            }
        }
        std::cout << "\n\nConnected...!!" << std::endl;
        print_time(__FILE__, __FUNCTION__, __LINE__);
       

        double sum=0;
        double avg=0;
        double local=0;
        double call_no=1;

        std::vector<double>::iterator vit;

        CommonAPI::CallStatus callStatus;

        // iterate through all input vector
        for (vit=vin.begin(); vit != vin.end(); ++vit, ++call_no ) {
                double arg = *vit;

                std::cout << __FILE__ <<"::"<< __FUNCTION__<<" : "<< __LINE__ << " ==> " << arg << " + " << call_no << "\n";
                // making remote function call
                myProxy->add(sum, arg, call_no, callStatus, local);
                print_time(__FILE__, __FUNCTION__, __LINE__);

                if ( static_cast<int>(callStatus) ) {
                        std::cout<<"ERROR:INVOCATION OF METHOD ADD FAILED!\t" ;
                        std::cout <<"ACTION:TERMINATING CLIENT!\n";
                        return 0;
                }

                sum=local;
                if (i++ > 150) {
                        std::cout << "Error: Exceeded max allowed loop!!";
                        break;
                }
        }

        avg=sum/vin.size();

        std::cout << "\n\nAVERAGE: " << avg <<"\n\n";

        return 0;
}
