/*
---------------
Leetcode 103
---------------

Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
[3],
[20,9],
[15,7]
]


*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int> > rst;
		queue<TreeNode *> qu;
		if (root) qu.push(root);
		bool needReverse = false;
		while (!qu.empty())
		{
			
			queue<TreeNode *> levelQu;
			vector<int> levelVec;
			while (!qu.empty())
			{
				TreeNode * cur = qu.front();
				qu.pop();
				levelVec.push_back(cur->val);
				if (cur->left) levelQu.push(cur->left);
				if (cur->right) levelQu.push(cur->right);
			}
			if (needReverse)
			{
				reverse(levelVec.begin(), levelVec.end());
			}
			needReverse = !needReverse;
			rst.push_back(levelVec);
			qu = levelQu;
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
	vector<vector<int> > rst = sol.levelOrder(root);
	for (int i = 0; i < rst.size(); ++i)
	{
		vector<int> & level = rst[i];
		cout << "level " << i << ": ";
		for (int j = 0; j < level.size(); ++j)
		{
			cout << level[j] << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}