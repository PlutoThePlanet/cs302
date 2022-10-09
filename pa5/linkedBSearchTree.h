#ifndef LINKED_B_SEARCH_TREE_H
#define LINKED_B_SEARCH_TREE_H

#include "linkedBTreeNode.h"
//#include "linkedBTree.h"


template<class ItemType>
class LinkedBSearchTree/*: public LinkedBTree<ItemType>*/{
private:
    LinkedBTreeNode<ItemType>* ptr_root;
protected:
    LinkedBTreeNode<ItemType>* placeNode(LinkedBTreeNode<ItemType>* subTreePtr, LinkedBTreeNode<ItemType>* newNodePtr);
    //LinkedBTreeNode<ItemType>* removeValue(LinkedBTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful) override;
    //LinkedBTreeNode<ItemType>* removeNode(LinkedBTreeNode<ItemType>* nodePtr);
    //LinkedBTreeNode<ItemType>* removeLeftmostNode(LinkedBTreeNode<ItemType>* inorderSuccessor);
    //LinkedBTreeNode<ItemType>* findNode(LinkedBTreeNode<ItemType>* treePtr, const ItemType& target) const;
public:
    LinkedBSearchTree();
    bool isEmpty() const;
    int getHeight() const;
    int getHeightHelper(LinkedBTreeNode<ItemType>* subTreePtr) const; // may need to reorganize
    ItemType getEntry(const ItemType& anEntry) const;
    ItemType getRootData() const;
    bool add(const ItemType& newEntry);
    //int getNumberOfNodes() const;
    //bool remove(const ItemType& anEntry);
    //void clear() = 0;
    //bool contains(const ItemType& anEntry) const;
    
    void preorder(void visit(ItemType&), LinkedBTreeNode<ItemType>*) const;
    void inorder(void visit(ItemType&), LinkedBTreeNode<ItemType>*) const;
    void postorder(void visit(ItemType&), LinkedBTreeNode<ItemType>*) const;
    void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;

    // ~LinkedBSearchTree();
};

#include "linkedBSearchTree.cpp"
#endif