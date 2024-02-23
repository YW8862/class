#include<iostream>
using namespace std;

class A
{

};

struct ListNode
{
	struct ListNode(int val)
	{
		data = val;
	}
	struct ListNode* next;
	struct ListNode* pre;
	int data;
};



int main()
{
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);

	return 0;
}