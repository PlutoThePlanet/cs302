#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include "Iqueue.h"

template<class ItemType>
class ArrayQueue : public IQueue<ItemType>{
private:
    static const int DEFAULT_CAPACITY = 50;
    ItemType items[DEFAULT_CAPACITY]; // Array of queue items
    int front; // Index to front of queue
    int back; // Index to back of queue
    int count; // Number of items currently in the queue
    int totalTime;
public:
    ArrayQueue();
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    int getTotal();
    void setTotal(int newTotal);
    ItemType peekFront() const;
    virtual ~ArrayQueue();
};

#include "arrayqueue.cpp"

#endif