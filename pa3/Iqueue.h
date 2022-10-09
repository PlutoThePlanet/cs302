#ifndef I_QUEUE
#define I_QUEUE

template<class ItemType>
class IQueue{
public:
    virtual bool isEmpty() const = 0;
    virtual bool enqueue(const ItemType& anEntry) = 0;
    virtual bool dequeue() = 0; //virtual ItemType dequeue() const 0;
};

#endif