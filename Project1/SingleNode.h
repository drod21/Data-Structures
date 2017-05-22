
//
//  SingleNode.h
//  Project1
//
//  Created by Derek Rodriguez on 5/17/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef SingleNode_h
#define SingleNode_h
#include "CyclicLinkedList.h"
#include <iostream>
using namespace std;


template <class T>

class SingleNode {
    template <class Type> friend class CyclicLinkedList;
    
    // Public members. nodeData and *next are public because they'll be accessed in
    // CyclicLinkedList class as private members
    
public:
    T nodeData;
    SingleNode *next;
    
    // Constructor
    SingleNode(T const &data, SingleNode *n) {
        nodeData = data;
        next = n;
    }
    // Constructor for data only
    SingleNode(T const &data) {
        nodeData = data;
    }
    // Constructor with no paramaters
    SingleNode():nodeData(0),next(nullptr) {
    }
    // Accessors
    
    // Returns the data for the node.
    T getData() const {
        return nodeData;
    }
    
    // Returns a pointer to the next element.
    SingleNode *getNext() const {
        return next;
    }
    
    
};


#endif /* SingleNode_h */
