#ifndef __fibonaccitrees__
#define __fibonaccitrees__

class FibonacciTree
{
public:
    FibonacciTree(unsigned int value);
    ~FibonacciTree();

    unsigned int size();   // Size of the tree
    unsigned int height(); // Height of the tree
    unsigned int leaves(); // Number of leaves/constants in the tree
    void traversePre();    // Print nodes in pre-order (prefix notation)

private:
    unsigned int value;
    FibonacciTree *left;
    FibonacciTree *right;
};

#endif
