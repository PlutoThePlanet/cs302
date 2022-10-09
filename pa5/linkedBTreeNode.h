#ifndef LINKED_B_TREE_NODE_H
#define LINKED_B_TREE_NODE_H

template<class ItemType>
class LinkedBTreeNode{
private:
    ItemType item;
    LinkedBTreeNode<ItemType>* ptr_leftChild;
    LinkedBTreeNode<ItemType>* ptr_rightChild;
public:
    LinkedBTreeNode();
    LinkedBTreeNode(const ItemType& newData);
    LinkedBTreeNode(const ItemType& newData, LinkedBTreeNode<ItemType>* left, LinkedBTreeNode<ItemType>* right);
    void setItem(const ItemType& newData);
    ItemType getItem() const;
    bool isLeaf();
    LinkedBTreeNode<ItemType>* getLeftChildPtr() const;
    LinkedBTreeNode<ItemType>* getRightChildPtr() const;
    void setLeftChildPtr(LinkedBTreeNode<ItemType>* newLeftChildPtr);
    void setRightChildPtr(LinkedBTreeNode<ItemType>* newRightChildPtr);
};

#include "LinkedBTreeNode.cpp"
#endif