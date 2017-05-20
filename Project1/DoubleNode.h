
//
//  DoubleNode.h
//  Project1
//
//  Created by Derek Rodriguez on 5/17/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef DoubleNode_h
#define DoubleNode_h
#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

// template for data type
template <class T>

// DoubleNode class definition
class DoubleNode {
    // a DoublyLinkedList has a DoubleNode
    template <class Type> friend class DoublyLinkedList;
    // private data members
    private:
            T data;
            DoubleNode* next;
            DoubleNode* previous;
    public:
        // constructor. usage: DoubleNode(data, previous, next)
        DoubleNode(T const& d, DoubleNode* p, DoubleNode* n){
            data = d;
            previous = p;
            next = n;
        }
    // Empty constructor for type
    DoubleNode<T>() {

    }
        // destructor
    ~DoubleNode() {

    }
        // get data function returns data stored at node
        T getData(void) const {
            return data;
        }
        // getNext function returns pointer to next element
        DoubleNode* getNext(void) const {
            return next;
        }
        // getPrevious function returns pointer to previous element
        DoubleNode* getPrevious(void) const {
            return previous;
        }
};

#endif /* DoubleNode_h */

