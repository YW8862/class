#include <iostream>
#include <string>
#include "mystring.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	std::string str = "1234567890";
	str.resize(20);
	cout << str << endl;
	return 0;
}