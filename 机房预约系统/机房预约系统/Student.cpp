#include"Student.h"


Student::Student(size_t id, string name, string pwd) : _id(id) {

}
//��ӡ�˵�
void Student::Oper_Menu() {
	cout << "Welcome��" << this->_M_Name << "Loader��" << endl;
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
	cout << "Input your Selection�� " << endl;
}

//����ԤԼ
void Student::Apply_Order() {

}

//�鿴�ҵ�ԤԼ
void Student::Show_Order() {

}

//�鿴����ԤԼ���
void Student::Show_All_Order() {

}

//ȡ��ԤԼ
void Student::Cancel_Order() {

}

