//
//  maxHeapTree.h
//  Project3
//
//  Created by Derek Rodriguez on 6/14/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef maxHeapTree_h
#define maxHeapTree_h

#include <cmath>	// for cieling, log2 and power functions

#import "treeNode.h"

template <class HeapType>;

class MaxHeapTree {
    
private:
    TreeNode<HeapType> *array;
    int size, capacity;
   
public:
    // constructor
    MaxHeapTree(int n){
	array = new HeapType[n];
	size = 0;
	capacity = n;
    }

    // destructor
    ~MaxHeapTree(void){
	delete [] array;
    }

    HeapType getMax() {
        return array[1]->getData;		// index 0 is empty
    }
    
    // Returns the number of elements in the tree
    int getSize() {
        return size;
    }
    // returns height of the tree
    int getHeight() {
	return ciel(log2(size));   
    }
    
    // Returns true if empty, false otherwise
    bool empty() {
        return (parent == NULL);
    }
    
    // Returns number of leaves in the tree
    int leaves() {
	return size - pow(2, (array->getHeight()-1)) + 1;
    }
    
    // Prints the heap
    void print() {
        for(int i = 1; i < size+1; i++){	// use 1 and size+1 because index 0 is empty
    		cout << array[i]->getData() << " ";
	}
    }
   
    // Mutators
    
    // Removes all elements in the tree
    void clear(){
	delete [] array;
	array = new TreeNode<HeapType>[15];	
    }
    // Inserts data in the tree
    void insert(HeapType data) {
    }
    
    // Removes data from the tree
    HeapType del(HeapType data){
    }
    
    
};


#endif /* maxHeapTree_h */
