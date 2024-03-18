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
		// 如果树为空，删除失败
		if (nullptr == _root)
			return false;
		// 查找在data在树中的位置
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
		// data不在二叉搜索树中，无法删除
		if (nullptr == pCur)
			return false;
		// 分以下情况进行删除，同学们自己画图分析完成
		if (nullptr == pCur->_right)
		{
			// 当前节点只有左孩子或者左孩子为空---可直接删除
		}
		else if (nullptr == pCur->_right){
			// 当前节点只有右孩子---可直接删除
		}
		else{
			// 当前节点左右孩子都存在，直接删除不好删除，可以在其子树中找一个替代结点，
			//比如：
			// 找其左子树中的最大节点，即左子树中最右侧的节点，或者在其右子树中最小的节点，即右子树中最小的节点
			// 替代节点找到后，将替代节点中的值交给待删除节点，转换成删除替代节点
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


