#include"tree.h"

int main()
{
	char str[] = "ABD##E#H##CF##G##";
	BTNode* root=BinaryTreeCreate(str);
	BinaryTreePostOrder(root);
	//BinaryTreePrevOrder(root);
	BinaryTreeDestory(&root);
	return 0;
}
