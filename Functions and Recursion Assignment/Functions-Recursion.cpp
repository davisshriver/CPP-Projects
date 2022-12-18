// Functions-Recursion.cpp 
// CSIS 112 D01
//  https://cplusplus.com/reference/iomanip/
//  https://www.tutorialspoint.com/c_standard_library/math_h.htm

#include <iostream>
#include <math.h>
#include <iomanip>

double PaymentCalculator(int p, double r, int n);
void LoanAmortizaeSchedule(int currentPeriod, int totalPeriods,
    double paymentAmount, double monthlyInterestRate, double currentBalance);
bool CheckPrinciple(double x);
bool CheckInterest(double x);
bool CheckTerm(int x);

using namespace std;
int main()
{
    int term;
    double interest, principle, payment;
    bool pBool = false;
    bool iBool = false;
    bool tBool = false;

    // Introduction, Receiving Input, and Checking Input

    cout << "Davis Shriver -- Lab 1 - Recursion" << endl << endl;

    while (pBool == false) {

        cout << "Principle (between 50000 & 100000):          ";
        cin >> principle;
        pBool = CheckPrinciple(principle);

        if (pBool == false) {
            cout << "Please re-enter a valid principle value (50000 - 100000)!" << endl;
        }
    }
    while (iBool == false) {
        cout << "Annual Interest Rate (e.g. 4.5):             ";
        cin >> interest;

        iBool = CheckInterest(interest);

        if (iBool == false) {
            cout << "Please enter a valid interest rate!" << endl;
        }
    }
    while (tBool == false) {
        cout << "Loan Term in Years (10, 15, 25, or 40):      ";
        cin >> term;

        tBool = CheckTerm(term);

        if (tBool == false) {
            cout << "Please enter a valid term value!" << endl;
        }
    }
    system("pause");
    
    // Calculations

    interest = (interest / 100) / 12;
    term = term * 12;

    payment = PaymentCalculator(principle, interest, term);

    // Print Answer
    cout << setprecision(2) << fixed << "Monthly Payment: " << payment << endl;
    LoanAmortizaeSchedule(0, term, payment, interest, principle);
    
}   
// Calculates payment
double PaymentCalculator(int p, double r, int n) {
    
    double A;

    A = p * (r * pow((1 + r), n) / (pow((1 + r), n) - 1));
    return A;
}

void LoanAmortizaeSchedule(int currentPeriod,int totalPeriods,
    double paymentAmount, double monthlyInterestRate, double currentBalance) {
    
    // For first iteration only
    if (currentPeriod == 0) {
        cout << "  Payment    Amount Interest Principal    Balance" << endl;
        cout << right << setw(49) << currentBalance << endl;
    }

    // Calculations
    double interAmount = monthlyInterestRate * currentBalance;
    double principle = paymentAmount - interAmount;
    currentBalance = currentBalance - principle;

    // Formatting and Printing
    cout << setprecision(2) << fixed << right;
    cout << setw(9) << (currentPeriod + 1) << setw(9) << paymentAmount << setw(10) <<
        interAmount << setw(10) << principle << setw(11) << abs(currentBalance) << endl;

    // Call function again if max periods has not been reached
    if (currentPeriod != (totalPeriods - 1)) {
        LoanAmortizaeSchedule(currentPeriod + 1, totalPeriods,
            paymentAmount, monthlyInterestRate, currentBalance);
    }

}
// Checks input for principle input
bool CheckPrinciple(double x) {
    if (x >= 50000 && x <= 100000) {
        return true;
    }
    else
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
}
// Checks interest for interest input
bool CheckInterest(double x) {
        /*
        Error check for a double that must be numeric and positive.
        cin.fail() becomes true when the value entered is non-numeric
        num <= 0 is true if the number is positive
        */
        bool ReturnVal(true); // Defaults to true
        if (cin.fail() || x <= 0)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            ReturnVal = false;
        }
        return ReturnVal;
    
}
// Checks term input
bool CheckTerm(int x) {
    if (x == 10 || x == 15 || x == 25 || x == 40)
    {
        return true;
    }
    else
    {
        return false;
    }
}
