//#include <iostream>
//#include<algorithm>
//using namespace std;
////牛客CM24
//class LCA {
//public:
//    int getLCA(int a, int b) {
//        while(a!=b){
//            if(a>b)
//                a/=2;
//            else if(b>a)
//                b/=2;
//        }
//        return a;
//    }
//};
//
//#include <iostream>
//#include<vector>
//#include<cmath>
//using namespace std;
//
//bool Is(int n){
//    for(int i=2;i<=sqrt(n);i++){
//        if(!(n%i)){
//            return false;
//        }
//    }
//    return true;
//}
//
//牛客HJ60
//int main() {
//    int num = 0;
//    int m = 0,n=0;
//    cin>>num;
//    n = m = num/2;
//    while(!(Is(m)&&Is(n))){
//        m++;
//        n--;
//    }
//    cout<<n<<endl;
//    cout<<m<<endl;
//}
// 64 位输出请用 printf("%lld")