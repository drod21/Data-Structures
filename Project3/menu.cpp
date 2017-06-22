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

using namespace std;

typedef double NodeType;

int main() {
    char tree_type;
    int menu_number = 0;
    cout << "Please enter a tree type: " << endl;
    cin >> tree_type;
    if (tree_type == 'g') {
	LinkedTree<TreeNode>* myTree(void);
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
		    cout << "Root: " << myTree->getRoot() << endl;
                    break;
                    
                case 2:
		    cout << "Size: " myTree->getSize() << endl;
                    break;
                    
                case 3:
                    cout << "Height of tree: " << myTree->getHeight() << endl;
                    break;
                    
                case 4:
		    NodeType data;
		    cout << "Find height of which node?: ";
		    cin >> data;
		    TreeNode nodeToGetHeight = myTree->findNode(data);
		    cout << "Height of node: " << myTree->getHeight(nodeToGetHeight) << endl;
                    break;
                    
                case 5:
		    if(myTree->empty() == true) cout << "Tree is empty" << endl;
		    else cout << "Tree is not empty" << endl;                    
                    break;
                    
                case 6:
                    cout << "Leaves: " << myTree->leaves();
                    break;
               
	        case 7:
			NodeType data;
			cout "Find number of siblings for which node?: ";
			cin >> data;
			TreeNode nodeToGetSiblings = myTree->findNode(data);
			cout << "Number of node's siblings: " << myTree->siblings(nodeToGetSiblings) << endl;
                    break;
                    
                case 8:
		    NodeType data;
		    cout << "Find which node?: ";
		    cin >> data;
		    TreeNode nodeToFind = myTree->findNode(data);
		    cout << "Found node: " << nodeToFind->getData() << endl; 
                    break;
                    
                case 9:
                    cout << "Preorder: " << myTree->preorder() << endl;                    
                    break;
                    
                case 10:
                    cout << "Postorder: " << myTree->postorder() << endl;
                    break;
                    
                case 11:
                    cout << "Inorder: " << myTree->inorder() << endl;
                    break;
                    
                case 12:
                    myTree->clear();
		    cout << "Tree cleared" << endl;
                    break;
                    
                case 13:
		    NodeType dataToInsert;
		    cout << "Enter data to insert: ";
		    cin >> dataToInsert;
                    myTree->insert(dataToInsert);
		    cout << endl;
                    break;
                    
                case 14:
		    NodeType dataToDelete;
		    cout << "Enter data to delete: "
		    cin >> dataToDelete;
                    myTree->del(dataToDelete);
		    cout << endl;
                    break;
                    
                case 15:
                    return 0;
                    break;
                    
                default:
                    cout << "Invalid entry. Select an option [1-15]: ";
		    cin >> menu_number;
		    cout << endl;
                    break;
            }
        }
    } else if (tree_type == 'a') {
	AvlTree<TreeNode>* myTree(void);
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
                    cout << "Root: " myTree->getRoot() << endl;
                    break;
                    
                case 2:
                    cout << "Size: " myTree->getSize() << endl;
                    break;
                    
                case 3:
                    cout << "Height of tree: " << myTree->getHeight() << endl;
                    break;
                    
                case 4:
                    NodeType data;
		    cout << "Find height of which node?: ";
		    cin >> data;
		    TreeNode nodeToGetHeight = myTree->find(data);
		    cout << "Height of node: " myTree->getHeight(nodeToGetHeight) << endl;
                    break;
                    
                case 5:
                    if(myTree->empty() == true) cout << "Tree is empty" << endl;
		    else cout << "Tree is not empty" << endl;
                    break;
                    
                case 6:
                    cout << "Number of leaves: " << myTree->getLeaves() << endl;
                    break;

                case 7:
                    NodeType data;
		    cout << "Get number of siblings for whcih node?: ";
		    cin >> data;
		    TreeNode nodeToGetSiblings = myTree->find(data);
		    cout << "Number of node's siblings: " << myTree->siblings(nodeToGetSiblings) << endl;
                    break;
                    
                case 8:
                    NodeType data;
		    cout << "Find which node?: ";
		    cin >> data;
		    TreeNode nodeToFind = myTree->find(data);
		    cout << "Found node: " << nodeToFind->getData() << endl;
                    break;
                    
                case 9:
                    cout << "Preorder: " << myTree->preorder() << endl;
                    break;
                    
                case 10:
                    cout << "Postorder: " << myTree->postorder() << endl;
                    break;
                    
                case 11:
                    cout << "Inorder: " << myTree->inorder() << endl;
                    break;
                    
                case 12:
                    myTree->clear();
		    cout << "Tree cleared" << endl;
                    break;
                    
                case 13:
		    NodeType dataToInsert;
                    cout << "Enter data to insert: ";
		    cin >> dataToInsert;
		    myTree->insert(dataToInsert);
		    cout << endl;
                    break;
                    
                case 14:
		    NodeType dataToDelete;
                    cout << "Enter data to delete: "
		    cin >> dataToDelete;
		    myTree->del(dataToDelete);
                    break;
                    
                case 15:
                    return 0;
                    break;
                    
                default:
                    cout << "Invalid selection. Enter option [1-15]: ";
		    cin >> menu_number;
		    cout << endl;
                    break;
            }
        }
    } else if (tree_type == 'h') {
	MaxHeapTree<TreeNode> myHeap(15);
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
                    cout << "Root: " << myHeap.getRoot() << endl;
                    break;
                    
                case 2:
                    cout << "Size: " << myHeap.getSize() << endl;
                    break;
                    
                case 3:
                    cout << "Height: " myHeap.getHeight() << endl;
                    break;
                    
                case 4:
		    if(myHeap.empty() == true) cout << "Heap is empty" << endl;
		    else cout << "Heap is not empty" << endl;
                    break;
                    
                case 5:
                    cout << "Number of leaves: " << myHeap.leaves() << endl;
                    break;
                    
                case 6:
                    myHeap.print();
                    break;

                case 7:
                    myTree.clear();
                    break;
                    
                case 8:
		    int keyToInsert;
		    NodeType dataToInsert;
                    cout << "Enter key for priority: ";
		    cin >> keyToInsert;
		    cout << "Enter data: ";
		    cin >> dataToInsert;
		    myHeap.insert(keyToInsert, dataToInsert);
		    cout << endl;
                    break;
                    
                case 9:
                    cout << "Deleted: " << myHeap.delMax() << endl;
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
