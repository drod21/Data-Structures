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
    int menu_number = 0;
    
    
    cout << "Please enter 's' for stack, 'q' for queue: ";
    cin >> ch;
    
    cin.ignore();
    
    cout << "1. Return Capacity (items actually in the data structure) " << endl;
    cout << "2. Return Size of the data structure" << endl;
    cout << "3. View first item ('top' for Stack, 'front' for Queue)" << endl;
    cout << "4. Insert item ('push' for Stack, 'enqueue' for Queue)" << endl;
    cout << "5. Delete item ('pop' for Stack, 'dequeue' for Queue)" << endl;
    cout << "6. Display" << endl;
    cout << "7. Clear" << endl;
    
    cin >> menu_number;
    
    if (ch == 's') {
    
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
        
    } else if (ch == 'q') {
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
    return 0;
}
