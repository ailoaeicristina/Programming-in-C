#include <iostream>

using namespace std;

int main()
{
    unsigned n;
    double sum = 0;
    cin >> n;

    double *u = new double[n];
    double *v = new double[n];

    for(int i = 0; i < n; i++)
        cin >> u[i];

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += u[i] * v[i];
    }

    cout << sum;

    delete[] u, v;

    return 0;
}