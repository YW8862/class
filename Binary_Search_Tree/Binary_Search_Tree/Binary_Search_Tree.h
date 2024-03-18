#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

template<class K>
struct BSTreeNode {


	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
	struct BSTreeNode(const K& key):_left(nullptr),_right(nullptr),_key(key) {
	}
};

template<class K>
class BSTree {
	typedef BSTreeNode<K> Node;
public:
	
	BSTree(){	
		_root = nullptr;
	}

	BSTree(K key){
		this->_root = new Node(key);
	}

	~BSTree() {
		dest(_root);
	}

	bool Find(K key) {
		return _Find(_root,key);
	}

	bool Insert(const K key) {
		if (_root == nullptr) {
			_root =new Node(key);
			return true;
		}
		Node* p = nullptr;
		Node* cur = _root;
		while (cur != nullptr) {
			if (cur->_key > key) {
				p = cur;
				cur = _root->_left;
			}
			else if (cur->_key < key) {
				p = cur;
				cur = _root->_right;
			}
		}
		cur =new Node(key);
		if (key > p->_key) {
			p->_right = cur;
		}
		else {
			p->_left = cur;
		}
		return true;
	}

	void InOrder() {
		_InOrder(_root);
	}

	bool Erase(const K& key)
	{
		// �����Ϊ�գ�ɾ��ʧ��
		if (nullptr == _root)
			return false;
		// ������data�����е�λ��
		Node* pCur = _root;
		Node* pParent = nullptr;
		while (pCur)
		{
			if (key == pCur->_key)
				break;
			else if (key < pCur->_key)
			{
				pParent = pCur;
				pCur = pCur->_left;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_right;
			}
		}
		// data���ڶ����������У��޷�ɾ��
		if (nullptr == pCur)
			return false;
		// �������������ɾ����ͬѧ���Լ���ͼ�������
		if (nullptr == pCur->_right)
		{
			// ��ǰ�ڵ�ֻ�����ӻ�������Ϊ��---��ֱ��ɾ��
		}
		else if (nullptr == pCur->_right){
			// ��ǰ�ڵ�ֻ���Һ���---��ֱ��ɾ��
		}
		else{
			// ��ǰ�ڵ����Һ��Ӷ����ڣ�ֱ��ɾ������ɾ��������������������һ�������㣬
			//���磺
			// �����������е����ڵ㣬�������������Ҳ�Ľڵ㣬������������������С�Ľڵ㣬������������С�Ľڵ�
			// ����ڵ��ҵ��󣬽�����ڵ��е�ֵ������ɾ���ڵ㣬ת����ɾ������ڵ�
		}
		return true;
	}


private:
	Node* _root=nullptr;

	void dest(Node* root) {
		if (root == nullptr)
			return;
		if (root->_left == nullptr && root->_right == nullptr) {
			delete root;
			return;
		}
		dest(root->_left);
		dest(root->_right);
	}

	bool _Find(Node* _root, K key) {
		if (_root == nullptr)
			return false;
		if (_root->_key == key)
			return true;
		return _Find(_root->_left) || _Find(_root->_right);
	}

	void _InOrder(Node*_root) {
		if (_root == nullptr) 
			return;
		_InOrder(_root->_left);
		cout << _root->_key << " ";
		_InOrder(_root->_right);
	}

};


