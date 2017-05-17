//
//  CyclicLinkedList.h
//  Project1
//
//  Created by Derek Rodriguez on 5/17/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef CyclicLinkedList_h
#define CyclicLinkedList_h

#include "SingleNode.h"

using namespace std;

typedef int ElemType;

class CyclicLinkedList {
    
    private:
    SingleNode *head;   // Pointer to the head of the list.
    SingleNode *tail;   // Pointer to the tail of the list.
    int n;  // Integer to store the size of the list.
    
    
    public:
    
    // Constructor
    CyclicLinkedList() {
        
        head = nullptr;
        tail = nullptr;
        n = 0;
        
    }
    
    int size() const {
        return n;
    }
    bool empty() const {
        //Return true if list is empty, false otherwise.
        if (head != nullptr) {
            return false;
        }
        
        return true;
    }
    
    ElemType front() const {
        // Retrieve the object stored in the node pointed to by the head pointer.
        // Throw underflow if list is empty.
        
        if (empty()) {
            
            throw underflow_error;
            
        }
        
        return head->nodeData;
        
    }
    
    ElemType back() const {
        
        if (empty()) {
            throw underflow_error;
        }
        
        return tail->nodeData;
    }
    
    // Returns head pointer
    SingleNode<ElemType> *head() const {
        return head;
    }
    
    // Returns tail pointer
    SingleNode<ElemType> *tail() const {
        return tail;
    }
    
    int count(ElemType const &) const {
        // Returns the number of nodes in the linked list,
        // storing a value equal to the argument.
    }
    
    void push_front(ElemType const &) {
        
        
    }
    
    void push_back(ElemType const &) {
        
    }
    
    ElemType pop_front() {
        
    }
    
    int erase(ElemType const &) {
        
        
    }

};


#endif /* CyclicLinkedList_h */
