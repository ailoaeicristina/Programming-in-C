#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vecA, vecB;
    char x;
    int y, k, scalarProduct = 0;

    while(cin >> x >> y)
    {
        if (x == 'a')
            vecA.push_back(y);
        else if (x == 'b')
            vecB.push_back(y);
        else
            break;
    }

    k = min(vecA.size(), vecB.size());

    for(int i = 0; i < k; i++)
    {
        scalarProduct += vecA[i] * vecB[i];
    }

    cout << scalarProduct;

    return 0;
}