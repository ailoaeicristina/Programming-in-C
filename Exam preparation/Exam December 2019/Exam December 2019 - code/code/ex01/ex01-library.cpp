#include <iostream>
#include "ex01-library.h"

using namespace std;

// Exercise 1 (a) Implement this function
cell **createAndInitBoard(int n)
{
	cell **board = new cell *[n];

	for (unsigned i = 0; i < n; i++)
	{
		board[i] = new cell[n];
		for (unsigned j = 0; j < n; j++)
		{
			board[i][j].color = computeColor(i, j);

			if (i < 3 && board[i][j].color == dark)
				board[i][j].status = blackPiece;
			else if (i >= n-3 && board[i][j].color == dark)
				board[i][j].status = whitePiece;
			else
				board[i][j].status = emptyC;
		}
	}

	return board;
}

// Exercise 1 (b) Implement this function
cell **duplicateBoard(cell **A, int n)
{
	cell **B = new cell *[n];

	for (unsigned i = 0; i < n; i++)
	{
		B[i] = new cell[n];
		for (unsigned j = 0; j < n; j++)
			B[i][j] = A[i][j];
	}

	return B;
}

// Exercise 1 (c) Implement this function
bool moveRight(cell **A, int n, int r, int c)
{
	if (r < 0 || r >= n || c < 0 || c >= n)
		return false;

	if (A[r][c].status == emptyC)
		return false;

	if (A[r][c].status == whitePiece)
	{
		r--;
		c++;

		if (r < 0 || r >= n || c < 0 || c >= n || A[r][c].status != emptyC)
			return false;

		A[r][c].status = whitePiece;
		A[++r][--c].status = emptyC;
	}
	else
	{
		r++;
		c--;

		if (r < 0 || r >= n || c < 0 || c >= n || A[r][c].status != emptyC)
			return false;

		A[r][c].status = blackPiece;
		A[--r][++c].status = emptyC;
	}

	return true;
}

// Exercise 1 (d) Implement this function
bool moveLeft(cell **A, int n, int r, int c)
{
	if (r < 0 || r >= n || c < 0 || c >= n)
		return false;

	if (A[r][c].status == emptyC)
		return false;

	if (A[r][c].status == whitePiece)
	{
		r--;
		c--;

		if (r < 0 || r >= n || c < 0 || c >= n || A[r][c].status != emptyC)
			return false;

		A[r][c].status = whitePiece;
		A[++r][++c].status = emptyC;
	}
	else
	{
		r++;
		c++;

		if (r < 0 || r >= n || c < 0 || c >= n || A[r][c].status != emptyC)
			return false;

		A[r][c].status = blackPiece;
		A[--r][--c].status = emptyC;
	}

	return true;
}

// Do not modify
cellColor computeColor(int r, int c)
{
	if ((r % 2 == 0 && c % 2 == 0) || (r % 2 != 0 && c % 2 != 0))
	{
		return bright;
	}
	return dark;
}

// Do not modify
void printBoard(cell **A, int n)
{
	cout << ' ';
	for (int c = 0; c < n; c++)
	{
		cout << c;
	}
	cout << endl;
	for (int r = 0; r < n; r++)
	{
		cout << r;
		for (int c = 0; c < n; c++)
		{
			// Print ' ' or '#' if empty, or the piece color (W or B)
			switch (A[r][c].status)
			{
			case emptyC:
				cout << ((A[r][c].color == bright) ? ' ' : '#');
				break;
			case whitePiece:
				cout << "W";
				break;
			case blackPiece:
				cout << "B";
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}
