#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

//class person {
//public:
//	virtual void buyticket() {
//		cout << "person买票" << endl;
//	}
//	~person() {
//		cout << "~person" << endl;
//	}
//};
//
//
//class student :public person{
//public:
//	 virtual void  buyticket() {
//		cout << "student买票" << endl;
//	 }
//	 ~student() {
//		 cout << "~student" << endl;
//	 }
//};

//void fun(person& p) {
//
//	cout << typeid(p).name() << endl;
//	p.buyticket();
//
//}


//int main() {
//	person p;
//	student s;
//	//p.buyticket();
//	//s.buyticket();
//	fun(s);
//}

//int main()
//{
//	// the type of il is an initializer_list 
//	auto il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
//	return 0;
//
//}

//int main()
//{
//	int i = 10;
//	auto p = &i;
//
//	auto pf = strcpy;
//	cout << typeid(p).name() << endl;
//	cout << typeid(pf).name() << endl;
//	map<string, string> dict = { {"sort", "排序"}, {"insert", "插入"} };
//	//map<string, string>::iterator it = dict.begin();
//	auto it = dict.begin();
//
//	cout << typeid(dict).name() << endl;
//	return 0;
//}

// decltype的一些使用使用场景
//template<class T1, class T2>
//void F(T1 t1, T2 t2)
//{
//	decltype(t1 * t2) ret;
//	cout << typeid(ret).name() << endl;
//}
//int main()
//{
//	const int x = 1;
//	double y = 2.2;
//	decltype(x * y) ret; // ret的类型是double
//	decltype(&x) p;      // p的类型是int*
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//	F(1, 'a');
//	return 0;
//}

//class person {
//public:
//	virtual void buyticket() {
//		cout << "person买票" << endl;
//	}
//	~person() {
//		cout << "~person()" << endl;
//	}
//};
//
//
//class student :public person {
//public:
//	virtual void  buyticket() {
//		cout << "student买票" << endl;
//	}
//	~student() {
//		cout << "~student()" << endl;
//	}
//};
//
//class A {
//
//};
//
//class B :public A {
//
//};
//
//int main() {
//	//person p1;
//	//student s1;
//	//person* p1 = new student();
//	//delete p1;
//
//	A* a = new B;
//	int* a = new int;
//	cout << typeid(*a).name() << endl;
//	return 0;
//}

class A
{
public:
	virtual void func(int val = 1) {
		std::cout << "A->" << val << std::endl; 
	}
	virtual void test() { 
		func(); 
	}
};

class B : public A
{
public:
	void func(int val = 0) {
		std::cout << "B->" << val << std::endl; 
	}
};

int main(int argc, char* argv[])
{
	B* p = new B;
	p->test();
	p->func();
	return 0;
}

