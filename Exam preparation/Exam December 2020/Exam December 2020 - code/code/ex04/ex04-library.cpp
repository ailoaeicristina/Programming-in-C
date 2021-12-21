#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of LimitedBuffer's
LimitedBuffer::LimitedBuffer(unsigned int capacity, int defaultVal)
{
    this->capacity = capacity;
    this->defaultVal = defaultVal;
}

// Task 4(b).  Write a working implementation of write() and occupancy()
void LimitedBuffer::write(int v)
{
    if (this->data.size() == this->capacity)
        return;

    this->data.push_back(v);
}

unsigned int LimitedBuffer::occupancy()
{
    return this->data.size();
}

// Task 4(c).  Write a working implementation of read()
int LimitedBuffer::read()
{
    if (this->occupancy() == 0)
        return this->defaultVal;

    int first = this->data[0];
    this->data.erase(this->data.begin());

    return first;
}

// Do not modify
Buffer::~Buffer()
{
    // Empty destructor
}
