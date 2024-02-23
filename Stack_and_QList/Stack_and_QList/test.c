#include"Stack_and_QList.h"
int main()
{
	Stack ST;
	StackInit(&ST);
	StackPush(&ST, 12);
	StackPush(&ST, 2);
	StackPush(&ST, 3);
	StackPush(&ST, 546);
	StackPush(&ST, 123);
	StackPush(&ST, 5435);
	StackPush(&ST, 124);
	StackPush(&ST, 35);
	StackPush(&ST, 46);
	StackPush(&ST, 57);
	while (!StackEmpty(&ST))
	{
		printf("%d ", StackTop(&ST));
		StackPop(&ST);
	}
	StackDestroy(&ST);
}