#pragma once
#include"Identity.h"

class Manager :public Identity {
	//打印菜单
	Manager() = default;
	Manager(string name,string pwd,size_t id);
	virtual void Oper_Menu();

	void Add_Account();

	void Show_Account();

	//查看机房信息
	void Show_Computer_Room();

	//清空预约记录
	void Clean_File();

private:
	//初始化容器
	void Init_Vector();

	//检测重复 参数1 检测学号/职工号  参数2  检测类型
	bool Check_Repeat(int id, int type);

	size_t _id;

};