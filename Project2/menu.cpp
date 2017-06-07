/***********************************************
 Derek Rodriguez, Derek Caprio
 COP4530 Project2
 stack.h
 ***********************************************/


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
    
    // Default sizes of 15
    DynStack<Type> stack(15);
    DynQueue<Type> queue(15);
    
    cout << "Please enter 's' for stack, 'q' for queue: ";
    cin >> ch;

    if (ch == 's') {
        while (menu_number != 8) {
            
            cout << "1. Return Capacity" << endl;
            cout << "2. Return Size of the data structure" << endl;
            cout << "3. View first item" << endl;
            cout << "4. Insert item" << endl;
            cout << "5. Delete item" << endl;
            cout << "6. Display" << endl;
            cout << "7. Clear" << endl;
            cout << "8. Exit" << endl;
            
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
                    try {
                        top = stack.top();
                        cout << "First item of the stack: " << top << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 4:
                    cout << "Please enter an item to insert: ";
                    cin.ignore();
                    getline(cin, toAdd);
                    stack.push(toAdd);
                    break;
                    
                case 5:
                    try {
                        removed = stack.pop();
                        cout << "Item " << removed << " popped from the stack." << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 6:
                    stack.display();
                    break;
                    
                case 7:
                    stack.clear();
                    break;
                case 8:
                    return 0;
                    break;
                    
                default:
                    cout << "Invalid selection, please make another selection: ";
                    cin >> menu_number;
                    cout << endl;
            }
        }
        
    } else if (ch == 'q') {
        while (menu_number != 8) {
            cout << "1. Return Capacity" << endl;
            cout << "2. Return Size of the data structure" << endl;
            cout << "3. View first item" << endl;
            cout << "4. Insert item" << endl;
            cout << "5. Delete item" << endl;
            cout << "6. Display" << endl;
            cout << "7. Clear" << endl;
            cout << "8. Exit" << endl;
            
            cin >> menu_number;
            switch (menu_number) {
                case 1:
                    size = queue.size();
                    cout << "Capacity of the queue: " << size << endl;
                    break;
                    
                case 2:
                    capacity = queue.capacity();
                    cout << "Size of the data structure: " << capacity << endl;
                    break;
                    
                case 3:
                    try {
                        top = queue.front();
                        cout << "First item of the queue: " << top << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 4:
                    cout << "Please enter an item to insert: ";
                    cin.ignore();
                    getline(cin, toAdd);
                    queue.enqueue(toAdd);
                    break;
                    
                case 5:
                    try {
                        removed = queue.dequeue();
                        cout << "Item " << removed << " removed from the queue." << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 6:
                    queue.display();
                    break;
                    
                case 7:
                    queue.clear();
                    break;
                    
                case 8:
                    return 0;
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
