#include"vector.h"


//测试构造函数与析构函数以及输入输出流操作符重载

void test1() {
	myvector::vector<int> v1;
	myvector::vector<string>v2;
	myvector::vector<myvector::A>v4;
	myvector::vector<int>v5(10, 2);
	myvector::vector<string>v6(10, "helle world!");
	
	int arr[] = { 1,2,3,4,5,6 };
	myvector::vector<int>v7(arr,arr+sizeof(arr)/sizeof(arr[0]));
	myvector::vector<int>v8(v7);
	auto v9 = v8;
}

//test2 测试容量相关函数
void test2() {
	myvector::vector<int>v5(10, 2);
	myvector::vector<string>v6(20, "helle world!");
	cout << "v5:capacity:" << v5.capacity()<<"size():"<<v5.size() << endl;
	cout << "v6:capacity:" << v6.capacity()<<"size():"<<v6.size() << endl;

	v5.reserve(10);
	cout << "v5:capacity:" << v5.capacity() << "size():" << v5.size() << endl;
	v6.resize(12,"hehe");
	cout << "v6:capacity:" << v6.capacity() << "size():" << v6.size() << endl;

}

int main() {

//	test1();
	test2();
	return 0;
}