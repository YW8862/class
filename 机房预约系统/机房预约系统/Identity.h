#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;


class Identity {
public:
    Identity() = default;
    Identity(string name, string pwd)
        :_M_Name(name),
        _M_Pwd(pwd) 
    {}

    
    virtual void Oper_Menu() = 0;
    string _M_Name;
    string _M_Pwd;
};

