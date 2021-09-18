#include <iostream>
#include <math.h>

using namespace std;

unsigned MaxElement(unsigned *a, unsigned n);
unsigned FindCountBetween(unsigned *a, unsigned n, unsigned left, unsigned right, bool includingLeft, bool includingRight);

int main()
{
    unsigned l, n, k, max, left, right, count;
    cin >> l >> n;

    unsigned *arr = new unsigned[n];

    for(int i = 0; i < n; i ++)
        cin >> arr[i];

    max = MaxElement(arr, n);

    if (l == 0 || max == 0)
        return 0;

    k = ceil((float)max/l);

    for(int i = 0; i < l; i++)
    {
        left = i * k;
        right = (i + 1) * k;

        if (i == l-1)
            count = FindCountBetween(arr, n, left, right, true, (max % l == 0));
        else 
            count = FindCountBetween(arr, n, left, right, true, false);

        cout << left << ": " << count << endl;
    }

    delete[] arr;

    return 0;
}

unsigned MaxElement(unsigned *a, unsigned n)
{
    unsigned max = 0;
    if (n == 0)
        return max;
    
    max = a[0];

    for(int i = 0; i < n; i++)
        if(a[i] > max)
            max = a[i];

    return max;
}

unsigned FindCountBetween(unsigned *a, unsigned n, unsigned left, unsigned right, bool includingLeft, bool includingRight)
{
    unsigned count = 0;
    
    if(!includingLeft)
        left++;

    if(!includingRight)
        right--;

    for(int i = 0; i < n; i++)
    {
        if(a[i] >= left && a[i] <= right)
            count++;
    }

    return count;
}