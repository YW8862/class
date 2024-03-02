#include"tree.h"
int main()
{
	const char a[] = "ABD##E#H##CF##G##";
	int p = 0;
	BTNode* root = BinaryTreeCreate(a, sizeof(a), &p);
	BinaryTreePrevOrder(root);
	printf("\n");

	printf("The number of the tree is: %d \n", BinaryTreeSize(root));
	printf("\n");

	printf("The number of the tree'sleaves is: %d \n", BinaryTreeLeafSize(root));
	printf("\n");

	BinaryTreeDestory(&root);
	return 0;
}