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
    TreeNode<LTree> *root;
    
    int size;
    // recursive call to leaves
    int leaves_helper(TreeNode<LTree> *node) {
        
        if (node == NULL) {
            return 0;
        }
        if (isLeaf(node)) {
            return 1;
        }
        
        return leaves_helper(node->left) + leaves_helper(node->right);
    }
    
    void insert_helper(LTree data, TreeNode<LTree> *node) {
        if (data < node->data) {
            if (node->left != NULL) {
                insert_helper(data, node->left);
            } else {
                node->left = new TreeNode<LTree>();
                node->left->data = data;
                node->left->parent = node;
                node->left->left = nullptr;
                node->left->right = nullptr;
            }
        } else if (data >= node->data) {
            if (node->right != NULL) {
                insert_helper(data, node->right);
            } else {
                node->right = new TreeNode<LTree>();
                node->right->data = data;
                node->right->parent = node;
                node->right->left = nullptr;
                node->right->right = nullptr;
            }
        }
    }
    
    // inorder helper function
    void inorder_helper(TreeNode<LTree>* node) {
        if (node->left != nullptr) {
            inorder_helper(node->left);
        }
        
        cout << node->data << " ";
        
        if (node->right != nullptr) {
            inorder_helper(node->right);
        }
        
    }
    // postorder helper function
    void postorder_helper(TreeNode<LTree>* node) {
        
        if (node->left != nullptr) {
            preorder_helper(node->left);
        }
        
        if (node->right != nullptr) {
            preorder_helper(node->right);
        }
        
        cout << node->data << " ";
    }
    
    void preorder_helper(TreeNode<LTree>* node) {

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
    LinkedTree() {
        root = nullptr;
        size = 0;
    }
    // Accessors
    // returns root of the tree
    LTree getRoot() const {
        TreeNode<LTree> *node = root;
        bool isRoot = false;
        
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        
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
            if (node->parent == nullptr && node != nullptr) {
                isRoot = true;
            }
        }
        
        
        return node->data;
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
        TreeNode<LTree>* n = root;
        if (n->left == nullptr && n->right == nullptr) {
            return 0;
        }
        return getHeight(n);
    }
    
    // Returns height of the node in argument
    // (from the root)
    int getHeight(TreeNode<LTree>* node) const {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
        
    }
    
    // Returns true if empty, false otherwise
    bool empty() const {
        return (root == NULL);
    }
    
    bool isLeaf(TreeNode<LTree> *n) {
        return (n->left == nullptr && n->right == nullptr);
    }
    
    // Returns number of leaves in the tree
    int leaves() {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        TreeNode<LTree>* node = root;
        
    
        return leaves_helper(node);
    }
    
    // Returns the number of siblings
    // of the node in the argument
    int siblings(TreeNode<LTree>* node) {
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
    // the data in the argument
    TreeNode<LTree>* findNode(const LTree &data) {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        
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
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        TreeNode<LTree>* node = root;
        preorder_helper(node);
    }
    // postorder traversal
    // left->right->parent
    void postorder() {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
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
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
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
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
    }
    // Inserts data in the tree
    void insert(const LTree &data) {
        TreeNode<LTree> *new_node = new TreeNode<LTree>;
        if (root != NULL) {
            insert_helper(data, root);
        } else {
            new_node->data = data;
            new_node->left = nullptr;
            new_node->right = nullptr;
            root = new_node;
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
