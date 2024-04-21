#include"hash_backet.h"
int main(){
    hash_backet<string,string>h;
    h.Insert(make_pair("string","字符串"));
    h.Insert(make_pair("apple","苹果"));
    h.Insert(make_pair("banana","香蕉"));
    h.Insert(make_pair("pear","梨"));
    h.Insert(make_pair("123","123"));
    h.Insert(make_pair("sfd","EWQ"));

}

