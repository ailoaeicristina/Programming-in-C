#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vecA, vecB;
    char x;
    int y, i, j;

    while(cin >> x >> y)
    {
        if (x == 'a')
            vecA.push_back(y);
        else if (x == 'b')
            vecB.push_back(y);
        else
            break;
    }

    i = vecA.size();
    j = vecB.size();

    while(i > 0 || j > 0)
    {
        if(i > 0)
            cout << vecA[vecA.size() - i] << " ";

        if(j > 0)
            cout << vecB[vecB.size() - j] << " ";

        i--;
        j--;
    }

    return 0;
}