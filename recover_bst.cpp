/*
---------------
Leetcode 99
---------------

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

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
	vector<TreeNode *> inorderTraversal(TreeNode* root)
	{
		// 使用栈，空间复杂度O(n)，要想空间O(1)应该使用Morris算法实现。
		vector<TreeNode *> rst;
		stack<TreeNode *> st;
		TreeNode * cur = root;
		while (!st.empty() || cur)
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
				rst.push_back(cur);
				cur = cur->right;
			}
		}
		return rst;
	}
	void recoverTree(TreeNode* root) {
		vector<TreeNode *> inorder = inorderTraversal(root);
		int leftval = inorder[0]->val;
		int rightval = inorder[inorder.size() - 1]->val;
		int leftIndex, rightIndex;
		for (int i = 1; i < inorder.size(); ++i)
		{
			if (inorder[i]->val >= leftval)
			{
				leftval = inorder[i]->val;
			}
			else
			{
				leftIndex = i;
			}
		}

		for (int i = inorder.size() - 2; i >= 0; --i)
		{
			if (inorder[i]->val <= rightval)
			{
				rightval = inorder[i]->val;
			}
			else
			{
				rightIndex = i;
			}
		}
		
		// swap
		int tmp = inorder[leftIndex]->val;
		inorder[leftIndex]->val = inorder[rightIndex]->val;
		inorder[rightIndex]->val = tmp;
	}
};


int main()
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);

	getchar();
	return 0;
}