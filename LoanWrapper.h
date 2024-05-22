#pragma once

#include "Loan.h"


//--
struct LoanWrapper
{
    LoanWrapper( Loan* ptr );
    ~LoanWrapper();

    Loan* pointerToLoan = nullptr;
};