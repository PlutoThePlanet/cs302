#ifndef NODE_H
#define NODE_H

template<class ItemType>
class Node{
    ItemType item;
    Node<ItemType>* next; // points to the next node
public: 
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
};

#include "node.cpp"
#endif