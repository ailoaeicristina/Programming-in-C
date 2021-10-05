#include <iostream>

using namespace std;

typedef enum { wood, stone } material;

struct tile 
{
    int x, y;
    bool isWall;
    material type;
};

void Display(int x, int y, tile **playground, int n, int m);

int main()
{
    int n, m, x, y;
    char userCommand;

    cin >> n >> m;
    x = n/2;
    y = m/2;

    tile **playground = new tile*[n];
    for(int i = 0; i < n; i++)
        playground[i] = new tile[m];

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++)
        {
            playground[i][j].x = j;
            playground[i][j].y = i;

            playground[i][j].isWall = (j == 0 || i == (n - 1) || (i == 0 && j !=3) ||  j == (m - 1));

            if (playground[i][j].isWall)
                playground[i][j].type = stone;
            else
                playground[i][j].type = wood;
        }
    }

    Display(x, y, playground, n, m);

    while(cin >> userCommand)
    {
        if (userCommand == 'q')
            break;
        else if (userCommand == 'l' && playground[x][--y].isWall)
            y++;
        else if (userCommand == 'r' && playground[x][++y].isWall)
            y--;
        else if (userCommand == 'u' && playground[--x][y].isWall)
            x++;
        else if (userCommand == 'd' && playground[++x][y].isWall)
            x--;

        Display(x, y, playground, n, m);
    }

    for(int i = 0; i < n; i ++)
        delete[] playground[i];

    delete[] playground;
    
    return 0;
}

void Display(int x, int y, tile **playground, int n, int m)
{
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++)
        {
            if(i == x && j == y)
                cout << "O";
            else if (playground[i][j].isWall)
                cout << "*";
            else cout << " ";
        }

        cout << endl;
    }
}
