#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual unsigned int occupancy() = 0;
    virtual void reset() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class FilteringBuffer, by extending Buffer
#include <vector>
#include <set>

using namespace std;

class FilteringBuffer: public Buffer {
    private:
        int defaultVal;
        vector<int> data;
        set<int> memory;
    public:
        FilteringBuffer(int defaultVal);
        void write(int v);
        int read();
        unsigned int occupancy();
        void reset();
};

#endif /* EX04_LIBRARY_H_ */
