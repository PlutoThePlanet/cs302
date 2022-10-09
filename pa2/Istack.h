#ifndef I_STACK
#define I_STACK

template<class ItemType>
class Istack{
public: 
    virtual bool isEmpty() const = 0;
    virtual bool push(const ItemType& newEntry) = 0;
    virtual bool pop() = 0;
    virtual ItemType peek() const = 0;
    virtual ~Istack(){}
};

#endif