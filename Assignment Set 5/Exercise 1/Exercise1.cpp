#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(const vector<int> &vec);

int main()
{
    vector<int> vecA, vecB;
    char x;
    int y;
    bool previousIsA;

    while(cin >> x >> y)
    {
        if (x == 'a')
            vecA.push_back(y);
        else if (x == 'b')
            vecB.push_back(y);
        else
            break;
    }

    sort(vecA.begin(), vecA.end());
    sort(vecB.begin(), vecB.end());

    printVector(vecA);
    printVector(vecB);

    return 0;
}

void printVector(const vector<int> &vec)
{
    for(auto e : vec)
        cout << e << " ";
}