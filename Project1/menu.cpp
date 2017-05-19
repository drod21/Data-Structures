//
//  main.cpp
//  Project1
//
//  Created by Derek Rodriguez on 5/17/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#include <iostream>
#include "CyclicLinkedList.h"
#include "DoublyLinkedList.h"


int main() {
    
    char list_type, ch;
    
    int menu_number, count;
    
    double list_count,
    first_item,
    last_item,
    item_to_delete,
    item_to_add,
    instances_of_item;
    
    
    CyclicLinkedList<double> *singly_list;
    //DoublyLinkedList<double> doubly_list;
    
    cout << "Enter the type of linked list: \n"
    << "'s' for single, 'd' for double. " << endl;
    cin >> ch;
    
    if (isupper(ch)) {
        cout << "Enter a lowercase letter 's' or 'd'." << endl;
        cin >> ch;
    }
    
    
    if (ch == 's') {
        
        
        
        bool menu_exit = true;
        cout << "1. Create list" << endl;
        cout << "2. Count number of items" << endl;
        cout << "3. Retrieve first item" << endl;
        cout << "4. Retrieve last item" << endl;
        cout << "5. Count instances of an item"
        << endl;
        cout << "6. Push front" << endl;
        cout << "7. Push back" << endl;
        cout << "8. Pop front" << endl;
        cout << "9. Pop back" << endl;
        cout << "10. Delete instance(s) of an item" << endl;
        cout << "11. Print list" << endl;
        cout << "12. Exit" << endl;
        cin >> menu_number;
        while (1) {
            
            
        
        switch(menu_number) {
            case 1:
            cout << "Creating list..." << endl;
            singly_list = new CyclicLinkedList<double>();
            cout << "List created. Enter a new option." << endl;
            cin >> menu_number;
            break;
            case 2:
            cout << "The list has : " << singly_list->size() << " elements." << endl;
            cout << "Select a new option: " << endl;
            cin >> menu_number;
            break;
            case 3:
            if (singly_list->head() != NULL) {
            first_item = singly_list->front();
            cout << first_item << endl;
            } else {
                cout << "List is empty; make another selection." << endl;
                cin >> menu_number;
            }
            cout << "Select a new option: " << endl;
            cin >> menu_number;
            break;
            case 4:
            last_item = singly_list->back();
            cout << last_item << endl;
            cout << "Select a new option: " << endl;
            cin >> menu_number;
            break;
            case 5:
            cout << "Enter the item to find count of: ";
            cin >> instances_of_item;
            singly_list->count(instances_of_item);
            cout << "Select a new option: " << endl;
            cin >> menu_number;
            break;
            case 6:
            cout << "Enter value to add: ";
            cin >> item_to_add;
            singly_list->push_front(item_to_add);
            cout << "Item added " << item_to_add << " added." << endl;
            cout << "Select a new option: " << endl;
            cin >> menu_number;
            break;
            
            case 7:
            cout << "Enter value to add: ";
            cin >> item_to_add;
            singly_list->push_back(item_to_add);
            cout << "Item added " << item_to_add << " added." << endl;
            cout << "Select a new option: " << endl;
            cin >> menu_number;
            break;
            
            case 8:
            cout << "Make another selection: " << endl;
            cin >> menu_number;
            break;
            
            case 9:
            cout << "Make another selection: " << endl;
            cin >> menu_number;
            break;
            
            case 10:
            cout << "Make another selection: " << endl;
            cin >> menu_number;
            break;
            
            case 11:
            SingleNode<double> *p;
            cout << "Items in list: " << endl;
            for (p = singly_list->head(); p != singly_list->tail(); p = p->getNext()) {
                cout << p->getData() << endl;
            }
            cout << "Make another selection: " << endl;
            cin >> menu_number;
            break;
            
            case 12:
            menu_exit = false;
            break;
            default:
            cout << "Invalid selection. ";
            cout << "Make another selection: " << endl;
            cin >> menu_number;
        }
    }
    }
    if (ch == 'd') {
        
        cout << "1. Create list" << endl;
        cout << "2. Count number of items" << endl;
        cout << "3. Retrieve first item" << endl;
        cout << "4. Retrieve last item" << endl;
        cout << "5. Count instances of an item"
        << endl;
        cout << "6. Push front" << endl;
        cout << "7. Push back" << endl;
        cout << "8. Pop front" << endl;
        cout << "9. Pop back" << endl;
        cout << "10. Delete instance(s) of an item" << endl;
        cout << "11. Print list" << endl;
        cout << "12. Exit" << endl;
        cin >> menu_number;
        
        bool menu_exit = true;
        while (menu_exit) {
        
        switch(menu_number) {
            
            case 1:
            break;
            case 2:
            //doubly_list.count(list_count);
            break;
            case 3:
            //first_item = doubly_list.front();
            cout << first_item << endl;
            break;
            case 4:
           // last_item = doubly_list.back();
            cout << last_item << endl;
            break;
            case 5:
            cout << "Enter the item to find count of: ";
            cin >> instances_of_item;
            //doubly_list.count(instances_of_item);
            break;
            case 6:
            break;
            case 7:
            break;
            case 8:
            break;
            
            case 9:
            break;
            
            case 10:
            break;
            
            case 11:
            break;
            
            case 12:
            menu_exit = false;
            break;
            default: break;
        }
        
    }
    }
    
    
    return 0;
}
