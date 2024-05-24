#pragma once

#include "Gym.h"
#include "Classroom.h"

struct RecreationCenter 
{
    Classroom academicClassroom;
    Gym fitnessGym;

    RecreationCenter(const Classroom& classroom, const Gym& gym);
    ~RecreationCenter();

    bool isLastRegisteredPersonSame() const;
    void compareNumMembers() const;
};
