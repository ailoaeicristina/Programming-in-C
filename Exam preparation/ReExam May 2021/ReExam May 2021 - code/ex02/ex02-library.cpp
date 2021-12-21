#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Elem *reverse(Elem *list)
{
    Elem *current = list;
    Elem *previous = nullptr;
    Elem *next = nullptr;

    while(current != nullptr)
    {
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }

    return previous;
}

// Task 2(b).  Implement this function
Elem *concatenate(Elem *list1, Elem *list2)
{
    if (list1 == nullptr)
        return list2;

    if (list2 == nullptr)
        return list1;

    Elem *lastElemOfList1 = list1;
    while (lastElemOfList1->next != nullptr)
        lastElemOfList1 = lastElemOfList1->next;

    if (lastElemOfList1->value == list2->value)
    {
        lastElemOfList1->times += list2->times;
        lastElemOfList1->next = list2->next;
    }
    else
    {
        lastElemOfList1->next = list2;
    }

    return list1;
}

// Task 2(c).  Implement this function
int sum(Elem *list)
{
    int sum = 0;

    while (list != nullptr)
    {
        sum += list->value * list->times;
        list = list->next;
    }

    return sum;
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
