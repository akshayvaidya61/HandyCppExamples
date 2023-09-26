#pragma once
#include "AlgorithmResults.h"

class IAlgorithmResultsReceiver
{
public:
    virtual const bool receiveAlgorithmResults(AlgorithmResults &) = 0;

    virtual ~IAlgorithmResultsReceiver() = default;
};