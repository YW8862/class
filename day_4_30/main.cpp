//#include<bits\stdc++.h>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
using namespace std;

//double Division(int a, int b)
//{
//    // ��b == 0ʱ�׳��쳣
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

//�ɱ�ģ�����
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
//    print(0.1,1,"���",2,new Data(),3.14);
//    //fun<100>();
//    return 0;
//}

//int main()
//{
//    std::list< std::pair<int, char> > mylist;
//    // emplace_back֧�ֿɱ�������õ�����pair����Ĳ������Լ�ȥ��������
//    // ��ô���������ǿ��Կ��������÷��ϣ���push_backûʲô̫�������
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
////չ������
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

////emplace��emplace_back
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



//lambda���ʽ

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
//    string _name;  // ����
//    double _price; // �۸�
//    int _evaluate; // ����
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
//    vector<Goods> v = { { "ƻ��", 2.1, 5 },
//                       { "�㽶", 3, 4 },
//                       { "����", 2.2,3 },
//                       { "����", 1.5, 4 } };
//    sort(v.begin(), v.end(), ComparePriceLess());
//    //sort(v.begin(), v.end(), ComparePriceGreater());
//    for(auto e:v){
//        cout<<e._name<<": "<<e._price<<endl;
//    }
//    return 0;
//}

//int main(){
//    vector<Goods> v = { { "ƻ��", 2.1, 5 },
//                       { "�㽶", 3, 4 },
//                       { "����", 2.2,3 },
//                       { "����", 1.5, 4 } };
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
