
#include"binary_tree.h"

/// SOLUTION 1 without using link to parent node //////////////////////////////////////////////////////////
template<typename T>
binary_tree_node<T>* inorder(binary_tree_node<T>* input_node, binary_tree_node<T>* root)
{
	// base case
	if (input_node == nullptr)
		return NULL;

	// For BST, in order successor of a node can be found by checking smallest
	// value on the right side of the node. This only works if the node on right
	// side of the given node is not NULL.
	if (input_node->right != nullptr)
	{
		binary_tree_node<T>* curr_node = input_node->right;
		while (curr_node->left != nullptr)
			curr_node = curr_node->left;
		return curr_node;
	}

	// if the right node of the input node is NULL, then we need to use a different
	// approach. First we will solve the problem considering we dont have any links to parent node.
	// We will need to start searching from the root and will hance need root node pointer.
	binary_tree_node<T>* curr_node = root;
	binary_tree_node<T>* inorder_node = nullptr;
	while (curr_node != nullptr)
	{
		if (input_node->value < curr_node->value)
		{
			inorder_node = curr_node;
			curr_node = curr_node->left;
		}
		else if (input_node->value > curr_node->value)
		{
			curr_node = curr_node->right;
		}
		else // nodes are equal
		{
			break;
		}
		return inorder_node;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////

/// SOLUTION 2 using link to parent node //////////////////////////////////////////////////////////
template<typename T>
mod_btnode<T>* inorder(mod_btnode<T>* input_node)
{
	// base case
	if (input_node == nullptr)
		return NULL;

	// For BST, in order successor of a node can be found by checking smallest
	// value on the right side of the node. This only works if the node on right
	// side of the given node is not NULL.
	if (input_node->right != nullptr)
	{
		mod_btnode<T>* curr_node = input_node->right;
		while (curr_node->left != nullptr)
			curr_node = curr_node->left;
		return curr_node;
	}

	// if the right node of the input node is NULL, then we need to use a different
	// approach.
	// We will use the parent pointer to travel up and find inorder successor.
	// if we draw a diagram of BST with some nodes and look at 2-3 different scenarios,
	// the solution will be more clear.
	// Idea is to start travel up from input node until we get a node which is left to its parent.
	// that node will be the inorder successor for given node
	mod_btnode<T>* curr_node = input_node;
	mod_btnode<T>* parent_node = input_node->parent;
	// move up until the current node is on right of its parent
	while ((parent_node != nullptr) && (curr_node != parent_node->left))
	{
		curr_node = parent_node;
		parent_node = curr_node->parent;
	}
	return parent_node;
}

int main()
{
	return 0;
}