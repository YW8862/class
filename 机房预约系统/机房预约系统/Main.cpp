#include"Identity.h"
#include"Gloabal_File.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
using namespace std;


//����ѧ���Ӳ˵�����
void studentMenu(Identity*& student){
    int select = 0;
    do {
        //����ѧ���Ӳ˵�
        student->Oper_Menu();

        Student* stu = (Student*)student;
        
        cin >> select; //�����û�ѡ��

        //����ԤԼ
        if (select == 1) {
            stu->Apply_Order();
        }
        //�鿴����ԤԼ
        else if (select == 2) {
            stu->Show_Order();
        }
        //�鿴������ԤԼ
        else if (select == 3) {
            stu->Show_All_Order();
        }
        //ȡ��ԤԼ
        else if (select == 4) {
            stu->Cancel_Order();
        }
        else{
            //ע����¼
            delete student;
            cout << "ע���ɹ�" << endl;
            system("pause");
            system("cls");
            return;
        }

    } while (select);
}

//�����ʦ�Ӳ˵�����
void teacherMenu(Identity*& teacher){
    int select = 0; //�����û�ѡ��
    do{
        //�����Ӳ˵�����
        teacher->Oper_Menu();

        Teacher* tea = (Teacher*)teacher;

        cin >> select;
        //�鿴����ԤԼ
        if (select == 1) {
            tea->Show_All_Order();
        }
        //���ԤԼ
        else if (select == 2){
            tea->Valid_Order();
        }
        else{
            delete teacher;
            cout << "ע���ɹ�" << endl;
            system("pause");
            system("cls");
            return;
        }
    } while (select);
}

//�������Ա�Ӳ˵�����
void managerMenu(Identity*& manager){
    int select = 0;
    do{      
        //���ù���Ա�Ӳ˵�
        manager->Oper_Menu();

        //������ָ�� תΪ����ָ�룬���������������ӿ�
        Manager* man = (Manager*)manager;

        
        //�����û�ѡ��
        cin >> select;

        //����˺�
        if (select == 1) {
            man->Add_Account();
        }

        //�鿴�˺�
        else if (select == 2){
           
            man->Show_Account();
        }
    
        else if (select == 3) {
            man->Show_Account();
        }
        //���ԤԼ
        else if (select == 4) {
            man->Clean_File();
        }
        else
        {
            //ע��
            delete manager; //���ٵ���������
            cout << "ע���ɹ�" << endl;
            system("pause");
            system("cls");
            return;
        }

    }while (select);

}

void Login_In(string fileName,int type) {
    //ʹ�ö�̬���ò�ͬ��
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
    
    //�����֤
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
