#include<iostream>
using namespace std;

void fun(int a = 0, int b = 3, int c = 2)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
int main()
{
	fun(1, 2, 5);
	return 0;
}
