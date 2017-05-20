
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
            DoubleNode<T>* i = h;
            if(i == nullptr){
                cout << "List is empty" << endl;
                return;
            }
            while(i->next != nullptr){
                i++;
                delete i->previous;
            }
            delete i;
        }

        // size function returns number of elements in the list
        int size(void) const{
         /*   int count = 0;
            DoubleNode<T>* i = h;
            if(i == nullptr){
                return count;
            }
            else if(i->next == nullptr){
                count = 1;
                return count;
            }
            count = 1;
            while(i->next != t){
                count++;
                i++;
            }
            return count;
        */
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
        if(h == nullptr){
            cout << "List is empty" << endl;
        }
        else{
            for (temp = h; temp != nullptr; temp = temp->next) {
                cout << temp->data << endl;
            }
        }
    }

        // erases any elements of list with data equal to the argument
        // returns number of nodes deleted
        int erase(T const& arg){

            DoubleNode<T> *temp1;
            DoubleNode<T> *temp2 = t;
            DoubleNode<T> *itemDelete;

            int count = 0;

            for (temp1 = h, itemDelete = nullptr; temp1 != nullptr && temp1->data != arg;
                 itemDelete = temp1, temp1 = temp1->next);

            // List is empty
            if (h == nullptr) {

                cout << "List is empty" << endl;
                return count;

            } else if (temp1 == nullptr) {
                return count;
            } else if (temp1->previous == nullptr) {
                // If item is at front of list
                h = h->next;
                count++;
                n--;
            } else if (temp2->data == arg) {
                // At end of list
                t = t->next;
                count++;
                n--;
            } else {
            for (temp1 = h; temp1 != nullptr && temp1->data != arg;
                 itemDelete = temp1, temp1 = temp1->next)
            ;
                temp1->previous->next = temp1->next;
                count++;
                n--;
            }
            if (DoublyLinkedList::count(arg) >= count) {

            DoublyLinkedList::erase(arg);
                count++;
            }
            delete temp1;
            return count;


           /* int count = 0;
            DoubleNode<T>* p = h;
            // if list is empty
            if(p == nullptr){
                return count;
            }
            // if list has 1 element
            else if(h->next == nullptr){
                if(p->data == arg){
                    count = 1;
                    n--;
                    delete p;
                    h = nullptr;
                    t = nullptr;
                }
                return count;
            }
            // if list has > 1 elements
            for(p = h; p != t; p = p->next){
                if(p->data == arg){
                    count++;
                    n--;
                    // if at end of list
                    if(p->next == nullptr){
                        t = p->previous;
                        delete p;
                    }
                    // if at beginning of list
                    else if(p->previous == nullptr){
                        h = p->next;
                        delete p;
                    }
                    // not at beginning or end of list
                    else{
                        DoubleNode<T>* temp = p->previous;
                        p->previous->next = p->next;
                        p->next->previous = temp;
                        delete p;
                    }
                }
            }
            return count; */
        }
};

#endif /* DoublyLinkedList_h */
