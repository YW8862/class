#include <iostream>
//#include "test.h"
#include "sort.h"
#pragma pack(1)
using std::cin;
using std::cout;
using std::endl;

//test extern
//extern int a;
//extern void print();
//int main()
//{
//	cout << a << endl;
//	print();
//	return 0;
//}

//extern "C"
//{
//	int add(int a, int b, int c)
//	{
//		return a + b + c;
//	}
//}
//
//extern "C"
//{
//	double add(double a, double b)
//	{
//		return a + b;
//	}
//}

//int main()
//{
//	cout << add(10, 20, 30) << endl;
//	cout << add(3.14, 3.15) << endl;
//}

//extern template A<int>;
//extern template void showNumber<int>(int);
//
//int main()
//{
//	A<int> a;
//	a.print(2);
//	showNumber(11);
//}


//class A
//{
//public:
//	A()
//	{
//		a_data = 1;
//	}
//public:
//	int a_data;
//};
//
//class B :public A
//{
//public:
//	B()
//	{
//		b_data = 2;
//	}
//public:
//	int b_data;
//};
//
//class C :public A
//{
//public:
//	C()
//	{
//		c_data = 3;
//	}
//public:
//	int c_data;
//};
//
//class D :public B , public C
//{
//public:
//	D()
//	{
//		d_data = 4;
//	}
//public:
//	int d_data;
//};
//
//int main()
//{
//	A a;
//	B b;
//	C c;
//	D d;
//	d.B::a_data = 2025;
//	cout << d.C::a_data << endl;
//	//cout << "sizeof(A)" << sizeof(A) << endl;
//	//cout << "sizeof(B)" << sizeof(B) << endl;
//	//cout << "sizeof(C)" << sizeof(C) << endl;
//	//cout << "sizeof(D)" << sizeof(D) << endl;
//
//	return 0;
//}

//test extend
//class A
//{
//public:
//	A()
//	{
//		a_data = 1;
//	}
//public:
//	int a_data;
//};
//
//class B :virtual public A{
//public:
//	B() {}
//public:
//	int b_data;
//};
//
//class C :virtual public A {
//public:
//	C() {}
//public:
//	int c_data;
//};
//
//class D :public B, public C {
//public:
//	D() {}
//public:
//	int d_data;
//};
//
//int main()
//{
//	A a;
//	B b;
//	C c;
//	D d;
//	printf("&d.B::a_data: %p\n", &d.B::a_data);
//	printf("&d.C::a_data: %p\n", &d.C::a_data);
//	d.B::a_data = 2025;
//	cout << d.C::a_data << endl;
//	cout << "sizeof(A)" << sizeof(A) << endl;
//	cout << "sizeof(B)" << sizeof(B) << endl;
//	cout << "sizeof(C)" << sizeof(C) << endl;
//	cout << "sizeof(D)" << sizeof(D) << endl;
//	cout << "a_data " << d.a_data << endl;
//	return 0;
//}


//test sort
int main()
{
	std::vector<int> nums = {};
	selectSort(nums);
	for (auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;
	return 0;
}