#include<bits\stdc++.h>
#include<>
using namespace std;

//C++11新特性
//int main(){
////    initializer_list<int>il={1,2,3,4,5,6,7,8,9,0};
////    vector<int>v1(il);
////    for(auto e:v1){
////        cout<<e<<" ";
////    }
////    cout<<endl;
////    vector<int>v={1,2,3,4,5};
//    string s = "string";
//    cout<<typeid(s).name()<<endl;
//    cout<<typeid("string").name()<<endl;
//    return 0;
//}

//int fun(){
//    return 2;
//}
//
//int main(){
////    const int x =10;
////    cout<<typeid(x).name()<<endl;
////    decltype(x) y = 1;
////    cout<<typeid(y).name()<<endl;
//    vector<decltype(fun())>v1;
//    v1.push_back(1);
//    v1.push_back(2);
//    return 0;
//}

int main(){
    const int c=2;
    cout<<&c<<endl;
    map<string,string>m;
    m.insert({"banana","香蕉"});
    m.insert({"apple","苹果"});
    m.insert({"string","字符串"});
    m.insert({"map","地图"});

    for(auto e:m){
        cout<<e.first<<" "<<e.second<<endl;
    }


    return 0;
}