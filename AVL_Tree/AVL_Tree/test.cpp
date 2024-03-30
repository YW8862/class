#include"AVL_Tree.h"

int main() {
	AVLTree<int, int>tree;
	tree.Insert({2,3});
	tree.Insert({3,3});
	tree.Insert({4,3});
	tree.Insert({5,3});
	tree.Insert({6,3});
	tree.Insert({7,3});
	tree.Insert({8,3});
	tree.Inorder();
	return 0;
}