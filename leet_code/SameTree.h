#pragma once

#include <vector>
/**
* Definition for a binary tree node. */


struct TreeNode {
	TreeNode() = default;
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

bool isSameTree(TreeNode* p, TreeNode* q) 
{
	if (nullptr == p && nullptr == q)
		return true;
	if (nullptr != p && nullptr != q)
	{
		if (p->val != q->val)
			return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
	return false;
}
