#include <iostream>
#include <memory>
#include <csignal>
#include <thread>
#include <atomic>

#include "ICommunicationManager.h"
#include "CommunicationManagerPipe.h"

using namespace std;

volatile sig_atomic_t gSignalStatus;

void signal_handler(int signal)
{
    gSignalStatus = signal;
}

int main()
{

    // register signal_handler function as the handler for SIGINT
    std::signal(SIGINT, signal_handler);

    std::cout << "Waiting for SIGINT signal..." << std::endl;
    while (gSignalStatus != SIGINT)
    {
        // do nothing, just wait for the signal
    }

    std::cout << "Received SIGINT signal!" << std::endl;
    return 0;
}
