#pragma once

#include "LeakedObjectDetector.h"

struct Loan
{
    double loanAmount;
    double interestRateInPercent;
    double numPayments;
    bool isSecured;
    double totalPayment = 0;

    Loan(double amount, double rate, double numPay, bool secured);
    ~Loan();
    void calculateTotalPayment();
    double calculateOverpayment() const;
    void printOverpayment() const;

    JUCE_LEAK_DETECTOR(Loan)
};