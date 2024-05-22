#pragma once

#include "Classroom.h"

struct ClassroomWrapper
{
    ClassroomWrapper( Classroom* ptr );
    ~ClassroomWrapper();

    Classroom* pointerToClassroom = nullptr;
};
