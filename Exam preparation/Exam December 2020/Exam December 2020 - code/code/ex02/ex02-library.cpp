#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
unsigned int length(Elem *list)
{
    if (list == nullptr)
        return 0;

    return list->times + length(list->next);
}

// Task 2(b).  Implement this function
Elem *append(Elem *list, int v)
{
    Elem *current = list;

    if (current == nullptr)
    {
        Elem *e = new Elem;
        e->value = v;
        e->times = 1;
        e->next = nullptr;
        
        return e;
    }

    while (current->next != nullptr)
        current = current->next;

    if (current->value == v)
        current->times++;
    else
    {
        Elem *e = new Elem;
        e->value = v;
        e->times = 1;
        e->next = nullptr;
        current->next = e;
    }

    return list;
}

// Task 2(c).  Implement this function
Elem *buildRLEList(int *data, unsigned int n)
{
    Elem *e = nullptr;

    for (unsigned i = 0; i < n; i++)
    {
        e = append(e, data[i]);
    }

    return e;
}

// Do not modify
void displayRLEList(Elem *list)
{
    if (list == nullptr)
    {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
