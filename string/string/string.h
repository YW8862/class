#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

namespace mystring {
	class string {
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		typedef char* iterator;
		typedef const char* const_itertor;

/////////////////////////////////////////////////////////////////////////
		//base
		string(const string& s) {
			this->_str = new char[s.size() + 1];
			strcpy(this->_str, s._str);
			this->_size = s._size;
			this->_capacity = s._capacity;
		}


		string(const char* str)
			: _size(strlen(str))
			, _str(new char[strlen(str) + 1])
			, _capacity(_size)
		{
			strcpy(this->_str, str);
		}

		string& operator=(const string& s) {
			this->_str = new char[s.size() + 1];
			this->_size = s._size;
			this->_capacity = s._capacity;
			strcpy(this->_str, s._str);
			return *this;
		}


		~string() {
			delete[]_str;
			_size = 0;
			_capacity = 0;
		}
		
		size_t size()const {
			return _size;
		}

		size_t capacity() const {
			return this->_capacity;
		}
///////////////////////////////////////////////////////////////////////////
		//capacity
		//扩容
		void reserve(size_t n) {
			if (n > _capacity) {
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;
				_capacity = n;
			}
		}
		bool empty()const {
			return _size == 0;
		}

		void resize(size_t n, const char ch='\0') {
			if (n <= _size) {
				_str[n] = '\0';
				_size = n;
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
//////////////////////////////////////////////////////////////////////////
		//Modify
		//尾插
		void push_back(const char s) {
			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			_str[_size] = s;
			_size++;
			_str[_size] = '\0';
		}

		void append(const char* s) {
			size_t len = strlen(s);
			if (_size + len > _capacity) {
				reserve(_size + len + 1);
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

		void clear() {
			if (_size != 0) {
				_str[0] = '\0';
				_size = 0;
			}

		}

		//插入
		void insert(size_t pos, const char ch) {
			assert(pos <= _size);
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

		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			// 扩容2倍
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}

			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = ch;
			++_size;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				// 扩容
				reserve(_size + len);
			}

			size_t end = _size + len;
			while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				end--;
			}

			strncpy(_str + pos, str, len);
			_size += len;
		}


		//删除
		void erase(size_t pos, size_t len = std::string::npos) {
			assert(pos < _size);
			if (len == std::string::npos || len >= _size - pos) {
				_str[pos] = '\0';
				_size = pos;
			}
			else {
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

		const char* c_str() {
			return _str;
		}

////////////////////////////////////////////////////////////////////
		// access
		char& operator[](int pos) {
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](int pos)const {
			assert(pos < _size);
			return _str[pos];
		}

		iterator begin() {
			return _str;
		}

		iterator end() {
			return _str + _size;
		}

		const iterator begin()const {
			return _str;
		}

		const iterator end()const {
			return _str + _size;
		}

/////////////////////////////////////////////////////////////////////////
		//relational operators

		bool operator<(const string& s) {
			memcmp(this->_str, s._str,max(this->_size,s._size)) < 0;
		}


		bool operator<=(const string& s) {
			memcmp(this->_str, s._str, max(this->_size, s._size)) <= 0;
		}

		bool operator>(const string& s) {
			memcmp(this->_str, s._str, max(this->_size, s._size)) > 0;
		}

		bool operator>=(const string& s) {
			memcmp(this->_str, s._str, max(this->_size, s._size)) >= 0;
		}

		bool operator==(const string& s) {
			if (this->_size != s._size)
				return false;

			return 
				memcmp(this->_str, s._str, max(this->_size, s._size)) == 0;
		}

		bool operator!=(const string& s) {
			return !((*this) == s);
		}

		void swap(string& s) {
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}


		size_t find(char c, size_t pos = 0) const{
			for (size_t i = pos; i < _size; ++i){
				if (_str[i] == c)
					return i;
			}
			return -1;//未找到
		}

		// 返回子串s在string中第一次出现的位置

		size_t find(const char* s, size_t pos = 0) const{
			assert(s);
			assert(pos < _size);
			const char* src = _str + pos;

			while (*src){
				const char* match = s;//如果不匹配，返回子串起始处重新查找
				const char* cur = src;
				while (*match && *match == *cur){
					++match;
					++cur;
				}
				if (*match == '\0'){
					return src - _str;//返回下标
				}
				else{
					++src;
				}
			}
			return -1;
		}
		friend ostream& operator<<(ostream& _cout, const mystring::string& s);
		friend istream& operator>>(istream& _cin, mystring::string& s);
///////////////////////////////////////////////////////////////////////////
		// 返回c在string中第一次出现的位置

		size_t find(char c, size_t pos = 0) const {
			for (int i = pos; i < _size; i++) {
				if (_str[i] == c)
					return i;
			}
		}
		// 返回子串s在string中第一次出现的位置

		size_t find(const char* s, size_t pos = 0) const;

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		

	};

	ostream& operator<<(ostream& _cout, const mystring::string& s) {

		for (size_t i = 0; i < s.size(); ++i)
		{
			if (s[i] == '\0')
				break;
			_cout << s[i];
		}
		return _cout;

	}

	istream& operator>>(istream& _cin, mystring::string& s) {
		
		char ch;
		ch = _cin.get();
		char buff[128];
		size_t i = 0;
		while (ch != ' ' && ch != '\n') {
			buff[i++] = ch;
			if (i == 127) {
				buff[127] = '\0';
				s += buff;
				i = 0;
			}
			ch = _cin.get();
		}
		if (i > 0) {
			buff[i] = '\0';
			s += buff;
		}

		return _cin;
	}
}

