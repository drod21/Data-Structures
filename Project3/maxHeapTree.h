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
#include "treeNode.h"
using namespace std;
#define INITIAL_HEAP_SIZE 15

template <class HeapType>

class MaxHeapTree {
    
private:
    //TreeNode<HeapType> *array;
    //TreeNode<HeapType>
    // array<TreeNode, 15> myArray;
    int capacity, size;
    TreeNode<HeapType> *myArray;
    
public:
    // constructor
    MaxHeapTree(int n){
        /*
         myArray = new TreeNode<HeapType>[n];
         size = 0;
         capacity = n;
         */
        myArray = new TreeNode<HeapType>[n];
        capacity = n;
        size = 0;
        //size++;
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
        //return (myArray == NULL);
        if(size == 0) return true;
        else return false;
    }
    
    // Returns number of leaves in the tree
    int leaves() {
        return size - pow(2, (getHeight()-1)) + 1;
    }
    
    // Prints the heap
    void print() {
        cout << "Heap [data/key]: ";
        for(int i = 1; i <= size; i++){		// start at 1 because index 0 is empty
            cout << "[" << myArray[i].getData() << "/" << myArray[i].getKey() << "] ";
        }
        cout << endl;
    }
    
    // Mutators
    
    // Removes all elements in the tree
    void clear(){
        // delete [] myArray;
        // myArray = TreeNode<HeapType>[15];
        //TreeNode<HeapType> myArray[INITIAL_HEAP_SIZE];
        
        size = 0;
        capacity = INITIAL_HEAP_SIZE;
        for (int i = 0; i < capacity; i++){
            myArray[i].data = myArray[i].key = 0;
        }
        
    }
    // Inserts data in the tree
    void insert(const int key, const HeapType data) {
        // if emty, insert at index 1
        /*
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
         */
        TreeNode<HeapType> node;
        node.data = data;
        node.key = key;
        size++;
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
            for(int i = 1; i < capacity; i++){
                myArray[i] = resizedArray[i];
            }
        }
        myArray[size] = node;
        // insert element at end of heap
        //size++;
        //myArray[size].setData(data);
        //myArray[size].setKey(key);
        
        //myArray[size+1].setData(data);
        //myArray[size+1].setKey(key);
        
        // compare key to parents key, bubble up if needed
        int currentIndex = size;
        cout << "key at current index " << myArray[currentIndex].key << endl;
        cout << "current index: " << currentIndex << endl;	// DEBUGGING
        int newIndex = ceil((static_cast<double>(currentIndex) - 1) / 2);
        
        cout << "key at new index " << myArray[newIndex].key << endl;
        cout << "parents index: " << newIndex << endl;	//DEBUGGING
        while(myArray[currentIndex].key > myArray[newIndex].key && currentIndex > 1){
            swapHeapNodes(currentIndex, newIndex);
            currentIndex = ceil((static_cast<double>(currentIndex) - 1) / 2);
            newIndex = ceil((static_cast<double>(newIndex) - 1) / 2);
            
            //TreeNode<HeapType> temp = myArray[currentIndex];
            //myArray[currentIndex] = myArray[newIndex];
            //myArray[newIndex] = temp;
            
            /*
             TreeNode<HeapType> temp;
             // temp = myArray[currentIndex]
             temp.data = myArray[currentIndex].data;
             temp.key = myArray[currentIndex].key;
             // myArray[currentIndex] = myArray[newIndex]
             myArray[currentIndex].data = myArray[newIndex].data;
             myArray[currentIndex].key = myArray[newIndex].key;
             //myArray[newIndex] = temp;
             myArray[newIndex].data = temp.data;
             myArray[newIndex].key = temp.key;
             */
            if (newIndex == 0) newIndex = newIndex + 1;
            if (currentIndex == 0) currentIndex = currentIndex + 1;
        }
        
    }
    
    // Removes data from the tree
    void delMax(void) {
        // if heap is empty
        if(size == 0){
            cout << "Error: The heap is empty" << endl;
            return;
        }
        // if only one element
        if(size == 1){
            size--;
            cout << "Removed " << myArray[1].getData() << " from heap." << endl;
            //return myArray[1].getData();
            return;
        }
        // if 2 or more elements in heap remove root and shift all else
        // one position left in array
        size--;
        // cout << "Removed " << myArray[1].getData() << " from heap." << endl;
        cout << "Removed " << myArray[1].getData() << " from heap." << endl;
        for(int i = size; i >= 1; i--){
            myArray[i] = myArray[i+1];
        }
        // if heap is 1/4 full, cut size in half
        if(size <= .25 * capacity && capacity/2 > INITIAL_HEAP_SIZE){
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
        //return myArray[1].getData();
        return;
    }
    
    // function to swap 2 heap nodes
    void swapHeapNodes(int a, int b) {
        TreeNode<HeapType> temp;
        temp = myArray[a];
        myArray[a] = myArray[b];
        myArray[b] = temp;
    }
    
    
};



#endif /* maxHeapTree_h */
