#include<iostream>
using namespace std;

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}

	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}

	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

void f1(A aa)
{}

A f2()
{
	A aa;
	return aa;
}

//int main()
//{
//	cout << "1" << endl;
//	// 传值传参
//	A aa1;
//	f1(aa1);
//	
//	// 传值返回
//	cout << "2" << endl;
//
//	f2();
//	// 隐式类型，连续构造+拷贝构造->优化为直接构造
//	cout << "3" << endl;
//
//	f1(1);
//	// 一个表达式中，连续构造+拷贝构造->优化为一个构造
//	f1(A(2));
//	cout << "4" << endl;
//
//	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
//	A aa2 = f2();
//	cout << "5" << endl;
//	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
//	aa1 = f2();
//	return 0;
//}
struct ListNode
{
	ListNode* next;
	int val;
	ListNode(int n)
	{
		val = n;
	}
};

struct ListNode Create_Node(int n)
{
	return NULL;
}
int main()
{
	/*A aa= f2();
	return 0;*/
	//int a = 1;
	//const int b = 1;
	////cout << &a << endl << &b << endl;
	//int* p = new int;
	//*p = 2;
	//cout << *p << endl;

	//int* p2 = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//for (size_t i = 0; i < 10; i++)
	//{
	//	cout << p2[i] << " ";
	//}
	//cout << endl;
	//struct ListNode* node1 = new ListNode(1);
	//struct ListNode* node2 = new ListNode(2);
	//struct ListNode* node3 = new ListNode(3);
	//delete p;
	//delete[]p2;
	//delete node1;
	//delete node2;
	//delete node3;
	int a = 1;
	int* b = new int(10);
	cout << &a <<endl<< b << endl;


	return 0;
}