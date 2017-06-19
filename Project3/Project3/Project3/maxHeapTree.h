//
//  maxHeapTree.h
//  Project3
//
//  Created by Derek Rodriguez on 6/14/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef maxHeapTree_h
#define maxHeapTree_h

#import "treeNode.h"

template <class HeapType>;

class MaxHeapTree {
    
private:
    
    TreeNode<HeapType> *root;
    
public:
    HeapType getMax() {
        return root->value;
    }
    
    // Returns the number of elements in the tree
    int getSize() {
        
    }
    // returns height of the tree
    int getHeight() {
        
    }
    
    // Returns true if empty, false otherwise
    bool empty() {
        return (parent == NULL);
    }
    
    // Returns number of leaves in the tree
    int leaves() {
        
    }
    
    // Prints the heap
    void print() {
        
    }
   
    // Mutators
    
    // Removes all elements in the tree
    void clear(){
    }
    // Inserts data in the tree
    void insert(HeapType data) {
    }
    
    // Removes data from the tree
    HeapType del(HeapType data){
    }


    
    
};


#endif /* maxHeapTree_h */
