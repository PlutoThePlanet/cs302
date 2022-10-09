#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "linkedlist.h"

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
    if(length == 0){
        return true;
    }else{
        return false;
    }
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const{
    return length;
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int pos) const{
    if((pos>=1) && (pos<=length)){
        Node<ItemType>* nodePtr = getNodeAt(pos); //from the node class
        return nodePtr->getItem(); // -> used for pointers
    }else{
        std::cout << "invalid location" << std::endl;
        return NULL; // throw an error?
    }
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int pos) const{
    if((pos>=1) && (pos<=length)){
        Node<ItemType>* curPtr = headPtr;
        for (int i=1; i<pos; i++){
            curPtr = curPtr->getNext();
        }
        return curPtr;
    }
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPos, const ItemType& newEntry){
    bool ableToInsert = (newPos>=1) && (newPos<=length+1);
    if(ableToInsert){ // valid position
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);// Create a new node containing the new entry
        if (newPos == 1){// Insert new node at beginning of chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }else{
            Node<ItemType>* prevPtr = getNodeAt(newPos-1); // Find node that will be before new node
            newNodePtr->setNext(prevPtr->getNext());// Insert new node after node to which prevPtr points
            prevPtr->setNext(newNodePtr);
        }
        length++; // Increase count of entries
    }
    return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::replace(int pos, const ItemType& newEntry){
    if((pos>=1) && (pos<=length)){
        Node<ItemType>* curPtr = getNodeAt(pos); // finds the old item
        *curPtr = newEntry; // replaces the new item
        //delete &curPtr; 
        &curPtr = nullptr; // "clears" the temp pointer memory
        return true;
    }else{
        return false;
    }
}

template<class ItemType>
void LinkedList<ItemType>::clear(){
    while(!isEmpty()){
        remove(1);
    }
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int pos){
    bool ableToRemove = ((pos>=1) && (pos<=length));
    if(ableToRemove){
        Node<ItemType>* curPtr = nullptr;
        if (pos == 1){ // Remove the first node in the chain
            curPtr = headPtr;
            headPtr = headPtr->getNext();
        }else{ 
            Node<ItemType>* prevPtr = getNodeAt(pos-1);// Find node that is before the one to remove
            curPtr = prevPtr->getNext();// Point to node to remove
            prevPtr->setNext(curPtr->getNext());// remove old node from chain by changing prev. ptr to new item
        }
        curPtr->getNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
        length--;
    }
    return ableToRemove;
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList(){
    clear();
}

#endif