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
    void insert(AType data) {
    }
    
    // Removes data from the tree
    AType del(AType data){
    }
    
    
};


#endif /* avlTree_h */
