#include"binary_tree.h"

// to check if a tree is BST or not, we need to make sure that for each node, maximum element
// in the left of the tree is smaller than the node and minimum value in the right of the tree is bigger
// than the node. Time complexity of this algorith is O(n^2).
// we can also do this in O(n) using BST properties.

bool IsBst_recur(binary_tree_node<int>* node, int min, int max)
{
	if (node == nullptr)
		return true;
	// if node violates the BST property, then return false
	if ((node->value < min) || (node->value > max))
		return false;
	// check for each node.
	// when traversing left side of the current node, we need to only make sure if the values are between
	// min and node value-1. Similarly for right side of the node, we need to make sure that values are between node_value+1
	// and max
	if ((!IsBst_recur(node->left, min, node->value - 1))
		|| (!IsBst_recur(node->right, node->value + 1, max)))
		return false;
	return true;
}

bool IsBst(binary_tree_node<int>* root)
{
	// base case
	if (root == nullptr)
		return true;
	// we will start with min and max values
	return IsBst_recur(root, INT_MIN, INT_MAX);
}

int main()
{
	//  5 test cases
	std::cout << "\n Is tree a BST 1: " << IsBst(nullptr);
	binary_tree_node<int>* root = new binary_tree_node<int>(15);
	std::cout << "\n Is tree a BST 2: " << IsBst(root);
	root->left = new binary_tree_node<int>(9);
	std::cout << "\n Is tree a BST 3: " << IsBst(root);
	root->right = new binary_tree_node<int>(20);
	std::cout << "\n Is tree a BST 4: " << IsBst(root);
	root->left->right = new binary_tree_node<int>(17);
	std::cout << "\n Is tree a BST 5: " << IsBst(root);
	return 0;
}