#include"Date.h"

//namespace name1
//{
//	int a;
//	int c=1;
//}

int main()
{
	//cout << name1::c << endl;

	const Date d1(2024, 2, 11);
	d1.Print();
	cout << d1 << endl;

	cout << &d1 << endl;
	return 0;
}
