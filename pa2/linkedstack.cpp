#include "linkedstack.h"
#include "node.h"

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : headPtr(nullptr), itemCount(0){}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack){
	itemCount = aStack.itemCount;
	if(itemCount > 0){
		Node<ItemType>* newNodePtr = new Node<ItemType>();
		Node<ItemType>* oldListPtr = aStack.headPtr;

		headPtr = newNodePtr;
		newNodePtr->setItem(oldListPtr->getItem());

		Node<ItemType>* newListPtr = nullptr;
		for(int pos = 2; pos <= itemCount; pos++){
			oldListPtr = oldListPtr->getNext();
			newListPtr = newNodePtr;
			
			newNodePtr = new Node<ItemType>();
			newListPtr->setNext(newNodePtr);
			newNodePtr->setItem(oldListPtr->getItem());
		}
	}
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const{
    //return headPtr == nullptr;
	return itemCount == 0;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry){ // add a new item onto the top of the stack
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	//newNodePtr->setNext(headPtr);
	headPtr = newNodePtr;
	newNodePtr = NULL;
	itemCount++;
	return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop(){ //remove an item from the top of the stack
	if(!isEmpty()){
		Node<ItemType>* delPtr = headPtr;
		headPtr = headPtr->getNext();
		delPtr->setNext(nullptr);
		delete delPtr;
		delPtr = nullptr;
		itemCount--;
	}
	return true;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const{ // return a copy of the item at the top of the stack
    bool canPeek = !isEmpty();
    if(canPeek){
		return headPtr->getItem();
    }else{
        throw "empty stack";
    }
}


// deleting
template<class ItemType>
void LinkedStack<ItemType>::remove(int position){
	Node<ItemType>* ptrToDelete = nullptr;
	
	ptrToDelete = headPtr; // Save pointer to node 
	headPtr = headPtr->getNext();// save pointer to next node
	
	ptrToDelete->setNext(nullptr);
	delete ptrToDelete;
	ptrToDelete = nullptr;
	itemCount--; // Decrease count of entries
}

template<class ItemType>
void LinkedStack<ItemType>::clear(){
	while(!isEmpty()){
		remove(1);
	}
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack(){
    clear();
}