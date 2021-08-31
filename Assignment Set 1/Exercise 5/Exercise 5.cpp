#include <iostream>

using namespace std;

int main()
{
    int n;
    float x, sum = 0;

    cout << "Please insert a positive integer number" << endl;
    cin >> n;

    if(n < 0)
        cout << "The inserted number is negative" << endl;
    else
    {
        for(int i = 0; i < n; i++)
        {
            cout << "Please insert a number (" << n - i << " numbers left)" << endl;
            cin >> x;
            sum += x;
        }

        cout << "The sum is " << sum;
    }

    return 0;
}