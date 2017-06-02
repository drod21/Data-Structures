//
//  queue.h
//  Project2
//
//  Created by Derek Rodriguez on 5/30/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <string>
using namespace std;

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
    DynQueue(int n = 15) : arraySize(n), count(0), iHead(0), iTail(0) {
        // Test values to set initial size
        if (n <= 0) {
            initialSize = 1;
        } else {
            initialSize = n;
        }
        // Allocate memory
        array = new Type[initialSize];
    }
    // Copy Constructor
    DynQueue(const DynQueue &queue):initialSize(queue.initialSize),
    arraySize(queue.arraySize), count(queue.count),
    iHead(queue.iHead), iTail(queue.iTail) {
        
        array = new (nothrow) Type[initialSize];
        
        if (array != 0) {
            for (int i = 0; i < initialSize; i++) {
                array[i] = queue.array[i];
            }
        } else {
            cerr << "Cannot allocate memory";
            exit(1);
        }
    }
    // Destructor
    ~DynQueue() {
        if (!empty())
            delete[] array;
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
        
        return count;
        
    }
    
    bool empty() const {
        return (arraySize == 0);
    }
    
    int capacity() const {
        
        return arraySize;
        
    }
    void display() {
        cout << "Contents of the queue: " << endl;
        for (int i = count; i >= 0; i--) {
            cout << array[i] << endl;
        }
        cout << endl;
        
    }
    
    // Mutators
    
    void enqueue(Type const &data) {
        
        if (size() != capacity()) {
            array[iTail] = data;
            iTail = (iTail + 1) % arraySize;
            ++count;
        } else {
            arraySize = arraySize * 2;
            Type *a = new Type[arraySize];
            for(int i = 0; i <= count; i++){
                a[i] = array[i];
            }
            delete [] array;
            array = a;
            array[iTail] = data;
            iTail = (iTail + 1) % arraySize;
            ++count;
        }
        
    }
    
    
    Type dequeue() throw(std::underflow_error) {
        Type removed = array[iHead];
        if (empty()) {
            throw underflow_error("Queue is empty");
        }
        
        iHead = (iHead + 1) % arraySize;
        --count;
        return removed;
    }
    
    void clear() {
        
    }
    
    // Overload assignment operator
    DynQueue &operator=(const DynQueue &queue) {
        if (this != &queue) {
            arraySize = queue.arraySize;
            initialSize = queue.initialSize;
            iHead = queue.iHead;
            iTail = queue.iTail;
            count = queue.count;
            if (initialSize != queue.initialSize) {
                delete [] array;
                array = new(nothrow) Type[initialSize];
            }
            for (int i = 0; i < initialSize; i++) {
                array[i] = queue.array[i];
            }
        }
        return *this;
    }
    
    
};


#endif /* queue_h */
