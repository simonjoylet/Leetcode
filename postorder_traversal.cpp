/*
---------------
Leetcode 145
---------------

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
 \
  2
 /
3
return [3,2,1]

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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> rst;
		stack<TreeNode *> st;
		TreeNode * cur = root;
		do 
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->left;
			}
			TreeNode * last = NULL;
			while (!st.empty())
			{
				cur = st.top();
				// 如果右子树为空或者刚刚访问过，则可以访问当前节点，否则处理右子树。
				if (cur->right == NULL || cur->right == last)
				{
					rst.push_back(cur->val);
					st.pop();
					last = cur;
				}
				else
				{
					cur = cur->right;
					break;
				}

			}
		} while (!st.empty());
		
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
	vector<int> rst = sol.postorderTraversal(root);

	for (size_t i = 0; i < rst.size(); ++i)
	{
		cout << rst[i] << " ";
	}
	getchar();
	return 0;
}