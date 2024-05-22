#pragma once

#include "LoanWrapper.h"



//--
LoanWrapper::LoanWrapper( Loan* ptr ) : pointerToLoan( ptr ) 
{
}
//--
LoanWrapper::~LoanWrapper()
{
    delete pointerToLoan;
}
