/************************************************
Derek Rodriguez, Derek Caprio
COP 4530, Project 1
menu.cpp
*************************************************/

#include <string>
#include <iostream>
#include "CyclicLinkedList.h"
#include "DoublyLinkedList.h"
//#include "SingleNode.h"
//#include "SingleNode.h"

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
    
    CyclicLinkedList<T> *singly_list = nullptr;
    DoublyLinkedList<T> *doubly_list = nullptr;
    
    cout << "Enter the type of linked list: \n"
    << "'s' for single, 'd' for double. " << endl;
    cin >> ch;
    
    if (isupper(ch)) {
        cout << "Enter a lowercase letter 's' or 'd'." << endl;
        cin >> ch;
    }
    
    //cout << "Make another selection: " << endl;
    //cin >> menu_number;
    
    if (ch == 's') {
        
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
                    try {
                        first_item = singly_list->front();
                        cout << first_item << " is the first time in the list." << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 4:
                    try {
                        last_item = singly_list->back();
                        cout << last_item << " is the last time in the list." << endl;
                    }
                    catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
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
                    try {
                        cout << "Deleting front item.. " << endl;
                        item_to_delete = singly_list->pop_front();
                        if (item_to_delete != 0) {
                            cout << item_to_delete << " was removed." << endl;
                        }
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 9:
                    try {
                    cout << "Deleting back item.. " << endl;
                    item_to_delete = singly_list->pop_back();
                    cout << item_to_delete << " was removed." << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 10:
                    cout << "Enter item to delete: " << endl;
                    cin >> item_to_delete;
                    deleted_item_number = singly_list->erase(item_to_delete);
                    cout << item_to_delete << " was removed " << deleted_item_number << " times." << endl;
                    break;
                    
                case 11:;
                    singly_list->print_list();
                    break;
                    
                case 12:
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
                    try {
                        first_item = doubly_list->front();
                        cout << first_item << " is the first time in the list." << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 4:
                    try {
                        last_item = doubly_list->back();
                        cout << last_item << " is the last time in the list." << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
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
                    try {
                        cout << "Enter value to add: ";
                        cin >> item_to_add;
                        doubly_list->push_back(item_to_add);
                        cout << "Item added " << doubly_list->back() << " added." << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 8:
                    try {
                        cout << "Deleting front item.. " << endl;
                        item_to_delete = doubly_list->pop_front();
                        cout << item_to_delete << " was removed." << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 9:
                    try {
                        cout << "Deleting back item.. " << endl;
                        item_to_delete = doubly_list->pop_back();
                        cout << item_to_delete << " was removed." << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 10:
                    cout << "Enter item to delete: " << endl;
                    cin >> item_to_delete;
                    deleted_item_number = doubly_list->erase(item_to_delete);
                    cout << item_to_delete << " was removed " << deleted_item_number << " times."<< endl;
                    break;
                    
                case 11:;
                    
                    doubly_list->print_list();
                    break;
                    
                case 12:
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
