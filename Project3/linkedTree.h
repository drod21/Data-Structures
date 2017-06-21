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

using namespace std;

template <class LTree>;

class LinkedTree {
    typedef TreeNode<LTree>* NodePtr;
private:
    NodePtr root;
    
    int size;
    
    // recursive call to leaves
    int leaves_helper(NodePtr node) {
        int count = 0;
        if (node == NULL) {
            count = 0;
        } else if (node->left == NULL && node->right == NULL) {
            count++;
        } else {
            return leaves(node->left);
            return leaves(node->right);
        }
    }
    
    // inorder helper function
    void inorder_helper(NodePtr node) {
        if (root == nullptr) {
            return;
        } else {
            inorder(root->left);
            cout << root->value << " ";
            inorder(root->right);
        }
    }
    // postorder helper function
    void postorder_helper(NodePtr node) {
        if (root = nullptr) {
            return;
        } else {
            postorder(node->left);
            postorder(node->right);
            cout << root->value << " ";
        }
        
    }
    void preorder_helper(NodePtr node) {
        if (root == nullptr) {
            return;
        } else {
            cout << root->value << " ";
            preorder(node->left);
            preorder(node->right);
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
    NodePtr getRoot() const {
        NodePtr node = root;
        bool isRoot = false
        
        // root at first node
        if (node->parent == nullptr && node != nullptr) {
            isRoot = true;
        } else {
            cerr << "Tree is empty" << endl;
        }
        
        // for some reason, node was placed elsewhere, so find the root
        if (!isRoot && node->parent != nullptr) {
            while (node->parent != null) {
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
        NodePtr n = root;
        if (n->left == nullptr && n->right == nullptr) {
            return 0;
        }
        return getHeight(n);
    }
    
    // Returns height of the node in argument
    // (from the root)
    int getHeight(NodePtr node) const {
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
        NodePtr node = root;
        
        count = leaves_helper(node);
        return count;
    }
    
    // Returns the number of siblings
    // of the node in the argument
    int siblings(NodePtr node) {
        
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
    NodePtr findNode(const LTree &data) {
        
        TreeNode<LTree> *temp = root;
        bool found = false;
        for (;;) {
            if (found || temp == nullptr) break;
            
            if (data < temp->data)
                temp = temp->left;
            else if (temp->data < data)
                temp = temp->right;
            else
                found = true;
        }
        return temp;
    }
    // preorder traversal
    // parent->left->right
    void preorder() {
        NodePtr node = root;
        if (node == nullptr) {
            cout << "Tree is empty" << endl;
        } else {
            preorder(node);
        }
    }
    // postorder traversal
    // left->right->parent
    void postorder() {
        NodePtr node = root;
        if (node == nullptr) {
            cout << "Tree is empty" << endl;
        } else {
            postorder(node);
        }
    }
    //inorder traversal
    // left->parent->right
    void inorder() {
        NodePtr node = root;
        if (node == nullptr) {
            cout << "Tree is empty" << endl;
        } else {
            inorder(node);
        }
    }
    // Mutators
    
    // Removes all elements in the tree
    void clear(){
    }
    // Inserts data in the tree
    void insert(const LTree &data) {
        NodePtr temp = root;
        
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
                temp = new TreeNode();
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
        bool found; // Signals if found
        NodePtr x, root;
        
        size--; //decrease size of tree
    }
    
};

#endif /* linkedTree_h */
