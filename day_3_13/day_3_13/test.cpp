#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#include<list>
//#pragma pack(4)
template<typename T>
bool Less(T x, T y) {
	return x < y;
}

template<>
bool Less<int*>(int* x, int* y) {
	return *x < *y;
}


//²âÊÔlist¹¹Ôì
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
	virtual void BuyTicket() { cout << "ÂòÆ±-È«¼Û" << endl; }
};
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "ÂòÆ±-°ë¼Û" << endl; }

};

void Func(Person& p)
{
	p.BuyTicket();
}

//class Car {
//public:
//	virtual void Drive() {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-ÊæÊÊ" << endl; }
//};


//void test3() {
//	Benz b;
//	b.Drive();
//}

//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}

class Car
{
public:
	virtual void Drive() = 0;
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz-ÊæÊÊ" << endl;
	}
};
class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-²Ù¿Ø" << endl;
	}
};

void Test()
{
	Car* pBenz = new Benz;
	pBenz->Drive();
	Car* pBMW = new BMW;
	pBMW->Drive();
}

class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
private:
	int _b = 1;
};

void test4() {
	Base b;
	cout << sizeof(b) << endl;
}


//Leetcode 118
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>res;
		vector<int>s = { 1 };
		res.push_back(s);
		if (numRows == 1)return res;
		s = { 1,1 };
		res.push_back(s);
		if (numRows == 2)return res;
		for (int i = 2; i < numRows; i++) {
			s.resize(0);
			s.push_back(1);
			for (int j = 1; j < i; j++) {
				s.push_back(res[i - 1][j - 1] + res[i - 1][j]);
			}
			s.push_back(1);
			res.push_back(s);
		}
		return res;
	}
};

class Solution2 {
public:
	                  
	int MoreThanHalfNum_Solution(vector<int>& numbers) {
		// write code here
		if (numbers.size() == 1)return numbers[0];
		int res = numbers[0];
		int count = 0;
		for (auto e : numbers) {
			if (count == 0) {
				res = e;
				count++;
			}
			else if (e == res)
				count++;
			else {
				count--;
			}
		}
		return res;
	}
};


int main() {
	//test3();
	//Test();
	//test4();

	vector<vector<int>>res=Solution().generate(5);
	for (auto e : res) {
		for (auto f : e) {
			cout << f << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
