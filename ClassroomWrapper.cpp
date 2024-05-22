#pragma once

#include "ClassroomWrapper.h"

ClassroomWrapper::ClassroomWrapper( Classroom* ptr ) : pointerToClassroom( ptr ) 
{
}
//--
ClassroomWrapper::~ClassroomWrapper()
{
    delete pointerToClassroom;
}
