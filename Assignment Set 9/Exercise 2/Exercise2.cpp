#include <iostream>

using namespace std;

unsigned fibonacci(unsigned n);

int main()
{
    unsigned n;

    while(cin >> n)
    {
        cout << fibonacci(n) << " ";
    }

    return 0;
}

unsigned fibonacci(unsigned n)
{
    if(n == 0 || n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}