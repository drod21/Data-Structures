//
//  linkedTree.h
//  Project3
//
//  Created by Derek Rodriguez on 6/14/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef linkedTree_h
#define linkedTree_h

using namespace std;

template <class LTree>;

class LinkedTree {
    
private:
    TreeNode <LTree> *node;
    
public:
    // Constructor
    LinkedTree() {
        root = nullptr;
        root->parent = nullptr;
        root->left = nullptr;
        root->right = nullptr;
        
        root->left->parent = node;
        root->right->parent = node;
    }
    // Accessors
    // returns root of the tree
    NodeType getRoot() const {
        bool isRoot = false
        
        if (root->parent == nullptr && root != nullptr) {
            isRoot = true;
        } else {
            cerr << "Tree is empty" << endl;
        }
        
        return root->parent;
    }
    
    // Returns the number of elements in the tree
    int getSize() {
        
    }
    // returns height of the tree
    int getHeight() {
        
    }
    // Returns heigh of the node in argument
    // (from the root)
    int getHeight(TreeNode <LTree> *node) const {
        
    }
    
    // Returns true if empty, false otherwise
    bool empty() const {
        return (root == NULL);
    }
    
    // Returns number of leaves in the tree
    int leaves() {
        
    }
    
    // Returns the number of siblings
    // of the node in the argument
    int siblings(TreeNode <LTree> *node) {
        
        
    }
    
    // Returns a pointer to a node that holds
    // the data in the argument
    TreeNode <LTree> *findNode(const LTree &data) {
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
    }
    // postorder traversal
    // left->right->parent
    void postorder() {
    }
    //inorder traversal
    // left->parent->right
    void inorder() {

        TreeNode<LTree> *curr = root;
        TreeNode<LTree> *prev = NULL;
        
        if (parent == NULL) {
            return;
        }
        
        while (curr != NULL) {
            if (curr->left != NULL) {
                cout << curr->data << " ";
                curr = curr->right;
            } else {
                // find inorder predecessor of current
                prev = curr->left;
                while (prev->right != NULL && prev->right != curr)
                    prev = prev->right;
                // make current as right child of inorder
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                    // Revert changes made to restore original tree
                } else {
                    prev->right = NULL;
                    cout << curr->data << " ";
                    curr = curr->right;
                } // end if prev->right == null
            } // end if curr->left == null
            
        } // end while

    }
    // Mutators
    
    // Removes all elements in the tree
    void clear(){
    }
    // Inserts data in the tree
    void insert(const LTree &data) {
        TreeNode<LTree> *temp = root;
        
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
    }
    
    // This is recursive method, I pulled this out to use the method from the slides to have an un-modified version of the method. I have some stuff to clarify with Zach regarding the layouts, so just leaving this in here for now.
        /*if (parent == NULL) {
            insert(data, parent);
        } else {
            new_node = new TreeNode();
            new_node->data = data;
            new_node->left = nullptr;
            new_node->right = nullptr;
            parent = new_node;
        }
    }
        
    void insert(LTree data, TreeNode<LTree> *root) {
        if (data < root->data) {
            if (root->left != NULL) {
                insert(data, root->left);
            } else {
                root->left = new TreeNode();
                root->left->data = data;
                root->left->left = nullptr;
                root->left->right = nullptr;
                }
        } else if (data >= root->data) {
            if (root->right != NULL) {
                insert(data, root->right);
            } else {
                root->right = new TreeNode();
                root->right->data = data;
                root->right->left = nullptr;
                root->right->right = nullptr;
            }
        }
    }
    */
    // Removes data from the tree
    LTree del(const LTree &data) {
        bool found; // Signals if found
        TreeNode<LTree> *x, *root;
        
    }

};

#endif /* linkedTree_h */
