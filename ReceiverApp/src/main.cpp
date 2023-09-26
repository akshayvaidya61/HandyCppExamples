#include <iostream>
#include <memory>
#include <csignal>
#include <thread>
#include <atomic>
#include <chrono>

#include "IAlgorithmResultsReceiver.h"
#include "AlgorithmResultsReceiverPipe.h"

using namespace std;

volatile sig_atomic_t gSignalStatus;

void signal_handler(int signal)
{
    gSignalStatus = signal;
}

class ReceiverTask
{
    std::unique_ptr<IAlgorithmResultsReceiver> ptrToAlgorithmResultsReceiver;
    AlgorithmResults receivedResults{};

public:
    ReceiverTask()
    {
        ptrToAlgorithmResultsReceiver = std::make_unique<AlgorithmResultsReceiverPipe>("MyFirstPipe");
    }
    ~ReceiverTask() = default;

    void keepReceivingAlgorithmResults()
    {
        while (gSignalStatus != SIGINT)
        {
            ptrToAlgorithmResultsReceiver->receiveAlgorithmResults(receivedResults);

            std::cout << "Data Received:currentHandleToBuffer: " << receivedResults.currentHandleToBuffer << std::endl;
            std::cout << "Data Received:currentSteamStatus: " << static_cast<uint8_t>(receivedResults.currentSteamStatus) << std::endl;
            std::cout << "Data Received:currentTimestamp: " << receivedResults.currentTimestamp << std::endl;

            std::cout << "Data Received: receivedResults.currentFrameStatistics.mAnalogGain: " << receivedResults.currentFrameStatistics.mAnalogGain << std::endl;
            std::cout << "Data Received: receivedResults.currentFrameStatistics.mDigitalGain: " << receivedResults.currentFrameStatistics.mDigitalGain << std::endl;
            std::cout << "Data Received: receivedResults.currentFrameStatistics.mEmbeddedFrameCount: " << receivedResults.currentFrameStatistics.mEmbeddedFrameCount << std::endl;
            std::cout << "Data Received: receivedResults.currentFrameStatistics.mExposureTime: " << receivedResults.currentFrameStatistics.mExposureTime << std::endl;

            std::cout << "Data Received: receivedResults.currentFrameStatistics.mListOfEmbeddedWhiteBalanceGains: " << std::endl;

            for (auto const iter : receivedResults.currentFrameStatistics.mListOfEmbeddedWhiteBalanceGains)
            {
                std::cout << iter << std::endl;
            }

            std::cout << "Data Received: receivedResults.currentFrameStatistics.mListOfEmbeddedWhiteBalanceOffsets: " << std::endl;

            for (auto const iter : receivedResults.currentFrameStatistics.mListOfEmbeddedWhiteBalanceOffsets)
            {
                std::cout << iter << std::endl;
            }
        }
    }
};

int main()
{

    // register signal_handler function as the handler for SIGINT
    std::signal(SIGINT, signal_handler);

    std::cout << "Waiting for SIGINT signal..." << std::endl;

    // Write sender implementation here
    ReceiverTask receiver;
    std::thread receiverThread(&ReceiverTask::keepReceivingAlgorithmResults, &receiver);

    while (gSignalStatus != SIGINT)
    {
        // do nothing, just wait for the signal
    }

    std::cout << "Received SIGINT signal!" << std::endl;

    // Write exit here
    receiverThread.join();

    return 0;
}
