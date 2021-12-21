#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of SensorBuffer's
SensorBuffer::SensorBuffer(unsigned int n)
{
    this->n = n;
    this->count = 0;
}

// Task 4(b).  Write a working implementation of write() and writeCount()
void SensorBuffer::write(int v)
{
    this->data.push_back(v);
    this->count++;
}

unsigned int SensorBuffer::writeCount()
{
    return this->count;
}

// Task 4(c).  Write a working implementation of read()
int SensorBuffer::read()
{
    if (writeCount() == 0)
        return 0;

    return this->data[writeCount() - 1];
}

// Task 4(d).  Write a working implementation of readAvg()
int SensorBuffer::readAvg()
{
    if (writeCount() == 0)
        return 0;

    int sum = 0;
    unsigned int times = (writeCount() < this->n) ? writeCount() : this->n;
    unsigned int sizeOfData = this->data.size();

    for (unsigned i = sizeOfData - 1; i > sizeOfData - times; i--)
        sum = sum + this->data[i];

    return sum / times;
}

// Do not modify
Buffer::~Buffer()
{
    // Empty destructor
}
