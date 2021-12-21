#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Passenger *find(Passenger *q, unsigned int ticket)
{
    if (q == nullptr)
        return nullptr;

    if (q->ticket == ticket)
        return q;

    return find(q->next, ticket);
}

// Task 2(b).  Implement this function
Passenger *remove(Passenger *q, unsigned int ticket)
{
    if (q == nullptr)
        return nullptr;

    if (q->next == nullptr)
    {
        if (q->ticket == ticket)
            return nullptr;
        else
            return q;
    }

    Passenger *current = q;
    Passenger *prev = nullptr;

    while (current != nullptr)
    {
        if (current->ticket == ticket)
        {
            prev->next = current->next;
            break;
        }

        prev = current;
        current = current->next;
    }

    return q;
}

// Task 2(c).  Implement this function
Passenger *priority(Passenger *q)
{
    Passenger *newQueue = nullptr;
    Passenger *current = q;

    while(current != nullptr)
    {
        if(current->priority == true)
        {
            Passenger *p = new Passenger;
            p->name = current->name;
            p->ticket = current->ticket;
            p->priority = current->priority;
            p->next = nullptr;

            if(newQueue == nullptr)
                newQueue = p;
            else
            {
                Passenger *last = newQueue;

                while (last->next != nullptr)
                    last = last->next;

                last->next = p;
            }
        }

        current = current->next;
    }

    return newQueue;
}

// Do not modify
void displayQueue(Passenger *q)
{
    if (q == nullptr)
    {
        return;
    }
    cout << q->name << " - ticket: " << q->ticket;
    if (q->priority)
    {
        cout << " (priority)";
    }
    cout << endl;
    displayQueue(q->next);
}
