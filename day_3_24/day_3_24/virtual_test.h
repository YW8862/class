#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

class A {
private:
	int a;
public:
	void virtual fun();
};

class B :public A {
private:
	int b;
public:
	void virtual fun();
};