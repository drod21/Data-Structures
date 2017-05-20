
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
        /*SingleNode<T> *temp = new SingleNode<T>;
        // If the list is initially empty
        if (p == NULL) {
            cout <<"List is empty" << endl;
            return;
        }
        // Loop through till p->next is not null.
        while (p->next != nullptr) {
            temp = p;
            p = p->next;
            if (temp != nullptr) {
                delete temp;
            }
        }*/
        while (!empty()) {
            pop_front();
        }
    }

    // Return size of list
    int size() const {
        /*SingleNode<ElemType> *temp;
         int count = 0;
         temp = p;

         while (temp->next != q->next) {
         count++;
         }
         return count;*/

        return n;

    }


    bool empty() const {
        //Return true if list is empty, false otherwise.
        if (p != nullptr) {
            return false;
        }

        return true;
    }

    T front() const {
        // Retrieve the object stored in the node pointed to by the head pointer.
        // Throw underflow if list is empty.

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

        // Data is in first node
        if (temp->nodeData == item_to_count) {
            count++;
        }

        while (temp->next != q->next) {

            if (temp->nodeData == item_to_count) {

                count++;

            }

            temp = temp->next;

        }

        return count;

    }

    // Creates new node at the beginning of the list
    void push_front(T const &item) {

        SingleNode<T> *newNode = new SingleNode<T>(item, p);

        newNode->nodeData = item;

        // If list is empty
        if (empty()) {
            p = new SingleNode<T>(item, q);
            q = p;

        } else {
            // If more than one item in list
            
            p = newNode;
            q->next = p;

        }
        // Increase size
        n++;

    }

    // Creates a new node at the end of the list
    void push_back(T const &item) {

        SingleNode<T> *newNode = new SingleNode<T>(item, p);
        SingleNode<T> *temp = nullptr;
        newNode->nodeData = item;

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
            cout << p->nodeData << endl;
        } else {
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
        
        SingleNode<T> *temp1 = nullptr;
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
        delete temp1;
        return count;
    }


};


#endif /* CyclicLinkedList_h */
