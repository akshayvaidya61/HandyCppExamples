#pragma once

#include <array>
#include <cstdint>

static constexpr uint32_t EMBEDDED_WHITE_BALANCE_GAIN_ARRAY_SIZE = 4U;

struct FrameStatistics
{
    uint64_t mEmbeddedFrameCount{0U};
    std::array<uint32_t, EMBEDDED_WHITE_BALANCE_GAIN_ARRAY_SIZE> mListOfEmbeddedWhiteBalanceGains{0U};
    std::array<uint32_t, EMBEDDED_WHITE_BALANCE_GAIN_ARRAY_SIZE> mListOfEmbeddedWhiteBalanceOffsets{0U};
    uint32_t mExposureTime{0U};
    uint32_t mAnalogGain{0U};
    uint32_t mDigitalGain{0U};
};
