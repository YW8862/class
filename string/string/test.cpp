#include"string.h"



//test1 ππ‘Ï≤‚ ‘

void test1() {
	mystring::string s1("abcd");
	mystring::string s2(s1);
	mystring::string s3=s2;
	mystring::string s4="abcd";

	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	cout << "s3:" << s3 << endl;
	cout << "s4:" << s4 << endl;
}


void test2() {
	mystring::string s1 = "hello world!";
	mystring::string::iterator it1 = s1.begin();
	while (it1 != s1.end()) {
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

	for (auto e : s1) {
		cout << e << " ";
	}
	cout << endl;

	const mystring::string s2 = "this is a sentance!";
	mystring::string::iterator it2 = s2.begin();
	while (it2 != s2.end()) {
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;

	for (auto e : s2) {
		cout << e << " ";
	}
	cout << endl;
}


//test2 ≤‚ ‘size¿‡∫Ø ˝

void test3() {
	mystring::string s1 = "abcdefg";
	cout << "s1: " << s1.size()<<" "<<s1.capacity() << endl;

	cout << "test capacity:";
	//n<_capacity
	s1.reserve(3);
	cout << s1.capacity() << endl;
	s1.reserve(20);
	cout << s1.capacity() << endl;

	cout << "test resize:";
	//n<_size
	s1.resize(3);
	cout << s1 << endl;
	//n>_size
	s1.resize(10, '#');
	cout << s1 << endl;

	cout << "test empty:";
	cout << s1.empty() << endl;
}


void test4() {
	mystring::string s1 = "abcd";
	//≤‚ ‘push_back
	s1.push_back('x');
	cout << s1 << endl;

	//≤‚ ‘qppend
	s1.append("hello worldz!");
	cout << s1 << endl;

	//≤‚ ‘+=
	s1 += '1';
	cout << s1 << endl;
	s1 += "234567";
	cout << s1 << endl;



}

////test3 ≤‚ ‘Œ≤≤Â
//
//void test4() {
//	my_string::string s1 = "abcdefgh";
//	s1.push_back('q');
//	cout << s1 << endl;
//	s1.append("hello world");
//	cout << s1 <<endl;
//	s1 += 'v';
//	cout << s1 << endl;
//	s1 += "nihao"; 
//	cout << s1 << endl;
//}
//
////test4 ≤‚ ‘µ¸¥˙∆˜
//
//void test4() {
//	my_string::string s1 = "abcdefghijk";
//	my_string::string::iterator it = s1.begin();
//	while (it != s1.end()) {
//		cout << *it << " ";
//		it++;
//	}
////	cout << "1" << endl;
//	cout << endl;
//	
//
//
//	for (auto e : s1) {
//		cout << e << " ";
//	}
//	cout << endl;
//}



int main() {
	
	//test1();                  //pass
	//test2();					//pass
	test3();					//pass
	//test4();					//pass

	return 0;
}