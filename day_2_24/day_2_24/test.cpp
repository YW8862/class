#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

template<typename T1, typename T2, typename T3>
T3 Add(T1 x, T2 y)
{
	return x + y;
}

//int main()
//{
//	int a = 1;
//	double b = 1.1;
//	
//	cout << Add<int,double,double>(a, b) << endl;
//	return 0;
//}

template<typename T>
class A
{
private:
	T a;
	A* next;
};

void test_string2()
{
	string s1("hello world!");
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
}

int main()
{
	//string s0;
	char s[] = "abdefghijklmnopqrstuvwxyz";
	string s1(s);
	//string s2(s1);
	string s3(s1, 5, 10);
	//string s4("hello world", 3);
	//string s5(10, '3');
	//cout << s0 << endl;
	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << s3 << endl;
	//cout << s4 << endl;
	//cout << s5 << endl;
	//test_string2();
	//string::iterator it3 = s3.begin();
	//while (it3!=s3.end())
	//{
	//	cout << *it3 << " ";
	//	++it3;
	//}
	//cout << endl;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int>::iterator tv = v.begin();
	while (tv!=v.end())
	{
		cout << *tv << " ";
		++tv;
	}
	cout << endl;

	for (auto k:v)
	{
		cout << k << " ";
	}
	cout << endl;


	return 0;
}
