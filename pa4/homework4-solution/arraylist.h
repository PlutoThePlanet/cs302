#ifndef ARRAY_LIST
#define ARRAY_LIST

#include "list.h"

template<class ItemType>
class ArrayList : public ListInterface<ItemType>{
	static const int DEFAULT_CAPACITY = 100000; 
	ItemType items[DEFAULT_CAPACITY + 1]; 
    int itemCount; 
    int maxCount; 
public:
	ArrayList();
	ArrayList(const ArrayList<ItemType>& aList);
	bool isEmpty() const;
	int getLength() const;
	bool insert(int position, const ItemType& newEntry);
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const;
	ItemType replace(int position, const ItemType& newEntry);
};

#include "arraylist.cpp"
#endif