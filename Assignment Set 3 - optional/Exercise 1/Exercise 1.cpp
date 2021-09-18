#include <iostream>

using namespace std;

int main()
{
    unsigned n, x, y;
    cin >> n;

    if(n <= 1)
    {
        cout << "SORTED";
        return 0;
    }

    cin >> x;
    for(int i = 1; i < n; i++)
    {
        cin >> y;

        if(x > y)
        {
            cout << "UNSORTED";
            return 0;
        }

        x = y;
    }

    cout << "SORTED";

    return 0;
}