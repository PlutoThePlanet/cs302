#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "I_list.h"
#include "node.h"

template<class ItemType>
class LinkedList{
    Node<ItemType>* headPtr;
    int length = 0;
    Node<ItemType>* getNodeAt(int position) const;
    /*
    Node<ItemType>* newNodePtr = new Node<ItemType>(); // create node pointer w/ new node
    Node<ItemType>* curPtr; // create pointer
    curPtr = headPtr; // set/save pointer
    headPtr = newNodePtr; // point pointer at node
    prevPtr->setNext(newNodePtr); // point node's next
    */
public: 
    ~LinkedList();
    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPos, const ItemType& newEntry);
    bool remove(int pos);
    void clear();
    ItemType getEntry(int pos) const;
    bool replace(int pos, const ItemType& newEntry);
    //Node<ItemType>* getNodeAt(int pos) const;
};

#include "linkedlist.cpp"
#endif