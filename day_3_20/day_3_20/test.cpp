#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

//template<class T1, class T2>
//class Data{
//public:
//	Data() {
//		cout << "Data<T1, T2>" << endl; 
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//template <class T1>
//class Data<T1, int>{
//public:
//	Data() { 
//		cout << "Data<T1, int>" << endl; 
//	}
//private:
//	T1 _d1;
//	int _d2;
//};
//
//template <typename T1, typename T2>
//class Data <T1*, T2*>{
//public:
//	Data() { 
//		cout << "Data<T1*, T2*>" << endl; 
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//template <typename T1, typename T2>
//class Data <T1&, T2&>{
//public:
//	Data(const T1& d1, const T2& d2): _d1(d1), _d2(d2){
//		cout << "Data<T1&, T2&>" << endl;
//	}
//private:
//	const T1& _d1;
//	const T2& _d2;
//};
//
//class A{
//public:
//  void f() { 
//	  cout << "A::f()" << endl; 
//  }
//  int a;
//};
//
//class B :  A{
//public:
//	void f(int a) { 
//		cout << "B::f()" << endl; 
//	}
//	int a;
//};
//
//int main(){
//	B b;
//	b.f();
//	return 0;
//}

//int main(){
//	Data<double, int> d1;
//	Data<int, double> d2;
//	Data<int*, int*> d3;
//	Data<int&, int&> d4(1, 2);
//	return 0;
//}


class A
{
public:

  A() { cout << "A::A()" << endl; }

  ~A() { cout << "A::~A()" << endl; }

  int a;

};



//class B : public A{
//public:
//	B() { 
//		cout << "B::B()" << endl; 
//	}
//	~B() { 
//		cout << "B::~B()" << endl; 
//	}
//	int b;
//
//};
//void f(){
//	B b;
//}
//
//int main() {
//	f();
//	return 0;
//}

class Base1{
public: 
	int _b1; 
};

class Base2 { 
public: 
	int _b2; 
};

class Derive : public Base1, public Base2{
public: 
	int _d;
};

int main() {
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;

	return 0;
}