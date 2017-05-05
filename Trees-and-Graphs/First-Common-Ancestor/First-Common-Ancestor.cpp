
#include"binary_tree.h"
#include"assert.h"

template<typename T>
binary_tree_node<T>* lca_recur(binary_tree_node<T>* node, T& node1,
	T& node2, bool& node1_present, bool& node2_present)
{
	if(node == nullptr)
		return node;
	if (node->value == node1)
	{
		node1_present = true;
		return node;
	}
	if (node->value == node2)
	{
		node2_present = true;
		return node;
	}

	binary_tree_node<T>* l_node = lca_recur(node->left, node1, node2, node1_present, node2_present);
	binary_tree_node<T>* r_node = lca_recur(node->right, node1, node2, node1_present, node2_present);

	if (l_node && r_node)
		return node;
	if (!l_node)
		return r_node;
	else
		return l_node;
}

template<typename T>
binary_tree_node<T>* lca(binary_tree_node<T>* root, T node1, T node2)
{

	if (root == nullptr)
		return root;
	bool  node1_present = false, node2_present = false;
	binary_tree_node<int>* result = lca_recur(root, node1, node2, node1_present, node2_present);
	if (node1_present && node2_present)
		return result;
	else
		return nullptr;

}
int main()
{
	// below are 3 test cases
	binary_tree_node<int>* result;
	binary_tree_node<int>* root = nullptr;
	result = lca(root, 17, 20);
	assert(result == nullptr && "expected result is nullptr");
	root = new binary_tree_node<int>(15);
	root->left = new binary_tree_node<int>(9);
	root->right = new binary_tree_node<int>(20);
	result = lca(root, 17, 20);
	assert(result == nullptr && "expected result is nullptr");
	root->left->right = new binary_tree_node<int>(17);
	result = lca(root, 17, 20);
	assert(result->value == 15 && "expected result is 15");
	return 0;
}