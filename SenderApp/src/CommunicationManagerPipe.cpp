#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include <thread>
#include <chrono>

#include "CommunicationManagerPipe.h"

void CommunicationManagerPipe::sendAlgorithmResults(const AlgorithmResults &algorithmResults)
{
    // write the size of the struct first
    size_t size = sizeof(AlgorithmResults);
    write(mPipe, &size, sizeof(size));

    // write the struct itself
    write(mPipe, &algorithmResults, size);

    std::cout << "Data: " << algorithmResults.frameCount << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000U));
}

void CommunicationManagerPipe::reportFault()
{
}

CommunicationManagerPipe::CommunicationManagerPipe(const std::string pipeName)
{
    // create a QNX named pipe with read/write permissions for all users
    mkfifo(pipeName.c_str(), S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    mPipeName = pipeName;

    // open the named pipe for reading and writing
    mPipe = open(pipeName.c_str(), O_RDWR);
    if (mPipe == -1)
    {
        std::cerr << "Failed to open named pipe." << std::endl;
    }
}

CommunicationManagerPipe::~CommunicationManagerPipe()
{
    // close the named pipe
    close(mPipe);
    unlink(mPipeName.c_str());
}

int CommunicationManagerPipe::getPipe() const
{
    return mPipe;
}
