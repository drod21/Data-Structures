//
//  treeNode.h
//  Project3
//
//  Created by Derek Rodriguez on 6/14/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.


#ifndef treeNode_h
#define treeNode_h

using namespace std;

template <class NodeType>;

class TreeNode {
    
private:
    int key;
    NodeType data;
    short int balanceFactor;
    TreeNode <NodeType> *left;
    TreeNode<NodeType> *parent;
    TreeNode <NodeType> *right;
    
    
public:
    
    // Constructor
    TreeNode():key(0), data(0), balanceFactor(0), parent(NULL), left(NULL), right(NULL) {
        
    }
    
    // Destructor
    
    ~TreeNode(){}

    // mutators
    void setData(NodeType d){
	data = d;
    )
    void setKey(int k){
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
	TreeNode<NodeType>* left = original->left;
	TreeNode<NodeType>* right = original->right;
	TreeNode<NodeType>* parent = original->parent;
    }
    
};


#endif /* treeNode_h */
