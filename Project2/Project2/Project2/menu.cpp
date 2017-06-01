//
//  main.cpp
//  Project2
//
//  Created by Derek Rodriguez on 5/30/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"

using namespace std;

int main() {
    
    typedef string Type;
    
    char ch;
    int menu_number = 0,
        size,
    capacity;
    
    Type top,
        removed,
        toAdd;
    
    DynStack<Type> stack(15);
    DynQueue<Type> queue;
    
    
    cout << "Please enter 's' for stack, 'q' for queue: ";
    cin >> ch;
    
    
    
    
    if (ch == 's') {
        while (menu_number != 8) {
            
            cout << "1. Return Capacity (items actually in the data structure) " << endl;
            cout << "2. Return Size of the data structure" << endl;
            cout << "3. View first item ('top' for Stack, 'front' for Queue)" << endl;
            cout << "4. Insert item ('push' for Stack, 'enqueue' for Queue)" << endl;
            cout << "5. Delete item ('pop' for Stack, 'dequeue' for Queue)" << endl;
            cout << "6. Display" << endl;
            cout << "7. Clear" << endl;
            
            cin >> menu_number;
        switch (menu_number) {
            
            case 1:
                size = stack.size();
                cout << "Capacity of the stack: " << size << endl;
                break;
            
            case 2:
                capacity = stack.capacity();
                cout << "Size of the data structure: " << capacity << endl;
                break;
            
            case 3:
                top = stack.top();
                cout << "First item of the stack: " << top << endl;
                break;
            
            case 4:
                cout << "Please enter an item to insert: ";
                cin.ignore();
                getline(cin, toAdd);
                stack.push(toAdd);
                break;
            
            case 5:
                removed = stack.pop();
                cout << "Item " << removed << " popped from the stack.";
                break;
            
            case 6:
                stack.display();
                break;
            
            case 7:
                stack.clear();
                break;
            
            default:
                cout << "Invalid selection, please make another selection: ";
                cin >> menu_number;
                cout << endl;
        }
        }
        
    } else if (ch == 'q') {
        while (menu_number != 8) {
            switch (menu_number) {
                
            case 1:
                
                break;
                
            case 2:
                
                break;
                
            case 3:
                
                break;
                
            case 4:
                
                break;
                
            case 5:
                
                break;
                
            case 6:
                
                break;
                
            case 7:
                
                break;
                
            default:
                cout << "Invalid selection, please make another selection: ";
                cin >> menu_number;
                cout << endl;
            }
        }
    }
    return 0;
}
