#include <iostream>
#include<vector>
#include <thread>
#include<windows.h>
using namespace  std;

//异常处理与智能指针

//异常处理
//try
//{
//// 保护的标识代码
//}catch( ExceptionName e1 )
//{
//// catch 块
//}catch( ExceptionName e2 )
//{
//// catch 块
//}catch( ExceptionName eN )
//{
//// catch 块
//}


//在catch需要有try模块
//在抛出异常后，程序会直接跳到catch处，执行catch后面的程序，catch只能捕获对应类型的异常。

//1. 异常是通过抛出对象而引发的，该对象的类型决定了应该激活哪个catch的处理代码。
//2. 被选中的处理代码是调用链中与该对象类型匹配且离抛出异常位置最近的那一个。即当有多个匹配的catch时，会优先匹配最近的catch
//3. 抛出异常对象后，会生成一个异常对象的拷贝，因为抛出的异常对象可能是一个临时对象，
//所以会生成一个拷贝对象，这个拷贝的临时对象会在被catch以后销毁。
//4. catch(...)可以捕获任意类型的异常，问题是不知道异常错误是什么。
//5. 实际中抛出和捕获的匹配原则有个例外，并不都是类型完全匹配，可以抛出的派生类对象，所以一般会使用基类捕获。

//double Division(int a, int b)
//{
//    // 当b == 0时抛出异常
//    if (b == 0)
//        throw "Division by zero condition!";
//    else
//        return ((double)a / (double)b);
//}
//
//void fun(int x){
//
//    if(x%2==0){
//        throw -1;
//    }
//}
//
//void Func()
//{
//    int len, time;
//    cin >> len >> time;
//    cout << Division(len, time) << endl;
//    fun(len);
//}
//
//int main(){
//
//    try{
//        Func();
//    }
//
//    catch (const char* errmsg) {
//        cout << errmsg << endl;
//    }
//
//    catch (int x){
//        cout<<x<<endl;
//    }
//    cout<<"exit"<<endl;
//
//    return 0;
//}

//在函数调用链中异常栈展开匹配原则:
//1. 首先检查throw本身是否在try块内部，如果是再查找匹配的catch语句。如果有匹配的，则调到catch的地方进行处理。
//2. 没有匹配的catch则退出当前函数栈，继续在调用函数的栈中进行查找匹配的catch。如果到达main函数的栈，依旧没有匹配的，则终止程序。
// 这个沿着调用链查找匹配的catch的过程称为栈展开。所以实际中都要加一个catch(...)捕获任意类型的异常，否则当有异常没捕获，程序就会直接终止。

//int main(){
//
//    try{
//        int a=0,b=0;
//        cin>>a>>b;
//        if(b==0) {
//            throw "Division by zero condition!";
//        }
//
//        if(b==1){
//            throw vector<int>();
//        }
//        cout<<a/(double)b<<endl;
//    }
//
//    catch (const char* errmsg) {
//        cout<<__LINE__ <<" "<< errmsg << endl;
//    }
//
//    catch (int x){
//        cout<<x<<endl;
//    }
//
//    catch(...){
//        cout<<"未知错误！"<<endl;
//    }
//
//    cout<<"exit"<<endl;
//
//    return 0;
//}


//// 服务器开发中通常使用的异常继承体系
//// 通常是使用继承与多态机制，总的异常体系作为基类，各个部门有各自的异常派生类，捕获的时候直接捕获其基类即可，使用多态调用其异常抛出函数
//class Exception{
//public:
//    Exception(const string& errmsg, int id):_errmsg(errmsg),_id(id) {}
//    virtual string what() const{
//        return _errmsg;
//    }
//protected:
//    string _errmsg;
//    int _id;
//};
//
//class SqlException : public Exception{
//public:
//    SqlException(const string& errmsg, int id, const string& sql):Exception(errmsg, id), _sql(sql){}
//    virtual string what() const{
//        string str = "SqlException:";
//        str += _errmsg;
//        str += "->";
//        str += _sql;
//        return str;
//    }
//private:
//    const string _sql;
//};
//
//class CacheException : public Exception{
//public:
//    CacheException(const string& errmsg, int id):Exception(errmsg, id){}
//    virtual string what() const{
//        string str = "CacheException:";
//        str += _errmsg;
//        return str;
//    }
//};
//
//class HttpServerException : public Exception{
//public:
//    HttpServerException(const string& errmsg, int id, const string& type):Exception(errmsg, id), _type(type){}
//    virtual string what() const{
//        string str = "HttpServerException:";
//        str += _type;
//        str += ":";
//        str += _errmsg;
//        return str;
//    }
//private:
//    const string _type;
//};
//
//void SQLMgr(){
//    srand(time(0));
//    if (rand() % 7 == 0){
//        throw SqlException("权限不足", 100, "select * from name = '张三'");
//    }
//
//}
//
//void CacheMgr(){
//    srand(time(0));
//    if (rand() % 5 == 0){
//        throw CacheException("权限不足", 100);
//    }
//    else if (rand() % 6 == 0){
//        throw CacheException("数据不存在", 101);
//    }
//    SQLMgr();
//}
//
//void HttpServer(){
//    // ...
//    srand(time(0));
//    if (rand() % 3 == 0){
//        throw HttpServerException("请求资源不存在", 100, "get");
//    }
//    else if (rand() % 4 == 0){
//        throw HttpServerException("权限不足", 101, "post");
//    }
//    CacheMgr();
//}
//
//int main(){
//    while (1){
//        Sleep(1000);
//        try{
//            HttpServer();
//        }
//
//            // 这里捕获父类对象就可以
//        catch (const Exception& e) {
//            // 多态
//            cout << e.what() << endl;
//        }
//        catch (...){
//            cout << "Unkown Exception" << endl;
//        }
//    }
//    return 0;
//}

