#include"tree.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if ((*pi) == n)
		return NULL;
	if ((a[*pi] == '#'))
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_left=NULL;
	root->_right=NULL;
	root->_data = a[*pi];
	(*pi)++;
	root->_left = BinaryTreeCreate(a, n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (!root || k <= 0) 
		return 0;

	int level = 1;
	queue<BTNode*> q{ {root} };

	while (!q.empty()) {
		int size = q.size();
		if (level == k) {
			// Count the number of nodes at current level
			int count = 0;
			for (int i = 0; i < size; ++i) {
				auto node = q.front();
				q.pop();
				if (node != nullptr) {
					++count;
				}
			}
			return count;
		}

		for (int i = 0; i < size; ++i) {
			auto node = q.front();
			q.pop();

			if (node->_left) {
				q.push(node->_left);
			}
			if (node->_right) {
				q.push(node->_right);
			}
		}

		++level;
	}

	return 0;
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* p = BinaryTreeFind(root->_left,x);
	BTNode* q = BinaryTreeFind(root->_right,x);
	return p ? p : q;
}

// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
		queue<BTNode*> Q;
		Q.push(root);

		while (!Q.empty()) {
			BTNode* current = Q.front();
			Q.pop();

				// 输出节点的值
			cout << current->_data << " ";

			// 如果左子节点不为空，则将其插入队列
			if (current->_left) {
				Q.push(current->_left);
			}

			// 如果右子节点不为空，则将其插入队列
			if (current->_right) {
				Q.push(current->_right);
			}
		}
	
}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	if (!root) {
		return true;
	}

	bool isLastNonNullNodeFound = false;
	vector<BTNode*> currLevel{ root };

	while (true) {
		vector<BTNode*> nextLevel;

		for (auto& currNode : currLevel) {
			if (currNode) {
				if (isLastNonNullNodeFound && !currNode->_left && !currNode->_right) {
					return false;
				}

				if (currNode->_left) {
					nextLevel.push_back(currNode->_left);
				}

				if (currNode->_right) {
					nextLevel.push_back(currNode->_right);
				}
				else {
					isLastNonNullNodeFound = true;
				}
			}
			else {
				if (!isLastNonNullNodeFound) {
					return false;
				}
			}
		}

		if (nextLevel.empty()) {
			break;
		}

		currLevel.swap(nextLevel);
	}

	for (const auto& elem : currLevel) {
		if (elem && !(elem->_left == nullptr && elem->_right == nullptr)) {
			return false;
		}
	}

	return true;


	
}