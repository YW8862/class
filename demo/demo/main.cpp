#include <iostream>
#include "test.h"
using std::cin;
using std::cout;
using std::endl;

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

extern template A<int>;
extern template void showNumber<int>(int);

int main()
{
	A<int> a;
	a.print(2);
	showNumber(11);
}
