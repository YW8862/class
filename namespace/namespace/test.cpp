#include<iostream>
using namespace std;

namespace space_name
{
	//name
}







//int add(int x)
//{
//	return x + n;
//}

namespace fun
{
	int n(int a, int b)
	{
		return a + b;
	}
}

//namespace num
//{
//	namespace num1
//	{
//		int x;
//		int n;
//	}
//	namespace num2
//	{
//		int x;
//		int n;
//	}
//}

//void test1()
//{
//	num::num1::n = 1;
//	cout << num::num1::n << endl;
//}
//
//void test2()
//{
//	using num::num1::n;
//	n = 1;
//	cout << n << endl;
//}
//
//void test3()
//{
//	using namespace num::num1;
//	n = 1;
//	cout << n << endl;
//}

//int main()
//{
//	test1();
//	test2();
//	test3();
//	return 0;
//}

//namespace num
//{
//	int n;
//}
//
//void test1()
//{
//	using namespace num;
//}
//
//int Add(int x)
//{
//	return n + x;
//}
//
//int main()
//{
//	cout << Add(3) << endl;
//	return 0;
//}

template<typename T1,typename T2,typename T3>
T3 Add(T1 x, T2 y)
{
	return x + y;
}

int main()
{
	int a = 1;
	double b = 1.1;
	cout << Add(a, b) << endl;

	return 0;
}
