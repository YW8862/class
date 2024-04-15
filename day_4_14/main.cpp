
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

using namespace std;

//bool Is(int n){
//    if(n<2)
//        return false;
//    for(int i=2;i<=sqrt(n);i++){
//        if(n%i==0)
//            return false;
//    }
//    return true;
//}
//int main(){
//    int n = 0;
//    vector<int>huang;
//    vector<int>yuyu;
//    cin>>n;
//    for(int i=0;i<n;i++){
//        int a=0;
//        cin>>a;
//        huang.push_back(a);
//    }
//    for(int i=0;i<n;i++){
//        int a=0;
//        cin>>a;
//        yuyu.push_back(a);
//    }
//    int cnt = 0;
//    for(int i=0;i<n;i++){
//        vector<int>::iterator it = yuyu.begin();
//        while(it!=yuyu.end()){
//            if(Is(huang[i]+*it)){
//                cnt++;
//                yuyu.erase(it);
//                break;
//            }
//            it++;
//        }
//    }
//    cout<<cnt<<endl;
//    return 0;
//}

//bool Is(int n){
//    if(pow((int)sqrt(n),2)==n)
//        return true;
//    return false;
//}
//int main(){
//    int n=0;
//    cin>>n;
//    vector<int>v;
//    for(int i=0;i<n;i++){
//        int a=0;
//        cin>>a;
//        v.push_back(a);
//    }
//    int cnt = 0;
//    for(int l = 0;l<n-1;l++){
//        for(int r = l+1;r<n;r++){
//            int ret = 1;
//            for(int i=l;i<=r;i++){
//                ret*=v[i];
//            }
//            if(Is(ret))
//                cnt++;
//        }
//    }
//    cout<<cnt<<endl;
//    return 0;
//}
#include<string>
#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    string::iterator it = s.begin();
    while(it!=s.end()){
        if(*it>='a'&&*it<'e')
            *it = 'a';
        else if(*it>='e'&&*it<'i')
            *it = 'e';
        else if(*it>='i'&&*it<'o')
            *it = 'i';
        else if(*it>='o'&&*it<'u')
            *it = 'o';
        else if(*it>='u'&&*it<='z')
            *it = 'u';
        it++;
    }
    cout<<s<<endl;
}
