//
//  linkedTree.h
//  Project3
//
//  Created by Derek Rodriguez on 6/14/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef linkedTree_h
#define linkedTree_h

#include <cmath>


template <class LTree>

class LinkedTree {
    
private:
    TreeNode<LTree>* root;
    
    int size;
    // recursive call to leaves
    int leaves_helper(TreeNode<LTree>* node) {
        int count = 0;
        if (node == NULL) {
            count = 0;
        } else if (node->left == NULL && node->right == NULL) {
            count++;
        } else {
            return leaves_helper(node->left);
            return leaves_helper(node->right);
        }
        
        return count;
    }
    
    // inorder helper function
    void inorder_helper(TreeNode<LTree>* node) {
        if (root == nullptr) {
            return;
        } else {
            inorder_helper(root->left);
            cout << root->data << " ";
            inorder_helper(root->right);
        }
    }
    // postorder helper function
    void postorder_helper(TreeNode<LTree>* node) {
        if (root == nullptr) {
            return;
        } else {
            postorder_helper(node->left);
            postorder_helper(node->right);
            cout << root->data << " ";
        }
        
    }
    void preorder_helper(TreeNode<LTree>* node) {
        if (root == nullptr) {
            return;
        } else {
            cout << root->data << " ";
            preorder_helper(node->left);
            preorder_helper(node->right);
        }
        
    }
    
    
public:
    // Constructor
    LinkedTree() {
        root = nullptr;
        root->parent = nullptr;
        root->left = nullptr;
        root->right = nullptr;
        size = 0;
        
    }
    // Accessors
    // returns root of the tree
    TreeNode<LTree>* getRoot() const {
        TreeNode<LTree> *node = root;
        bool isRoot = false;
        
        // root at first node
        if (node->parent == nullptr && node != nullptr) {
            isRoot = true;
        } else {
            cerr << "Tree is empty" << endl;
        }
        
        // for some reason, node was placed elsewhere, so find the root
        if (!isRoot && node->parent != nullptr) {
            while (node->parent != nullptr) {
                node = node->parent;
            }
            isRoot = true;
        }
        
        
        return node;
    }
    
    // Returns the number of elements in the tree
    int getSize() {
        return size;
        
    }
    // returns height of the tree
    int getHeight() {
        TreeNode<LTree>* n = root;
        if (n->left == nullptr && n->right == nullptr) {
            return 0;
        }
        return getHeight(n);
    }
    
    // Returns height of the node in argument
    // (from the root)
    int getHeight(TreeNode<LTree>* node) const {
        int count = 0;
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
        
    }
    
    // Returns true if empty, false otherwise
    bool empty() const {
        return (root == NULL);
    }
    
    // Returns number of leaves in the tree
    int leaves() {
        
        int count;
        TreeNode<LTree>* node = root;
        
        count = leaves_helper(node);
        return count;
    }
    
    // Returns the number of siblings
    // of the node in the argument
    int siblings(TreeNode<LTree>* node) {
        
        int count = 0;
        if (node->left == nullptr && node->right == nullptr) {
            return 0;
        } else if (node->left != nullptr && node->right != nullptr) {
            count++;
            return siblings(node->left);
            return siblings(node->right);
        }
        return count;
    }
    
    // Returns a pointer to a node that holds
    // the data in the argument
    TreeNode<LTree>* findNode(const LTree &data) {
        
        TreeNode<LTree> *temp = root;
        bool found = false;
        for (;;) {
            if (found || temp == nullptr) break;
            
            if (data < temp->data) {
                temp = temp->left;
            } else if (temp->data < data) {
                temp = temp->right;
            } else {
                found = true;
            }
        }
        return temp;
    }
    // preorder traversal
    // parent->left->right
    void preorder() {
        TreeNode<LTree>* node = root;
        if (node == nullptr) {
            cout << "Tree is empty" << endl;
        } else {
            preorder_helper(node);
        }
    }
    // postorder traversal
    // left->right->parent
    void postorder() {
        TreeNode<LTree>* node = root;
        if (node == nullptr) {
            cout << "Tree is empty" << endl;
        } else {
            postorder_helper(node);
        }
    }
    //inorder traversal
    // left->parent->right
    void inorder() {
        TreeNode<LTree>* node = root;
        if (node == nullptr) {
            cout << "Tree is empty" << endl;
        } else {
            inorder_helper(node);
        }
    }
    // Mutators
    
    // Removes all elements in the tree
    void clear(){
    }
    // Inserts data in the tree
    void insert(const LTree &data) {
        TreeNode<LTree>* temp = root;
        TreeNode<LTree> *node = root;
        
        bool found = false;
        while (!found && temp != nullptr) {
            temp->parent = temp;
            if (data < temp->data) {
                temp = temp->left;
            } else if (temp->data < data) {
                temp = temp->right;
            } else {
                found = true;
            }
            
            // construct node containing data
            if (!found) {
                temp = new TreeNode<LTree>();
                temp->data = data;
                if (node == nullptr) { // empty tree
                    node = temp;
                    node->parent = nullptr;
                } else if (data < root->data) {
                    // Insert to left of parent
                    node->left = temp;
                    node->left->parent = node;
                } else {
                    // Insert to right of parent
                    node->right = temp;
                    node->right->parent = node;
                }
            } else {
                cout << "Item already in tree\n";
            }
        }
        size++;
    }
    
    // Removes data from the tree
    LTree del(const LTree &data) {
        bool found = false; // Signals if found
        TreeNode<LTree> *x, *root;
        LTree n = data;
        size--; //decrease size of tree
        return n;
    }
    
};




#endif /* linkedTree_h */
