
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

template <class T>

class CyclicLinkedList {
    
private:
    SingleNode<T> *p;   // Pointer to the head of the list.
    SingleNode<T> *q;   // Pointer to the tail of the list.
    int n;  // Integer to store the size of the list.
    
    
public:
    
    // Constructor, sets member values to 0 or nullptr
    CyclicLinkedList() {
        
        p = nullptr;
        q = nullptr;
        n = 0;
    }
    
    // Destructor
    ~CyclicLinkedList() {
        while (!empty()) {
            pop_front();
        }
    }
    
    // Return size of list
    int size() const {
        return n;
    }
    
    
    //Return true if list is empty, false otherwise.
    bool empty() const {
        
        if (p != nullptr) {
            return false;
        }
        
        return true;
    }
    
    // Retrieve the object stored in the node pointed to by the head pointer.
    // Throw underflow if list is empty.
    T front() const {
        
        if (empty()) {
            throw underflow_error("Empty list");
        }
        
        return p->nodeData;
        
    }
    
    // Return data stored at last node, throw underflow if empty.
    T back() const {
        
        if (empty()) {
            throw underflow_error("Empty list");
        }
        
        return q->nodeData;
    }
    
    // Returns head pointer
    SingleNode<T> *head() const {
        if (empty()) {
            throw underflow_error("Empty list");
        }
        return p;
    }
    
    // Returns tail pointer
    SingleNode<T> *tail() const {
        return q;
    }
    
    int count(T const & item_to_count) const {
        // Returns the number of nodes in the linked list,
        // storing a value equal to the argument.
        SingleNode<T> *temp = p;
        int count = 0;

        do {
            if (temp->nodeData == item_to_count) {
                count++;
            }
            temp = temp->next;
        } while (temp != p);
        return count;
    }
    
    // Creates new node at the beginning of the list
    void push_front(T const &item) {
        
        SingleNode<T> *newNode = new SingleNode<T>();
        newNode->nodeData = item;

        // If list not empty, set newNode->next to point to p
        if (p != nullptr) {
            newNode->next = p;
        }
        // Set p to newNode
        p = newNode;
        if (q == nullptr) {
            q = p;
        }
        // Make it circular
        q->next = p;
        // Increase size
        n++;
        
    }
    
    
    // Creates a new node at the end of the list
    void push_back(T const &item) {
        
        SingleNode<T> *newNode = new SingleNode<T>;
        SingleNode<T> *temp = nullptr;
        newNode->nodeData = item;
        newNode->next = p;
        
        // List is empty
        if (p == nullptr) {
            cout << "Can't add to end of list, list is empty." << endl;
            return;
        }
        
        // List is not empty
        for (temp = p; temp != q; temp = temp->next)
            ;
        
        temp->next = newNode;
        q = newNode;
        
        n++;
        
    }
    
    // Returns the data to be popped,
    // Deletes list head, adjust size
    T pop_front() {
        // Set temp to the second node in the list
        SingleNode<T> *temp = p->next;
        T deleted = p->nodeData;
        
        p = p->next;
        q->next = p;
        delete temp;
        n--;
        
        return deleted;
        
    }
    
    // Returns the data to be popped,
    // Deletes list head, adjust size
    T pop_back() {
        SingleNode<T> *temp;
        SingleNode<T> *prev;
        
        T deleted = q->nodeData;
        
        // Loop to the end of the list
        for (temp = p, prev = nullptr; temp != q; prev = temp, temp = temp->next);
        
        prev->next = p;
        q = prev;
        delete temp;
        n--;
        
        return deleted;
        
    }
    
    // Function to print out the list
    void print_list() {
        SingleNode<T> *temp = p;
        if(p == nullptr) {
            cout << "The list is empty" << endl;
            return;
        } else if (p->next == nullptr) {
            cout << "Items in list: " << endl;
            cout << p->nodeData << endl;
        } else {
            cout << "Items in list: " << endl;
            do{
                cout << temp->nodeData << endl;
                temp = temp->next;
            }
            // Allows the loop to control the iteration, first loop executes and then it checks condition.
            while(temp != p);
        }
        cout  << endl;
    }
    
    
    int erase(T const &item) {
        
        SingleNode<T> *temp1 = p;
        SingleNode<T> *previous;
        
        int cNum = CyclicLinkedList<T>::count(item);
        int count = 0;
        
        while (count != cNum) {
            for (temp1 = p, previous = nullptr; temp1 != q && temp1->nodeData != item;
                 previous = temp1, temp1 = temp1->next);
            
            // List is empty
            if (temp1 == nullptr) {
                return count;
            } else if (previous == nullptr) {
                // If item is at front of list and list has one element
                p = p->next;
                q->next = p;
                count++;
                n--;
            } else if (q->nodeData == item) {
                
                pop_back();
                count++;
                
            } else {
                // Item is at end of list
                previous->next = temp1->next;
                count++;
                n--;
            }
            
        }
        return count;
    }
    
    
};


#endif /* CyclicLinkedList_h */
