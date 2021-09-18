#include <iostream>

using namespace std;

int main()
{
    unsigned n;
    unsigned const sizeOfArray = 1000;
    unsigned *a = new unsigned[sizeOfArray];

    for(int i = 0; i < sizeOfArray; i++)
        a[i] = 0;

    while(cin >> n)
    {
        if(n <= 0 || n > sizeOfArray)
            return 0;
        else
            cout << a[n]++ << endl;
    }

    delete[] a;
    return 0;
}