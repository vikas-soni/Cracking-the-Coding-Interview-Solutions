
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