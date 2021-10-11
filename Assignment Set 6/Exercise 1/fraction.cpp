#include "fraction.h"
#include <numeric>
#include <iostream>
using namespace std;

fraction::fraction(int n, int d)
{
    numerator = n;
    denominator = d;
}

void fraction::add(fraction f)
{
    checkForUndefinedFractions(denominator, f.denominator);

    if(denominator == f.denominator)
        numerator += f.numerator;
    else
    {
        numerator = numerator * f.denominator + denominator * f.numerator;
        denominator *= f.denominator;
    }

    reduceFractionToSimplestForm(numerator, denominator);
}

void fraction::mult(fraction f)
{
    checkForUndefinedFractions(denominator, f.denominator);

    numerator *= f.numerator;
    denominator *= f.denominator;

    reduceFractionToSimplestForm(numerator, denominator);
}

void fraction::div(fraction f)
{
    checkForUndefinedFractions(denominator, f.denominator);

    if(f.numerator == 0)
        throw "This will cause a division by 0 later. Rejected.";

    fraction newFraction = fraction(f.denominator, f.numerator);
    mult(newFraction);
}

void fraction::display(void)
{
    cout << numerator << " / " << denominator << endl;
}

void checkForUndefinedFractions(int d1, int d2)
{
    if(d1 == 0 || d2 == 0)
        throw "Division by zero unaccepted";
}

void reduceFractionToSimplestForm(int &n, int &d)
{
    int greatestDivisor = gcd(n, d);
    n /= greatestDivisor;
    d /= greatestDivisor;
}