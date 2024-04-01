#include <iostream>
#include<cstring>
#include<map>
using namespace std;
int main() {
    string s;
    cin>>s;
    map<string,int>m;
    while(s.size()){
        m[s]++;
        cin>>s;
    }

    for(auto e:m){
        cout<<e.first<<":"<<e.second<<endl;
    }

}