#include"string.h"

//test1 �������

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


//test2 ����size�ຯ��

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
	//����push_back
	s1.push_back('x');
	cout << s1 << endl;

	//����qppend
	s1.append("hello worldz!");
	cout << s1 << endl;

	//����+=
	s1 += '1';
	cout << s1 << endl;
	s1 += "234567";
	cout << s1 << endl;

	//����clear
	s1.clear();
	cout << s1 << " s1._capacity:" << s1.capacity() <<"s1._size: "<< s1.size() << endl;

	//����swap����
	cout << "����swap" << endl;
	mystring::string s2 = "hello world 12345";
	cout << s2 << endl;
	s1.swap(s2);
	cout << "s1: " << s1 << "s2: " << s2 << endl;


	cout << "����C_str" << endl;
	//����c_str
	cout << s1.c_str() << endl;

	//����insert
	cout <<endl<< "����insert" << endl;
	s1.insert(3, "haha");
	cout << s1 << endl;
	s1.insert(2, 's');
	cout << s1 << endl;

	//����erase
	cout << "����erase:" << endl;
	s1.erase(3, 5);
	cout << s1 << endl;
}

void test5() {
	mystring::string s1 = "hello world!";
	for (int i = 0; i < s1.size(); i++) {
		s1[i]++;
		cout << s1[i] << " ";
	}
	cout << endl;
}

void test6() {
	mystring::string s1 = "hello world!";
	cout<<s1.find('5')<<endl;
	cout << s1.find('l')<<endl;
	cout << s1.find("hello") << endl;
}

////test3 ����β��
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
////test4 ���Ե�����
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
	//test3();					//pass
	test4();					//pass
	//test5();					//pass
	//test6();
	return 0;
}