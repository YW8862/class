#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;


class Base {
private:
	int a=1;
public:
	virtual void f1() {
		cout << "Base::f1()" << endl;
	}
	virtual void f2() {
		cout << "base::f2()" << endl;
	}
};

class Derive :public Base {
private:
	int b=2;
public:
	virtual void f1() {
		cout << "Derive::f1()" << endl;
	}
	virtual void f3() {
		cout << "Derive::f3()" << endl;
	}
};

void func() {
	Base* bb = new Base();
	Base* dd = new Derive();
	*(int*)*(int*)bb;
}
//
//int main() {
//	func();
//	return 0;
//}


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};

//Leetcode 606
class Solution {
public:
	void frontOrder(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		s += '(';
		s += (to_string(root->val));
		if (root->left == nullptr && root->right != nullptr) s += "()";
		frontOrder(root->left);
		frontOrder(root->right);
		s += ')';
	}
	string tree2str(TreeNode* root) {
		frontOrder(root);
		s.erase(s.begin());
		s.pop_back();
		return s;
	}
private:
	string s;
};


//Leetcode 102
class Solution2 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>>res;

		if (root == nullptr)return res;
		queue<TreeNode*>q;
		q.push(root);

		while (!q.empty()) {
			vector<int>tmp;
			size_t size = q.size();
			for (size_t i = 0; i < size; i++) {
				auto node = q.front();
				q.pop();
				tmp.push_back(node->val);
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			res.push_back(tmp);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};