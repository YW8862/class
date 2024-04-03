#include"Student.h"


Student::Student(size_t id, string name, string pwd) : _id(id) {

}
//打印菜单
void Student::Oper_Menu() {
	cout << "Welcome：" << this->_M_Name << "Loader！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.Apply Order           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.Show My Order         |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.Show All Order        |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.Cancel Order          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.Exit                  |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "Input your Selection： " << endl;
}

//申请预约
void Student::Apply_Order() {

}

//查看我的预约
void Student::Show_Order() {

}

//查看机房预约情况
void Student::Show_All_Order() {

}

//取消预约
void Student::Cancel_Order() {

}

