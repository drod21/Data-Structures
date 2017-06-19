//
//  main.cpp
//  Project3
//
//  Created by Derek Rodriguez on 6/14/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    char tree_type;
    int menu_number;
    cout << "Please enter a tree type: " << endl;
    cin >> tree_type;
    if (tree_type == 'g' || tree_type == 'a') {
        while (menu_number != 15) {
        cout << "Select an option:\n"
            << "1. Return root\n"
            << "2. Return size\n"
            << "3. Return height\n"
            << "4. Return height (node)\n"
            << "5. Is tree empty?\n"
            << "6. Return number of leaves\n"
            << "7. Return number of siblings (node)\n"
            << "8. Find node (data)\n"
            << "9. Print preorder\n"
            << "10. Print postorder\n"
            << "11. Print inorder\n"
            << "12. Clear tree\n"
            << "13. Insert (data)\n"
            << "14. Delete (data)\n"
            << "15. Exit\n";
            
            cin >> menu_number;
            
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
                    
                case 8:
                    
                    break;
                    
                case 9:
                    
                    break;
                    
                case 10:
                    
                    break;
                    
                case 11:
                    
                    break;
                    
                case 12:
                    
                    break;
                    
                case 13:
                    
                    break;
                    
                case 14:
                    
                    break;
                    
                case 15:
                    
                    break;
                    
                default:
                    
                    break;
            }
        }
        
     } else if (tree_type == 'h') {
         cout << "Select an option:\n"
            << "1. Return root\n"
            <<  "2. Return size\n"
            << "3. Return height\n"
            << "4. Is tree empty?\n"
            << "5. Return number of leaves\n"
            << "6. Print\n"
            << "7. Clear tree\n"
            << "8. Insert (key, data)\n"
            << "9. Delet\n"
            << "10. Exit\n";
         
         while (menu_number != 10) {
             cin >> menu_number;
         
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
                 
                 case 8:
                 
                     break;
                 
                 case 9:
                 
                     break;
                 
                 case 10:
                 
                     break;
                     
                 default:
                     
                     break;
             }
     }
     }
    return 0;
}
