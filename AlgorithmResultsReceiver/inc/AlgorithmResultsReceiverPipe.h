#pragma once

#include <string>

#include "IAlgorithmResultsReceiver.h"

class AlgorithmResultsReceiverPipe final : public IAlgorithmResultsReceiver
{
    int mPipe;
    std::string mPipeName;

public:
    explicit AlgorithmResultsReceiverPipe(const std::string &pipeName);
    ~AlgorithmResultsReceiverPipe() = default;

    virtual const bool receiveAlgorithmResults(AlgorithmResults &) override;
};