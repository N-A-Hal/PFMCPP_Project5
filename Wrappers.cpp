#include "Wrappers.h"

StudentWrapper::StudentWrapper( Classroom::Student* ptr ) : pointerToStudent( ptr ) 
{
}
//--
StudentWrapper::~StudentWrapper()
{
    delete pointerToStudent;
}
//--
RecreationCenterWrapper::RecreationCenterWrapper( RecreationCenter* ptr ) : pointerToRecreationCenter( ptr ) 
{
}
//--
RecreationCenterWrapper::~RecreationCenterWrapper()
{
    delete pointerToRecreationCenter;
}
//--
MemberWrapper::MemberWrapper( Gym::Member* ptr ) : pointerToMember( ptr ) 
{
}
MemberWrapper::~MemberWrapper()
{
    delete pointerToMember;
}
//--
LoanWrapper::LoanWrapper( Loan* ptr ) : pointerToLoan( ptr ) 
{
}
//--
LoanWrapper::~LoanWrapper()
{
    delete pointerToLoan;
}
//--
LoanManagerWrapper::LoanManagerWrapper( LoanManager* ptr ) : pointerToLoanManager( ptr ) 
{
}
//--
LoanManagerWrapper::~LoanManagerWrapper()
{
    delete pointerToLoanManager;
}
//--
GymWrapper::GymWrapper( Gym* ptr ) : pointerToGym( ptr ) 
{
}
//--
GymWrapper::~GymWrapper()
{
    delete pointerToGym;
}
//--
ClassroomWrapper::ClassroomWrapper( Classroom* ptr ) : pointerToClassroom( ptr ) 
{
}
//--
ClassroomWrapper::~ClassroomWrapper()
{
    delete pointerToClassroom;
}
//--
