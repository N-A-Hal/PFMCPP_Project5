#pragma once

#include "Gym.h"

struct MemberWrapper
{
    MemberWrapper( Gym::Member* ptr );
    ~MemberWrapper();

    Gym::Member* pointerToMember = nullptr;
};
