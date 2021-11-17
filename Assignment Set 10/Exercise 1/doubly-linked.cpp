#include <iostream>
#include "doubly-linked.h"

using namespace std;

void deallocateRecursively(Node *p);
void insertRecursively(int n, Node *&p, Node *last, Node *first);
unsigned sizeRecursively(Node *p);
void reverseRecursively(Node *&p, Node *last, Node *&first);
void mySwap(Node *p);
void printRecursively(Node *p);

// Constructor
List::List(void)
{
    this->first = nullptr;
}

// Destructor
List::~List(void)
{
    deallocateRecursively(this->first);
}

// Insert n in the list
void List::insert(int n)
{
    insertRecursively(n, first, first, first);
}

// Reverse the list
void List::reverse()
{
    if (first == nullptr)
        return;

    reverseRecursively(first->next , first, first);
}

// Print the list
void List::print()
{
    printRecursively(first);
}

// Helper methods
void deallocateRecursively(Node *p)
{
    if (p == nullptr)
        return;

    deallocateRecursively(p->next);
    delete p;
}

void insertRecursively(int n, Node *&p, Node *last, Node *first)
{
    // list is empty or we arrived at the end
    if (p == nullptr)
    {
        Node *newNode = new Node;
        newNode->val = n;
        newNode->next = nullptr;

        // if the list is empty
        if (sizeRecursively(first) == 0)
        {
            newNode->prev = nullptr;
        }
        else // we arrived at the end of the list
            newNode->prev = last;

        p = newNode;

        return;
    }

    insertRecursively(n, p->next, p, first);
}

unsigned sizeRecursively(Node *p)
{
    if (p == nullptr)
        return 0;

    return 1 + sizeRecursively(p->next);
}

void reverseRecursively(Node *&p, Node *last, Node *&first)
{
    if (p == nullptr)
    {
        mySwap(last);
        first = last;
        return;
    }

    reverseRecursively(p->next, p, first);
    
    mySwap(last);
}

void mySwap(Node *p)
{
    Node *aux;
    aux = p->prev;
    p->prev = p->next;
    p->next = aux;
}

void printRecursively(Node *p)
{
    if (p == nullptr)
    {
        cout << endl;
        return;
    }

    cout << p->val << " ";
    printRecursively(p->next);
}

int main(void)
{

    List l;
    int n;

    while (cin >> n)
    {
        l.insert(n);
    }

    // Print list as read from cin
    l.print();
    // Reverse the list and print it
    l.reverse();
    l.print();
    // Reverse again and print it
    l.reverse();
    l.print();

    return 0;
}
