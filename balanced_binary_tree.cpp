/*
---------------
Leetcode 110
---------------

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as 
a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


*/

#include <iostream>
#include <string>
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
	bool isBalanced(TreeNode* root) {
		return (balancedHeight(root) >= 0);
	}
	int balancedHeight(TreeNode *root)
	{
		if (root == NULL) return 0;
		int leftH = balancedHeight(root->left);
		int rightH = balancedHeight(root->right);
		if (leftH < 0 || rightH < 0 || abs(leftH - rightH) > 1) return -1;
		return max(leftH, rightH) + 1;
	}
};



int main()
{

	Solution sol;

	getchar();
	return 0;
}