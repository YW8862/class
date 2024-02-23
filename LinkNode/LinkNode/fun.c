#include"slist.h"

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* phead = (SListNode*)malloc(sizeof(SListNode));
	phead->data = x;
	phead->next = NULL;
	return phead;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
	//assert(plist);
	SListNode* tmp = plist;
	if (tmp == NULL)
		printf("Empty LinkNode\n");
	while (tmp)
	{
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	printf("NULL\n");

}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist && *pplist);
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));

	tmp->data = x;
	tmp->next = NULL;
	SListNode* p = *pplist;
	while (p->next)
	{
		p = p->next;
	}
	p->next = tmp;

}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{  
	assert(pplist && *pplist);

	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	tmp->data = x;
	tmp->next = NULL;
	SListNode* p = (*pplist)->next;
	(*pplist)->next = tmp;
	tmp->next = p;

}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(pplist && *pplist);
	SListNode* p=*pplist;
	SListNode* q = (*pplist)->next;

	if (p->next == NULL)
		free(p);
	else
	{
		while (q->next)
		{
			p = p->next;
			q = q->next;
		}
		free(q);
		p->next = NULL;
	}
}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(pplist && (*pplist));
	SListNode* p = (*pplist)->next;
	SListNode* q = *pplist;
	*pplist = p;
	free(q);
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	SListNode* p = plist;
	while (p)
	{
		if (p->data == x)
			return p;
		else
			p = p->next;
	}
}


// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode** pphead, int pos, SLTDateType x)
{
	if (pphead == NULL || (*pphead) == NULL)
	{
		printf("Input a NULL point,Check!\n");
		return;
	}
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	tmp->data = x;
	tmp->next = NULL;
	int n = 1;
	SListNode* p = *pphead;
	//SListNode* q = *pphead;

	while (n < pos && p)
	{
		n++;
		p = p->next;
	}
	//while (q->next)
	//{
	//	q = q->next;
	//}
	if (n == pos && p != NULL)
	{
		tmp->next = p->next;
		p->next = tmp;
	}
	//else if (n == pos && p == NULL)
	//{
	//	q->next = tmp;
	//}
	else 
	{
		printf("Error!\n");
		return;
	}


}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode** pphead, int pos)
{
	if ((*pphead) == NULL || pphead == NULL)
	{
		printf("Input a NULL point,Check!\n");
		return;
	}
	int n = 1;
	SListNode* p = *pphead;
	while (n < pos && p)
	{
		n++;
		p = p->next;
	}
	if (n == pos && p != NULL)
	{
		
		if (p->next)
		{	
			SListNode* q = p->next->next;
			free(p->next);
			p->next = q;
		}
			
		
	}
	else
	{
		printf("Error!\n");
		return;
	}

}

//销毁链表
void SLTDestroy(SListNode** pphead)
{
	if (pphead == NULL || (*pphead) == NULL)
		return;
	SListNode* p = *pphead;
	SListNode* q = (*pphead)->next;
	while (p)
	{
		free(p);
		p = q;
		if (q)
			q = q->next;
	}
	*pphead = NULL;

}