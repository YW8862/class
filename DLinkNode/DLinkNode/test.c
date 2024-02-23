#include"DLinkNode.h"

void test()
{

}




int main()
{
	ListNode* plist;
	plist = ListCreate();
	ListPushBack(plist, 23);
	ListPrint(plist);
	ListPushBack(plist, 76);
	ListPrint(plist);
	ListPushFront(plist, 5);
	ListPrint(plist);
	//ListPopBack(plist);
	//ListPrint(plist);
	//ListPopFront(plist);
	//ListPrint(plist);
	printf("%0xp\n", ListFind(plist, 23));
	printf("%0xp\n", ListFind(plist, 5));
	ListInsert(ListFind(plist, 5), 12);
	ListPrint(plist);
	ListErase(ListFind(plist, 5));
	ListPrint(plist);
	ListDestory(plist);
}