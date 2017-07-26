/*
---------------
Leetcode 94
---------------

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
 \
  2
 /
3
return [1,3,2]

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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> rst;
		stack<TreeNode *> st;
		TreeNode * cur = root;
		
		while (!st.empty() || cur != NULL)
		{
			if (cur)
			{
				st.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = st.top();
				st.pop();
				rst.push_back(cur->val);
				cur = cur->right;
			}
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
	vector<int> rst = sol.inorderTraversal(root);

	for (size_t i = 0; i < rst.size(); ++i)
	{
		cout << rst[i] << " ";
	}
	getchar();
	return 0;
}