#pragma once

#include <vector>
#include <algorithm>

struct TreeNode {
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

bool isMirror(TreeNode* tree1, TreeNode* tree2)
{
	if (tree1 == nullptr && tree2 == nullptr)
		return true;
	if (tree1 == nullptr || tree2 == nullptr)
		return false;
	return tree1->val == tree2->val && isMirror(tree1->left, tree2->right) && isMirror(tree1->right, tree2->left);

}

bool isSymmetric(TreeNode* root)
{
	return isMirror(root, root);
}


int maxDepth(TreeNode* root)
{
	return root == nullptr ? 0 : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

void levelOrder(TreeNode* node, std::vector<std::vector<int>>& ans, int level)
{
	if (!node)
		return;
	if (level > ans.size())
		ans.push_back({});
	ans[level].push_back(node->val);
	levelOrder(node->left, ans, level + 1);
	levelOrder(node->right, ans, level + 1);
}

std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) 
{
	std::vector<std::vector<int>> ans;
	levelOrder(root, ans, 0);
	reverse(ans.begin(), ans.end());
	return ans;
}

