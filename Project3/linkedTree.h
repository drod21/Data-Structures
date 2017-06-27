/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 3
 maxHeapTree.h
 ************************************************************/

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
    
    
    TreeNode<LTree> *delete_helper(const LTree &data, TreeNode<LTree> *node) {
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
                TreeNode<LTree> *temp = node->left ? node->left : node->right;
                //no children
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    // copy contents of non-empty child
                    node->data = temp->data;
                    delete temp;
                }
            } else {
                // node with two children
                // get inorder successor (smallest in right tree)
                TreeNode<LTree> *temp = minValue(node->right);
                node->data = temp->data;
                node->right = delete_helper(temp->data,node->right);
            }
        }
        // one node
        if (node == nullptr) {
            return node;
        }
        return node;
    }
    
    
    TreeNode<LTree> *insert_helper(LTree data, TreeNode<LTree> *node) {
        TreeNode<AType> *temp;
        if (node == nullptr) {
            node = new TreeNode<LTree>;
            node->data = data;
            node->parent = nullptr;
            return node;
        }
        
        if (data < node->data) {
            // Use temp to add new node, set node to be parent.
            temp = node->left;
            temp = insert_helper(data, temp);
            temp->parent = node;
            node->left = temp;
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
        
        return node;
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
    
    // copy constructor
    
    
    // Destructor
    ~LinkedTree() {
        delete root;
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
    
    TreeNode<LTree> *minValue(TreeNode<LTree> *node) {
        TreeNode<LTree> *curr = node;
        while (curr->left != nullptr)
            curr = curr->left;
        return curr;
    }
    
    // Returns the number of siblings
    // of the node in the argument
    int siblings(TreeNode<LTree>* node) {
        if (empty()) {
            throw underflow_error("Tree is empty");
        }
        if (root == nullptr) {
            return 0;
        }
        TreeNode<LTree> *temp = node->parent;
        if (temp->left && temp->right) {
            return 1;
        }
        return 1;
    }
    
    // Returns a pointer to a node that holds
    // the data in the argument
    TreeNode<LTree> *findNode(const LTree &data) {
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
        TreeNode<LTree>* node = root;
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
        TreeNode<LTree>* node = root;
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
        TreeNode<LTree>* node = root;
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
        root = new TreeNode<LTree>;
    }
    // Inserts data in the tree
    void insert(const LTree &data) {
        root = insert_helper(data, root);
        size++;
    }
    
    // Removes data from the tree
    void del(const LTree &data) {
        root = delete_helper(data, root);
        size--; //decrease size of tree
    }
    
};

#endif /* linkedTree_h */
