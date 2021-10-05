#include <iostream>

using namespace std;

typedef enum { wood, stone } material;

struct tile 
{
    int x, y;
    bool isWall;
    material type;
};

#define NROWS 12
#define NCOLS 16

void Display(int x, int y, tile playground[NROWS][NCOLS]);

int main()
{
    tile playground[NROWS][NCOLS];
    int x = 5, y = 5;
    char userCommand;

    for(int i = 0; i < NROWS; i++) 
    {
        for(int j = 0; j < NCOLS; j++)
        {
            playground[i][j].x = j;
            playground[i][j].y = i;

            playground[i][j].isWall = (j == 0 || i == (NROWS - 1) || (i == 0 && j !=3) ||  j == (NCOLS - 1));

            if (playground[i][j].isWall)
                playground[i][j].type = stone;
            else
                playground[i][j].type = wood;
        }
    }

    Display(x, y, playground);

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

        Display(x, y, playground);
    }
    
    return 0;
}

void Display(int x, int y, tile playground[NROWS][NCOLS])
{
    for(int i = 0; i < NROWS; i++) 
    {
        for(int j = 0; j < NCOLS; j++)
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
