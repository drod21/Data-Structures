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
    
    SingleNode<double> *head;
    SingleNode<double> *tail = nullptr;
    
    CyclicLinkedList singly_list;
    //DoublyLinkedList<double> doubly_list;
    
    cout << "Enter the type of linked list: \n"
    << "'s' for single, 'd' for double. " << endl;
    cin >> ch;
    
    if (isupper(ch)) {
        cout << "Enter a lowercase letter 's' or 'd'." << endl;
        cin >> ch;
    }
    
    if (ch == 's') {
        
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
            tail = singly_list.tail();
            break;
            case 2:
            singly_list.size();
            break;
            case 3:
            first_item = singly_list.front();
            cout << first_item << endl;
            break;
            case 4:
            last_item = singly_list.back();
            cout << last_item << endl;
            break;
            case 5:
            cout << "Enter the item to find count of: ";
            cin >> instances_of_item;
            singly_list.count(instances_of_item);
            break;
            case 6:
            cout << "Enter value to add: ";
            cin >> item_to_add;
            singly_list.push_front(item_to_add);
            break;
            
            case 7:
            cout << "Enter value to add: ";
            cin >> item_to_add;
            singly_list.push_back(item_to_add);
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
            return 0;
            break;
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
            return 0;
            break;
            default: break;
        }
        
    }
    
    
    return 0;
}
