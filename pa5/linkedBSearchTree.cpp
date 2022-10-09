#ifndef LINKED_B_SEARCH_TREE_CPP
#define LINKED_B_SEARCH_TREE_CPP

#include <iostream>
#include "linkedBSearchTree.h"
#include "linkedBTreeNode.h"


template<class ItemType>
LinkedBSearchTree<ItemType>::LinkedBSearchTree() : ptr_root(nullptr){}

template<class ItemType>
bool LinkedBSearchTree<ItemType>::isEmpty() const{
    if(ptr_root == nullptr){
        return true;
    }else{
        return false;
    }
}

template<class ItemType>
int LinkedBSearchTree<ItemType>::getHeight() const{
    int height = getHeightHelper(ptr_root);
    std::cout << height;
    return height;
}

template<class ItemType>
int LinkedBSearchTree<ItemType>::getHeightHelper(LinkedBTreeNode<ItemType>* subTreePtr) const{
    if (subTreePtr == nullptr){
        return 0;
    }else{
        return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), 
                            getHeightHelper(subTreePtr->getRightChildPtr()));
    }
}

template<class ItemType>
ItemType LinkedBSearchTree<ItemType>::getRootData() const{
    return ptr_root->getItem();
}

template<class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::placeNode(LinkedBTreeNode<ItemType>* subTreePtr, LinkedBTreeNode<ItemType>* newNodePtr){
    if(subTreePtr == nullptr){
        return newNodePtr;
    }else if((subTreePtr->getItem()) > (newNodePtr->getItem())){
        LinkedBTreeNode<ItemType>* tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(tempPtr);
    }else{
        LinkedBTreeNode<ItemType>* tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}

template<class ItemType>
bool LinkedBSearchTree<ItemType>::add(const ItemType& newEntry){
    LinkedBTreeNode<ItemType>* newNodePtr = new LinkedBTreeNode<ItemType>(newEntry);
    ptr_root = placeNode(ptr_root, newNodePtr);
    return true;
}

template<class ItemType>
ItemType LinkedBSearchTree<ItemType>::getEntry(const ItemType& anEntry) const{
    anEntry.getItem();
}

template<class ItemType>
void LinkedBSearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const{
    preorder(visit, ptr_root);
}

template<class ItemType>
void LinkedBSearchTree<ItemType>::preorder(void visit(ItemType&), LinkedBTreeNode<ItemType>* treePtr) const{
    if (treePtr != nullptr){
        ItemType item = treePtr->getItem();
        visit(item);
        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
        
    }
}

template<class ItemType>
void LinkedBSearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const{
    inorder(visit, ptr_root);
}

template<class ItemType>
void LinkedBSearchTree<ItemType>::inorder(void visit(ItemType&), LinkedBTreeNode<ItemType>* treePtr) const{
    if (treePtr != nullptr){
        inorder(visit, treePtr->getLeftChildPtr());
        ItemType item = treePtr->getItem();
        visit(item);
        inorder(visit, treePtr->getRightChildPtr());
    }
}

template<class ItemType>
void LinkedBSearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const{
    postorder(visit, ptr_root);
}

template<class ItemType>
void LinkedBSearchTree<ItemType>::postorder(void visit(ItemType&), LinkedBTreeNode<ItemType>* treePtr) const{
    if (treePtr != nullptr){
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
        ItemType item = treePtr->getItem();
        visit(item);
    }
}

#endif