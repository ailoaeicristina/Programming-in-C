#include <iostream>
#include "ex01-library.h"
using namespace std;

// Task 1(a).  Implement this function
Complex **createMatrix(unsigned int m, unsigned int n, Complex c)
{
    Complex **myMatrix = new Complex *[m];

    for (unsigned i = 0; i < m; i++)
    {
        myMatrix[i] = new Complex[n];
        for (unsigned j = 0; j < n; j++)
        {
            myMatrix[i][j] = c;
        }
    }

    return myMatrix;
}

// Task 1(b).  Implement this function
void displayMatrix(Complex **A, unsigned int m, unsigned int n)
{
    for (unsigned i = 0; i < m; i++)
    {
        for (unsigned j = 0; j < n; j++)
        {
            cout << A[i][j].re;
            if (A[i][j].im >= 0)
                cout << "+";

            cout << A[i][j].im << "i";

            if (j != n - 1)
                cout << " ";
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
Complex **createIdentityMatrix(unsigned int n)
{
    Complex zero = {0, 0};
    Complex one = {1, 0};
    Complex **matrix = createMatrix(n, n, zero);

    for (unsigned i = 0; i < n; i++)
    {
        matrix[i][i] = one;
    }

    return matrix;
}

// Task 1(d).  Implement this function
void multMatrix(Complex **A, Complex **B, Complex **C,
                unsigned int m, unsigned int n, unsigned int p)
{
    for (unsigned i = 0; i < m; i++)
    {
        for (unsigned j = 0; j < p; j++)
        {
            C[i][j] = {0, 0};
            for (unsigned k = 0; k < n; k++)
            {
                C[i][j] = add(C[i][j], mult(A[i][k], B[k][j]));
            }
        }
    }
}

// Do not modify
Complex add(Complex c, Complex d)
{
    Complex result = {c.re + d.re, c.im + d.im};
    return result;
}

// Do not modify
Complex mult(Complex c, Complex d)
{
    Complex result;
    result.re = (c.re * d.re) - (c.im * d.im);
    result.im = (c.re * d.im) + (c.im * d.re);
    return result;
}

// Do not modify
void deleteMatrix(Complex **A, unsigned int nRows)
{
    for (unsigned int i = 0; i < nRows; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}
