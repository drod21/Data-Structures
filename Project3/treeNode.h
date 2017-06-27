/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 3
 maxHeapTree.h
 ************************************************************/


#ifndef treeNode_h
#define treeNode_h

#include <iostream>
using namespace std;

template <class NodeType>

class TreeNode {
    
public:
    int key;
    NodeType data;
    short int balanceFactor;
    TreeNode <NodeType> *left;
    TreeNode<NodeType> *parent;
    TreeNode <NodeType> *right;
    int height;
    
    
    // Constructor
    TreeNode():key(0), balanceFactor(0), left(nullptr), parent(nullptr), right(nullptr), height(0) {
        
    }
    
    TreeNode(const TreeNode &obj) {
        TreeNode<NodeType> *myArray = new TreeNode<NodeType>;
        myArray->parent = obj.parent;
        myArray->left = obj.left;
        myArray->right = obj.right;
        myArray->key = obj.key;
        myArray->balanceFactor = obj.balanceFactor;
        myArray->data = obj.data;
    }
    
    // Destructor
    
    ~TreeNode(){
        if (parent != nullptr)
            delete parent;
        if (right != nullptr)
            delete right;
        if (left != nullptr)
            delete left;
    }
    
    // mutators

    void setData(NodeType d){
        data = d;
    }
    void setKey(const int k){
        key = k;
    }
    
    // accessors
    NodeType getData(void){
        return data;
    }
    int getKey(void){
        return key;
    }

    short int getBalanceFactor(void){
        return balanceFactor;
    }
    
    // overloaded assignment operator
    
    TreeNode& operator=(const TreeNode& original){
        key = original.key;
        data = original.data;
        balanceFactor = original.balanceFactor;
        left = original.left;
        right = original.right;
        parent = original.parent;
        
        return *this;
    }
    
    
};


#endif /* treeNode_h */
