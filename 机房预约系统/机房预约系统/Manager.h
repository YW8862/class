#pragma once
#include"Identity.h"

class Manager :public Identity {
	//��ӡ�˵�
	Manager() = default;
	Manager(string name,string pwd,size_t id);
	virtual void Oper_Menu();

	void Add_Account();

	void Show_Account();

	//�鿴������Ϣ
	void Show_Computer_Room();

	//���ԤԼ��¼
	void Clean_File();

private:
	//��ʼ������
	void Init_Vector();

	//����ظ� ����1 ���ѧ��/ְ����  ����2  �������
	bool Check_Repeat(int id, int type);

	size_t _id;

};