
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
        SingleNode<T> *temp = new SingleNode<T>;
        if (temp == NULL) {
            cout <<"List is empty" << endl;
            return;
        }
        while (p->next != nullptr) {
            temp = p;
            p = p->next;
            if (temp != nullptr) {
                delete temp;
            }
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
        if (temp->getData() == item_to_count) {
            count++;
        }

        while (temp->getNext() != q->next) {

            if (temp->getData() == item_to_count) {

                count++;

            }

            temp = temp->next;

        }

        return count;

    }

    // Creates new node at the beginning of the list
    void push_front(T const &item) {

        SingleNode<T> *newNode = new SingleNode<T>;

        newNode->nodeData = item;

        // If list is empty
        if (empty()) {
            //p = new SingleNode<T>();
            p = newNode;
            p->next = q;
            q= p;

        } else if (p->next == nullptr) {
            // If one item in list
            newNode->next = p;
            p = newNode;
            q->next = p;

        } else {
            // If more than one item in list
            newNode->next = p;
            p = newNode;
            q->next = p;

        }
        // Increase size
        n++;

    }

    // Creates a new node at the end of the list
    void push_back(T const &item) {

        SingleNode<T> *newNode = new SingleNode<T>;
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
                newNode->next = p;
                q = newNode;

        n++;

    }

    // Returns the data to be popped,
    // Deletes list head, adjust size
    T pop_front() {
        SingleNode<T> *temp = p->next;


        T deleted = temp->getData();

        // Only set list head to next pointer if
        // head is not only node
        if (temp->next != nullptr) {
            delete p;
            p = temp;
            q->next = p;
        } else {
            delete p;
            p = new SingleNode<T>();
        }

        n--;

        return deleted;

    }

    // Returns the data to be popped,
    // Deletes list head, adjust size
    T pop_back() {
        SingleNode<T> *temp = q;


        T deleted = temp->getData();

        // Only set list head to next pointer if
        // head is not only node
        if (temp->next != nullptr) {
            delete q;
            q = temp->next;

        }

        n--;

        return deleted;

    }

    // Function to print out the list
    void print_list() {
        SingleNode<T> *temp = p;
        if(p == nullptr){
            cout << "The list is empty" << endl;
        }
        else {
            do{
                cout << temp->nodeData << endl;
                temp = temp->next;
                }
                while(temp != q);
        }
        cout << q->nodeData << endl;
    }


    int erase(T const &item) {
        SingleNode<T> *temp1 = p;
        SingleNode<T> *temp2 = q;
        SingleNode<T> *previous;

        int count = 0;

        // List is empty
        if (temp1 == nullptr) {
            return count;
        } else if (temp1->nodeData == item) {
            // If item is at front of list and list has one element
            temp1 = temp1->next;
            delete p;
            p = temp1;
            count++;
            n--;
        } else if (temp2->nodeData == item) {
            // At end of list
            previous = p;
            while (previous->next != temp2) {
                previous = previous->next;
            }
            previous->next = temp2->next;
            delete temp2;
            q = previous;
            count++;
            n--;
        }

            SingleNode<T> *deleteItem;
            // Item is somewhere else in the list
            for (deleteItem = p, previous = nullptr; deleteItem != temp2 && deleteItem->nodeData != item; previous = deleteItem, deleteItem = deleteItem->next);

            previous->next = deleteItem->next;
            delete deleteItem;
            count++;
            n--;



        return count;

    }

};


#endif /* CyclicLinkedList_h */
