#pragma once

#include "StudentWrapper.h"


StudentWrapper::StudentWrapper( Classroom::Student* ptr ) : pointerToStudent( ptr ) 
{
}
//--
StudentWrapper::~StudentWrapper()
{
    delete pointerToStudent;
}

