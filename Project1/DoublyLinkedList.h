
//
//  DoublyLinkedList.h
//  Project1
//
//  Created by Derek Rodriguez on 5/17/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include <iostream>
#include "DoubleNode.h"

using namespace std;

template <class T>

class DoublyLinkedList {
    // private data members
    private:
    DoubleNode<T>* h;   // head
    DoubleNode<T>* t;   // tail
    int n;              // size

    public:
    // constructor sets member values to 0 or null as appropriate
    DoublyLinkedList() {
        h = nullptr;
        t = nullptr;
        n = 0;
    }
    // destructor, delete each node in list
    ~DoublyLinkedList() {
        while (!empty()) {
            pop_front();
        }
    }

    // size function returns number of elements in the list
    int size(void) const{
        return n;
    }

    // returns true if list is empty, else returns false
    bool empty(void) const{
    //Return true if list is empty, false otherwise.
        if (h != nullptr) {
            return false;
        }
        return true;
    }

    // returns data stored at head node
    T front(void) const{
        if(empty() == true){
            throw underflow_error("Error: List is empty");
        }
        return h->data;
    }

    // returns data stored at tail node
    T back() const {
        if(empty() == true){
            throw underflow_error("Error: List is empty");
        }
        return t->data;
    }

    // returns head pointer
    DoubleNode<T> *head() const{
        return h;
    }
    // returns tail pointer
    DoubleNode<T> *tail() const {
        return t;
    }

    // count function returns number of nodes with same data as argument
    int count(T const& arg) const {
        int count = 0;
        DoubleNode<T> *temp = h->next;
        // Data is in first node

        if (temp->previous->data == arg) {
            count++;
        }
        // Data is elsewhere
        while (temp != NULL) {
            if (temp->data == arg) {
                count++;
            }

            temp = temp->next;

        }

        return count;

    }

        // push_front function creates new DoubleNode at the beginning of the list
    void push_front(T const& d) {
        DoubleNode<T>* newNode = new DoubleNode<T>;
        newNode->data = d;
        // List is empty
        if (empty()) {
            h = new DoubleNode<T>;
            newNode->next = nullptr;
            newNode->previous = nullptr;
            h = newNode;
            t = h;
            // List is not empty
        } else {
            newNode->previous = nullptr;
            newNode->next = h;
            h = newNode;
            h->next->previous = h;
            t = h->next;
        }
        n++;
    }

        // push_back function creates a new DoubleNode at the end of the list
    void push_back(T const& d){
        DoubleNode<T>* newNode = new DoubleNode<T>();
        DoubleNode<T>* temp;

        newNode->data = d;
        // Insert to front of list if list is empty
        if(h == nullptr){
            h = new DoubleNode<T>();
            newNode->next = nullptr;
            newNode->previous = nullptr;
            h = newNode;
            cout << "List is empty, inserting at front.." << endl;
        } else {
            for (temp = h; temp->next != nullptr; temp = temp->next) ;
            
            newNode->next = nullptr;
            newNode->previous = temp;
            temp->next = newNode;
            t = temp->next;
            t->previous = temp;
        }
        n++;
    }

        // returns data stored in list head, deletes list head, adjusts head pointer, adjusts size
    T pop_front(void){
        DoubleNode<T>* node = h;
        T item = h->getData();
        h = node->next;
        
        delete node;
        
        n--;
        
        return item;
    }

    T pop_back() {
        DoubleNode<T> *temp = t;


        T deleted = temp->getData();

        // Only set list head to next pointer if
        // head is not only node
        if (temp->next != nullptr) {
            delete t;
            t = temp->next;

        }

        n--;

        return deleted;
    }


    // Function to print out the list
    void print_list() {
        DoubleNode<T> *temp;
        if (h == nullptr) {
            cout << "List is empty" << endl;
            return;
        } else {
            cout << "Items in list: " << endl;
            for (temp = h; temp != nullptr; temp = temp->next) {
                cout << temp->data << endl;
            }
        }
    }


        // Erases any elements of list with data equal to the argument
        // Returns number of nodes deleted
    int erase(T const& arg){
        
        DoubleNode<T> *temp1 = nullptr;
        int cNum = DoublyLinkedList<T>::count(arg);
        int count = 0;
        
        while (count != cNum) {
            
            for (temp1 = h; temp1 != nullptr && temp1->data != arg; temp1 = temp1->next)
            ;
            
            // List is empty
            if (temp1 == nullptr) {
                return count;
            } else if (temp1->previous == nullptr) {
                // If item is at front of list and list has one element
                pop_front();
                count++;
                n--;
            } else {
                // Item is elsewhere
                temp1->previous->next = temp1->next;
                count++;
                n--;
            }
            
        }
        // Free memory
        delete temp1;
        return count;
    }
};

#endif /* DoublyLinkedList_h */
