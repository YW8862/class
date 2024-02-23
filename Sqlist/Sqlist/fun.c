#include"SqList.h"

//��ʼ�����Ա�
void SeqListInit(SeqList* ps)
{
	ps->a = (int*)malloc(sizeof(int)*20);
	ps->size = 0;
	ps->capacity = 20;
}


//���˳����Ƿ��Ѿ�����������ˣ���������
void CheckCapacity(SeqList* ps)
{
	int* ptr = NULL;
	if (ps->size == ps->capacity)
	{
		ptr = (int*)realloc(ps->a, sizeof(int) * (ps->capacity)*2);
		if (ptr)
			ps->a = ptr;
	}
}

//����˳���
void SeqListDestroy(SeqList* ps)
{
	ps->size = 0;
	ps->capacity = 0;
	free(ps->a);
	ps->a = NULL;
}

//��ӡ˳���
void SeqListPrint(SeqList* ps)
{
	if (ps->a == NULL)
	{
		printf("ERROR!\n");
		return;
	}
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//β��Ԫ��x
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//ͷ��Ԫ��x
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	CheckCapacity(ps);
	for (int i = ps->size; i>0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}

//ɾ����ͷԪ��
void SeqListPopFront(SeqList* ps)
{
	assert(ps->size);
	for (int i = 0; i < ps->size-1; i++)
	{
		ps->a[i] = ps->a[i+1];
	}
	ps->a[ps->size - 1] = 0;
	ps->size--;
}

//ɾ��ĩβԪ��
void SeqListPopBack(SeqList* ps)
{
	assert(ps->size);
	ps->a[ps->size - 1] = 0;
	ps->size--;
}

//��˳����в���Ԫ��
int SeqListFind(SeqList* ps, SLDateType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i + 1;
	}
	return -1;
}

//��ָ��λ�ò���Ԫ��
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	CheckCapacity(ps);
	int loc = pos - 1;
	for (int i = ps->size; i>loc;i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[loc] = x;
	ps->size++;
}

//ɾ��ָ��λ��Ԫ��
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps->size>=pos);
	int loc = pos - 1;
	for (int i = loc; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->a[ps->size - 1] = 0;
	ps->size--;
}
