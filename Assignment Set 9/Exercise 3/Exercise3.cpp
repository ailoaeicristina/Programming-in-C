#include <iostream>
#include <vector>

using namespace std;

bool checkIfPalindrome(vector<int> a);

int main()
{
    int x;
    vector<int> myVector;

    while (cin >> x)
        myVector.push_back(x);

    bool result = checkIfPalindrome(myVector);

    if (result)
        cout << "yes";
    else
        cout << "no";

    return 0;
}

bool checkIfPalindrome(vector<int> a)
{
    if (a.size() == 0 || a.size() == 1)
        return true;

    if (a.size() == 2)
        return a.front() == a.back();

    bool res = a.front() == a.back();
    a.erase(a.begin());
    a.pop_back();

    return res && checkIfPalindrome(a);
}