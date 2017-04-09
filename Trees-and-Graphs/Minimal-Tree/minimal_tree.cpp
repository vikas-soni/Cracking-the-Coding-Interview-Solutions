#include<vector>
#include<assert.h>

#include"bst.h"
using namespace std;

void min_tree(vector<int>& input, bst* result, int start, int end)
{
	if (start <= end)
	{
		int mid = (start + end) / 2;
		result->add(input[mid]);
		min_tree(input, result, start, mid-1);
		min_tree(input, result, mid + 1, end);
	}
}

binary_tree_node<int>* minimal_tree(vector<int>& input)
{
	int len = input.size();
	if (len == 0)
		return nullptr;
	// to get minimal height tree from a sorted array, we need to use middle element as root,
	// then recursively add middle element of left half array to left, middle element of right
	// half array to right.
	bst* result = new bst;
	min_tree(input,result, 0, len - 1);
	return result->root;
}

int main()
{
	binary_tree_node<int>* result = nullptr;
	vector<int> input1 = {};
	result = minimal_tree(input1);
	assert((height(result) == 0) && "expected height of tree is 0");

	vector<int> input2 = {1};
	result = minimal_tree(input2);
	assert((height(result) == 1) && "expected height of tree is 1");

	vector<int> input3 = { 1,2 };
	result = minimal_tree(input3);
	assert((height(result) == 2) && "expected height of tree is 2");

	vector<int> input4 = {1,2,3,4,5,6,7,8};
	result = minimal_tree(input4);
	assert((height(result) == 4) && "expected height of tree is 4");
	return 0;
}