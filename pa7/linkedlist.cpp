template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0){}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
	itemCount = aList.itemCount;
	if(itemCount > 0){
		Node<ItemType>* newNodePtr = new Node<ItemType>();
		Node<ItemType>* oldListPtr = aList.headPtr;

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
int LinkedList<ItemType>::getItemCount() const{
	return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
	return itemCount == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getHead() const{
	return headPtr;
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const{
	// enforce precondition
	if((position >= 1) && (position <= itemCount)){
		// Count from the beginning of the chain
		Node<ItemType>* curPtr = headPtr;
		for (int skip = 1; skip < position; skip++){
			curPtr = curPtr->getNext();
		}
		return curPtr;
	}
	return nullptr;
} 

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
	if (ableToInsert){
		// Create a new node containing the new entry
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		// Attach a new node to chain
		if (newPosition == 1){
			// Insert new node at beginning of chain
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
			newNodePtr->setIndex(1); ////////////////////////////////////////////////////////////

		}else{
			// Find node that will be before new node
			Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
			// Insert new node after node to which prevPtr points
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
			newNodePtr->setIndex(newPosition); //////////////////////////////////////////////////

		}
		itemCount++; // Increase count of entries
		////////////////////////////////////////////////////////////
		Node<ItemType>* curPtr;
		curPtr->(newNodePtr->getNext());
		newPosition++;
		while(curPtr != nullptr){
			curPtr->setIndex(newPosition);
			newPosition++;
			curPtr->((curPtr*)->getNext);
		}
		///////////////////////////////////////////////////////////
	} 
	return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position){
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove){
		Node<ItemType>* ptrToDelete = nullptr;
		if (position == 1){
			// Remove the first node in the chain
			ptrToDelete = headPtr; // Save pointer to node 
			headPtr = headPtr->getNext();// save pointer to next node
			headPtr->setIndex(1); ////////////////////////////////////////////////////////////

		}else{
			// Find node that is before the one to remove
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			// Point to node to remove
			ptrToDelete = prevPtr->getNext();
			// Disconnect indicated node from chain by connecting the prior node with the one after
			prevPtr->setNext(ptrToDelete->getNext());
			(prevPtr->getNext)->setIndex(position); /////////////////////////////////////////

		}

		ptrToDelete->setNext(nullptr);
		delete ptrToDelete;
		ptrToDelete = nullptr;
		itemCount--; // Decrease count of entries

		////////////////////////////////////////////////////////////
		Node<ItemType>* curPtr;
		curPtr->((prevPtr->getNext())->getNext());
		position++;
		while(curPtr != nullptr){
			curPtr->setIndex(position);
			position++;
			curPtr->((curPtr*)->getNext())
		}
		///////////////////////////////////////////////////////////
	}
	return ableToRemove;

}

template<class ItemType>
void LinkedList<ItemType>::clear(){
	while(!isEmpty()){
		remove(1);
	}
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
	// enforce precondition
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet){
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();		
	} 
	throw "Item not found";
} 

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry){
	// enforce precondition
	bool ableToReplace = (position >= 1) && (position <= itemCount);
	if (ableToReplace){
		Node<ItemType>* nodePtr = getNodeAt(position);
		ItemType oldEntry = nodePtr->getItem();
		nodePtr->setItem(newEntry);	
		return oldEntry;	
	} 
	throw "Item not found";
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList(){
	clear();
} 
