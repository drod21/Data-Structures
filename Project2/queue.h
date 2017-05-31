//
//  queue.h
//  Project2
//
//  Created by Derek Rodriguez on 5/30/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef queue_h
#define queue_h


template <class Type>

class DynQueue {

private:
    
    Type *array; // To be used as an array
    
    int iHead, // Head index
        iTail, // Tail index
        count, // Counter
        initialSize, // Initial size of the array
        arraySize; // Current size of the array
    
public:
    // Constructor
    DynQueue(int n = 15) {
        // Test values to set initial size
        if (n <= 0) {
            initialSize = 1;
        } else {
            initialSize = n;
        }
        // Allocate memory
        array = new T[initialSize];
    }
    
    // Destructor
    ~DynQueue() {
        if (!empty())
            delete array;
    }
    
    // Accessors
    
    Type front() const throw(std::underflow_error) {
        // Throw underflow error if queue is empty.
        if (empty())
            throw std::underflow_error("Queue is empty");
            
            // Return head element
            return array[iHead];
    }
    
    Type back() const throw(std::underflow_error) {
        // Throw underflow error if queue is empty.
        if (empty())
            throw std::underflow_error("Queue is empty");
            
            // Return tail element
            return array[iTail];
        
    }
    
    int size() const {
        
        return arraySize;
        
    }
    
    bool empty() const {
        return (arraySize == 0);
    }
    
    int capacity() const {
        
        return initialSize;
        
    }
    void display() {
        
        
    }
    
    // Mutators
    
    void enqueue(Type const &data) {
        T *a = nullptr;
        if (size() == capacity()) {
            initialSize = initialSize * 2;
            a = new T[initialSize];
            
        }
        
        //array[iHead];
    }
    
    
    Type dequeue() throw(std::underflow_error) {
        
    }
    
    void clear() {
        
    }
    
};


#endif /* queue_h */
