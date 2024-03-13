#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#include<list>
template<typename T>
bool Less(T x, T y) {
	return x < y;
}

template<>
bool Less<int*>(int* x, int* y) {
	return *x < *y;
}


//测试list构造
void test1() {
	list<int>l1;
	list<int>l2(3, 100);
	auto it2 = l2.begin();
	while (it2 != l2.end()) {
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;

	list<int>l3(l2.begin(), l2.end());
	auto it3 = l3.begin();
	while (it3 != l3.end()) {
		cout << *it3 << " ";
		it3++;
	}
	cout << endl;

	int arr[] = {1, 2, 3, 4, 5, 6};
	list<int>l4(arr, arr + sizeof(arr) / sizeof(arr[0]));
	auto it4 = l4.begin();
	while (it4 != l4.end()) {
		cout << *it4 << " ";
		it4++;
	}
	cout << endl;

	list<int>l6{ 1,2,3,4,6,7,8,9 };
	auto it6 = l6.begin();
	cout << "l6: ";
	while (it6 != l6.end()) {
		cout << *it6 << " ";
		it6++;
	}
	cout << endl;
}

class person {
protected:
	string _name;
	string _gender;
	int _age;
private:
	int a = 0;
public:
	person(string name=" ", string gender="female", int age = 10) :_name(name), _gender(gender), _age(age) {}

	void print() {
		cout << "name:" << _name << " gender: " << _gender << " age: " << _age << endl;
	}

};

class student :public person {
protected:
	int  _id;
public:
	student() = default;
	student(string name, string gender, int ag, int id) :_id(id) {}
	void print() {
		cout <<"student:" << "name:" << _name << " gender: " << _gender << " age: " << _age << " id: " << _id << endl;
	}
};

class teacher :public person {
protected:
	int _id;
public:
	teacher() = default;
	teacher(string name, string gender, int ag, int id) :_id(id) {}
	void print() {
		cout << "teacher:" << "name:" << _name << " gender: " << _gender << " age: " << _age << " id: " << _id << endl;
	}
};




void test2() {
	
	student s("zhangsan", "male", 20,12345);
	s.print();

	person p = s;
	p.print();
}



class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
	/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因
	为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议
	这样使用*/
	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person ps;
	Student st;
	Func(ps);
	Func(st);
	return 0;
}

