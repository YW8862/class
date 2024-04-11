#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

int main() {
	fstream fs("test.txt",ios::in | ios::out | ios::app);

	fs << "hello world" << endl;

	fs.seekg(0, fs.beg);
	string s;
	getline(fs, s);
	cout << s << endl;
	fs.close();
	return 0;
}