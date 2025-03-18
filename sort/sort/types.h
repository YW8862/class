#ifndef __TYPES_H__
#define __TYPES_H__

struct TreeNode
{
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int data) :val(data), left(nullptr), right(nullptr) {}

	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

#endif 
