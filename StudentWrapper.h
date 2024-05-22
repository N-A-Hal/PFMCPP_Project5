#pragma once

#include "Classroom.h"

struct StudentWrapper
{
    StudentWrapper( Classroom::Student* ptr );
    ~StudentWrapper();

    Classroom::Student* pointerToStudent = nullptr;
};
