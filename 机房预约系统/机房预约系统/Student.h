#include"Identity.h"

class Student :public Identity {
public:
	Student() = default;
	Student(size_t id, string name, string pwd);
	
	//打印菜单
	virtual void Oper_Menu();

	//申请预约
	void Apply_Order();

	//查看我的预约
	void Show_Order();

	//查看所有预约
	void Show_All_Order();

	//取消预约
	void Cancel_Order();

private:
	size_t _id;
};