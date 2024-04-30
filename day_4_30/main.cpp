//#include<bits\stdc++.h>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
using namespace std;

//double Division(int a, int b)
//{
//    // 当b == 0时抛出异常
//    if (b == 0)
//        throw "Division by zero condition!";
//    else
//        return ((double)a / (double)b);
//}
//void Func()
//{
//    int len, time;
//    cin >> len >> time;
//    cout << Division(len, time) << endl;
//}
//int main()
//{
//    try {
//        Func();
//    }
//    catch (const char* errmsg) {
//        cout << errmsg << endl;
//    }
//    catch(...){
//        cout<<"unkown exception"<<endl;
//    }
//    return 0;
//}

//可变模板参数
//class Data{
//
//};
//
//void print(){
//
//}
//
//template<typename T,typename...Args>
//void print(T&&value,Args&&...args){
//    cout<<typeid(value).name()<<endl;
//    print(forward<Args>(args)...);
//}
//
//template<size_t N>
//void fun(){
//    cout<<N<<endl;
//    fun<N-1>();
//}
//
//template<>
//void fun<1>(){
//    cout<<0<<endl;
//}
//
//int main(){
//    print(0.1,1,"你好",2,new Data(),3.14);
//    //fun<100>();
//    return 0;
//}

//int main()
//{
//    std::list< std::pair<int, char> > mylist;
//    // emplace_back支持可变参数，拿到构建pair对象的参数后自己去创建对象
//    // 那么在这里我们可以看到除了用法上，和push_back没什么太大的区别
//    mylist.emplace_back(10, 'a');
//    mylist.emplace_back(20, 'b');
//    mylist.emplace_back(make_pair(30, 'c'));
//    mylist.push_back(make_pair(40, 'd'));
//    mylist.push_back({ 50, 'e' });
//    for (auto e : mylist)
//        cout << e.first << ":" << e.second << endl;
//    return 0;
//}

//template <class T>
//void PrintArg(T t){
//    cout << typeid(t).name()<< endl;
//}
////展开函数
//template <class ...Args>
//void ShowList(Args... args){
//    int arr[] = { (PrintArg(args), 0)... };
//    cout << endl;
//}
//int main(){
//    ShowList(1);
//    ShowList(1, 'A');
//    ShowList(1, 'A', std::string("sort"));
//    return 0;
//}

////emplace与emplace_back
//int main(){
//    vector<pair<int,string>>v={};
//    auto it =v.begin();
//    v.insert(v.begin(),make_pair(2,"two"));
//    for(auto e:v){
//        cout<<e.first<<" "<<e.second<<endl;
//    }
//    cout<<endl;
//    return 0;
//}



//lambda表达式

//int main(){
//    int a=1,b=2;
//    auto x=[](int a,int b)->auto {return a+b;};
//    cout<<x(1,2)<<endl;
//    return 0;
//}



//int main(){
//    vector<int>v={3,1,2,6,8,4,5,9,6,4,2,1,9};
//    auto v1=v;
//    sort(v.begin(),v.end());
//    for (auto e:v) {
//        cout<<e<<" ";
//    }
//    cout<<endl<<"-------------------------"<<endl;
//    sort(v1.begin(),v1.end(),[](int a,int b){return b<a; });
//    for (auto e:v1) {
//        cout<<e<<" ";
//    }
//    cout<<endl<<"-------------------------"<<endl;
//    return 0;
//}

//struct Goods{
//    string _name;  // 名字
//    double _price; // 价格
//    int _evaluate; // 评价
//    Goods(const char* str, double price, int evaluate)
//        :_name(str)
//          , _price(price)
//          , _evaluate(evaluate)
//    {}
//};
//struct ComparePriceLess{
//    bool operator()(const Goods& gl, const Goods& gr){
//        return gl._price < gr._price;
//
//    }
//};
//struct ComparePriceGreater{
//    bool operator()(const Goods& gl, const Goods& gr){
//        return gl._price > gr._price;
//    }
//};
//int main(){
//    vector<Goods> v = { { "苹果", 2.1, 5 },
//                       { "香蕉", 3, 4 },
//                       { "橙子", 2.2,3 },
//                       { "菠萝", 1.5, 4 } };
//    sort(v.begin(), v.end(), ComparePriceLess());
//    //sort(v.begin(), v.end(), ComparePriceGreater());
//    for(auto e:v){
//        cout<<e._name<<": "<<e._price<<endl;
//    }
//    return 0;
//}

//int main(){
//    vector<Goods> v = { { "苹果", 2.1, 5 },
//                       { "香蕉", 3, 4 },
//                       { "橙子", 2.2,3 },
//                       { "菠萝", 1.5, 4 } };
//    sort(v.begin(), v.end(), [](Goods g1,Goods g2)->bool{return g1._name<g2._name;});
//    //sort(v.begin(), v.end(), ComparePriceGreater());
//    for(auto e:v){
//        cout<<e._name<<": "<<e._price<<endl;
//    }
//    return 0;
//}


int main(){
    int a=1,b=2;
    auto x=[]()->auto {cout<<"aaa"<<endl;};
    cout<<typeid(x).name()<<endl;
    x();
    return 0;
}
