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

#include <iostream>

using namespace std;
typedef double ElemType;


class CyclicLinkedList {
    
    private:
    SingleNode<ElemType> *p;   // Pointer to the head of the list.
    SingleNode<ElemType> *q;   // Pointer to the tail of the list.
    int n;  // Integer to store the size of the list.
    
    
    public:
    
    // Constructor
    CyclicLinkedList():p(nullptr), q(nullptr), n(0) {

    }
    
    int size() const {
        SingleNode<ElemType> *temp;
        int count = 0;
        temp = p;
        
        while (temp->next != q->next) {
            count++;
        }
        return count;
        
    }
    bool empty() const {
        //Return true if list is empty, false otherwise.
        if (p != nullptr) {
            return false;
        }
        
        return true;
    }
    
    ElemType front() const {
        // Retrieve the object stored in the node pointed to by the head pointer.
        // Throw underflow if list is empty.
        
        if (empty()) {
            
            throw underflow_error("Empty list");
            
        }
        
        return p->nodeData;
        
    }
    
    ElemType back() const {
        
        if (empty()) {
            throw underflow_error("Empty list");
        }
        
        return q->nodeData;
    }
    
    // Returns head pointer
    SingleNode<ElemType> *head() const {
        return p;
    }
    
    // Returns tail pointer
    SingleNode<ElemType> *tail() const {
        return q;
    }
    
    int count(ElemType const & item_to_count) const {
        // Returns the number of nodes in the linked list,
        // storing a value equal to the argument.
        SingleNode<ElemType> *temp;
        int count = 0;
        
        temp = p;
        
        while (temp->getNext() != q->next) {
            
            if (temp->getData() == item_to_count) {
                
                count++;
            
            }
            
            temp = temp->next;
            
        }
        
        return count;
        
    }
    
    void push_front(ElemType const &item) {
        
        SingleNode<ElemType> *newNode = nullptr;
        newNode->nodeData = item;
        newNode->next = p;
        p = newNode;
        
        
    }
    
    void push_back(ElemType const &item) {
        
        SingleNode<ElemType> *newNode = nullptr;
        newNode->nodeData = item;
        
        if (q != nullptr) {
            
            q->next = newNode;
            
        } else {
        
            q = newNode;
            
        }
        newNode->next = p;
        
    }
    
    ElemType pop_front() {
        SingleNode<ElemType> *temp = nullptr;
        temp = p;
        
        ElemType deleted = temp->getData();
        
        return deleted;
        
    }
    
    int erase(ElemType const &item) {
        SingleNode<ElemType> *temp1 = nullptr;
        SingleNode<ElemType> *temp2 = nullptr;
        
        int count = 0;
        
        if (p->nodeData == item) {
            temp1 = p->next;
            delete p;
            p = temp1;
            count++;
        }
            
            temp1 = head();
            while (temp1 != q->next && temp1->nodeData != item) {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            
            if (temp1->next == q && q->nodeData == item) {
                
                temp1->next = q->next;
                temp2->next = temp1;
                delete q;
                count++;
                
            } else if (temp1) {
                temp2->next = temp1->next;
                delete temp1;
                count++;
            }
        
        return count;
        
        }
    
};


#endif /* CyclicLinkedList_h */
