/*
---------------
Leetcode 144
---------------

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
 \
  2
 /
3
return [1,2,3]

*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> rst;
		stack<TreeNode *> st;
		if (root) st.push(root);
		while (!st.empty())
		{
			TreeNode * cur = st.top();
			st.pop();
			rst.push_back(cur->val);
			// 先序遍历的顺序是根左右，因此栈中先压入右子树
			if (cur->right) st.push(cur->right);
			if (cur->left) st.push(cur->left);
		}
		return rst;
	}
};


int main()
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);

	Solution sol;
	vector<int> rst = sol.preorderTraversal(root);
	
	for (size_t i = 0; i < rst.size(); ++i)
	{
		cout << rst[i] << " ";
	}
	getchar();
	return 0;
}