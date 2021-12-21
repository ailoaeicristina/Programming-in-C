#include <iostream>
#include <cstdlib>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int n)
{
    if (n < 2)
        return nullptr;

    Square **chessboard = new Square *[n];

    for (unsigned i = 0; i < n; i++)
    {
        chessboard[i] = new Square[n];
        for (unsigned j = 0; j < n; j++)
        {
            chessboard[i][j] = {none, nobody};
        }
    }

    return chessboard;
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c, unsigned int n)
{
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < n; j++)
        {
            if (c[i][j].piece == none)
                cout << "_";
            else if (c[i][j].piece == rook)
                cout << ((c[i][j].team == black) ? "R" : "r");
            else
                cout << ((c[i][j].team == black) ? "B" : "b");

            if (j != n - 1)
                cout << " ";
        }

        cout << endl;
    }
}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int n,
          int r1, int c1, int r2, int c2)
{
    if (n < 2)
        return false;

    if (c[r1][c1].piece == none)
        return false;

    if ((r1 == r2 && c1 == c2) || (c[r1][c1].team == c[r2][c2].team))
        return false;

    if (c[r1][c1].piece == rook && r1 != r2 && c1 != c2)
        return false;

    if (c[r1][c1].piece == bishop && (abs(r1 - c1) != abs(r2 - c2)))
        return false;

    c[r2][c2] = c[r1][c1];
    c[r1][c1] = {none, nobody};
    return true;
}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int n,
                int row, int col)
{
    if (n < 2)
        return false;

    if (c[row][col].piece == none)
        return false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == row || j == col) && c[i][j].piece == rook && c[i][j].team != c[row][col].team)
                return true;

            if (abs(i - j) == abs(row - col) && c[i][j].piece == bishop && c[i][j].team != c[row][col].team)
                return true;
        }
    }

    return false;
}

// Do not modify
void deleteChessboard(Square **c, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        delete[] c[i];
    }
    delete[] c;
}
