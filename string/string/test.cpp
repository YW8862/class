#include"string.h"



//test1 ππ‘Ï≤‚ ‘

void test1() {
	my_string::string s1("abcd");
	my_string::string s2(s1);
	my_string::string s3=s2;
	my_string::string s4="abcd";

	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	cout << "s3:" << s3 << endl;
	cout << "s4:" << s4 << endl;
}

//test2 ≤‚ ‘size¿‡∫Ø ˝

void test2() {
	my_string::string s1 = "abcdefg";
	cout << "s1: " << s1.size()<<" "<<s1.capacity() << endl;

	s1.resize(10, '#');

	cout << "s1: " << s1 << endl;
	cout << "s1._size(): " << s1.size() << endl;
	cout<< "s1.capacity(): " << s1.capacity()<< endl;
}


//test3 ≤‚ ‘Œ≤≤Â

void test3() {
	my_string::string s1 = "abcdefgh";
	s1.push_back('q');
	cout << s1 << endl;
	s1.append("hello world");
	cout << s1 <<endl;
	s1 += 'v';
	cout << s1 << endl;
	s1 += "nihao"; 
	cout << s1 << endl;
}

//test4 ≤‚ ‘µ¸¥˙∆˜

void test4() {
	my_string::string s1 = "abcdefghijk";
	my_string::string::iterator it = s1.begin();
	while (it != s1.end()) {
		cout << *it << " ";
		it++;
	}
//	cout << "1" << endl;
	cout << endl;
	


	for (auto e : s1) {
		cout << e << " ";
	}
	cout << endl;
}



int main() {
	
	//test1();                  //pass
	//test2();					//pass
	//test3();					//pass
	//test4();					//pass

	return 0;
}