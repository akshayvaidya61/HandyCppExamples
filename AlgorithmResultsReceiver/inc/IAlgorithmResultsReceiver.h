#include "AlgorithmResults.h"

class IAlgorithmResultsReceiver
{
public:
    virtual const bool receiveAlgorithmResults(AlgorithmResults &) const = 0;

    virtual ~IAlgorithmResultsReceiver() = default;
};