#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include<unordered_set>
#include"hahTable.h"
using namespace std;


//int main() {
//	const size_t N = 10000000;
//	vector<int> V;
//	V.reserve(N);
//	srand(time(0));
//	set<int>s;
//	unordered_set<int> us;
//
//	size_t num1 = 0;
//	size_t num2 = 0;
//
//	for (size_t i = 0; i < N; i++){	
//		V.push_back(rand()%N+i);
//	}
//
//	size_t begin1 = clock();
//	for (auto e:V) {
//		s.insert(e);
//	}
//	size_t end1 = clock();
//
//	size_t begin2 = clock();
//	for (auto e : V) {
//		us.insert(e);
//	}
//	size_t end2 = clock();
//
//	cout << "set.Insert" << end1 - begin1 << endl;
//	cout << "unordered_set.Insert" << end2 - begin2 << endl;
//	cout << endl;
//
//	size_t begin3 = clock();
//	for (auto e : V) {
//		s.find(e);
//	}
//	size_t end3 = clock();
//
//	size_t begin4 = clock();
//	for (auto e : V) {
//		us.find(e);
//	}
//	size_t end4 = clock();
//
//
//	cout << "set.find" << end3 - begin4 << endl;
//	cout << "unordered_set.find" << end3 - begin4 << endl;
//	cout << endl;
//
//	size_t begin5 = clock();
//	for (auto e : V) {
//		s.erase(e);
//	}
//	size_t end5 = clock();
//
//	size_t begin6 = clock();
//	for (auto e : V) {
//		us.erase(e);
//	}
//	size_t end6 = clock();
//
//	cout << "set.erase" << end3 - begin4 << endl;
//	cout << "unordered_set.erase" << end3 - begin4 << endl;
//	cout << endl;
//
//	return 0;
//}


int main() {

    hashTable<string, string>h;
    h.Insert(make_pair("banana", "Ïã½¶"));
    h.Insert(make_pair("apple", "Æ»¹û"));
    h.Insert(make_pair("pear", "Àæ×Ó"));
    h.Insert(make_pair("watermelon", "Î÷¹Ï"));
    h.Insert(make_pair("pineapple", "²¤ÂÜ"));
    h.Insert(make_pair("strawberry", "²ÝÝ®"));
    cout << h.find("strawberry")->_data.second << endl;
    return 0;
}