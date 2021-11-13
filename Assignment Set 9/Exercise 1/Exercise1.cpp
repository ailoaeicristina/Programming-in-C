#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int> a);

int main()
{
    int x;
    vector<int> myVector;

    while(cin >> x)
        myVector.push_back(x);

    reverse(myVector);

    return 0;
}

void reverse(vector<int> a)
{
    if(a.size() == 0)
        cout << "";
    else if(a.size() == 1)
        cout << a.front() << " ";
    else
    {
        int firstElement = a.front();
        a.erase(a.begin());
        reverse(a);
        cout << firstElement << " ";
    }
}