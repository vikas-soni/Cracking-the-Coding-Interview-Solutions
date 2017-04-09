#include"binary_tree.h"
#include<cstdlib>

// this is a helper recursion function.
bool Is_balanced(binary_tree_node<int> *node, int& height)
{
	if (node == nullptr)
	{
		height = 0;
		return true;
	}
		
	int l_height = 0, r_height = 0;
	if (!(Is_balanced(node->left, l_height)) || !(Is_balanced(node->right, r_height)))
		return false;

	if (l_height > r_height)
		height = l_height + 1;
	else
		height = r_height + 1;
	if (abs(l_height - r_height) > 1)
		return false;
	else
		return true;
}

bool check_balanced(binary_tree_node<int> *root)
{
	// we basically need to calculate height of left subtree and right subtree for each node
	// then if the difference is greator than 1, tree is unbalanced.
	// but time complexity is O(n^2) as for each node, we are traversing almost all nodes again
	// to find the height.

	// we can also do it in one traversal. idea is to combine the height calculation logic and node traversal logic in
	// one function
	if (root == nullptr)
		return true;
	int height = 0;
	return Is_balanced(root,height);
}

int main()
{
	// we will run tests here
	// there are 7 tests below for different scenarios
	std::cout << "\n Is the tree balanced 1: " << check_balanced(nullptr);
	binary_tree_node<int> root(10);
	std::cout << "\n Is the tree balanced 2: " << check_balanced(&root);
	root.left = new binary_tree_node<int>(9);
	root.right = new binary_tree_node<int>(11);
	std::cout << "\n Is the tree balanced 3: " << check_balanced(&root);
	root.left->left = new binary_tree_node<int>(7);
	std::cout << "\n Is the tree still balanced 4: " << check_balanced(&root);
	root.left->left->left = new binary_tree_node<int>(6);
	std::cout << "\n Is the tree still balanced 5: " << check_balanced(&root);
	root.right->left = new binary_tree_node<int>(12);
	std::cout << "\n Is the tree still balanced 6: " << check_balanced(&root);
	root.left->right = new binary_tree_node<int>(8);
	std::cout << "\n Is the tree still balanced 7: " << check_balanced(&root);
	return 0;
}