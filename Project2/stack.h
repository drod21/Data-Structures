//
//  stack.h
//  Project2
//
//  Created by Derek Rodriguez on 5/30/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef stack_h
#define stack_h


using namespace std;

template <class T>


class DynStack {
    
private:
    
    T *array; // To be used as an array
    
    int count, // Counter
        initialSize, // Initial size of the array
        arraySize; // Current size of the array
    
public:
    // Constructor
    DynStack(int n = 15):arraySize(0), count(0)  {
        // Test values to set initial size
        if (n <= 0) {
            initialSize = 1;
        } else {
            initialSize = n;
        }
        // Allocate memory
        array = new T[initialSize];
        
        
    }
    
    // Copy Constructor
    
    DynStack(const DynStack &stack):initialSize(stack.initialSize), arraySize(stack.arraySize), count(stack.count) {
        
        array = new (nothrow) T[initialSize];
        if (array != 0) {
            for (int i = 0; i < initialSize; i++) {
                array[i] = stack.array[i];
            }
        } else {
            cerr << "Cannot allocate memory";
            exit(1);
        }
        
    }
    
    // Destructor
    ~DynStack() {
        if (!empty()) {
            delete[] array;
        }
    }
    
    // Accessors
    
    T top() const throw(std::underflow_error) {
        // Throw underflow error if queue is empty.
        if (empty())
            throw underflow_error("Queue is empty");
            
            // Return head element
            return array[arraySize];
    }

    
    int size() const {
        
        return count;
        
    }
    
    bool empty() const {
        // Check if arraysize is empty
        return (arraySize == 0);
    }
    
    int capacity() const {
        // Return total capacity of stack
        return initialSize;
    }
    
    void display() {
        
        // Print the contents of the stack
        
        cout << endl << "Contents of the stack: " << endl;
        
        for (int i = arraySize; i >= 0; i--) {
            cout << array[i] << endl;
        }
        
        cout << endl;
        
        
    }
    
    // Mutators
    
    void push(T const &data) {
        T *a = nullptr;
        if (size() != capacity()) {
            
        } else {
            a = new T[initialSize * 2];
            a = array;
            delete [] array;
            array = a;
        }
        
        arraySize++;
        array[arraySize] = data;
        
        count++;
        
    }
    
    
    T pop() throw(std::underflow_error) {
        T popped = 0;
        
        return popped;
        
    }
    
    void clear() {
        
    }
    
    // Overload assignment operator
    DynStack &operator=(const DynStack &stack) {
        if (this != &stack) {
            arraySize = stack.arraySize;
            initialSize = stack.initialSize;
            if (initialSize != stack.initialSize) {
                delete [] array;
                array = new(nothrow) T[initialSize];
            }
            for (int i = 0; i < initialSize; i++) {
                array[i] = stack.array[i];
            }
        }
        return *this;
    }
    
};

#endif /* stack_h */
