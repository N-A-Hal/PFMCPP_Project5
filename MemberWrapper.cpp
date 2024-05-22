#include "MemberWrapper.h"


MemberWrapper::MemberWrapper( Gym::Member* ptr ) : pointerToMember( ptr ) 
{
}
MemberWrapper::~MemberWrapper()
{
    delete pointerToMember;
}
