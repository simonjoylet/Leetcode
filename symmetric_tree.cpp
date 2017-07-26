/*
---------------
Leetcode 101
---------------

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
  1
 / \
2   2
 \   \
  3   3


*/

#include <iostream>
#include <string>
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
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		return isSymmetric(root->left, root->right);
	}
	bool isSymmetric(TreeNode* left, TreeNode * right)
	{
		if (left == NULL && right == NULL) return true;
		if (left == NULL || right == NULL) return false;
		return (left->val == right->val) && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	}
	// ∑«µ›πÈ–¥∑®
	bool isSymmetric_2(TreeNode * root)
	{
		if (root == NULL) return true;
		stack<TreeNode *> st;
		st.push(root->right);
		st.push(root->left);
		while (!st.empty())
		{
			TreeNode * l = st.top();
			st.pop();
			TreeNode * r = st.top();
			st.pop();
			if (l == NULL && r == NULL) continue;
			if (l == NULL || r == NULL) return false;
			if (l->val != r->val) return false;

			st.push(r->right);
			st.push(l->left);
			st.push(r->left);
			st.push(l->right);
		}
		return true;
	}
};



int main()
{

	Solution sol;

	getchar();
	return 0;
}