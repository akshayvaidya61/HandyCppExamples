#pragma once

#include <cstdint>

enum class VideoStreamStatus_e : uint8_t
{
    STOPPED = 0,
    IN_RECOVERY,
    FAULT,
    ACTIVE
};