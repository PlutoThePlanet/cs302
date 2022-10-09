#ifndef LINKED_STACk
#define LINKED_STACk

#include "Istack.h"
#include "node.h"

template<class ItemType>
class LinkedStack : public Istack<ItemType>{
	Node<ItemType>* headPtr;
	int itemCount;
public:
	LinkedStack();
	LinkedStack(const LinkedStack<ItemType>& aStack);
	bool isEmpty() const;
    bool push(const ItemType& newEntry);
    bool pop();
    ItemType peek() const;
	void remove(int position);
	void clear();
    virtual ~LinkedStack();
};

#include "linkedstack.cpp"
#endif