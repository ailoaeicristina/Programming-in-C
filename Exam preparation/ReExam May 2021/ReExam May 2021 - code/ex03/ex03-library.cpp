#include <iostream>
#include "ex03-library.h"
#include <algorithm>
using namespace std;

// Do not modify
GroceryList::GroceryList()
{
    this->items.push_back("Lasagne");
    this->itemsInfo["Lasagne"] = {1, "With eggs if available"};

    this->items.push_back("Salmon");
    this->itemsInfo["Salmon"] = {500, "Smoked if available"};

    this->items.push_back("Spinach");
    this->itemsInfo["Spinach"] = {300, "Fresh"};

    this->items.push_back("Dessert");
    this->itemsInfo["Dessert"] = {8, "Maybe lagkage?"};
}

// Task 3(a).  Implement this method
void GroceryList::add(string name, unsigned int quantity, string notes)
{
    map<string, Info>::iterator it = this->itemsInfo.find(name);

    if (it == this->itemsInfo.end())
    {
        this->items.push_back(name);
        this->itemsInfo.insert(pair<string, Info>(name, {quantity, notes}));
    }
    else
    {
        this->itemsInfo[name].quantity += quantity;
        this->itemsInfo[name].notes += ";" + notes;
    }
}

// Task 3(b).  Implement this method
bool GroceryList::remove(string name, unsigned int quantity)
{
    map<string, Info>::iterator it = this->itemsInfo.find(name);

    if (it == this->itemsInfo.end())
        return false;

    if (this->itemsInfo[name].quantity < quantity)
        return false;

    this->itemsInfo[name].quantity -= quantity;

    if (this->itemsInfo[name].quantity == 0)
    {
        this->itemsInfo.erase(name);
        this->items.erase(std::remove(this->items.begin(), this->items.end(), name), this->items.end());
    }

    return true;
}

// Task 3(c).  Implement this method
bool GroceryList::copyEntry(string name, string newName)
{
    if (find(this->items.begin(), this->items.end(), name) == this->items.end())
        return false;

    if (find(this->items.begin(), this->items.end(), newName) != this->items.end())
        return false;

    this->items.push_back(newName);

    map<string, Info>::iterator it = this->itemsInfo.find(name);

    if (it == this->itemsInfo.end())
        return false;

    this->itemsInfo.insert(pair<string, Info>(newName, this->itemsInfo[name]));

    return true;
}

// Do not modify
void GroceryList::display()
{
    // Write your code here
    for (auto it = this->items.begin(); it != this->items.end(); it++)
    {
        Info &item = this->itemsInfo[*it];
        cout << "name='" << *it << "'; ";
        cout << "quantity=" << item.quantity << "; ";
        cout << "notes='" << item.notes << "'" << endl;
    }
}