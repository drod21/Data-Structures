//
//  DoublyLinkedList.h
//  Project1
//
//  Created by Derek Rodriguez on 5/17/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

template <class T>

class DoublyLinkedList {
    
    public:

DoublyLinkedList() { //This constructor sets all member variables to 0 or nullptr,as appropriate.

}

~DoublyLinkedList() {
    
}


int size() const; //returns the number of items in the list.
bool empty() const; //Returns true if the list is empty, false otherwise.
T front() const; //Retrieves the object stored in the node pointed to by the head pointer. This function throws a underflow if the list is empty.
T back() const; //Retrieves the object stored in the node pointed to by the tail pointer. This function throws a underflow if the list is empty.
//DoubleNode<T> *head() const; //Returns the head pointer.
//DoubleNode<T> *tail() const; //Returns the tail pointer.
/*int count( Type const & ) const; Returns the number of nodes in the
linked list storing a value equal to the argument.
Mutators
void push front( Type const & ); Creates a new DoubleNode< Type >
storing the argument, the next pointer of which is set to the current head pointer.
The head pointer is set to this new node. If the list was originally empty, the
tail pointer is set to point to the new node.
void push back( Type const & ); Similar to push front, this places a
new node at the back of the list.
Type pop front(); Delete the node at the front of the linked list and, as
necessary, update the head and tail pointers. Return the object stored in the
node being popped. Throw an under
ow exception if the list is empty.
int erase( Type const & ); Delete the node(s) (from the front) in the
linked list that contains the element equal to the argument (use == to to test
                                                             for equality with the retrieved element). As necessary, update the head and
tail pointers and the next pointer of any other node within the list. Return the
number of nodes that were deleted.
    };*/
};

#endif /* DoublyLinkedList_h */
