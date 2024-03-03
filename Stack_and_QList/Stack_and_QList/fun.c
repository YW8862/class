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




// 初始化队列 
void QueueInit(Queue* q)
{
    q->front = q->rear = NULL;
}

//  销毁队列 
void QueueDestroy(Queue* q)
{
    QNode* cur = q->front;
    QNode* next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }

    q->front = q->rear = NULL;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int isEmpty(Queue* q)
{
    return q->front == NULL && q->rear == NULL;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
    int size = 0;
    QNode* cur = q->front;

    while (cur != NULL)
    {
        size++;
        cur = cur->next;
    }

    return size;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = data;
    newNode->next = NULL;

    if (q->front == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// 队头出队列 
void QueuePop(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Error: Queue is empty.\n");
        return;
    }

    QNode* oldFront = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(oldFront);
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Error: Queue is empty.\n");
        exit(-1);
    }

    return q->front->data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Error: Queue is empty.\n");
        exit(-1);
    }

    return q->rear->data;
}

// 打印队列元素
void QueuePrint(Queue* q)
{
    QNode* cur = q->front;
    printf("Queue: ");

    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    printf("\n");
}