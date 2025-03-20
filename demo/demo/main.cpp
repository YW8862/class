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
//	cout << "������ֵ���ú���" << endl;
//}
//
//void func(int&& a)
//{
//	cout << "������ֵ���ú���" << endl;
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
//	int a = 2;		//a���г־õ��ڴ棬����ֵ��2���ڴ棬����ֵ
//	a = getOne();	//getOne��ȡ����ֵû�г־õ��ڴ棬����ֵ
//
//	const int b = 3;//b���г־��ڴ棬��Ȼ���ܷ��ڵȺ���ߣ�����Ҳ����ֵ
//
//	b = 1;			//bΪ�����޸ĵ���ֵ
//	2 = b;			//������ֵ�����ڵȺ����
//	getOne() = b;	//������ֵ�����ڵȺ����
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
//		//���Ϊ��������������
//		if (&other == this)
//			return *this;
//		//1.�ȳ��Է����µĿռ�
//		char* buffer = new char[other._size];
//
//		//2.�ͷ�ԭ���ռ�
//		delete[] _buffer;
//		_size = 0;
//
//		//3.��������
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
//		//���Ϊ��������������
//		if (&other == this)
//			return *this;
//
//		//1.�ͷ�ԭ���ռ�
//		delete[] _buffer;
//		_size = 0;
//
//		//2.��ȡ��Դ
//		_buffer = other._buffer;
//		_size = other._size;
//
//		//3.��other��Ϊ��
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
//	cout << "��ֵ����" << endl;
//}
//
//void f(charBuffer&& buffer)
//{
//	cout << "��ֵ����" << endl;
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
