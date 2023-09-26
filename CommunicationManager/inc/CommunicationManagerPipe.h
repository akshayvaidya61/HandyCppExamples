#pragma once

#include "ICommunicationManager.h"
#include "AlgorithmResults.h"

// Communication Manager Implementation using named pipe
class CommunicationManagerPipe final : public ICommunicationManager
{
private:
    int mPipe;
    std::string mPipeName;

public:
    explicit CommunicationManagerPipe(const std::string pipeName);

    virtual void sendAlgorithmResults(const AlgorithmResults &algorithmResults) override;
    virtual void reportFault() override;

    virtual ~CommunicationManagerPipe();

    int getPipe() const;

    int pipeFlusher() const;
};
