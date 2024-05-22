#pragma once


#include "LoanManager.h"

struct LoanManagerWrapper
{
    LoanManagerWrapper( LoanManager* ptr );
    ~LoanManagerWrapper();

    LoanManager* pointerToLoanManager = nullptr;
};