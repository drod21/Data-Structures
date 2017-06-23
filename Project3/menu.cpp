//
//  main.cpp
//  Project3
//
//  Created by Derek Rodriguez on 6/14/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#include <iostream>
#include "maxHeapTree.h"
#include "linkedTree.h"
#include "avlTree.h"


int main() {
    typedef double Node;
    
    Node data;
    Node dataToInsert;
    Node *nodeToGetHeight;
    char tree_type;
    int menu_number = 0;
    LinkedTree<Node> *myTree = new LinkedTree<Node>();
    MaxHeapTree<Node> *myHeap = new MaxHeapTree<Node>(15);
    cout << "Please enter a tree type: " << endl;
    cin >> tree_type;
    if (tree_type == 'g') {
        
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
                    try {
                        cout << "Root: " << myTree->getRoot() << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 2:
                    try {
                        cout << "Size: " << myTree->getSize() << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 3:
                    try {
                        cout << "Height of tree: " << myTree->getHeight() << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 4:
                    try {
                        cout << "Find height of which node?: ";
                        cin >> data;
                        TreeNode<Node> *nodeToGetHeight = myTree->findNode(data);
                        cout << "Height of node: " << myTree->getHeight(nodeToGetHeight) << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 5:
                    if(myTree->empty() == true) cout << "Tree is empty" << endl;
                    else cout << "Tree is not empty" << endl;
                    break;
                    
                case 6:
                    try {
                        cout << "Leaves: " << myTree->leaves() << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 7:
                    try {
                        cout << "Find number of siblings for which node?: ";
                        cin >> data;
                        TreeNode<Node> *nodeToGetSiblings = myTree->findNode(data);
                        cout << "Number of node's siblings: " << myTree->siblings(nodeToGetSiblings) << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 8:
                    try {
                        cout << "Find which node?: ";
                        cin >> data;
                        TreeNode<Node> *nodeToFind = myTree->findNode(data);
                        cout << "Found node: " << nodeToFind->getData() << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 9:
                    try {
                        cout << "Preorder: " << endl;
                        myTree->preorder();
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 10:
                    try {
                        cout << "Postorder: " << endl;
                        myTree->postorder();
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 11:
                    try {
                        cout << "Inorder: " << endl;
                        myTree->inorder();
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 12:
                    myTree->clear();
                    cout << "Tree cleared" << endl;
                    break;
                    
                case 13:
                    Node dataToInsert;
                    cout << "Enter data to insert: ";
                    cin >> dataToInsert;
                    myTree->insert(dataToInsert);
                    cout << endl;
                    break;
                    
                case 14:
                    try {
                        Node dataToDelete;
                        cout << "Enter data to delete: ";
                        cin >> dataToDelete;
                        myTree->del(dataToDelete);
                        cout << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 15:
                    return 0;
                    break;
                    
                default:
                    cout << "Invalid entry. Select an option [1-15]: ";
                    cin >> menu_number;
                    cout << endl;
                    break;
                    
            }// end switch
        } // end while
    }
    
    if (tree_type == 'a') {
        
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
            
            /* switch (menu_number) {
             
             case 1:
             cout << "Root: " << avlTree->getRoot() << endl;
             break;
             
             case 2:
             cout << "Size: " << avlTree->getSize() << endl;
             break;
             
             case 3:
             cout << "Height of tree: " << avlTree->getHeight() << endl;
             break;
             
             case 4:
             cout << "Find height of which node?: ";
             cin >> data;
             nodeToGetHeight = avlTree->find(data);
             cout << "Height of node: " << avlTree->getHeight(nodeToGetHeight) << endl;
             break;
             
             case 5:
             if(avlTree->empty() == true)
             cout << "Tree is empty" << endl;
             else
             cout << "Tree is not empty" << endl;
             break;
             
             case 6:
             cout << "Number of leaves: " << avlTree->getLeaves() << endl;
             break;
             
             case 7:
             cout << "Get number of siblings for whcih node?: ";
             cin >> data;
             Node nodeToGetSiblings = avlTree->find(data);
             cout << "Number of node's siblings: " << avlTree->siblings(nodeToGetSiblings) << endl;
             break;
             
             case 8:
             cout << "Find which node?: ";
             cin >> data;
             Node nodeToFind = avlTree->find(data);
             cout << "Found node: " << nodeToFind << endl;
             break;
             
             case 9:
             cout << "Preorder: " << avlTree->preorder() << endl;
             break;
             
             case 10:
             cout << "Postorder: " << avlTree->postorder() << endl;
             break;
             
             case 11:
             cout << "Inorder: " << avlTree->inorder() << endl;
             break;
             
             case 12:
             avlTree->clear();
             cout << "Tree cleared" << endl;
             break;
             
             case 13:
             
             cout << "Enter data to insert: ";
             cin >> dataToInsert;
             avlTree->insert(dataToInsert);
             cout << endl;
             break;
             
             case 14:
             Node dataToDelete;
             cout << "Enter data to delete: ";
             cin >> dataToDelete;
             avlTree->del(dataToDelete);
             break;
             
             case 15:
             return 0;
             break;
             
             default:
             cout << "Invalid selection. Enter option [1-15]: ";
             cin >> menu_number;
             cout << endl;
             break;
             } // end switch*/
        } // end while
    } else if (tree_type == 'h') {        
        while (menu_number != 10) {        
            cout << "Select an option:\n"
            << "1. Return root\n"
            <<  "2. Return size\n"
            << "3. Return height\n"
            << "4. Is tree empty?\n"
            << "5. Return number of leaves\n"
            << "6. Print\n"
            << "7. Clear tree\n"
            << "8. Insert (key, data)\n"
            << "9. Delete\n"
            << "10. Exit\n";
            cin >> menu_number;
            switch (menu_number) {
                    
                case 1:
                    try {
                        cout << "Root: " << myHeap->getRoot() << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 2:
                    try {
                        cout << "Size: " << myHeap->getSize() << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 3:
                    try {
                        cout << "Height: " << myHeap->getHeight() << endl;
                    } catch (underflow_error &e) {
                        cout << e.what() << endl;
                    }
                    break;
                    
                case 4:
                    if(myHeap->empty() == true) cout << "Heap is empty" << endl;
                    else cout << "Heap is not empty" << endl;
                    break;
                    
                case 5:
                    cout << "Number of leaves: " << myHeap->leaves() << endl;
                    break;
                    
                case 6:
                    myHeap->print();
                    break;
                    
                case 7:
                    
                    break;
                    
                case 8:
                    int keyToInsert;
                    Node dataToInsert;
                    cout << "Enter key for priority: ";
                    cin >> keyToInsert;
                    cout << "Enter data: ";
                    cin >> dataToInsert;
                    myHeap->insert(keyToInsert, dataToInsert);
                    cout << endl;
                    break;
                    
                case 9:
                    cout << "Deleted: " << myHeap->delMax() << endl;
                    break;
                    
                case 10:
                    return 0;
                    break;
                    
                default:
                    cout << "Invalid selection. Select an option [1-10]: ";
                    cin >> menu_number;
                    cout << endl;
                    break;
            }
        }
    }
    return 0;
}
