//#include"virtual_test.h"

#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
//
//class B {
//public: 
//	B() {
//		cout << " class B::B()" << endl;
//	}
//	~B() {
//		cout << " class B::~B()" << endl;
//	}
//private:
//	int b; 
//	void fun() {
//		cout << "hello world" << endl;
//	}
//};
//
//class C1 : public B {
//public: 
//	C1() {
//		cout << " class C1::C1()" << endl;
//	}
//	~C1() {
//		cout << " class C1::~C1()" << endl;
//	}
//	int c1; 
//};
//
//class C2 : public B {
//public: 
//	
//	C2() {
//		cout << " class C2::C2()" << endl;
//	}
//
//	~C2() {
//		cout << " class C2::~C2()" << endl;
//	}
//	int c2;
//};
//
//class D : public C1, public C2 {
//public:
//	D() {
//		cout << " class D::D()" << endl;
//	}
//	~D() {
//		cout << " class D::~D()" << endl;
//	}
//	int d; 
//};
//
//void fun() {
//	B b;
//	C1 c1;
//	C2 c2;
//	D d;
//	cout << sizeof(d) << endl;
//	
//}
//
//int main() {
//	fun();
//	return 0;
//}
//
// 
// 


//虚函数的声明定义分离不需要要两个地方都加virtual关键字

//void A::fun() {
//	cout << "A::fun()" << endl;
//}
//
//void B::fun() {
//	cout << "A::fun()" << endl;
//}

//
//int main() {
//	A a;
//	B b;
//	a.fun();
//	b.fun();
//	return 0;
//}	


//static修饰的函数无法使用this指针
//class test {
//private:
//	int a;
//public:
//	static void fun() {
//		cout << "static void fun()" << this->a << endl;
//	}
//};



////友元函数不可以使用virtual修饰
//class test {
//private:
//	int a = 1;
//public:
//	friend void f(test x);
//};
//
//void f(test x) {
//	cout << x.a << endl;
//}
//
//int main() {
//	test x;
//	f(x);
//	return 0;
//}



//static修饰的函数无法使用virtual修饰
//class test {
//private:
//	int a;
//public:
//	virtual static void fun() {
//		
//	}
//};


//class A {
//public:
//	void fun() {
//		cout << "class A()" << endl;
//	}
//};
//
//class B :public A {
//	virtual void fun() {
//		cout << "class B()" << endl;
//	}
//};

//void func(A& a) {
//	a.fun();
//}

//
//int main() {
//	A* a = new A();
//	A* b = new B();
//	a->fun();
//	b->fun();
//	return 0;
//}

//int main() {
//	set<int>s = { 1,2,1,27,3,54 };
//	for (auto e : s) {
//		cout << e << " ";
//	}
//	cout << endl;
//
//	s.erase(s.find(7));
//	for (auto e : s) {
//		cout << e << " ";
//	}
//	cout << endl;
//
//	s.erase(7);
//	for (auto e : s) {
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}



//int main() {
//	set<int>s;
//	for (size_t i = 0; i < 100; i++) {
//		s.insert(i);
//	}
//	set<int>::iterator start = s.lower_bound(2);
//	set<int>::iterator finish = s.lower_bound(34);
//	s.erase(start, finish);
//	for (auto e : s) {
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//class A{
//public:
//    virtual void f(){
//        cout << "A::f()" << endl;
//    }
//};
//
//class B : public A{
//public:
//    void f(){
//        cout << "B::f()" << endl;
//    }
//};


//
//int main() {
//
//    //A* pa = new B();
//    ////cout << typeid(*pa).name() << endl;
//    //pa->f();
//    B b;
//    b.f();
//    return 0;
//}


//class A{
//public:
//    A() 
//        :m_iVal(0) {
//        test(); 
//    }
//    virtual void func() {
//        std::cout << m_iVal << " ";
//    }
//    void test() { 
//        func(); 
//    }
//public:
//    int m_iVal;
//};
//
//class B : public A{
//public:
//    B() {
//        test();
//    }
//    virtual void func(){
//        ++m_iVal;
//        std::cout << m_iVal << " ";
//    }
//};
//
//int main(){
//    A* p = new B;
//    p->test();
//    return 0;
//}


class A {
public:
    virtual void func() {
        std::cout << " A::func()" << " ";
    }
};

class B {
public:
    virtual void fun() {
        std::cout << "B::fun()" << " ";
    }
};

class C :public A, public B {
public:
    virtual void fun() {
        cout << " C::func()" << " ";
    }
    virtual void func() {
        cout << " C::func()" << " ";
    }
    void virtual function() {
        cout << "C::function()" << endl;
    }
};

int main() {
    A *a = new A();
    B *b = new B();
    C *c = new C();
    return 0;
}