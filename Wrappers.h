#pragma once

#include "Classroom.h"
#include "Gym.h"

struct RecreationCenter;
struct Gym;
struct Loan;
struct LoanManager;

struct StudentWrapper
{
    StudentWrapper( Classroom::Student* ptr );
    ~StudentWrapper();

    Classroom::Student* pointerToStudent = nullptr;
};
//--
struct RecreationCenterWrapper
{
    RecreationCenterWrapper( RecreationCenter* ptr );
    ~RecreationCenterWrapper();

    RecreationCenter* pointerToRecreationCenter = nullptr;
};
//--
struct MemberWrapper
{
    MemberWrapper( Gym::Member* ptr );
    ~MemberWrapper();

    Gym::Member* pointerToMember = nullptr;
};
//--
struct LoanWrapper
{
    LoanWrapper( Loan* ptr );
    ~LoanWrapper();

    Loan* pointerToLoan = nullptr;
};
//--
struct LoanManagerWrapper
{
    LoanManagerWrapper( LoanManager* ptr );
    ~LoanManagerWrapper();

    LoanManager* pointerToLoanManager = nullptr;
};
//--
struct GymWrapper
{
    GymWrapper( Gym* ptr );
    ~GymWrapper();

    Gym* pointerToGym = nullptr;
};
//--
struct ClassroomWrapper
{
    ClassroomWrapper( Classroom* ptr );
    ~ClassroomWrapper();

    Classroom* pointerToClassroom = nullptr;
};
//--
