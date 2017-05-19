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


typedef double Type;

class DoublyLinkedList {
    // private data members
    private:
        DoubleNode<Type>* h;   // head
        DoubleNode<Type>* t;   // tail
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
            DoubleNode<Type>* i = h;
            if(i == NULL){
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
            if(h == nullptr){
                return true;
            }
            return false;
        }

        // returns data stored at head node
        Type front(void) const{
            if(empty() == true){
                throw underflow_error("Error: List is empty");
            }
            return h->data;
        }

        // returns data stored at tail node
        Type back() const {
            if(empty() == true){
                throw underflow_error("Error: List is empty");
            }
            return t->data;
        }

        // returns head pointer
        DoubleNode<Type> *head() const{
            return h;
        }
        // returns tail pointer
        DoubleNode<Type> *tail() const {
            return t;
        }

        // count function returns number of nodes with same data as argument
        int count(Type const& arg) const {
            int count = 0;
            DoubleNode<Type>* i = h;
            while(i != nullptr){
                if(arg == i->data){
                    count++;
                }
                i = i->next;
            }
            return count;
        }

        // push_front function creates new DoubleNode at the beginning of the list
        void push_front(Type const& d){
            DoubleNode<Type>* newNode = nullptr;
            newNode->data = d;
            if(h == nullptr){
                newNode->next = nullptr;
                newNode->previous = nullptr;
            }
            else{
            newNode->previous = nullptr;
            newNode->next = h;
            h = newNode;
            }
            n++;
        }

        // push_back function creates a new DoubleNode at the end of the list
        void push_back(Type const& d){
            DoubleNode<Type>* newNode = nullptr;
            newNode->data = d;
            if(h == nullptr){
                newNode->next = nullptr;
                newNode->previous = nullptr;
            }
            else{
                newNode->next = nullptr;
                newNode->previous = t;
                t = newNode;
            }
            n++;
        }

        // returns data stored in list head, deletes list head, adjusts head pointer, adjusts size
        Type pop_front(void){
            DoubleNode<Type>* node = h;
            Type item = h->getData();
            h = node->next;
            delete node;
            n--;
            return item;
        }

        // erases any elements of list with data equal to the argument
        // returns number of nodes deleted
        int erase(Type const& arg){
            int count = 0;
            DoubleNode<Type>* p = h;
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
            for(p = h; p != t; p++){
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
                        DoubleNode<Type>* temp = p->previous;
                        p->previous->next = p->next;
                        p->next->previous = temp;
                        delete p;
                    }
                }
            }
            return count;
        }
};

#endif /* DoublyLinkedList_h */
