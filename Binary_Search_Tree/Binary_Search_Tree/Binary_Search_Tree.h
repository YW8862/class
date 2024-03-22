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
				cur = cur->_left;
			}
			else if (cur->_key < key) {
				p = cur;
				cur = cur->_right;
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

	bool Erase(const K& key){
		Node*p=deleteNode(_root, key);
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

	Node* minValueNode(Node* node) {
		Node* current = node;
		while (current && current->_left != nullptr)
			current = current->_left;
		return current;
	}	
	Node* maxValueNode(Node* node) {
		Node* current = node;
		while (current && current->_right != nullptr)
			current = current->_right;
		return current;
	}

	// 在 BST 中删除值为 key 的节点
	Node* deleteNode(Node* root, int key) {
		if (root == nullptr) return root;  // 如果树为空，直接返回

		// 在左子树中查找
		if (key < root->_key)
			root->_left = deleteNode(root->_left, key);

		// 在右子树中查找
		else if (key > root->_key)
			root->_right = deleteNode(root->_right, key);

		// 找到要删除的节点
		else {
			// 节点只有一个子节点或没有子节点
			if (root->_left == nullptr) {
				Node* temp = root->_right;
				delete root;
				return temp;
			}
			else if (root->_right == nullptr) {
				Node* temp = root->_left;
				delete root;
				return temp;
			}

			//// 节点有两个子节点，找到后继节点
			//Node* temp = minValueNode(root->_right);

			//// 将后继节点的值复制到当前节点
			//root->_key = temp->_key;

			//// 删除后继节点
			//root->_right = deleteNode(root->_right, temp->_key);
			Node* temp = maxValueNode(root->_left);
			root->_key = temp->_key;
			root->_left = deleteNode(root->_left, temp->_key);

		}
		return root;
	}
};