//异常安全
//1.构造函数完成对象的构造和初始化，最好不要在构造函数中抛出异常，否则可能导致对象不完整或没有完全初始化
//2.析构函数主要完成资源的清理，最好不要在析构函数内抛出异常，否则可能导致资源泄漏(内存泄漏、句柄未关闭等)
//3.C++中异常经常会导致资源泄漏的问题，比如在new和delete中抛出了异常，导致内存泄漏，在lock和unlock之间抛出了异常导致死锁，


//double Division(int a, int b)
//{
//    // 当b == 0时抛出异常
//    if (b == 0)
//        throw "Division by zero condition!";
//    else
//        return ((double)a / (double)b);
//}
//
//class A{
//public:
//    A(){
//        cout<<"A()"<<endl;
//        ptr1 = new int;
//        int x=0,y=0;
//        cin>>x>>y;
//        Division(x,y);
//        ptr2 = new int;
//
//    }
//    ~A(){
//        cout<<"~A()"<<endl;
//        delete ptr1;
//        delete ptr2;
//    }
//private:
//    int* ptr1;
//    int* ptr2;
//};
//int main(){
//    try{
//        A aa;
//    }
//    catch (const char* errmsg){
//        cout<<errmsg<<endl;
//    }
//    return 0;
//}

////C++中异常经常会导致资源泄漏的问题，比如在new和delete中抛出了异常，导致内存泄漏，在lock和unlock之间抛出了异常导致死锁，
////问题解决方案：在中间进行捕获一次，再将异常重新抛出
//
//double Division(int a, int b){
//    // 当b == 0时抛出异常
//    if (b == 0){
//        throw "Division by zero condition!";
//    }
//    return (double)a / (double)b;
//}
//
//void Func(){
//    // 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
//    // 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
//    // 重新抛出去。
//    int* array = new int[10];
//    try {
//        int len, time;
//        cin >> len >> time;
//        cout << Division(len, time) << endl;
//    }
//    //将内存释放后，再重新抛出
//    catch (...){
//        cout << "delete []" << array << endl;
//        delete[] array;
//        throw;
//    }
//    // ...
//    cout << "delete []" << array << endl;
//    delete[] array;
//}
//
//int main(){
//    try{
//        Func();
//    }
//    catch (const char* errmsg){
//        cout << errmsg << endl;
//    }
//    return 0;
//}

////异常规范
//1. 异常规格说明的目的是为了让函数使用者知道该函数可能抛出的异常有哪些。 可以在函数的后面接throw(类型)，列出这个函数可能抛掷的所有异常类型。
//2. 函数的后面接throw()，表示函数不抛异常。
//3. 若无异常接口声明，则此函数可以抛掷任何类型的异常。

//// 这里表示这个函数会抛出A/B/C/D中的某种类型的异常
//void fun() throw(A,B,C,D);
//// 这里表示这个函数只会抛出bad_alloc的异常
//void* operator new (std::size_t size) throw (std::bad_alloc);
//// 这里表示这个函数不会抛出异常
//void* operator delete (std::size_t size, void* ptr) throw();
//// C++11 中新增的noexcept，表示不会抛异常
//thread() noexcept;
//thread (thread&& x) noexcept;


//智能指针
//为了解决由于异常跳出而导致指针没有被释放的问题，提出了智能指针
//智能指针的原理就是使用一个类的代替指针，在构造函数的时候为其开辟空间，类的生命周期结束后就会自动调用其析构函数并释放空间
template<class T>
class smartptr{
private:

public:
    T* _ptr;
    smartptr(T* ptr= nullptr):_ptr(ptr){
        cout<<" smartptr(T*ptr= nullptr)"<<endl;
    }
    ~smartptr(){
        cout<<"~smartptr()"<<endl;
        delete _ptr;
    }
};

double Division(int a, int b){
    // 当b == 0时抛出异常
    if (b == 0){
        throw "Division by zero condition!";
    }
    return (double)a / (double)b;
}

void func(){
    smartptr<int> sp1(new int[10]);
    cout<<sizeof(*sp1._ptr)<<endl;
    smartptr<int> sp2(new int);
    smartptr<int> sp3=new int[10];
    int x,y;
    cin>>x>>y;
    Division(x,y);
}

int main(){
    try{
        func();
    }catch(const char* errmsg){
        cout<<errmsg<<endl;
    }
    return 0;
}