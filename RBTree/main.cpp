#include"RBTree.h"
#include<bits/stdc++.h>
using namespace std;

int main(){
    RBTree<string,int> t;
    t.Insert(make_pair("apple",1));
    t.Insert(make_pair("banana",2));
    t.Insert(make_pair("peat",3));
    t.In_Order();
    t.LeftMost()->print();
    return 0;
}