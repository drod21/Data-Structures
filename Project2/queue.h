/***********************************************
 Derek Rodriguez, Derek Caprio
 COP4530 Project2
 stack.h
 ***********************************************/


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
    DynQueue(int n = 15) : iHead(0), iTail(0), count(0),  arraySize(n) {
        // Test values to set initial size
        if (n <= 0) {
            initialSize = 1;
        } else {
            initialSize = n;
        }
        // Allocate memory
        array = new Type[initialSize];
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
        return (iHead == iTail);
    }
    
    int capacity() const {
        
        return arraySize;
        
    }
    void display() {
        int i = iHead;
        cout << "Contents of the queue: " << endl;
        
        bool atEnd = false;
        // while loop to end of queue
        while (!atEnd) {
            atEnd = i % arraySize == iTail;
            cout << array[i] << endl;
            i++;
        }
        cout << endl;
    }
    
    // Mutators
    
    void enqueue(Type const &data) {
        int newSize = arraySize * 2;
        
        // If list is full, resize
        if ((iTail + 1) % arraySize == iHead) {
            Type *a = new Type[newSize];
            if (a == nullptr) {
                cerr << "Memory allocation failed." << endl;
                exit(1);
            }
            
            for (int i = iHead; i != iTail; i = (i + 1) % arraySize) {
                a[i] = array[i];
            }
            
            delete [] array;
            array = a;
            arraySize = newSize;
            
        }
        array[iTail] = data;
        if ((iTail + 1) % arraySize != iHead) {
            iTail = (iTail + 1) % arraySize;
        } else {
            iTail++;
        }
        count++;
    }
    
    
    Type dequeue() throw(std::underflow_error) {
        Type removed;
        if (empty()) {
            throw underflow_error("Queue is empty");
        }
        
        removed = front();
        iHead = (iHead + 1) % arraySize;
        count--;
        
        // resize array if neccessary
        if (count <= .25 * arraySize && arraySize > initialSize) {
            
            int newSize = .5 * arraySize;
            Type* resizedArray= new Type[newSize];
            
            bool atEnd = false;
            int i = iHead, j = 0;
            
            // Loop through list and copy elements over
            while (!atEnd) {
                atEnd = i % arraySize == iTail;
                resizedArray[j] = array[i % arraySize];
                i++;
                j++;
            }
            
            delete [] array;
            array = resizedArray;
            arraySize = newSize;
            iHead = 0;
            iTail = count;
        }
        return removed;
    }
    
    void clear() {
        delete[] array;
        array = new Type[initialSize];
        iHead = iTail = count = 0;
        arraySize = initialSize;
    }
};


#endif /* queue_h */
