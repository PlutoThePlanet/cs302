// Paige Mortensen
// cs 302
// hw 5 - binary search tree

#include <iostream>
#include <cstdlib> // random
#include <time.h>  // unique random
#include "linkedBSearchTree.h"
#define NUM_VALS 100


void generateData(int[]);
void insertIntoTree(int[], LinkedBSearchTree<int>*);
template<class ItemType>
void visit(ItemType& node);

int main(){
    int data[NUM_VALS];
    int height;
    LinkedBSearchTree<int>* tree = new LinkedBSearchTree<int>;
    
    srand(time(NULL));                     // unique, random data
    generateData(data);                    // Randomly generate 100 unique values in the range of [1-200]
    insertIntoTree(data, tree);            // and insert them into a binary search tree (BST)

    std::cout << "height: ";               // Print height
    tree->getHeight();
    std::cout << "\ninorder: ";            // and inorder,
    tree->inorderTraverse(visit);
    std::cout << "\npreorder: ";           // preorder,
    tree->preorderTraverse(visit);
    std::cout << "\npostorder: ";          // and postorder output of the BST
    tree->postorderTraverse(visit);

    return 0;
}

void generateData(int data[]){
    for(int i=0; i<NUM_VALS; i++){
        data[i] = (rand() % 200) + 1; // range from 1 - 200
    }
}

void insertIntoTree(int data[], LinkedBSearchTree<int>* tree){
    for(int i=0; i<NUM_VALS; i++){
        tree->add(data[i]);
    }
}

template<class ItemType>
void visit(ItemType& node){
    std::cout << node << ", ";
}

/*
Randomly generate 100 unique values in the range of [1-200]
and insert them into a binary search tree (BST). Print
height and inorder, preorder, and postoder output of the
BST tree. Deliver source code and a test file that shows
the result of printing height and inorder, preorder, and
postorder traversal.
*/