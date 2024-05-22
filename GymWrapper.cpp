#pragma once

#include "GymWrapper.h"


GymWrapper::GymWrapper( Gym* ptr ) : pointerToGym( ptr ) 
{
}
//--
GymWrapper::~GymWrapper()
{
    delete pointerToGym;
}
