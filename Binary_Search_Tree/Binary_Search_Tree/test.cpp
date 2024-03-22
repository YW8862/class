#include"Binary_Search_Tree.h"

int main() {
	BSTree<int> t(10);

	t.Insert(2);
	t.Insert(20);
	t.Insert(5);
	t.Insert(7);
	t.Insert(4);
	t.Insert(1);
	t.InOrder();
	cout << endl;
	t.Erase(7);
	t.InOrder();
	cout << endl;
	t.Erase(3);
	t.InOrder();
	cout << endl;
	t.Erase(10);
	t.InOrder();

	return 0;
}