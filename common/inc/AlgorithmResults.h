#pragma once

#include <string>
#include <chrono>

#include "VideoStreamStatus.h"
#include "FrameStatistics.h"
struct AlgorithmResults
{
    std::string currentHandleToBuffer{};
    VideoStreamStatus_e currentSteamStatus;
    uint64_t currentTimestamp{0U};
    FrameStatistics currentFrameStatistics{};
};
