#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

//查找时遇到空或者是存在才停止，遇到删除继续往后面找
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