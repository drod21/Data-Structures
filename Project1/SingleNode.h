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
    
    private:
    T nodeData;
    SingleNode *next;
    
    // Constructor
    public:
    
    SingleNode(T const & data, SingleNode *p) {
        
        nodeData = data;
        next = p;
        
    }
    // Empty type constructor
    SingleNode<T>() {
        
    }
    // Accessors
    
    T getData() const {
        return nodeData;        // Returns the data for the node.
    }
    
    SingleNode *getNext() const {
        return next;            // Returns a pointer to the next element.
    }
    
    
};


#endif /* SingleNode_h */
