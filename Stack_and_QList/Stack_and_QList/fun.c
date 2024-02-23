#include"Stack_and_QList.h"

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType));
	ps->capacity = 1;
	ps->top = -1;
}


//ջ������
void StackAdd(Stack* ps)
{
	STDataType* p = (STDataType*)realloc(ps->a, sizeof(STDataType)*2*ps->capacity);
	if (p)
	{
		ps->a = p;
		ps->capacity = ps->capacity * 2;
	}
}

// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	ps->top++;
	if (ps->top == ps->capacity)
		StackAdd(ps);
	ps->a[ps->top] = data;
}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	ps->top--;
}


// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->a[ps->top];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top + 1;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == -1;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = -1;
	ps->capacity = 0;
}
