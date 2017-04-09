#include<vector>
#include<list>
#include<queue>
#include"assert.h"

#include"binary_tree.h"

using namespace std;

// function will return vector of list
template<typename T>
vector<list<binary_tree_node<T>*>> ListOfDepths(binary_tree_node<T>* root)
{
	vector<list<binary_tree_node<T>*>> lod;
	//base case
	if (root == nullptr)
		return lod;
	
	// we need to do a level order traversal. We also need to keep track of current depth
	// so that whenever we start at a new depth, we create a new list.
	// to achieve this lets use a queue of pair of node and level of that node.
	queue<pair<binary_tree_node<T>*, int>> my_queue;
	// root will start from level 0
	my_queue.emplace(root, 0);
	//list to store nodes of current level
	list<binary_tree_node<T>*> temp_list;
	//initialise to -1 for algorithm
	int curr_level = -1;
	// till queue has some data
	while (!my_queue.empty())
	{
		// pop out the top node
		pair<binary_tree_node<T>*, int> temp_node = my_queue.front();
		my_queue.pop();
		// push all childs of temp node in queue. all childs will be at 1 deeper level. so we also increment the level
		// for them
		if (temp_node.first->left)
			my_queue.emplace(temp_node.first->left, temp_node.second + 1);
		if (temp_node.first->right)
			my_queue.emplace(temp_node.first->right, temp_node.second + 1);
		// also if the popped out node has the level which is different than current_level
		if (temp_node.second != curr_level)
		{
			if (!temp_list.empty())
			{
				lod.emplace_back(temp_list);
				temp_list.clear();
			}			
			curr_level = temp_node.second;
		}
		temp_list.emplace_back(temp_node.first);
	}
	if (!temp_list.empty())
		lod.emplace_back(temp_list);
	return lod;
}

int main()
{
	// below are few test cases. they are not strong test cases but good enough to check in a debugger
	// ideally i should have validate result with the exact expected result
	vector<list<binary_tree_node<int>*>> result;
	result = ListOfDepths<int>(nullptr);
	assert((result.size() == 0) && "result should have 0 depth");
	binary_tree_node<int> root(10);
	result = ListOfDepths<int>(&root);
	assert((result.size() == 1) && "result should have 1 depth");
	root.left = new binary_tree_node<int>(9);
	result = ListOfDepths<int>(&root);
	assert((result.size() == 2) && "result should have 2 depth");
	root.right = new binary_tree_node<int>(11);
	result = ListOfDepths<int>(&root);
	assert((result.size() == 2) && "result should have 2 depth");
	root.left->left = new binary_tree_node<int>(7);
	result = ListOfDepths<int>(&root);
	assert((result.size() == 3) && "result should have 3 depth");
	root.left->left->left = new binary_tree_node<int>(6);
	result = ListOfDepths<int>(&root);
	assert((result.size() == 4) && "result should have 4 depth");
	root.right->left = new binary_tree_node<int>(12);
	result = ListOfDepths<int>(&root);
	assert((result.size() == 4) && "result should have 4 depth");
	root.left->right = new binary_tree_node<int>(8);
	result = ListOfDepths<int>(&root);
	assert((result.size() == 4) && "result should have 4 depth");
	return 0;
}