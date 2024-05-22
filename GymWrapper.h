#pragma once

#include "Gym.h"

struct GymWrapper
{
    GymWrapper( Gym* ptr );
    ~GymWrapper();

    Gym* pointerToGym = nullptr;
};
