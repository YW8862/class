#include"Identity.h"

class Teacher :public Identity {
public:
	Teacher() = default;
	Teacher(size_t id,string name, string pwd);

	//菜单界面
	virtual void Oper_Menu();


	//查看所有预约
	void Show_All_Order();

	//审核预约
	void Valid_Order();

private:
	size_t _id;
};
