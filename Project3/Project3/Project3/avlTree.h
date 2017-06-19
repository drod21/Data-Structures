//
//  avlTree.h
//  Project3
//
//  Created by Derek Rodriguez on 6/14/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef avlTree_h
#define avlTree_h

#include "treeNode.h"
using namespace std;

template <class AType>;

class AvlTree {
    
private:
    TreeNode <AType> *root;
    
public:
    
    // Constructor
    AvlTree() {
        
        
    }
    
    // Destructor
    ~AvlTree() {
        
    }
    
    AType getRoot() {
        return *parent;
    }
    
    // Returns the number of elements in the tree
    int getSize() {
        
    }
    // returns height of the tree
    int getHeight() {
        
    }
    // Returns height of the node in argument
    // (from the root)
    int getHeight(TreeNode <AType> *node) {
        
    }
    
    // Returns true if empty, false otherwise
    bool empty() {
        return (root == NULL);
    }
    
    // Returns number of leaves in the tree
    int leaves() {
        
    }
    
    // Returns the number of siblings
    // of the node in the argument
    int siblings(TreeNode <AType> *node) {
        
        
    }
    
    // Returns a pointer to a node that holds
    // the date in the argument
    TreeNode <AType> *find(AType data) {
        
    }
    // preorder traversal
    void preorder() {
    }
    // postorder traversal
    void postorder(){
    }
    //inorder traversal
    void inorder(){
    }
    // Mutators
    
    // Removes all elements in the tree
    void clear(){
    }
    // Inserts data in the tree
    void insert(AType data) {
    }
    
    // Removes data from the tree
    AType del(AType data){
    }

    
};


#endif /* avlTree_h */
