
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
        
        // List is empty
        if (p == nullptr) {
            return 0;
        }
        
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
        
        SingleNode<T> *newNode = new SingleNode<T>(item);
        
        
        // If list is empty, allocate memory for p
        if (empty()) {
            p = new SingleNode<T>(item);
            q = p;
            q->next = p;
        } else {
            newNode->next = p;
            // Set p to newNode
            p = newNode;
            // Make it circular
            q->next = p;
        }
        // Increase size
        n++;
        
    }
    
    
    // Creates a new node at the end of the list
    void push_back(T const &item) {
        
        SingleNode<T> *newNode = new SingleNode<T>(item);
        SingleNode<T> *temp = nullptr;

        // List is empty
        if (p == nullptr) {
            cout << "Can't add to end of list, list is empty." << endl;
            return;
        }
        
        // List is not empty
        for (temp = p; temp != q; temp = temp->next)
            ;
        temp->next = newNode;
        newNode->next = p;
        q = newNode;
        
        n++;
        
    }
    
    // Returns the data to be popped,
    // Deletes list head, adjust size
    T pop_front() {
        if (empty()) {
            cout << "List is empty, cannot remove first element." << endl;
            return NULL;
        }
        
        // Set temp to the first node in the list
        SingleNode<T> *temp = p;
        T deleted = p->nodeData;
        
        p = temp->next;
        q->next = p;
        // If only item in list
        if (p->next == q) {
            p = nullptr;
            q = nullptr;
        }
        delete temp;
        n--;
        
        return deleted;
        
    }
    
    // Returns the data to be popped,
    // Deletes list head, adjust size
    T pop_back() {
        
        if (empty()) {
            cout << "List is empty, cannot remove last element." << endl;
            return NULL;
        }
        
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
            }while(temp != p);
            // Allows the loop to control the iteration, first loop executes and then it checks condition.
        
        }
        cout  << endl;
    }
    
    
    int erase(T const &item) {
        
        SingleNode<T> *temp1 = new SingleNode<T>();
        SingleNode<T> *previous;
        
        int cNum = CyclicLinkedList<T>::count(item);
        int count = 0;
        
        if (cNum == 0) {
            cout << "No instances of item." << endl;
            return count;
        }
        
        while (count != cNum) {
            for (temp1 = p, previous = nullptr; temp1 != q && temp1->nodeData != item;
                 previous = temp1, temp1 = temp1->next);
            
            // List is empty
            if (temp1 == nullptr) {
                return count;
            } else if (previous == nullptr) {
                // If item is at front of list and list has one element
                pop_front();
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
