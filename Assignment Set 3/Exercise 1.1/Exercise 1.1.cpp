#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> bag;
    string command;
    int x;

    while(cin >> command)
    {
        if (command == "add")
        {
            cin >> x;
            bag.insert(x);
        }
        else if (command == "del")
        {
            cin >> x;
            bag.erase(x);
        }
        else if (command == "qry")
        {
            cin >> x;
            cout << ((bag.find(x) != bag.end()) ? "T" : "F");
        }
        else
            return 0;
    }

    return 0;
}