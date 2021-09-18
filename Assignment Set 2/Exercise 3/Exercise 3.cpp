#include <iostream>

using namespace std;

double pi(int n);

int main()
{
    unsigned n;
    cin >> n;
    cout << pi(n);

    return 0;
}

double pi(int n)
{
    double pi = 0;

    for(int i = 0; i < n; i++)
    {
        pi += (i % 2 == 0) ? 1.0/(2*i+1) : (-1.0)/(2*i+1);
    }

    return 4*pi;
}