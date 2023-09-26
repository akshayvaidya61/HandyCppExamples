#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include <sys/ioctl.h>

#include "CommunicationManagerPipe.h"

static constexpr int MAX_PIPE_SIZE = 4096; // maximum size of the pipe
static constexpr int FLUSH_THRESHOLD = 3;  // MAX_PIPE_SIZE / 2; // flush when pipe is half full

void CommunicationManagerPipe::sendAlgorithmResults(const AlgorithmResults &algorithmResults)
{
    // write the size of the struct first
    size_t size = sizeof(AlgorithmResults);
    write(mPipe, &size, sizeof(size));

    // write the struct itself
    write(mPipe, &algorithmResults, size);
}

// TODO Write a fault reporter implementation that reports the current fault
// reason.
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

// TODO Does not work yet
int CommunicationManagerPipe::pipeFlusher() const
{
    int free_space;
    if (ioctl(mPipe, FIONREAD, &free_space) == -1)
    {
        std::cerr << "Error getting pipe status: " << strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }

    if (free_space <= FLUSH_THRESHOLD)
    {
        // flush the pipe by reading the remaining data
        char buf[1024];
        while (read(mPipe, buf, sizeof(buf)) > 0)
        {
            // do nothing, just read the data
        }
        std::cout << "Pipe flushed!" << std::endl;
    }
}