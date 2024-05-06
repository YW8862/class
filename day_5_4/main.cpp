#include<bits\stdc++.h>
#include<functional>
using namespace std;
//包装器与绑定

//包装器
//可调用对象：函数指针、仿函数、lambda表达式
template<class F, class T>
T useF(F f, T x){//将可调用对象作为函数模板，并在其中调用，传入不同的可执行对象实例化不同的模板参数
    static int count = 0;
    cout << "count:" << ++count << endl;
    cout << "count:" << &count << endl;
    return f(x);
}

double f(double i){
    return i / 2;
}

//
//double fu(int i){
//    return i + 2;
//}

struct Functor{
    double operator()(double d){
        return d / 3;
    }
};

//int main() {
//    // 函数指针
////    cout << useF(f, 11.11) << endl;
////    cout << useF(f, 11.11) << endl;
////    cout << useF(fu, 2) << endl;
//    // 函数对象
//    cout << useF(Functor(), 11.11) << endl;
//    // lamber表达式
//    cout << useF([](double d)->double{ return d/4; }, 11.11) << endl;
//
//    return 0;
//}

//int main() {
//
//    //使用包装器，当函数的返回值和参数列表相同时，类模板只会实例化一份
//    //当函数的返回值或者是参数列表有不同是时，会再实例化出一份类模板
//    // 函数指针
//    function<double(double)> fc1 = f;
//    cout<<useF(fc1,5)<<endl;
//
//    // 函数对象
//    function<double(double)> fc2 = Functor();
//    cout<<useF(fc2,5)<<endl;
//
//    // lamber表达式
//    function<double(double)> fc3 = [](double x)->auto {return x/4;};
//    function<double(double)> fc4 = fc3;
//    cout<<useF(fc3,5)<<endl;
//    cout<<useF(fc4,5)<<endl;
//    function<int(double )> fc5 = [](double x)->auto {return x+5;};
//    cout<<useF(fc5,5)<<endl;
//    return 0;
//}


////力扣T150,逆波兰表达式
//class Solution {
//public:
//    int evalRPN(vector<string>& tokens) {
//        map<string,function<int(int,int)>> opFuntions={
//                {"+",[](int x,int y)->auto{return x+y;}},
//                {"-",[](int x,int y)->auto{return x-y;}},
//                {"*",[](int x,int y)->auto{return x*y;}},
//                {"/",[](int x,int y)->auto{return x/y;}}
//        };
//        stack<int>st;
//        for(auto e:tokens){
//            if(opFuntions.count(e)){
//                int y = st.top();
//                st.pop();
//                int x = st.top();
//                st.pop();
//                st.push(opFuntions[e](x,y)) ;
//            }
//            else{
//                st.push(stoi(e));
//            }
//        }
//        return st.top();
//    }
//};


////不同类型函数的包装
//struct Plus{
//    static int plus(int a, int b){
//        return a + b;
//    }
//};
//
//class Sub{
//public:
//    int sub(int a, int b){
//        return a - b;
//    }
//};
//
//int Max(int x1,int x2){
//    return std::max(x1,x2);
//}
//
//int main(){
//
//    //静态成员函数包装
//    function<int(int,int)>fc1 = Plus::plus;
//    cout<<fc1(2,4)<<endl;
//    //非静态成员函数包装
//    Sub s;
//    function<int(Sub*, int, int)>fc2 = &Sub::sub;
//    cout<<fc2(&s,5,1)<<endl;
//
//    function<int(Sub, int, int)>fc3 = &Sub::sub;
//    cout<<fc3(Sub(),4,1)<<endl;
//
//    //普通函数包装
//    function<int(int,int)>fc4 = Max;
//    cout<<fc4(4,5)<<endl;
//
//    return 0;
//}


//绑定
// 原型如下：
//template <class Fn, class... Args>
///* unspecified */ bind (Fn&& fn, Args&&... args);
//// with return type (2)
//template <class Ret, class Fn, class... Args>
///* unspecified */ bind (Fn&& fn, Args&&... args);


//1.调整参数顺序
//int Sub(int x,int y){
//    return x - y;
//}
//int main(){
//    int x=10,y=20;
//    cout<<Sub(x,y)<<endl;
//    function<int(int,int)> f1 = bind(Sub,placeholders::_2,placeholders::_1);
//    cout<<f1(x,y)<<endl;
//    return 0;
//}

//2.调整参数个数

class Sub{
public:
    int sub(int a, int b){
        return a - b;
    }
};

int main(){
    function<int(Sub, int, int)>fc1 = &Sub::sub;
    cout<<fc1(Sub(),4,1)<<endl;

    function<int(int,int)> fc2 = bind(&Sub::sub,Sub(),placeholders::_1,placeholders::_2);
    cout<<fc2(23,1)<<endl;

//    function<int(int,int)> fc3 = bind(&Sub::sub,Sub(),placeholders::_1,placeholders::_2);
//    cout<<fc3(23,1)<<endl;
//    cout<<typeid(fc3).name()<<endl;
    return 0;
}



