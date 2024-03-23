#include"vector.h"


//测试构造函数与析构函数
void test1() {
	myvector::vector<int>v1;
	myvector::vector<int>v2(5, 10);
	myvector::vector<int>v3(v2);
	myvector::vector<int>v4(v3.begin(), v3.end());
	myvector::vector<int>v5 = v4;
}

//测试迭代器函数
void test2(){

	myvector::vector<int>v1(12,6);
	const myvector::vector<int>v2 = v1;
	myvector::vector<int>::iterator it1 = v1.begin();
	while(it1 != v1.end()) {
		(*it1)++;
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

	myvector::vector<int>::const_iterator it2 = v2.begin();
	while (it2 != v2.end()) {
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
	
}

//测试容量相关函数
void test3() {
	myvector::vector<int>v5(10, 2);
	myvector::vector<string>v6(20, "helle world!");
	cout << "v5:capacity:" << v5.capacity()<<"size():"<<v5.size() << endl;
	cout << "v6:capacity:" << v6.capacity()<<"size():"<<v6.size() << endl;

	v5.reserve(10);
	cout << "v5:capacity:" << v5.capacity() << "size():" << v5.size() << endl;
	v6.resize(12,"hehe");
	cout << "v6:capacity:" << v6.capacity() << "size():" << v6.size() << endl;

	for (int i = 0; i < v5.size();i++) {
		cout << v5[i] << " ";
	}
	cout << endl;

}

void test4() {
	myvector::vector<int>v1(10, 2);
	for (auto e : v1) {
		cout << e << " ";
	}
	cout << endl;

	v1.push_back(4);
	for (auto e : v1) {
		cout << e << " ";
	}
	cout << endl;

	v1.pop_back();
	for (auto e : v1) {
		cout << e << " ";
	}
	cout << endl;

	v1.insert(v1.begin(),3);
	for (auto e : v1) {
		cout << e << " ";
	}
	cout << endl;

	v1.erase(v1.begin());
	for (auto e : v1) {
		cout << e << " ";
	}
	cout << endl;
	
	myvector::vector<int>v2(2, 7);
	v1.swap(v2);
	for (auto e : v1) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {

	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}