#include"SqList.h"


int main()
{
	SeqList ps;
	SeqListInit(&ps);
	SeqListPushBack(&ps, 123);
	SeqListPrint(&ps);
	SeqListPushBack(&ps, 456);
	SeqListPrint(&ps);
	SeqListPushBack(&ps, 789);
	SeqListPrint(&ps);
	SeqListPushBack(&ps, 111);
	SeqListPrint(&ps);
	SeqListPushFront(&ps, 234);
	SeqListPrint(&ps);
	SeqListPushFront(&ps, 345);
	SeqListPrint(&ps);
	SeqListPushFront(&ps, 456);
	SeqListPrint(&ps);
	SeqListPushFront(&ps, 567);
	SeqListPrint(&ps);
	SeqListPushFront(&ps, 678);
	SeqListPrint(&ps);

	SeqListPopBack(&ps);
	SeqListPrint(&ps);
	SeqListPopFront(&ps);
	SeqListPrint(&ps);

	SeqListInsert(&ps, 4, 6);
	SeqListPrint(&ps);

	SeqListErase(&ps, 7);
	SeqListPrint(&ps);

	printf("The \"%d\" is at local %d\n", 234, SeqListFind(&ps, 234));

	return 0;
}