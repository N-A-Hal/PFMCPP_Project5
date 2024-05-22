#pragma once

#include "RecreationCenterWrapper.h"


RecreationCenterWrapper::RecreationCenterWrapper( RecreationCenter* ptr ) : pointerToRecreationCenter( ptr ) 
{
}
//--
RecreationCenterWrapper::~RecreationCenterWrapper()
{
    delete pointerToRecreationCenter;
}
