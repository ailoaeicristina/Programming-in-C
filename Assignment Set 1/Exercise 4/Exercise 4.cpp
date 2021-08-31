#include <iostream>

using namespace std;

int main()
{
    double x, y, z;

    cout << "Please insert three numbers" << endl;
    cin >> x >> y >> z;

    int result = x + y - z;

    cout << x << " + " << y << " - " << z << " = " << result << endl;

    return 0;
}