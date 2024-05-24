#pragma once

#include "Loan.h"


struct LoanManager 
{
    double totalPayment = 0;
    LoanManager();
    ~LoanManager();

    void addLoan(const Loan& loan);
    void printTotalPayment() const;
};
