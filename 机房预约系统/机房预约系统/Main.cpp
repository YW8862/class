#include"Identity.h"
#include"Gloabal_File.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
using namespace std;


//进入学生子菜单界面
void studentMenu(Identity*& student){
    int select = 0;
    do {
        //调用学生子菜单
        student->Oper_Menu();

        Student* stu = (Student*)student;
        
        cin >> select; //接受用户选择

        //申请预约
        if (select == 1) {
            stu->Apply_Order();
        }
        //查看自身预约
        else if (select == 2) {
            stu->Show_Order();
        }
        //查看所有人预约
        else if (select == 3) {
            stu->Show_All_Order();
        }
        //取消预约
        else if (select == 4) {
            stu->Cancel_Order();
        }
        else{
            //注销登录
            delete student;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }

    } while (select);
}

//进入教师子菜单界面
void teacherMenu(Identity*& teacher){
    int select = 0; //接受用户选择
    do{
        //调用子菜单界面
        teacher->Oper_Menu();

        Teacher* tea = (Teacher*)teacher;

        cin >> select;
        //查看所有预约
        if (select == 1) {
            tea->Show_All_Order();
        }
        //审核预约
        else if (select == 2){
            tea->Valid_Order();
        }
        else{
            delete teacher;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    } while (select);
}

//进入管理员子菜单界面
void managerMenu(Identity*& manager){
    int select = 0;
    do{      
        //调用管理员子菜单
        manager->Oper_Menu();

        //将父类指针 转为子类指针，调用子类里其他接口
        Manager* man = (Manager*)manager;

        
        //接受用户选项
        cin >> select;

        //添加账号
        if (select == 1) {
            man->Add_Account();
        }

        //查看账号
        else if (select == 2){
           
            man->Show_Account();
        }
    
        else if (select == 3) {
            man->Show_Account();
        }
        //清空预约
        else if (select == 4) {
            man->Clean_File();
        }
        else
        {
            //注销
            delete manager; //销毁掉堆区对象
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }

    }while (select);

}

void Login_In(string fileName,int type) {
    //使用多态调用不同的
    Identity* person = nullptr;
    ifstream ifs;
    ifs.open(fileName, ios::in);

    if (!ifs.is_open()) {
        cout << "No File!" << endl;
        ifs.close();
        return;
    }

    size_t id;
    string name;
    string pwd;

    if (type == 1) {
        cout << "Input your Student ID Please!:->" << endl;
        cin >> id;
    }
    else  if (type == 2) {
        cout << "Input your job ID Please!:->" << endl;
        cin >> id;
    }
    cout << "Input Your Name:->" << endl;
    cin >> name;
    cout << "Input Your Password!:->" << endl;
    cin >> pwd;
    
    //身份验证
    if (type == 1) {
        size_t fid;
        string fname;
        string fpwd;
        while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
            if (fid == id && fname == name && fpwd == pwd) {
                cout << "Load Successfully!" << endl;
                system("pause");
                system("cls");
                person = new Student(id,name, pwd);

                return;
            }
        }

    }
    else if (type == 2) {
        size_t fid;
        string fname;
        string fpwd;
        while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
            if (fid == id && fname == name && fpwd == pwd) {
                cout << "Load Successfully!" << endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);

                return;
            }
        }
    }
    else if (type == 3) {
        string fname;
        string fpwd;
        while (ifs >> fname && ifs >> fpwd) {
            if (fname == name && fpwd == pwd) {
                cout << "Load Successfully!" << endl;
                system("pause");
                system("cls");
                person = new Manager(name, pwd);

                return;
            }
        }
    }
    cout << "Loade Fail! Check your account or password Please!" << endl;
    system("pause");
    system("cls");
    return;
}
inline void menu() {
    cout << "======================  Welcome  =====================" << endl;
    cout << endl << "Select your identity!" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1.Student            |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2.Teacher            |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          3.Administrator      |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0.Exit               |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
    cout << "Input your Selection: ";
}

int main() {
    size_t select = 0;
    do {
        menu();
        cin >> select;
        switch (select) {
        case 1:
            Login_In(STUDENT_FILE, 1);
            break;
        case 2:
            Login_In(TEACHER_FILE, 2);
            break;
        case 3:
            Login_In(ADMIN_FILE, 3);
            break;
        case 0:
            cout << "See you!" << endl;
            break;
        default:
            cout << "Error Select,try again please!" << endl;
            system("pause");
            system("cls");
            break;
        }
    } while (select);
    return 0;
}
