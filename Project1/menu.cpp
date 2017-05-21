
//
//  main.cpp
//  Project1
//
//  Created by Derek Rodriguez on 5/17/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#include <string>
#include <iostream>
#include "CyclicLinkedList.h"
#include "DoublyLinkedList.h"

int main() {

    typedef double T;

    char ch;

    int menu_number = 0;

    T first_item,
    last_item,
    item_to_delete,
    item_to_add,
    instances_of_item;
    int size = 0, deleted_item_number;

    // Initialize to nullptrs
    CyclicLinkedList<T> *singly_list = nullptr;
    DoublyLinkedList<T> *doubly_list = nullptr;

    cout << "Enter the type of linked list: \n"
    << "'s' for single, 'd' for double. " << endl;
    cin >> ch;

    if (isupper(ch)) {
        cout << "Enter a lowercase letter 's' or 'd'." << endl;
        cin >> ch;
    }

    if (ch == 's') {
        // Menu until menu_number is 12
        while (menu_number != 12) {
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

            switch(menu_number) {

                case 1:
                cout << "Creating list..." << endl;
                singly_list = new CyclicLinkedList<T>;
                break;

                case 2:
                size = singly_list->size();
                cout << "The list has : " << size << " elements." << endl;
                break;

                case 3:
                if (singly_list->head() != NULL) {
                    first_item = singly_list->front();
                    cout << first_item << endl;
                } else {
                    cout << "List is empty." << endl;
                }
                break;

                case 4:
                last_item = singly_list->back();
                cout << last_item << endl;
                break;

                case 5:
                cout << "Enter the item to find count of: ";
                cin >> instances_of_item;
                cout << "Item appears " << singly_list->count(instances_of_item) << " times." << endl;
                break;

                case 6:
                cout << "Enter value to add: ";
                cin >> item_to_add;
                singly_list->push_front(item_to_add);
                cout << "Item " << singly_list->front() << " added." << endl;
                break;

                case 7:
                cout << "Enter value to add: ";
                cin >> item_to_add;
                singly_list->push_back(item_to_add);
                cout << "Item added " << singly_list->back() << " added." << endl;
                break;

                case 8:
                cout << "Deleting front item.. " << endl;
                item_to_delete = singly_list->pop_front();
                cout << item_to_delete << " was removed." << endl;
                break;

                case 9:
                cout << "Deleting back item.. " << endl;
                item_to_delete = singly_list->pop_back();
                cout << item_to_delete << " was removed." << endl;
                break;

                case 10:
                cout << "Enter item to delete: " << endl;
                cin >> item_to_delete;
                deleted_item_number = singly_list->erase(item_to_delete);
                cout << item_to_delete << " was removed " << deleted_item_number << " times." << endl;
                break;

                case 11:;
                cout << "Items in list: " << endl;
                singly_list->print_list();
                break;

                case 12:
                delete singly_list;
                return 0;
                break;
    
                default:
                cout << "Invalid selection. ";
                cout << "Make another selection: " << endl;
                cin >> menu_number;
            }
        }
    }

    if (ch == 'd') {
        // Menu until menu_number is 12
        while (menu_number != 12) {
            cout << "1. Create list" << endl;
            cout << "2. Count number of items" << endl;
            cout << "3. Retrieve first item" << endl;
            cout << "4. Retrieve last item" << endl;
            cout << "5. Count instances of an item" << endl;
            cout << "6. Push front" << endl;
            cout << "7. Push back" << endl;
            cout << "8. Pop front" << endl;
            cout << "9. Pop back" << endl;
            cout << "10. Delete instance(s) of an item" << endl;
            cout << "11. Print list" << endl;
            cout << "12. Exit" << endl;
            cin >> menu_number;

            switch(menu_number) {

                case 1:
                cout << "Creating list..." << endl;
                doubly_list = new DoublyLinkedList<T>();
                cout << "List created. " << endl;
                break;
                
                case 2:
                size = doubly_list->size();
                cout << "The list has : " << size << " elements." << endl;
                break;

                case 3:
                first_item = doubly_list->front();
                cout << first_item << endl;
                break;

                case 4:
                last_item = doubly_list->back();
                cout << last_item << endl;
                break;

                case 5:
                cout << "Enter the item to find count of: ";
                cin >> instances_of_item;
                cout << "Item appears " << doubly_list->count(instances_of_item) << " times." << endl;
                break;

                case 6:
                cout << "Enter value to add: ";
                cin >> item_to_add;
                doubly_list->push_front(item_to_add);
                cout << "Item added " << doubly_list->front() << " added." << endl;
                break;

                case 7:
                cout << "Enter value to add: ";
                cin >> item_to_add;
                doubly_list->push_back(item_to_add);
                cout << "Item added " << doubly_list->back() << " added." << endl;
                break;

                case 8:
                cout << "Deleting front item.. " << endl;
                item_to_delete = doubly_list->pop_front();
                cout << item_to_delete << " was removed." << endl;
                break;

                case 9:
                cout << "Deleting back item.. " << endl;
                item_to_delete = doubly_list->pop_back();
                cout << item_to_delete << " was removed." << endl;
                break;

                case 10:
                cout << "Enter item to delete: " << endl;
                cin >> item_to_delete;
                deleted_item_number = doubly_list->erase(item_to_delete);
                cout << item_to_delete << " was removed " << deleted_item_number << " times."<< endl;
                break;

                case 11:;
                cout << "Items in list: " << endl;
                doubly_list->print_list();
                break;

                case 12:
                delete doubly_list;
                return 0;
                break;

                default:
                cout << "Invalid selection. ";
                cout << "Make another selection: " << endl;
                cin >> menu_number;
            }
        }
    }


    return 0;
}
