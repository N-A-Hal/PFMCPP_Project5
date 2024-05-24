#include "RecreationCenter.h"

RecreationCenter::RecreationCenter(const Classroom& classroom, const Gym& gym)
    : academicClassroom(classroom), fitnessGym(gym)
{
    std::cout << "RecreationCenter constructor called!" << std::endl;
}
//--
RecreationCenter::~RecreationCenter()
{
    std::cout << "RecreationCenter destructor called!" << std::endl;
}
//--
bool RecreationCenter::isLastRegisteredPersonSame() const
{
    return academicClassroom.lastRegisteredStudentName == fitnessGym.lastRegisteredMembersName;
}
//--
void RecreationCenter::compareNumMembers() const
{
    if (academicClassroom.totalStudents > fitnessGym.totalMembers)
    {
        std::cout << "There are more members in the academic classroom than the gym." << std::endl;
    }
    else if (academicClassroom.totalStudents > fitnessGym.totalMembers)
    {
        std::cout << "There are more members in the gym than the academic classroom." << std::endl;
    }
    else
    {
        std::cout << "There are the same number of members in both the gym and the academic classrom." << std::endl;
    }
}
