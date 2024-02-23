#include"Date.h"

//namespace name1
//{
//	int a;
//	int c=1;
//}

int main()
{
	//cout << name1::c << endl;
	Date d1 = Date(2024, 2, 22);
	d1.Print();
	Date d2();
	Date().Print();
	cout << d1 <<d2<<endl;

	cout << &d1 << endl;
	return 0;
}
