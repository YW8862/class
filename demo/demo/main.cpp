#include <iostream>
#include <array>
//#include "test.h"
//#include "sort.h"
#pragma pack(1)
using std::cin;
using std::cout;
using std::endl;

//test extern
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

//extern template A<int>;
//extern template void showNumber<int>(int);
//
//int main()
//{
//	A<int> a;
//	a.print(2);
//	showNumber(11);
//}


//class A
//{
//public:
//	A()
//	{
//		a_data = 1;
//	}
//public:
//	int a_data;
//};
//
//class B :public A
//{
//public:
//	B()
//	{
//		b_data = 2;
//	}
//public:
//	int b_data;
//};
//
//class C :public A
//{
//public:
//	C()
//	{
//		c_data = 3;
//	}
//public:
//	int c_data;
//};
//
//class D :public B , public C
//{
//public:
//	D()
//	{
//		d_data = 4;
//	}
//public:
//	int d_data;
//};
//
//int main()
//{
//	A a;
//	B b;
//	C c;
//	D d;
//	d.B::a_data = 2025;
//	cout << d.C::a_data << endl;
//	//cout << "sizeof(A)" << sizeof(A) << endl;
//	//cout << "sizeof(B)" << sizeof(B) << endl;
//	//cout << "sizeof(C)" << sizeof(C) << endl;
//	//cout << "sizeof(D)" << sizeof(D) << endl;
//
//	return 0;
//}

//test extend
//class A
//{
//public:
//	A()
//	{
//		a_data = 1;
//	}
//public:
//	int a_data;
//};
//
//class B :virtual public A{
//public:
//	B() {}
//public:
//	int b_data;
//};
//
//class C :virtual public A {
//public:
//	C() {}
//public:
//	int c_data;
//};
//
//class D :public B, public C {
//public:
//	D() {}
//public:
//	int d_data;
//};
//
//int main()
//{
//	A a;
//	B b;
//	C c;
//	D d;
//	printf("&d.B::a_data: %p\n", &d.B::a_data);
//	printf("&d.C::a_data: %p\n", &d.C::a_data);
//	d.B::a_data = 2025;
//	cout << d.C::a_data << endl;
//	cout << "sizeof(A)" << sizeof(A) << endl;
//	cout << "sizeof(B)" << sizeof(B) << endl;
//	cout << "sizeof(C)" << sizeof(C) << endl;
//	cout << "sizeof(D)" << sizeof(D) << endl;
//	cout << "a_data " << d.a_data << endl;
//	return 0;
//}

//class A 
//{
//public:
//	A(int a = 1) :a_data(a) {}
//	void print()
//	{
//		cout << "hello world" << endl;
//	}
//private:
//	int a_data;
//};
//
//
////test sort
//int main()
//{
//	//A a1(1);
//	//A a2(2);
//	A* ptr = nullptr;
//	ptr->print();
//	return 0;
//}

//void func(int& a)
//{
//	cout << "调用左值引用函数" << endl;
//}
//
//void func(int&& a)
//{
//	cout << "调用右值引用函数" << endl;
//}
//
//int main()
//{
//	int a = 5;
//	func(a);
//	func(5);
//	return 0;
//}

//int getOne()
//{
//	return 1;
//}
//
//int main()
//{
//	int&& aa = 2;
//	cout << aa << endl;
//
//	int&& bb = getOne();
//	cout << bb << endl;
//	return 0;
//}

//int main()
//{
//
//	int a = 2;		//a具有持久的内存，是左值，2无内存，是右值
//	a = getOne();	//getOne获取到的值没有持久的内存，是右值
//
//	const int b = 3;//b具有持久内存，虽然不能放在等号左边，但是也是左值
//
//	b = 1;			//b为不能修改的左值
//	2 = b;			//错误，右值不能在等号左边
//	getOne() = b;	//错误，右值不能在等号左边
//
//	return 0;
//}

//class charBuffer
//{
//public:
//	charBuffer(int size = 10) :_size(size), _buffer(new char[size])
//	{
//		cout << "default constructor" << endl;
//	}
//
//	charBuffer(const charBuffer& other):_size(other._size),_buffer(new char[other._size])
//	{
//		memcpy(_buffer, other._buffer, other._size);
//		cout << "copy constructor" << endl;
//	}
//
//	charBuffer(charBuffer&& other) :_size(other._size), _buffer(other._buffer)
//	{
//		other._size = 0;
//		other._buffer = nullptr;
//		cout << "move constructor" << endl;
//	}
//	
//	charBuffer& operator=(const charBuffer& other)
//	{
//		//如果为自身，返回自身即可
//		if (&other == this)
//			return *this;
//		//1.先尝试分配新的空间
//		char* buffer = new char[other._size];
//
//		//2.释放原来空间
//		delete[] _buffer;
//		_size = 0;
//
//		//3.拷贝内容
//		memcpy(buffer, other._buffer, other._size);
//		_buffer = buffer;
//		_size = other._size;
//
//		cout << "copy assignment" << endl;
//
//		return *this;
//	}
//
//	charBuffer& operator=(charBuffer&& other)
//	{
//		//如果为自身，返回自身即可
//		if (&other == this)
//			return *this;
//
//		//1.释放原来空间
//		delete[] _buffer;
//		_size = 0;
//
//		//2.获取资源
//		_buffer = other._buffer;
//		_size = other._size;
//
//		//3.将other置为空
//		other._buffer = nullptr;
//		other._size = 0;
//
//		cout << "move assignment" << endl;
//
//		return *this;
//	}
//
//	~charBuffer()
//	{
//		delete[]_buffer;
//		_size = 0;
//		cout << "destructor" << endl;
//	}
//
//	char* getBuffer()
//	{
//		return _buffer;
//	}
//
//private:
//	int _size;
//	char* _buffer;
//};

//charBuffer getBuffer()
//{
//	charBuffer buffer(100);
//	return buffer;
//}

//void f(charBuffer& buffer)
//{
//	cout << "左值引用" << endl;
//}
//
//void f(charBuffer&& buffer)
//{
//	cout << "右值引用" << endl;
//}
//
//template<typename T>
//void g(T&& buffer)
//{
//	f(static_cast<T&&>(buffer));
//}
//
//int main()
//{
//	charBuffer buffer1(100);
//	charBuffer buffer2(100);
//
//	g(buffer1);
//	g(std::move(buffer2));
//	
//	return 0;
//}

//int main()
//{
//	int a = 2*2+7;
//	//constexpr int b{a+2};
//	//cout << b << endl;
//	return 0;
//}


constexpr int getSize(int a, int b)
{
	return a + b;
}

int main()
{
	const int a = 10;
	constexpr int b{ a + 1 };

	constexpr float c = 3.14;
	const float d{ c + 1.0f };

	/*std::array<int, getSize(2, 3)> arr;*/
	return 0;
}
