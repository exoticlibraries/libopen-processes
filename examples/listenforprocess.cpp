/**
    \copyright GNU General Public License v3.0 Copyright (c) 2019, Adewale Azeez 
    \author Adewale Azeez <azeezadewale98@gmail.com>
    \date 23 March 2020
    \file listenforprocess.cpp
*/

#define USE_HACKY_PROCESSES_MONITOR

#include "../src/processes.cpp"
#include <iostream>

using namespace libopen;

void ProcessStatusChange(PROCESS process, void* extraParam)
{
    if (process.status == PROCESS_STATUS::STARTED)
    {
        std::cout << process.exeName << " has started running" << std::endl; //plus id
        
    } else if (process.status == PROCESS_STATUS::STOPPED)
    {
        std::cout << process.exeName << " has stopped running" << std::endl;
    }
    
}

int main() 
{
    std::string name;
    std::cout << "Enter the process to monitor : ";
    std::getline(std::cin, name);
    std::cout << "listen for status change of " << name.c_str() << std::endl << std::endl;
#ifdef USE_HACKY_PROCESSES_MONITOR
    Hacky_MonitorProcess(name.c_str(), &ProcessStatusChange, NULL);
#else
    //use proper Monitor function
#endif
    return 0;
}

// Win: g++ listenforprocess.cpp -I../include/ -lpsapi