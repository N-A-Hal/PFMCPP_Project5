#pragma once

#include "LoanManager.h"

LoanManager::LoanManager()
{
    std::cout << "LoanManager constructor called!" << std::endl;
}
//--
LoanManager::~LoanManager()
{
    std::cout << "LoanManager destructor called!" << std::endl;
}
//--
void LoanManager::addLoan(const Loan& loan) 
{
    totalPayment += loan.totalPayment; 
}
//--
void LoanManager::printTotalPayment() const
{
    std::cout << "Total payment: " << totalPayment << std::endl;
}