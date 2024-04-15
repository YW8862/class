#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//牛客WY16
//int main() {
//    int W = 0,H = 0;
//    cin>>W>>H;
//    vector<vector<int>>board(W,vector<int>(H,0));
//    int cnt = 0;
//    for(int i = 0;i < W;i++){
//        for(int j = 0;j < H;j++){
//            if(board[i][j] == 0){
//                cnt++;
//                board[i][j] = 1;
//                if(i<W-2)
//                    board[i+2][j] = 1;
//                if(j<H-2)
//                    board[i][j+2] = 1;
//            }
//        }
//    }
//    cout<<cnt<<endl;
//}

//牛客CM46
//class Parenthesis {
//public:
//    bool chkParenthesis(string A, int n) {
//        stack<char>s;
//        string::iterator it = A.begin();
//        while(it!=A.end()){
//            switch(*it){
//                case '(':
//                    s.push(*it);
//                    break;
//                case ')':
//                    if(!s.empty()){
//                        s.pop();
//                        break;
//                    }
//                    else
//                        return false;
//                default:return false;
//            }
//            it++;
//        }
//
//        if(!s.empty()) return false;
//        return true;
//
//    }
//};


//牛客WY20
//#include <iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//    vector<string>s1;
//    int n=0;
//    cin>>n;
//    string s;
//    for(int i=0;i<n;i++){
//        cin>>s;
//        s1.push_back(s);
//    }
//    vector<string>s2=s1;
//    vector<string>s3=s1;
//    sort(s2.begin(),s2.end(),[](string s1,string s2){return s1<s2;});
//    sort(s3.begin(),s3.end(),[](string s1,string s2){return s1.size()<s2.size();});
//    bool match1 = s1 == s2;
//    bool match2 = s1 == s3;
//    if(match1 && match2) cout<<"both"<<endl;
//    else if(!(match1||match2)) cout<<"none"<<endl;
//    else if(match1)  cout<<"lexicographically"<<endl;
//    else if(match2)  cout<<"lengths"<<endl;
//    return 0;
//}

//牛客HJ108
//辗转相除法
//#include <iostream>
//using namespace std;
//
//int fun(int m,int n){
//    if(m%n==0)
//        return n;
//    else
//        return fun(n,m % n);
//}
//
//int main() {
//    int m= 0,n = 0;
//    cin>>m>>n;
//    int temp = fun(m,n);
//    int ret = m/temp*n;
//    cout<<ret<<endl;
//}

//牛客HJ91
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n=0,m=0;
    cin>>n>>m;
    vector<vector<int>>board(m+1,vector<int>(n+1,1));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            board[i][j] = board[i-1][j]+board[i][j-1];
        }
    }
    cout<<board[m][n]<<endl;
    return 0;
}
