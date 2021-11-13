#include <iostream>
#include <algorithm>

using namespace std;

unsigned getDistance(string u, string v);

int main()
{
    string u, v;
    cin >> u >> v;

    cout << getDistance(u, v);

    return 0;
}

unsigned getDistance(string u, string v)
{
    if (u.size() == 0)
        return v.size();

    if (v.size() == 0)
        return u.size();

    unsigned d1 = getDistance(u.substr(1), v) + 1;
    unsigned d2 = getDistance(u, (v.substr(1))) + 1;
    unsigned d3 = getDistance(u.substr(1), v.substr(1)) + (u.at(0) == v.at(0) ? 0 : 1);

    return min(min(d1, d2), d3);
}