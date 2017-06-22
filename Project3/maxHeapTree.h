//
//  maxHeapTree.h
//  Project3
//
//  Created by Derek Rodriguez on 6/14/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef maxHeapTree_h
#define maxHeapTree_h

#include <cmath>	// for ceiling, log2 and power functions
#include <array>
//#import "treeNode.h"
#include "treeNode.h"
using namespace std;

template <class HeapType>

class MaxHeapTree {
    
private:
    //TreeNode<HeapType> *array;
    //TreeNode<HeapType> 
   // array<TreeNode, 15> myArray;
    int size, capacity;
    TreeNode<HeapType> myArray[];
    
public:
    // constructor
    MaxHeapTree(int n){
       /*
        myArray = new TreeNode<HeapType>[n];
        size = 0;
        capacity = n;
	*/
	capacity = n;
	size = 0;
	/*
	myArray[0].data = 0;
	myArray[0].key = 0;
	myArray[0].balanceFactor = 0;
	myArray[0].left = myArray[0].right = myArray[0].parent = nullptr;
	*/
    }
    
    // destructor
    ~MaxHeapTree(void){
        delete [] myArray;
    }
    
    HeapType getRoot() {
        return myArray[1].getData();		// index 0 is empty
    }
    
    // Returns the number of elements in the tree
    int getSize() {
        return size;
    }
    // returns height of the tree
    int getHeight() {
        return ceil(log2(size));
    }
    
    // Returns true if empty, false otherwise
    bool empty() {
        return (myArray == NULL);
    }
    
    // Returns number of leaves in the tree
    int leaves() {
        return size - pow(2, (getHeight()-1)) + 1;
    }
    
    // Prints the heap
    void print() {
        for(int i = 1; i <= size; i++){		// start at 1 because indez 0 is empty
            cout << myArray[i].getData() << " ";
        }
    }
    
    // Mutators
    
    // Removes all elements in the tree
    void clear(){
        delete [] myArray;
       // myArray = TreeNode<HeapType>[15];
	TreeNode<HeapType> myArray[15];
    }
    // Inserts data in the tree
    void insert(int key, HeapType data) {
        // if emty, insert at index 1
        if(size == 0){
            //myArray[1]->setKey(key);
	    //myArray[1]->key = key;
	    myArray[1].setKey(key);
            //myArray[1]->setData(data);
            //myArray[1]->data = data;
 	    myArray[1].setData(data);
	    size++;
            return;
        }
        // if heap is full, double the size
        if(size == capacity){
            capacity *= 2;
            TreeNode<HeapType> resizedArray[capacity];
            for(int i = 1; i <= size; i++){
                resizedArray[i] = myArray[i];
                
                //delete [] myArray;
                //myArray = resizedArray;
		/*
		myArray = resizedArray;
		delete [] resizedArray;
		*/
		//myArray = resizedArray;
		//delete [] resizedArray;
            }
	    for(int i = 0; i < capacity; i++){
		myArray[i] = resizedArray[i];
	    }
	
            
            // insert element at end of heap
            size++;
            myArray[size].setData(data);
            myArray[size].setKey(key);
            // compare key to parents key, bubble up if needed
            int currentIndex = size;
            int newIndex = ceil((currentIndex - 1) / 2);
            while(myArray[newIndex].getKey() > myArray[currentIndex].getKey()){
                TreeNode<HeapType> temp = myArray[currentIndex];
                myArray[currentIndex] = myArray[newIndex];
                myArray[currentIndex] = temp;
            }
        }
    }
    
        // Removes data from the tree
        HeapType delMax(void) {
            // if heap is empty
            if(size == 0){
                cout << "Error: The heap is empty" << endl;
            }
            // if only one element
            if(size == 1){
                size--;
                cout << "Removed " << myArray[1].getData() << " from heap." << endl;
                return myArray[1].getData();
            }
            // if 2 or more elements in heap remove root and shift all else
            // one position left in array
            size--;
            cout << "Removed " << myArray[1].getData() << " from heap." << endl;
            for(int i = size; i >= 1; i--){
                myArray[i] = myArray[i+1];
            }
            // if heap is 1/4 full, cut size in half
            if(size <= .25 * capacity){
                capacity /= 2;
                TreeNode<HeapType> resizedArray[capacity];
                for(int i = 1; i <= size+1; i++){
                    resizedArray[i] = myArray[i];
                }
				
               // delete [] myArray;
                //myArray = resizedArray;
		//TreeNode<HeapType> myArray = resizedArray;
		
		//myArray = resizedArray;
		//delete [] resizedArray;
		
		for(int i = 0; i < capacity; i++){
			myArray[i] = resizedArray[i];
		}
            }
            return myArray[1].getData();
        }
        
        
    };
    
    
#endif /* maxHeapTree_h */
