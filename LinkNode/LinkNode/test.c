#include"slist.h"

void test(SListNode** pplist)
{
	for (int i = 0; i < 20; i++)
	{
		int x = rand() % 30;
		SListPushBack(pplist, x);
	}
	SListPrint(*pplist);
}


void test1(SListNode** pplist)
{
	SListEraseAfter(pplist, 6);
	SListPrint(*pplist);
	SListEraseAfter(pplist, 10);
	SListPrint(*pplist);
	SListEraseAfter(pplist, 3);
	SListPrint(*pplist);
}
int main()
{

	int t1 = clock();
	//1
	SListNode* plist = BuySListNode(6);
	SListPrint(plist);
	//2
	SListPushBack(&plist, 34);
	SListPrint(plist);
	//3
	SListPushFront(&plist, 12);
	SListPrint(plist);
	//4
	SListPopBack(&plist);
	SListPrint(plist);
	//5
	SListPopFront(&plist);
	SListPrint(plist);
	//6
	SListInsertAfter(&plist, 2, 6);
	SListPrint(plist);

	//7.
	test(&plist);
	//8.
	test1(&plist);


	SLTDestroy(&plist);

	int t2 = clock();
	printf("%d", t2 - t1);
	return 0;

}


