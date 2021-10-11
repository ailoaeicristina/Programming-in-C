#include <algorithm>
#include <iostream>
using namespace std;

#ifndef FRACTION_H_
#define FRACTION_H_

class fraction {

    private:
        int numerator;
        int denominator;

    public:
        fraction(int n, int d);

        void add(fraction f);
        void mult(fraction f);
        void div(fraction f);

        void display(void);
};
#endif

fraction::fraction(int n, int d)
{
    numerator = n;
    denominator = d;
}

void checkForUndefinedFractions(int d1, int d2)
{
    if(d1 == 0 || d2 == 0)
        throw "Division by zero unaccepted";
}

void reduceFractionToSimplestForm(int &n, int &d)
{
    int greatestDivisor = __gcd(n, d);
    n /= greatestDivisor;
    d /= greatestDivisor;
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

int main(void)
{
    int n, d;
    char a, c;

    while(!cin.fail())
    {
        cin >> n;
        if(cin.fail())
            return 0;
        cin >> a;
        cin >> d;

        fraction f1 = fraction(n, d);

        cin >> c;
        if(c == 'd')
        {
            cin >> c;
            cin >> c;
        }

        cin >> n;
        cin >> a;
        cin >> d;

        fraction f2 = fraction(n, d);

        if(c == '+')
            f1.add(f2);
        else if(c == '*')
            f1.mult(f2);
        else if(c == 'v')
            f1.div(f2);

        f1.display();
    }

    return 0;
}