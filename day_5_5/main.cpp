#include <iostream>
#include<vector>
#include <thread>
#include<windows.h>
using namespace  std;

//�쳣����������ָ��

//�쳣����
//try
//{
//// �����ı�ʶ����
//}catch( ExceptionName e1 )
//{
//// catch ��
//}catch( ExceptionName e2 )
//{
//// catch ��
//}catch( ExceptionName eN )
//{
//// catch ��
//}


//��catch��Ҫ��tryģ��
//���׳��쳣�󣬳����ֱ������catch����ִ��catch����ĳ���catchֻ�ܲ����Ӧ���͵��쳣��

//1. �쳣��ͨ���׳�����������ģ��ö�������;�����Ӧ�ü����ĸ�catch�Ĵ�����롣
//2. ��ѡ�еĴ�������ǵ���������ö�������ƥ�������׳��쳣λ���������һ���������ж��ƥ���catchʱ��������ƥ�������catch
//3. �׳��쳣����󣬻�����һ���쳣����Ŀ�������Ϊ�׳����쳣���������һ����ʱ����
//���Ի�����һ���������������������ʱ������ڱ�catch�Ժ����١�
//4. catch(...)���Բ����������͵��쳣�������ǲ�֪���쳣������ʲô��
//5. ʵ�����׳��Ͳ����ƥ��ԭ���и����⣬��������������ȫƥ�䣬�����׳����������������һ���ʹ�û��ಶ��

//double Division(int a, int b)
//{
//    // ��b == 0ʱ�׳��쳣
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

//�ں������������쳣ջչ��ƥ��ԭ��:
//1. ���ȼ��throw�����Ƿ���try���ڲ���������ٲ���ƥ���catch��䡣�����ƥ��ģ������catch�ĵط����д���
//2. û��ƥ���catch���˳���ǰ����ջ�������ڵ��ú�����ջ�н��в���ƥ���catch���������main������ջ������û��ƥ��ģ�����ֹ����
// ������ŵ���������ƥ���catch�Ĺ��̳�Ϊջչ��������ʵ���ж�Ҫ��һ��catch(...)�����������͵��쳣���������쳣û���񣬳���ͻ�ֱ����ֹ��

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
//        cout<<"δ֪����"<<endl;
//    }
//
//    cout<<"exit"<<endl;
//
//    return 0;
//}


//// ������������ͨ��ʹ�õ��쳣�̳���ϵ
//// ͨ����ʹ�ü̳����̬���ƣ��ܵ��쳣��ϵ��Ϊ���࣬���������и��Ե��쳣�����࣬�����ʱ��ֱ�Ӳ�������༴�ɣ�ʹ�ö�̬�������쳣�׳�����
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
//        throw SqlException("Ȩ�޲���", 100, "select * from name = '����'");
//    }
//
//}
//
//void CacheMgr(){
//    srand(time(0));
//    if (rand() % 5 == 0){
//        throw CacheException("Ȩ�޲���", 100);
//    }
//    else if (rand() % 6 == 0){
//        throw CacheException("���ݲ�����", 101);
//    }
//    SQLMgr();
//}
//
//void HttpServer(){
//    // ...
//    srand(time(0));
//    if (rand() % 3 == 0){
//        throw HttpServerException("������Դ������", 100, "get");
//    }
//    else if (rand() % 4 == 0){
//        throw HttpServerException("Ȩ�޲���", 101, "post");
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
//            // ���ﲶ�������Ϳ���
//        catch (const Exception& e) {
//            // ��̬
//            cout << e.what() << endl;
//        }
//        catch (...){
//            cout << "Unkown Exception" << endl;
//        }
//    }
//    return 0;
//}

//�쳣��ȫ
//1.���캯����ɶ���Ĺ���ͳ�ʼ������ò�Ҫ�ڹ��캯�����׳��쳣��������ܵ��¶���������û����ȫ��ʼ��
//2.����������Ҫ�����Դ��������ò�Ҫ�������������׳��쳣��������ܵ�����Դй©(�ڴ�й©�����δ�رյ�)
//3.C++���쳣�����ᵼ����Դй©�����⣬������new��delete���׳����쳣�������ڴ�й©����lock��unlock֮���׳����쳣����������


//double Division(int a, int b)
//{
//    // ��b == 0ʱ�׳��쳣
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

////C++���쳣�����ᵼ����Դй©�����⣬������new��delete���׳����쳣�������ڴ�й©����lock��unlock֮���׳����쳣����������
////���������������м���в���һ�Σ��ٽ��쳣�����׳�
//
//double Division(int a, int b){
//    // ��b == 0ʱ�׳��쳣
//    if (b == 0){
//        throw "Division by zero condition!";
//    }
//    return (double)a / (double)b;
//}
//
//void Func(){
//    // ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
//    // �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
//    // �����׳�ȥ��
//    int* array = new int[10];
//    try {
//        int len, time;
//        cin >> len >> time;
//        cout << Division(len, time) << endl;
//    }
//    //���ڴ��ͷź��������׳�
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

////�쳣�淶
//1. �쳣���˵����Ŀ����Ϊ���ú���ʹ����֪���ú��������׳����쳣����Щ�� �����ں����ĺ����throw(����)���г�����������������������쳣���͡�
//2. �����ĺ����throw()����ʾ���������쳣��
//3. �����쳣�ӿ���������˺������������κ����͵��쳣��

//// �����ʾ����������׳�A/B/C/D�е�ĳ�����͵��쳣
//void fun() throw(A,B,C,D);
//// �����ʾ�������ֻ���׳�bad_alloc���쳣
//void* operator new (std::size_t size) throw (std::bad_alloc);
//// �����ʾ������������׳��쳣
//void* operator delete (std::size_t size, void* ptr) throw();
//// C++11 ��������noexcept����ʾ�������쳣
//thread() noexcept;
//thread (thread&& x) noexcept;


//����ָ��
//Ϊ�˽�������쳣����������ָ��û�б��ͷŵ����⣬���������ָ��
//����ָ���ԭ�����ʹ��һ����Ĵ���ָ�룬�ڹ��캯����ʱ��Ϊ�俪�ٿռ䣬����������ڽ�����ͻ��Զ������������������ͷſռ�
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
    // ��b == 0ʱ�׳��쳣
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