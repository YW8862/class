#include"Stack_and_QList.h"
//int main()
//{
//	Stack ST;
//	StackInit(&ST);
//	StackPush(&ST, 12);
//	StackPush(&ST, 2);
//	StackPush(&ST, 3);
//	StackPush(&ST, 546);
//	StackPush(&ST, 123);
//	StackPush(&ST, 5435);
//	StackPush(&ST, 124);
//	StackPush(&ST, 35);
//	StackPush(&ST, 46);
//	StackPush(&ST, 57);
//	while (!StackEmpty(&ST))
//	{
//		printf("%d ", StackTop(&ST));
//		StackPop(&ST);
//	}
//	StackDestroy(&ST);
//}

int main()
{
	Queue q;
	
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 23);
	QueuePush(&q, 21);
	QueuePush(&q, 6);
	QueuePush(&q, 87);
	QueuePrint(&q);
	QueuePop(&q);
	QueuePrint(&q);
	QueueDestroy(&q);

	printf("Size of Queue is:%d \n", QueueSize(&q));
	printf("Top elem is:%d \n", QueueFront(&q));
	printf("Tail elem is:%d \n", QueueBack(&q));

	return 0;
}