#include<iostream>
#include<cstdio>
#include<algorithm>
#include"assert.h"

#include"binary_tree.h"

// This is a wrapper class for a binary search tree
class bst
{
public:
	binary_tree_node<int> *root;
	bst() :root(nullptr){}
	// add a new node with value val
	inline void add(int val)
	{
		this->root = add(this->root,val);
	}
private:
	// private utility function which is not exposed
	binary_tree_node<int>* add(binary_tree_node<int>* node, int val);
};

binary_tree_node<int>* bst::add(binary_tree_node<int>* node, int val)
{
	//base case
	if (node == nullptr)
	{
		return new binary_tree_node<int>(val);
	}
	else if (val > node->value)
	{
		node->right = add(node->right, val);
	}
	else if(val < node->value)
	{
		node->left = add(node->left, val);
	}
	else
	{
		assert(0 && "\n Same value node is being added twice which is currently not allowed");
	}
	return node;
}

// utility function
int height(binary_tree_node<int>* node)
{
	if (node == nullptr)
		return 0;
	int l_height = height(node->left);
	int r_height = height(node->right);
	return (1 + std::max(l_height, r_height));
}