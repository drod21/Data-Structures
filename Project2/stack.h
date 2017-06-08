/***********************************************
 Derek Rodriguez, Derek Caprio
 COP4530 Project2
 stack.h
 ***********************************************/


#ifndef stack_h
#define stack_h

#include <string>
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
    DynStack(int n = 15):arraySize(n), count(-1)  {
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
    
    // peek at top element of stack
    T top() const throw(std::underflow_error) {
        // Throw underflow error if queue is empty.
        if (empty())
            throw underflow_error("Stack is empty");
            // Return top element
            return array[count];
    }
    
    // return number of elements in stack
    int size() const {
        return (count + 1);
    }
    
    // check if stack is empty
    bool empty() const {
        return count < 0;
    }
    
    // Return total capacity of stack
    int capacity() const {
        return arraySize;
    }
    
    // Print the contents of the stack
    void display() {
        cout << endl << "Contents of the stack: " << endl;
        for (int i = count; i >= 0; i--) {
            cout << array[i] << endl;
        }
        cout << endl;
    }
    
    // Mutators
    
    // push data to top of stack, resize if neccessary
    void push(T const &data) {
        
        if (size() == capacity()) {
            
            arraySize = arraySize * 2;
            T* a = new T[arraySize];
            
            for(int i = 0; i <= count; i++){
                a[i] = array[i];
            }
            
            delete [] array;
            array = a;
        }
        
        array[++count] = data;
        
    }
    
    // pop and return item on top of stack, resize if neccessary
    T pop() throw(std::underflow_error) {
        // if array is empty, throw underflpw error
        if(empty() == true) {
            throw std::underflow_error("Stack is empty");
        }
        // otherwise pop top item
        T popped = top();
        --count;
        
       	// resize array if neccessary
        if(count <= .25*arraySize && arraySize > initialSize) {
            arraySize = .5 * arraySize;
            T* resizedArray= new T[arraySize];
            
            for(int i = count; i >= 0; i--){
                resizedArray[i] = array[i];
            }
            
            T* temp = array;
            array = resizedArray;
            delete[] temp;
        }
        return popped;
        
    }
    
    // remove all elements and resize to initial size
    void clear(void) {
        delete[] array;
        array = new T[initialSize];
        count = 0;
        arraySize = initialSize;
    }
    
    // Overload assignment operator
    DynStack &operator=(const DynStack &stack) {
        if (this != &stack) {
            arraySize = stack.arraySize;
            initialSize = stack.initialSize;
            count = stack.count;
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
