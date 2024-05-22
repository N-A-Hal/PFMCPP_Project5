#pragma once

#include "RecreationCenter.h"

struct RecreationCenterWrapper
{
    RecreationCenterWrapper( RecreationCenter* ptr );
    ~RecreationCenterWrapper();

    RecreationCenter* pointerToRecreationCenter = nullptr;
};