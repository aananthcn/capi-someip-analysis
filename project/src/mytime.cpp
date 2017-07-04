#include <iostream>
#include <ctime>
#include <time.h>
#include <sys/time.h>
#include <string>


using namespace std;

static double Time_us;

void init_time(void)
{
        struct timeval tv;

        gettimeofday(&tv, NULL);
        Time_us = tv.tv_sec * 1000000 + tv.tv_usec;
}

void print_time(string file, string func, int line)
{
        double time_us;
        struct timeval tv;
        struct tm time_tm; 
        
        gettimeofday(&tv, NULL);
        time_us = tv.tv_sec * 1000000 + tv.tv_usec;
        time_tm = *localtime(&tv.tv_sec);

        std::cout << "»—› " << file << "::" << func << "():" << line << " | time=" << time_tm.tm_hour 
        	<< ":" << time_tm.tm_min << ":" << time_tm.tm_sec << "." << tv.tv_usec 
        	<< "; time-diff=" << time_us - Time_us << " us\n";
}