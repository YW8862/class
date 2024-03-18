#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

//class A {
//public:
//	virtual void fun() {
//		cout << "A::fun()" << endl;
//	}
//};
//
//class B : public A {
//public:
//	virtual void fun() {
//		cout << "B::fun()" << endl;
//	}
//};
//
//void test(A& a) {
//	a.fun();
//}
//
//int main() {
//	A a;
//	test(a);
//	B b;
//	test(b);
//	return 0;
//}


//class Base
//{
//public:
//	Base()
//		:_b(2)
//	{
//		//cout << "Base()" << endl;
//	}
//	
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//	
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//	
//	virtual void Func3()
//	{
//		cout << "Derive::Func3()" << endl;
//	}
//private:
//	int _d = 2;
//};
//	
//
//typedef void(*VF_PTR)();
//void test(VF_PTR* vft) {
//	for (size_t i = 0; vft[i] != nullptr; i++) {
//		cout << "[" << i << "]:" << vft[i] << "->";
//		VF_PTR f = vft[i];
//		f();
//	}
//}
//
//int main() {
//	Base bb;
//	Derive dd;
//	cout << &bb << endl;
//	test((VF_PTR*)(*((int*)&bb)));
//	test((VF_PTR*)(*((int*)&dd)));
//	return 0;
//}

//int main()
//{
//	Base b;
//
//	Derive d;
//
//
//	int i = 0;
//	static int j = 1;
//	int* p1 = new int;
//	const char* p2 = "xxxxxxxx";
//	printf("栈:%p\n", &i);
//	printf("静态区:%p\n", &j);
//	printf("堆:%p\n", p1);
//	printf("常量区:%p\n", p2);
//
//	Base* p3 = &b;
//	Derive* p4 = &d;
//
//	printf("Base虚表地址:%p\n", *(int*)p3);
//	printf("Base虚表地址:%p\n", *(int*)p4);
//
//	return 0;
//}

//
//class Base1 {
//public:
//	virtual void func1() {
//		cout << "Base1::func1" << endl; 
//	}
//	virtual void func2() { 
//		cout << "Base1::func2" << endl; 
//	}
//private:
//	int b1;
//};
//class Base2 {
//public:
//	virtual void func1() { 
//		cout << "Base2::func1" << endl; 
//	}
//	virtual void func2() { 
//		cout << "Base2::func2" << endl;
//	}
//private:
//	int b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { 
//		cout << "Derive::func1" << endl; 
//	}
//	virtual void func3() { 
//		cout << "Derive::func3" << endl; 
//	}
//private:
//	int d1;
//};
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[]){
//	cout << " 虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i){
//		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//int main(){
//	Derive d;
//	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTableb1);
//	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
//	PrintVTable(vTableb2);
//	return 0;
//}

//class A {
//public:
//	A(const char* s) {
//		cout << s << endl; 
//	}
//	~A() {
//	}
//};
//
//class B :virtual public A
//{
//public:
//	B(const char* s1, const char* s2) :A(s1) {
//		cout << s2 << endl;
//	}
//};
//
//class C :virtual public A
//{
//public:
//	C(const char* s1, const char* s2) :A(s1) {
//		cout << s2 << endl; 
//	}
//};
//
//class D :public B, public C
//{
//public:
//	D(const char* s1, const char* s2, const char* s3, const char* s4)
//		:B(s1, s2)
//		, C(s1, s3)
//		, A(s1){
//		cout << s4 << endl;
//	}
//};
//
//int main() {
//	D* p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}