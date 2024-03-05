#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#define npos (int)pow(2,32)
using namespace std;

namespace my_string {
	class string {
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		typedef char* itertor;
		typedef const char* const_itertor;


		string(const string& s) {
			this->_str = new char[s.size()+1];
			strcpy(this->_str, s._str);
			this->_size = s._size;
			this->_capacity = s._capacity;
		}


		string(const char*str="")
			: _size(strlen(str))
			, _str(new char[strlen(str)+1])
			,_capacity(_size)
		{
			strcpy(this->_str, str);
		}

		string& operator=(const string& s) {
			this->_str = new char[s.size()+1];
			this->_size = s._size;
			this->_capacity = s._capacity;
			strcpy(this->_str, s._str);
			return *this;
		}

		void operator=(const char*s) {
			this->_size = strlen(s);
			this->_capacity = this->_size+1;
			strcpy(this->_str, s);
		}
		


		~string() {
			delete[]_str;
			_size = 0;
			_capacity = 0;
		}

		size_t size()const {
			return _size;
		}

		size_t capacity() const{
			return this->_capacity;
		}

		//À©ÈÝ
		void reserve(size_t n) {
			if (n > _capacity) {
				char* tmp = new char[n+1];
				strcpy(tmp,_str);
				delete[]_str;
				_str = tmp;
				_capacity = n;
			}
		}

		//Î²²å
		void push_back(const char s) {
			if (_size == _capacity) {
				reserve(_capacity==0?4:2*_capacity);
			}
			_str[_size] = s;
			_size++;
			_str[_size] = '\0';
		}

		void append(const char*s) {
			size_t len = strlen(s);
			if (_size + len>_capacity) {
				reserve(_size + len+1);
			}
			strcpy(_str + _size, s);
			_size += len;
		}

		void operator+=(const char ch) {
			push_back(ch);
		}

		void operator+=(const char* s) {
			append(s);
		}

		//²åÈë
		void insert(size_t pos,const char ch) {
			assert(pos<=_size);
			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : 2 * _capacity);				
			}
			int end = _size;
			while (end >= (int)pos) {
				_str[end + 1] = _str[end];
				--end;
			}
			_str[pos] = ch;
			_size++;
		}

		//É¾³ý
		
		void erase(size_t pos, size_t len = npos) {
			assert(pos < _size);
			if (len == npos || len >= _size - pos) {
				_str[pos] = '\0';
				_size = pos;
			}
			else {
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}


		//
		void resize(size_t n,const char ch) {
			if (n <= _size) {
				_str[n] = '\0';
			}
			else {
				reserve(n);
				for (int i = _size; i < n; i++) {
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
		}
		
		//±éÀú
		char& operator[](int pos) {
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](int pos)const {
			assert(pos < _size);
			return _str[pos];
		}

		char* begin() {
			return _str;
		}
		
		char* end() {
			return _str + _size;
		}

		const char* begin() const{
			return _str;
		}

		const char* end() const {
			return _str + _size;
		}

	};
}


int main() {
	my_string::string s1= "abcdefg";
	my_string::string::itertor it= s1.begin();

	while (it != s1.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	
	//for (auto e : s1) {
	//	e -= 1;
	//	cout << e<<" ";
	//}
	//cout << endl;
	s1 += "hello world!";
	s1.insert(0, '1');
	s1.erase(3, 7);
	for (auto e : s1) {
		cout << e << " ";
	}
	cout << endl;
	
	s1.resize(30, 'x');
	for (auto e : s1) {
		cout << e << " ";
	}
	cout << endl;
	my_string::string s2(s1);
	for (auto e : s2) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
