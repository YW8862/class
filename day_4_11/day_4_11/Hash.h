#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

//����ʱ�����ջ����Ǵ��ڲ�ֹͣ������ɾ��������������
enum State{
	EMPTY,
	EXIST,
	DELETE
};

template<class K,class V>
struct HashData {
	pair<K, V>;
	State _state;
};
template<class K,class V>
class Hash {

private:
	vector<pair<K,V>> _table;
};