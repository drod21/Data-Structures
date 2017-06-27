/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 3
 AvlTree.h
 ************************************************************/

//include guard
#ifndef avlTree_h
#define avlTree_h

#include "treeNode.h"

template <class AType>

class AvlTree {
    
private:
    TreeNode <AType> *root;
    int size;
    // Begin helper/auxiliary functions for recursion.
    int leaves_helper(TreeNode<AType> *node) {
        if (node == NULL) {
            return 0;
        }
        if (isLeaf(node)) {
            return 1;
        }
        return leaves_helper(node->left) + leaves_helper(node->right);
    }
    
    TreeNode<AType> *delete_helper(const AType &data, TreeNode<AType> *node) {
        if (node == nullptr)
            return node;
        // if data to be deleted is smaller than roots data
        if (data < node->data) {
            node->left = delete_helper(data, node->left);
        } else if (data > node->data) {
            node->right = delete_helper(data, node->right);
        } else {
            // node with 1 or 0 children
            if ((node->left == NULL) || (node->right == NULL)) {
                TreeNode<AType> *temp;
                if (node->left != nullptr) {
                    temp = node->left;
                } else {
                    temp = node->right;
                }
                //no children
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    // copy contents of non-empty child
                    node->data = temp->data;
                    node->left = temp->left;
                    node->right = temp->right;
                    node->height = temp->height;
                }
            } else {
                // node with two children
                // get inorder successor (smallest in right tree)
                TreeNode<AType> *temp2 = minValue(node->right);
                node->data = temp2->data;
                node->right = delete_helper(temp2->data,node->right);
            }
        }
        // one node
        if (node == nullptr) {
            return node;
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        node->balanceFactor = getBalance(node);
        
        
        // Left Left Case
        if (node->balanceFactor > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);
        
        // Left Right Case
        if (node->balanceFactor > 1 && getBalance(node->left) < 0) {
            node->left =  leftRotate(node->left);
            return rightRotate(node);
        }
        
        // Right Right Case
        if (node->balanceFactor < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);
        
        // Right Left Case
        if (node->balanceFactor < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;
    }
    
    TreeNode<AType> *insert_helper(AType data, TreeNode<AType> *node) {
        TreeNode<AType> *temp;
        if (node == nullptr) {
            node = new TreeNode<AType>;
            node->data = data;
            return node;
        }
        
        if (data < node->data) {
            // Use temp to add new node, set node to be parent.
            temp = node->left;
            temp = insert_helper(data, temp);
            temp->parent = node;
            node->left = temp;
            // else go to right side of tree
        } else if (data > node->data) {
            // Use temp to add new node, set node to be parent.
            temp = node->right;
            temp = insert_helper(data, temp);
            temp->parent = node;
            node->right = temp;
        } else {
            cout << "Item already in tree." << endl;
            return node;
        }
        
        node->height = getHeight(node);
        node->balanceFactor = getBalance(node);
        // Left Left Case
        if (node->balanceFactor > 1 && data < node->left->data) {
            // rotate right
            return rightRotate(node);
        }
        
        // Right Right Case
        if (node->balanceFactor < -1 && data > node->right->data) {
            // left rotate
            return leftRotate(node);
        }
        
        // Left Right Case
        if (node->balanceFactor > 1 && data > node->left->data) {
            // node->left left rotate
            node->left = leftRotate(node->left);
            //return right rotate
            return rightRotate(node);
        }
        
        // Right Left Case
        if (node->balanceFactor < -1 && data < node->right->data) {
            // node->right right rotate
            node->right = rightRotate(node->right);
            // return left rotate
            return leftRotate(node);
        }
        return node;
    }
    
    TreeNode<AType> *minValue(TreeNode<AType> *node) {
        TreeNode<AType> *curr = node;
        while (curr->left != nullptr)
            curr = curr->left;
        return curr;
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
    
    TreeNode<AType> *leftRotate(TreeNode<AType> *node) {
        TreeNode<AType> *temp = node->right;
        TreeNode<AType> *temp2 = temp->left;
        
        temp->left = node;
        node->right = temp2;
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
        return temp;
    }
    
    TreeNode<AType> *rightRotate(TreeNode<AType> *node) {
        
        TreeNode<AType> *temp = node->left;
        TreeNode<AType> *temp2 = temp->right;
        
        temp->right = node;
        node->left = temp2;
        
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
        
        return temp;
    }
    
public:
    // Constructor
    AvlTree() {
        root = nullptr;
        size = 0;
    }
    
    // Destructor
    ~AvlTree() {
	if (this->left)
		delete this->left;
	if (this->right)
		delete this->right;
	if (this->key)
		delete this->data;
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
        if (!found) {
            throw underflow_error("Item not in tree.");
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
        root = new TreeNode<AType>;
    }
    // Inserts data in the tree
    void insert(const AType &data) {
        root = insert_helper(data, root);
        size++;
    }
    
    // Removes data from the tree
    void del(AType data) {
        root = delete_helper(data, root);
        size--; //decrease size of tree
    }
    
    
};


#endif /* avlTree_h */
