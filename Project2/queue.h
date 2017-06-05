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
        return (iHead == iTail);
    }
    
    int capacity() const {
        
        return arraySize;
        
    }
    void display() {
        int i;
        int cap = capacity();
        cout << "Contents of the queue: " << endl;
        for (i = iHead; i != iTail; i++) {
            cout << array[i % cap] << endl;
        }
        cout << endl;
    }
    
    // Mutators
    
    void enqueue(Type const &data) {

        if (size() == capacity()) {
            
            arraySize = arraySize * 2;
            Type *a = new Type[arraySize];
            
            for(int i = iHead; i <= iTail; i++){
                a[i] = array[i];
            }
            
            delete [] array;
            array = a;
            
        }
        
        array[iTail++] = data;
        if (iTail % arraySize != iHead) {
            iTail = iTail % capacity();
        }
        cout << iTail << endl;
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
        if(count <= .25 * arraySize && arraySize > initialSize) {
            arraySize = .5 * arraySize;
            Type* resizedArray= new Type[arraySize];
            
            for(int i = iHead; i <= iTail; i++){
                resizedArray[i] = array[i];
            }
            delete [] array;
            array = resizedArray;
        }

        return removed;
    }
    
    void clear() {
        delete[] array;
        array = new Type[initialSize];
        iHead = iTail = count = 0;
        arraySize = initialSize;
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
