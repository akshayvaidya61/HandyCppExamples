#pragma once

#include "AlgorithmResults.h"

class ICommunicationManager
{
public:
    virtual void sendAlgorithmResults(const AlgorithmResults &) = 0;
    virtual void reportFault() = 0;

    virtual ~ICommunicationManager() = default;
};