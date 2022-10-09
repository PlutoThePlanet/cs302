#ifndef LINKED_B_TREE_NODE_CPP
#define LINKED_B_TREE_NODE_CPP

#include "linkedBTreeNode.h"

template<class ItemType>
LinkedBTreeNode<ItemType>::LinkedBTreeNode() : item(0), ptr_leftChild(nullptr), ptr_rightChild(nullptr){}

template<class ItemType>
LinkedBTreeNode<ItemType>::LinkedBTreeNode(const ItemType& newData) : item(newData), ptr_leftChild(nullptr), ptr_rightChild(nullptr){}

template<class ItemType>
LinkedBTreeNode<ItemType>::LinkedBTreeNode(const ItemType& newData, LinkedBTreeNode<ItemType>* left, LinkedBTreeNode<ItemType>* right) : item(newData), ptr_leftChild(left), ptr_rightChild(right){}

template<class ItemType>
void LinkedBTreeNode<ItemType>::setItem(const ItemType& newData){
    item = newData;
}

template<class ItemType>
ItemType LinkedBTreeNode<ItemType>::getItem() const{
    return item;
}

template<class ItemType>
LinkedBTreeNode<ItemType>* LinkedBTreeNode<ItemType>::getLeftChildPtr() const{
    return ptr_leftChild;
}

template<class ItemType>
LinkedBTreeNode<ItemType>* LinkedBTreeNode<ItemType>::getRightChildPtr() const{
    return ptr_rightChild;
}

template<class ItemType>
void LinkedBTreeNode<ItemType>::setLeftChildPtr(LinkedBTreeNode<ItemType>* newLeftChildPtr){
    ptr_leftChild = newLeftChildPtr;
}

template<class ItemType>
void LinkedBTreeNode<ItemType>::setRightChildPtr(LinkedBTreeNode<ItemType>* newRightChildPtr){
    ptr_rightChild = newRightChildPtr;
}

template<class ItemType>
bool LinkedBTreeNode<ItemType>::isLeaf(){
    if((ptr_leftChild == nullptr) && (ptr_rightChild == nullptr)){
        return true;
    }else{
        return false;
    }
}

#endif