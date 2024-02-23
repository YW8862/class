#include"Stack_and_QList.h"

// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType));
	ps->capacity = 1;
	ps->top = -1;
}


//栈的扩容
void StackAdd(Stack* ps)
{
	STDataType* p = (STDataType*)realloc(ps->a, sizeof(STDataType)*2*ps->capacity);
	if (p)
	{
		ps->a = p;
		ps->capacity = ps->capacity * 2;
	}
}

// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	ps->top++;
	if (ps->top == ps->capacity)
		StackAdd(ps);
	ps->a[ps->top] = data;
}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	ps->top--;
}


// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->a[ps->top];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top + 1;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == -1;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = -1;
	ps->capacity = 0;
}
