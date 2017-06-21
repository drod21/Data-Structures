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

#import "treeNode.h"

template <class HeapType>;

class MaxHeapTree {
    
private:
    TreeNode<HeapType> *array;
    int size, capacity;
    
public:
    // constructor
    MaxHeapTree(int n){
        array = new TreeNode[n];
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
        return ceil(log2(size));
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
        for(int i = 1; i <= size; i++){		// start at 1 because indez 0 is empty
            cout << array[i]->getData() << " ";
        }
    }
    
    // Mutators
    
    // Removes all elements in the tree
    void clear(){
        delete [] array;
        array = new TreeNode[15];
    }
    // Inserts data in the tree
    void insert(int key, HeapType data) {
        // if emty, insert at index 1
        if(size == 0){
            array[1]->setKey(key);
            array[1]->setData(data);
            size++;
            return;
        }
        // if heap is full, double the size
        if(size == capacity){
            capacity *= 2;
            TreeNode* resizedArray = new TreeNode[capacity];
            for(int i = 0; i <= size; i++){
                resizedArray[i] = array[i];
                ]
                delete [] array;
                array = resizedArray;
            }
            
            // insert element at end of heap
            size++;
            array[size]->setData(data);
            array[size]->setKey(key);
            // compare key to parents key, bubble up if needed
            int currentIndex = size;
            while(array[ceil((currentIndex - 1) / 2)]->getKey() > array[currentIndex]->getKey()){
                TreeNode<HeapType> temp = array[ceil((currentIndex-1)/2)];
                array[currentIndex] = array[ceil((currentIndex-1)/2)];
                array[currentIndex] = temp;
            }
        }
        
        // Removes data from the tree
        HeapType delMax(void){
            // if heap is empty
            if(size == 0){
                cout << "Error: The heap is empty" << endl;
            }
            // if only one element
            if(size == 1){
                size--;
                cout << "Removed " << array[1]->getData() << " from heap." << endl;
                return;
            }
            // if 2 or more elements in heap remove root and shift all else
            // one position left in array
            size--;
            cout << "Removed " << array[1]->getData() << " from heap." << endl;
            for(int i = size; i >= 1; i--){
                array[i] = array[i+1];
            }
            // if heap is 1/4 full, cut size in half
            if(size <= .25 * capacity){
                capacity /= 2;
                TreeNode* resizedArray = new TreeNode[capacity];
                for(int i = 0; i <= size; i++){
                    resizedArray[i] = array[i];
                }
                delete [] array;
                array = resizedArray;
            }
        }
        
        
    };
    
    
#endif /* maxHeapTree_h */
