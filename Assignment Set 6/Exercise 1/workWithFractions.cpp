#include <iostream>
#include "fraction.h"

using namespace std;

int main(void)
{
    int n, d;
    char c;

    while(!cin.fail())
    {
        cin >> n;
        cin.ignore();
        cin >> d;

        fraction f1 = fraction(n, d);

        cin.ignore();
        cin >> c;
        if(c == 'd')
        {
            cin >> c;
            cin >> c;
        }
        cin.ignore();

        cin >> n;
        cin.ignore();
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