#include"Identity.h"

class Teacher :public Identity {
public:
	Teacher() = default;
	Teacher(size_t id,string name, string pwd);

	//�˵�����
	virtual void Oper_Menu();


	//�鿴����ԤԼ
	void Show_All_Order();

	//���ԤԼ
	void Valid_Order();

private:
	size_t _id;
};
