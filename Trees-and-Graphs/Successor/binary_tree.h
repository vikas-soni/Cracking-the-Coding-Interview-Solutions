
#include<iostream>
#include<cstdio>
#include<algorithm>

// This is a generic binary tree node
template<typename T>
class binary_tree_node
{
public:
	T value;
	binary_tree_node *left;
	binary_tree_node *right;
	binary_tree_node() :value(0), left(nullptr), right(nullptr) {}
	binary_tree_node(int val) :value(val), left(nullptr), right(nullptr) {}
};

template<typename T>
class mod_btnode :public binary_tree_node<T>
{
public:
	// add parent node
	binary_tree_node<T>* parent;
	mod_btnode() :value(0), left(nullptr), right(nullptr), parent(nullptr){}
	mod_btnode(int val):value(val), left(nullptr), right(nullptr), parent(nullptr) {}
};