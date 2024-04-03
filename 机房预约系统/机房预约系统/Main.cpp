#include"Identity.h"
#include"Gloabal_File.h"
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
            }
        }

    }
    else if (type == 2) {

    }
    else if (type == 3) {

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
            break;
        case 3:
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
