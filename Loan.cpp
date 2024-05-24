#include "LeakedObjectDetector.h"
#include "Loan.h"

//--
Loan::Loan(double amount, double rate, double numPay, bool secured):
    loanAmount(amount), interestRateInPercent(rate), numPayments(numPay), isSecured(secured)
{
    if(isSecured)
    {
        interestRateInPercent *= 0.9;
    }
    calculateTotalPayment();
}
//--
Loan::~Loan()
{
    std::cout << "Loan destructor called!" << std::endl;
}
//--
void Loan::calculateTotalPayment()
{
    double currentLoanAmount = loanAmount;
    totalPayment = 0;
    for(unsigned int i = 0; i < numPayments; ++i)
    {
        double interestPayment = currentLoanAmount * (interestRateInPercent / 12 / 100.0);
        double principalPayment = loanAmount / numPayments;
        double payment = interestPayment + principalPayment;

        totalPayment += payment;
        currentLoanAmount -= principalPayment;
    }
}
//--
double Loan::calculateOverpayment() const
{
    return totalPayment - loanAmount;
}
//--
void Loan::printOverpayment() const
{
    std::cout << "Loan amount: " << this->loanAmount << "\nOverpayment: " << this->calculateOverpayment() << std::endl;
}
