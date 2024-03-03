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




// ��ʼ������ 
void QueueInit(Queue* q)
{
    q->front = q->rear = NULL;
}

//  ���ٶ��� 
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

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int isEmpty(Queue* q)
{
    return q->front == NULL && q->rear == NULL;
}

// ��ȡ��������ЧԪ�ظ��� 
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

// ��β����� 
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

// ��ͷ������ 
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
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Error: Queue is empty.\n");
        exit(-1);
    }

    return q->front->data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Error: Queue is empty.\n");
        exit(-1);
    }

    return q->rear->data;
}

// ��ӡ����Ԫ��
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