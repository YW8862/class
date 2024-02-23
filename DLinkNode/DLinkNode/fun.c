//fun.h
#pragma once
#include"DLinkNode.h"

//typedef int LTDataType;
//typedef struct ListNode
//{
//	LTDataType data;
//	struct ListNode* next;
//	struct ListNode* pre;
//}ListNode;

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->data = 0;
	head->next = head;
	head->pre = head;
	return head;
}

// ˫����������
void ListDestory(ListNode* pHead)
{
	if (pHead == NULL)
		return;
	ListNode* p = pHead->next;
	ListNode* q = pHead->next;

	while (p != pHead)
	{
		q = p->next;
		p->next->pre = p->pre;
		p->pre->next = p->next;
		free(p);
		p = q;
	}
	free(pHead);
}

// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	ListNode* p = pHead->next;
	while (p != pHead)
	{
		printf("%d<==> ", p->data);
		p = p->next;
	}
	printf("\n");
}

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = x;
	p->next = NULL;
	p->pre = NULL;
	p->next = pHead;
	p->pre = pHead->pre;
	pHead->pre->next = p;
	pHead->pre = p;
}

// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	if (pHead == NULL)
		return;
	ListNode* p = pHead->pre;
	p->pre->next = pHead;
	pHead->pre = p->pre;
	free(p);
}

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = x;
	p->next = NULL;
	p->pre = NULL;
	p->next = pHead->next;
	p->pre = pHead;
	pHead->next->pre = p;
	pHead->next = p;
}

// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	if (pHead == NULL||(pHead->next == pHead))
		return;
	ListNode* p = pHead->next;
	pHead->next = p->next;
	pHead->next->pre = pHead;
	free(p);
}

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	ListNode* p = pHead->next;
	while (p != pHead)
	{
		if (p->data == x)
			return p;
		p = p->next;
	}
	return NULL;
}

// ˫��������pos��ǰ����в���
void ListInsert( ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* p = pos->pre;
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	tmp->data = x;
	tmp->pre = p;
	tmp->next = pos;
	p->next = tmp;
	pos->pre = tmp;

}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* p = pos->pre;
	p->next = pos->next;
	pos->next->pre = p;
	free(pos);
}