#ifndef NODE
#define NODE

#include<string>

template<class ItemType>
class Node{
	ItemType item; // A data item
	Node<ItemType>* next; // Points to next node

	// attributes that make node a person 
	int index;
	std::string phoneNumber;
public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
	
	// additional functions
	int getIndex() const;
	void setIndex(int newIndex);
	std::string getPhoneNumber() const;
	void setPhoneNumber(std::string newNumber);
	
}; 

#include "node.cpp"
#endif