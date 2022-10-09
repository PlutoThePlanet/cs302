#ifndef PRIORITY_ARRAY_QUEUE
#define PRIORITY_ARRAY_QUEUE

#include "Iqueue.h"
#include "event.h"

template<class ItemType>
class PriorityArrayQueue : public IQueue<ItemType>{
private:
    static const int DEFAULT_CAPACITY = 50;
    ItemType items[DEFAULT_CAPACITY]; // Array of queue items
    int front; // Index to front of queue
    int back; // Index to back of queue
    int count; // Number of items currently in the queue
public:
    PriorityArrayQueue();
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
    virtual ~PriorityArrayQueue();
};

#include "priorityarrayqueue.cpp"

#endif