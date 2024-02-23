#include"tree.h"

void QueueInit(Queue** p)
{
	*p = (Queue*)malloc(sizeof(BTNode) * 1000);
	(*p)->pt = 0;
	(*p)->ph = 0;
}

void QueuePush(Queue** p, BTNode x)
{
	(*p)->data[(*p)->ph] = x;
	(*p)->ph++;
}

void QueuePop(Queue** p)
{
	printf("%c ", (*p)->data[(*p)->ph]);
	(*p)->pt++;
}

void QueueDestory(Queue** p)
{
	free((*p)->data);
}

bool QueueIsEmpty(Queue* p)
{
	return p->ph == p->pt;
}

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a)
{
	if (*a == '\0')
		return NULL;
	if (*a == '#')
	{
		a++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_left = root->_right = NULL;
	root->_data = *a;
	a++;
	root->_left = BinaryTreeCreate(a);
	root->_data = BinaryTreeCreate(a);
	return root;
}

// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;
	BinaryTreeDestory((*root)->_left);
	BinaryTreeDestory((*root)->_right);
	free(*root);
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (k == 1)
		if (root)
			return 1;
		else
			return 0;
	else
	{
		return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
	}
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (x == root->_data)
		return root;
	
	BTNode*tmp1=BinaryTreeFind(root->_left, x);
	BTNode*tmp2=BinaryTreeFind(root->_right, x);
	if (tmp1 == NULL && tmp2 == NULL)
	{
		return NULL;
	}
	if (tmp1)
		return tmp1;
	return tmp2;
}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}

// ������� --------------------------------------------------��Ҫ�޸�
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
		return;
	Queue* p;
	QueueInit(&p);
	QueuePush(&p, *root);
	while (!QueueIsEmpty(&p))
	{
		if (root->_left)
			QueuePush(&p, *root->_left);
		if (root->_right)
			QueuePush(&p, *root->_right);
		QueuePop(&p);
	}
	QueueDestory(&p);
}


// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
		return true;
	if (!((root->_left == NULL) ^ (root->_right == NULL)))
		return false;
	return BinaryTreeComplete(root->_left) && BinaryTreeComplete(root->_right);
	
}