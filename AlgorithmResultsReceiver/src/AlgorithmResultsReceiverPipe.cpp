#include <cstdint>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "AlgorithmResultsReceiverPipe.h"

AlgorithmResultsReceiverPipe::AlgorithmResultsReceiverPipe(const std::string &pipeName)
{
    mPipeName = pipeName;

    // open the named pipe for reading and writing
    mPipe = open(pipeName.c_str(), O_RDONLY);
    if (mPipe == -1)
    {
        std::cerr << "Failed to open named pipe." << std::endl;
    }
}

const bool AlgorithmResultsReceiverPipe::receiveAlgorithmResults(AlgorithmResults &algorithmResults)
{
    // read the size of the struct first
    size_t size;
    if (read(mPipe, &size, sizeof(size)) != sizeof(size))
    {
        return false;
    }

    // read the struct itself
    if (read(mPipe, &algorithmResults, size) != size)
    {
        return false;
    }

    return true;
}
