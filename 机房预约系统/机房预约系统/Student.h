#include"Identity.h"

class Student :public Identity {
public:
	Student() = default;
	Student(size_t id, string name, string pwd);
	
	//��ӡ�˵�
	virtual void Oper_Menu();

	//����ԤԼ
	void Apply_Order();

	//�鿴�ҵ�ԤԼ
	void Show_Order();

	//�鿴����ԤԼ
	void Show_All_Order();

	//ȡ��ԤԼ
	void Cancel_Order();

private:
	size_t _id;
};