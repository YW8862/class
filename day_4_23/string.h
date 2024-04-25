//
// Created by YANGWEI on 24-4-23.
//
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<iostream>
#include<cstring>

using namespace std;

namespace mystring
{
    class string
    {
    public:
        typedef char* iterator;
        typedef const char* const_iterator;

        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }

        const_iterator begin() const
        {
            return _str;
        }

        const_iterator end() const
        {
            return _str + _size;
        }

        const char* c_str() const
        {
            return _str;
        }

        size_t size() const
        {
            return _size;
        }

        string(const char* str = "");
        // ִд
        string(const string& s);
        string(string&&s);
        string& operator=(string s);
        string& operator=(string&& s);
        ~string();

        const char& operator[](size_t pos) const;
        char& operator[](size_t pos);
        void reserve(size_t n);
        void push_back(char ch);

        void append(const char* str);
        string& operator+=(char ch);
        string& operator+=(const char* str);

        void insert(size_t pos, char ch);
        void insert(size_t pos, const char* str);
        void erase(size_t pos, size_t len = npos);
        void swap(string& s);
        size_t find(char ch, size_t pos = 0);
        //21:10
        size_t find(const char* str, size_t pos = 0);
        string substr(size_t pos = 0, size_t len = npos);
        void clear();

    private:
        size_t _capacity = 0;
        size_t _size = 0;
        char* _str = nullptr;

        const static size_t npos = -1;
    };

    istream& operator>>(istream& in, string& s);
    ostream& operator<<(ostream& out, const string& s);
}
