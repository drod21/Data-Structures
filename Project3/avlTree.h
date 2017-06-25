//
//  avlTree.h
//  Project3
//
//  Created by Derek Rodriguez on 6/14/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef avlTree_h
#define avlTree_h

#include "treeNode.h"

template <class AType>

class AvlTree {
    
private:
    TreeNode <AType> *root;
    int size;
    
    int leaves_helper(TreeNode<AType> *node) {
        
        if (node == NULL) {
            return 0;
        }
        if (isLeaf(node)) {
            return 1;
        }
        
        return leaves_helper(node->left) + leaves_helper(node->right);
    }
    
    void insert_helper(AType data, TreeNode<AType> *node) {
        if (data < node->data) {
            if (node->left != NULL) {
                insert_helper(data, node->left);
            } else {
                node->left = new TreeNode<AType>();
                node->left->data = data;
                node->left->parent = node;
                node->left->left = nullptr;
                node->left->right = nullptr;
            }
        } else if (data >= node->data) {
            if (node->right != NULL) {
                insert_helper(data, node->right);
            } else {
                node->right = new TreeNode<AType>();
                node->right->data = data;
                node->right->parent = node;
                node->right->left = nullptr;
                node->right->right = nullptr;
            }
        }
        node->balanceFactor = getBalance(node);
        // Left Left Case
        if (node->balanceFactor > 1 && data < node->left->data) {
            // rotate right
        }
        
        // Right Right Case
        if (node->balanceFactor < -1 && data > node->right->data) {
            // left rotate
        }
        
        // Left Right Case
        if (node->balanceFactor > 1 && data > node->left->data) {
            // node->left left rotate
            //return right rotate
        }
        
        // Right Left Case
        if (node->balanceFactor < -1 && data < node->right->data) {
            // node->right right rotate
            // return left rotate
        }
        
    }
    
    // inorder helper function
    void inorder_helper(TreeNode<AType>* node) {
        if (node->left != nullptr) {
            inorder_helper(node->left);
        }
        
        cout << node->data << " ";
        
        if (node->right != nullptr) {
            inorder_helper(node->right);
        }
        
    }
    // postorder helper function
    void postorder_helper(TreeNode<AType>* node) {
        
        if (node->left != nullptr) {
            preorder_helper(node->left);
        }
        
        if (node->right != nullptr) {
            preorder_helper(node->right);
        }
        
        cout << node->data << " ";
    }
    
    void preorder_helper(TreeNode<AType>* node) {
        
        cout << node->data << " ";
        
        if (node->left != nullptr) {
            preorder_helper(node->left);
        }
        
        if (node->right != nullptr) {
            preorder_helper(node->right);
        }
        
    }
    
    
    
public:
    
    // Constructor
    AvlTree() {
        root = nullptr;
        size = 0;
    }
    
    // Destructor
    ~AvlTree() {
        delete root;
    }
    
    AType getRoot() {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        return root->data;
    }
    
    // Returns the number of elements in the tree
    int getSize() {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        
        return size;
        
    }
    // returns height of the tree
    int getHeight() {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        TreeNode<AType> *n = root;
        if (n->left == nullptr && n->right == nullptr) {
            return 0;
        }
        return getHeight(n);
        
    }
    // helper function for maximum of two ints
    int max(int a, int b) {
        return (a > b)? a : b;
    }
    // Returns height of the node in argument
    // (from the root)
    int getHeight(TreeNode <AType> *node) {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
    
    // Returns true if empty, false otherwise
    bool empty() {
        return (root == NULL);
    }
    
    bool isLeaf(TreeNode<AType> *n) {
        return (n->left == nullptr && n->right == nullptr);
    }
    
    
    
    int getBalance(TreeNode<AType> *node) {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        return (getHeight(node->left) - getHeight(node->right));
    }
    
    // Returns number of leaves in the tree
    int leaves() {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        TreeNode<AType>* node = root;
        
        
        return leaves_helper(node);
    }
    
    // Returns the number of siblings
    // of the node in the argument
    int siblings(TreeNode <AType> *node) {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
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
    // the date in the argument
    TreeNode <AType> *find(const AType &data) {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        
        TreeNode<AType> *temp = root;
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
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        TreeNode<AType>* node = root;
        if (node == nullptr) {
            cout << "Tree is empty" << endl;
        } else {
            preorder_helper(node);
        }
        
        cout << endl;
    }
    // postorder traversal
    // left->right->parent
    void postorder() {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        TreeNode<AType>* node = root;
        if (node == nullptr) {
            cout << "Tree is empty" << endl;
        } else {
            postorder_helper(node);
        }
        cout << endl;
    }
    //inorder traversal
    // left->parent->right
    void inorder() {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        TreeNode<AType>* node = root;
        if (node == nullptr) {
            cout << "Tree is empty" << endl;
        } else {
            inorder_helper(node);
        }
        cout << endl;
    }
    // Mutators
    
    // Removes all elements in the tree
    void clear() {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        delete root;
        root = new TreeNode<AType>;
    }
    // Inserts data in the tree
    void insert(const AType &data) {
        TreeNode<AType> *new_node = new TreeNode<AType>;
        if (root != NULL) {
            insert_helper(data, root);
        } else {
            new_node->data = data;
            new_node->left = nullptr;
            new_node->right = nullptr;
            new_node->balanceFactor = 0;
            root = new_node;
        }
        size++;
    }
    
    // Removes data from the tree
    AType del(AType data) {
        TreeNode<AType> *x, *parent;
        x = findNode(data);
        parent = x->parent;
        cout << x->data << endl;
        if (x == nullptr) {
            throw underflow_error("Item not in tree\n");
            return;
        }
        
        // Case for 2 children, find inorder successor
        if (x->left != nullptr && x->right != nullptr) {
            TreeNode<AType> *successor = x->right;
            parent = x;
            while (successor->left != nullptr) {
                parent = successor;
                successor = successor->left;
            }
            // Move contents of successor to x and change
            // x to point to successor
            x->data = successor->data;
            x = successor;
        }
        
        // 0 children or 1 child
        TreeNode<AType> *subtree = x->left;
        if (subtree == nullptr) {
            subtree = x->right;
        }
        
        if (parent == nullptr) {    // root being removed
            root = subtree;
        } else if (parent->left == x) { // left child of parent
            parent->left = subtree;
        } else {    // right child of parent
            parent->right = subtree;
        }
        delete x;
        
        size--; //decrease size of tree
    }
    
    
};


#endif /* avlTree_h */
