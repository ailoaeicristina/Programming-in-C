#include <iostream>
#include <set>

using namespace std;

int main()
{
    multiset<int> bag;
    string command;
    int x, y;

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
            y = bag.count(x);
            bag.erase(x);

            if(y > 1)
            {
                for(int i = 0; i < y; i++)
                    bag.insert(x);
            }
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