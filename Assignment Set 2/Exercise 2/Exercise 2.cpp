#include <iostream>

using namespace std;

int main()
{
    unsigned n, i = 2;
    cin >> n;

    while(n != 1)
    {
        while(n % i == 0)
        {
            cout << i;
            n /= i;

            if(n != 1)
                cout << " * ";
        }
 
        i++;
    }

    cout << endl;
    return 0;
}