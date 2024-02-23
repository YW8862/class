#include"SqList.h"

//初始化线性表
void SeqListInit(SeqList* ps)
{
	ps->a = (int*)malloc(sizeof(int)*20);
	ps->size = 0;
	ps->capacity = 20;
}


//检查顺序表是否已经满，如果满了，进行扩容
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

//销毁顺序表
void SeqListDestroy(SeqList* ps)
{
	ps->size = 0;
	ps->capacity = 0;
	free(ps->a);
	ps->a = NULL;
}

//打印顺序表
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

//尾插元素x
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//头插元素x
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

//删除开头元素
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

//删除末尾元素
void SeqListPopBack(SeqList* ps)
{
	assert(ps->size);
	ps->a[ps->size - 1] = 0;
	ps->size--;
}

//在顺序表中查找元素
int SeqListFind(SeqList* ps, SLDateType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i + 1;
	}
	return -1;
}

//在指定位置插入元素
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

//删除指定位置元素
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
