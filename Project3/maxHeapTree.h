/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 3
 maxHeapTree.h
 ************************************************************/

//include guard
#ifndef maxHeapTree_h
#define maxHeapTree_h

//libraries
#include <cmath>	// for ceiling, log2 and power functions
#include <array>
#include "treeNode.h"
using namespace std;

// macros
#define INITIAL_HEAP_SIZE 3

// class template
template <class HeapType>

// MaxHeapTree class
class MaxHeapTree {
    
private:
    // data members
    int capacity, size;
    TreeNode<HeapType> *myArray;
    
public:
    // constructor
    MaxHeapTree(int n){
        myArray = new TreeNode<HeapType>[n];
        capacity = n;
        size = 0;
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
            cout << "[" << myArray[i].data << "/" << myArray[i].key << "] ";
        }
        cout << endl;
    }
    
    // Mutators
    
    // Removes all elements in the tree
    void clear(){
        size = 0;
        capacity = INITIAL_HEAP_SIZE;
        for (int i = 0; i < capacity; i++){
            myArray[i].data = myArray[i].key = 0;
        }
        
    }
    
    // Inserts data in the tree
    void insert(const int key, const HeapType data) {
        TreeNode<HeapType> node;
        node.data = data;
        node.key = key;
        int newSize = capacity * 2;
        
        // if heap is full, double the size
        if(size == capacity){
            
            TreeNode<HeapType> *resizedArray = new TreeNode<HeapType>[newSize];
            for(int i = 1; i <= size; i++) {
                resizedArray[i] = myArray[i];
            }
            
            delete [] myArray;
            myArray = new TreeNode<HeapType>[newSize];
            myArray = resizedArray;
            capacity = newSize;
            cout << " Heap capacity has been doubled " << endl;
        }
        // insert node at end of array
        size++;
        myArray[size] = node;
        // compare key to parents key, bubble up if needed
        int currentIndex = size;
        int newIndex = ceil((static_cast<double>(currentIndex) - 1) / 2);
        while(myArray[currentIndex].key > myArray[newIndex].key && currentIndex > 1){
            swapHeapNodes(currentIndex, newIndex);
            currentIndex = ceil((static_cast<double>(currentIndex) - 1) / 2);
            newIndex = ceil((static_cast<double>(newIndex) - 1) / 2);
            if (newIndex == 0) newIndex = newIndex + 1;
            if (currentIndex == 0) currentIndex = currentIndex + 1;
        }
    }
    
    // Removes data from the tree
    void delMax(void) {
        // Error if heap is empty
        if(size == 0){
            cout << "Error: The heap is empty" << endl;
            return;
        }
        // if only one element
        if(size == 1){
            size--;
            cout << "Removed " << myArray[1].data << " from heap." << endl;
            //return myArray[1].getData();
            return;
        }
        // if 2 or more elements in heap remove root and shift all else
        TreeNode<HeapType> temp;
        cout << "Removed " << myArray[1].data << " from heap." << endl;
        TreeNode<HeapType> tempArr[capacity];
        for(int i = 2; i < size+1; i++){
            tempArr[i-1] = myArray[i];
        }
        for(int i = 1; i < size; i++){
            myArray[i] = tempArr[i];
        }
        size--;
        // if heap is 1/4 full, cut size in half
        if(size <= .25 * capacity && capacity/2 > INITIAL_HEAP_SIZE){
            capacity /= 2;
            TreeNode<HeapType> resizedArray[capacity];
            for(int i = 1; i <= size; i++){
                resizedArray[i] = myArray[i];
            }
            for(int i = 1; i < capacity; i++){
                myArray[i] = resizedArray[i];
            }
        }
        cout << " Heap size halved " << endl;
    }
    
    // function to swap 2 heap nodes
    void swapHeapNodes(int a, int b) {
        TreeNode<HeapType> temp;
        temp = myArray[a];
        myArray[a] = myArray[b];
        myArray[b] = temp;
    } 
};

#endif // maxHeapTree_h 
