#include "LoanManagerWrapper.h"


LoanManagerWrapper::LoanManagerWrapper( LoanManager* ptr ) : pointerToLoanManager( ptr ) 
{
}
//--
LoanManagerWrapper::~LoanManagerWrapper()
{
    delete pointerToLoanManager;
}
