#include <iostream>

using namespace std;

int main()
{
    unsigned n, max = 0, *arr;
    bool firstOccurence = true;

    cin >> n;
    arr = new unsigned[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if(arr[i] > max)
            max = arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == max && firstOccurence)
        {
            cout << "*" << arr[i] << "* ";
            firstOccurence = false;
        }
        else
            cout << arr[i] << " ";
    }

    delete [] arr;

    return 0;
}