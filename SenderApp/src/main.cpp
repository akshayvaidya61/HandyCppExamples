#include <iostream>
#include <memory>
#include <csignal>
#include <thread>
#include <atomic>
#include <chrono>

#include "ICommunicationManager.h"
#include "CommunicationManagerPipe.h"

using namespace std;

volatile sig_atomic_t gSignalStatus;

void signal_handler(int signal)
{
    gSignalStatus = signal;
}

class SenderTask
{
    std::unique_ptr<ICommunicationManager> ptrToCommunicationManager;
    uint64_t frameCount{0U};

public:
    SenderTask()
    {
        // TODO Add configuration filename string
        ptrToCommunicationManager = std::make_unique<CommunicationManagerPipe>("MyFirstPipe");
    }
    ~SenderTask() = default;

    void keepSendingAlgorithmResultsAt100msCadence()
    {
        AlgorithmResults lAlgorithmResults{};
        FrameStatistics lFrameStatistics{};

        lFrameStatistics.mAnalogGain = 2232U;
        lFrameStatistics.mDigitalGain = 1111U;
        lFrameStatistics.mEmbeddedFrameCount = 22212U;
        lFrameStatistics.mExposureTime = 1213U;
        lFrameStatistics.mListOfEmbeddedWhiteBalanceGains = {121U, 121U, 13U, 31U};
        lFrameStatistics.mListOfEmbeddedWhiteBalanceOffsets = {121U, 121U, 13U, 31U};

        lAlgorithmResults.currentHandleToBuffer = "Akshay";
        lAlgorithmResults.currentSteamStatus = VideoStreamStatus_e::STOPPED;

        auto currentTimePoint = std::chrono::high_resolution_clock::now();
        lAlgorithmResults.currentTimestamp = std::chrono::time_point_cast<std::chrono::nanoseconds>(currentTimePoint).time_since_epoch().count();
        lAlgorithmResults.currentFrameStatistics = lFrameStatistics;

        while (gSignalStatus != SIGINT)
        {
            // ptrToCommunicationManager->sendAlgorithmResults({true, frameCount++});
            ptrToCommunicationManager->sendAlgorithmResults(lAlgorithmResults);

            std::this_thread::sleep_for(std::chrono::milliseconds(100U));
        }
    }
};

int main()
{

    // register signal_handler function as the handler for SIGINT
    std::signal(SIGINT, signal_handler);

    std::cout << "Waiting for SIGINT signal..." << std::endl;

    // Write sender implementation here
    SenderTask sender;
    std::thread senderThread(&SenderTask::keepSendingAlgorithmResultsAt100msCadence, &sender);

    while (gSignalStatus != SIGINT)
    {
        // do nothing, just wait for the signal
    }

    std::cout << "Received SIGINT signal!" << std::endl;

    // Write exit here
    senderThread.join();

    return 0;
}
