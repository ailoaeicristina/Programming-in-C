#include <iostream>
#include <algorithm>
#include "fibonaccitrees.h"

using namespace std;

FibonacciTree::FibonacciTree(unsigned int value)
{
    if (value == 0 || value == 1)
    {
        this->value = 1;
        this->left = nullptr;
        this->right = nullptr;
        return;
    }

    this->left = new FibonacciTree(value - 1);
    this->right = new FibonacciTree(value - 2);

    this->value = this->left->value + this->right->value;
}

FibonacciTree::~FibonacciTree()
{
    if (this->left != nullptr)
        delete this->left;

    if (this->right != nullptr)
        delete this->right;
}

unsigned int FibonacciTree::size()
{
    if (this->left == nullptr && this->right == nullptr)
        return 1;

    return 1 + this->left->size() + this->right->size();
}

unsigned int FibonacciTree::height()
{
    if (this->left == nullptr && this->right == nullptr)
        return 1;

    return 1 + max(this->left->height(), this->right->height());
}

unsigned int FibonacciTree::leaves()
{
    if (this->left == nullptr && this->right == nullptr)
        return 1;

    return this->left->leaves() + this->right->leaves();
}

void FibonacciTree::traversePre()
{
    cout << this->value << " ";

    if (this->left != nullptr)
        this->left->traversePre();

    if (this->right != nullptr)
        this->right->traversePre();
}

int main()
{
    unsigned int n;
    cin >> n;

    FibonacciTree *ft = new FibonacciTree(n);

    cout << "Call tree in pre-order: ";
    ft->traversePre();
    cout << endl;

    cout << "Call tree size: " << ft->size() << endl;
    cout << "Call tree depth: " << ft->height() << endl;
    cout << "Call tree leafs: " << ft->leaves() << endl;

    delete ft;

    return 0;
}