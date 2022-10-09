template<class ItemType>
Node<ItemType>:: Node() : next(nullptr){}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr){}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr){} // end constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem){
	item = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr){
	next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const{
	return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const{
	return next;
}

template<class ItemType>
std::string Node<ItemType>::getPhoneNumber() const{
	return phoneNumber;
}

template<class ItemType>
void Node<ItemType>::setPhoneNumber(std::string newNumber){
	phoneNumber = newNumber;
}