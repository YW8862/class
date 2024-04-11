//#include <iostream>
//#include <algorithm>
//
//using namespace std;

//牛客DD5
//int main() {
//    int a, b;
//    cin>>a>>b;
//    string s = "0123456789ABCDEF";
//    string res;
//    int i=0;
//    int flag=1;
//    if(a<0){
//        a = 0-a;
//        flag = -1;
//    }
//
//    while(a){
//        int ret = a % b;
//        res += s[ret];
//        a /= b;
//    }
//    if(flag==-1){
//        cout<<"-";
//    }
//    reverse(res.begin(),res.end());
//    if(res.size()==0)
//        cout<<"0"<<endl;
//    else
//        cout<<res<<endl;
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    string ch;
    int num = 0;
    cin >> s;
    cin >> ch;
    for (int i = 0; i <= s.size(); i++) {
        string cpstring = s;

        cpstring.insert(i, ch);
        string ss = cpstring;
        reverse(cpstring.begin(), cpstring.end());
        if (cpstring == ss)
            num++;
    }
    cout << num << endl;
}


