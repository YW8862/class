#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <string.h>
#include <numeric>
#include <map>
#include <unordered_map>
#include <functional>
#include <cassert>
#include <queue>

#include "Date.h"
using namespace std;
using namespace myClass;

//单链表节点定义
template <class T>
class ListNode
{
public:
    T val;
    ListNode *next;

    ListNode() : val(0), next(nullptr)
    {}

    explicit ListNode(T x) : val(x), next(nullptr)
    {}

    ListNode(T x, ListNode *next) : val(x), next(next)
    {}

    ListNode(const ListNode& node) = default;
};


//模板树节点定义
template<class T>
class TreeNode {
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(T x): val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(T x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {
    }
};

template<class T>
class Tree {
public:
    TreeNode<T> *root;

    void _preorder(TreeNode<T> *root) {
        if (root == nullptr)return;
        cout << root->val << " ";
        _preorder(root->left);
        _preorder(root->right);
    }

    void _inorder(TreeNode<T> *root) {
        if (root == nullptr)return;
        _inorder(root->left);
        cout << root->val << " ";
        _inorder(root->right);
    }

    void _postorder(TreeNode<T> *root) {
        if (root == nullptr)return;
        _postorder(root->left);
        _postorder(root->right);
        cout << root->val << " ";
    }

    TreeNode<T> *_init(vector<T> list, int pos) {
        if (pos >= list.size() || list[pos] == INT_MIN)
        	return nullptr;
        TreeNode<T> *node = new TreeNode<T>(list[pos]);
        node->left = _init(list, 2 * pos + 1);
        node->right = _init(list, 2 * pos + 2);
        return node;
    }

public:
    Tree(initializer_list<T> list) {
        root = _init(list, 0);
    }


    void preorder() {
        _preorder(root);
    }

    void inorder() {
        _inorder(root);
    }

    void postorder() {
        _postorder(root);
    }
};


template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf; // balance factor
	pair<K, V> _kv;

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		while (parent)
		{
			if(cur == parent->left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 旋转处理
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else
				{
					RotateRL(parent);
				}

				break;
			}
			else
			{
				// 插入之前AVL树就有问题
				assert(false);
			}
		}

		return true;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if(subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}
			subR->_parent = ppnode;
		}

		parent->_bf = 0;
		subR->_bf = 0;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;

		Node* ppnode = parent->_parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subL;
			}
			else
			{
				ppnode->_right = subL;
			}
			subL->_parent = ppnode;
		}

		subL->_bf = 0;
		parent->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		int bf = subLR->_bf;
		RotateL(parent->_left);
		RotateR(parent);

		if (bf == -1)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)
		{
			subLR->_bf = 0;
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == 0)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

private:
	Node* _root = nullptr;
};

////Leetcode 11
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        size_t size = height.size();
//        int left=0,right=size-1;
//        //创建数组存放最大面积。
//        vector<int>area;
//        while(left<right){
//            int Area = min(height[left],height[right])*(right-left);
//            area.push_back(Area);
//            if(height[left] < height[right])
//                left++;
//            else if(height[left] > height[right])
//                right--;
//            else{
//                if(height[left+1]>height[right-1])
//                    right--;
//                else
//                    left++;
//            }
//        }
//        int max_area = area[0];
//        for(auto e:area)
//            if(e>max_area)
//                max_area = e;
//        return max_area;
//    }
//};
//bool find(vector<int>price,int start,int dif){
//    int i=start,j=price.size()-1;
//    while(i<=j){
//        int mid = (i+j)/2;
//        if(price[mid]>dif) j--;
//        else if(price[mid]<dif) i++;
//        else return true;
//    }
//    return false;
//}
//int main() {
//    vector<int>height={1,2,3,4,5,6,7,8};
//    cout<<find(height,3,8)<<endl;
//    //cout<<Solution().maxArea(height)<<endl;
//    return 0;
//}

//class Solution {
//public:
//    double myPow(double x, int n) {
//        if(x==0)return 0;
//        if(n==0)return 1;
//        if(n>0)
//            return x*myPow(x,n-1);
//        else
//            return 1.0/x*myPow(x,n+1);
//    }
//};


//Leetcode 2331
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    bool evaluateTree(TreeNode* root) {
//        if(root->left==nullptr&&root->right==nullptr&&root->val)return true;
//        if(root->left==nullptr&&root->right==nullptr&&root->val==0)return false;
//        if(root->val == 2)return evaluateTree(root->left)||evaluateTree(root->right);
//        return evaluateTree(root->left)&&evaluateTree(root->right);
//    }
//};
//
//int main(){
//    cout<<Solution().myPow(2.1,3);
//    return 0;
//
//}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//Leetcode 129
//class Solution {
//public:
//    int sumNumbers(TreeNode* root) {
//        if(root==nullptr)return 0;
//        if(root->left==nullptr&&root->right==nullptr)return root->val;
//        return pre(root->left,root->val)+pre(root->right,root->val);
//    }
//    int pre(TreeNode* root,int preval){
//        if(root == nullptr)return preval;
//        int curval = 0;
//        if(root->left==nullptr&&root->right==nullptr){
//            curval = 10*preval+root->val;
//            return curval;
//        }
//        curval = 10*preval+root->val;
//        return pre(root->left,curval)+pre(root->right,curval);
//    }
//};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

////Leetcode 98
//class Solution {
//public:
//    bool isValidBST(TreeNode* root) {
//        if(root->left==nullptr&&root->right==nullptr)return true;
//        return isValid(root,LONG_LONG_MIN,LONG_LONG_MAX);
//    }
//    bool isValid(TreeNode*root,long long min,long long max){
//        if(root==nullptr)return true;
//        return root->val>min
//               &&root->val<max
//               &&isValid(root->left,min,root->val)
//               &&isValid(root->right,root->val,max);
//    }
//};


//int main(){
//    Tree<int> t = {0,1,2,3,4,5,6};
//    t.inorder();
//}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//Leetcode230
//template<class T>
//class Solution {
//private:
//    int pos;
//    int ret;
//public:
//    Solution(){
//        pos = 0;
//        ret = 0;
//    }
//
//    int kthSmallest(TreeNode<T>* root, int k) {
//        order(root,k);
//        return ret;
//    }
//    void order(TreeNode<T>*root,int k){
//        if(root==nullptr)return;
//        order(root->left,k);
//        pos++;
//        if(pos == k)
//            ret = root->val;
//        order(root->right,k);
//    }
//};

////Leetcode257
//
//class Solution {
//public:
//    vector<string>ret;
//    vector<string> binaryTreePaths(TreeNode<int>* root) {
//        if(root==nullptr)
//            return ret;
//        string s = to_string(root->val);
//        if(root->left == nullptr && root->right == nullptr){
//            ret.push_back(s);
//            return ret;
//        }
//        order(root->left,s);
//        order(root->right,s);
//        return ret;
//    }
//    void order(TreeNode<int>*root,string s){
//        if(root==nullptr){
//            return;
//        }
//        s+="->";
//        s+=to_string(root->val);
//        order(root->left,s);
//        order(root->right,s);
//        if(root->left==nullptr && root->right==nullptr){
//            ret.push_back(s);
//            return;
//        }
//    }
//
//};
//int main(){
//    Tree<int>t = {1};
//    vector<string>ret = Solution().binaryTreePaths(t.root);
//    for(auto e:ret){
//        cout<<e<<endl;
//    }
//    return 0;
//}

////Leetcode 46
//class Solution {
//public:
//    vector<vector<int>>ret;
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<int>v;
//        vector<bool>check(nums.size(),false);
//        backtracking(nums,v,check);
//        return ret;
//    }
//    void backtracking(vector<int>nums,vector<int>v,vector<bool>check){
//        if(v.size() == nums.size()){
//            ret.push_back(v);
//            return;
//        }
//        for(int i=0;i<nums.size();i++){
//            if(check[i] == false){
//                //如果数字没有使用过，将数字放进数组中
//                v.push_back(nums[i]);
//                check[i] = true;
//                backtracking(nums,v,check);
//                //回退
//                v.pop_back();
//                check[i] = false;
//            }
//        }
//
//    }
//};

////Leetcode 78
//class Solution {
//public:
//    vector<vector<int>>ret;
//    vector<vector<int>> subsets(vector<int>& nums) {
//        vector<int>v;
//        ret.push_back(v);
//        bachtracking(nums,v,0);
//        return ret;
//    }
//    void bachtracking(vector<int>nums,vector<int>v,int i){
//        if(i == nums.size()){
//            return;
//        }
//        for(int index = i;index<nums.size();index++){
//            v.push_back(nums[index]);
//            ret.push_back(v);
//            bachtracking(nums,v,index+1);
//            v.pop_back();
//        }
//    }
//};


//#include <iostream>
//#include <string>
//using namespace std;
//std::string solution(std::string binary1, std::string binary2) {
//    // Please write your code here
//    int weight = 1;
//    int num1 = 0;
//    int num2 = 0;
//    while(!binary1.empty()){
//        num1 += (binary1[binary1.length()-1]-48)*weight;
//        binary1.pop_back();
//        weight *= 2;
//    }
//    weight = 1;
//    while(!binary2.empty()){
//        num2 += (binary2.at(binary2.length()-1)-'0')*weight;
//        binary2.pop_back();
//        weight *= 2;
//    }
//    return to_string(num1+num2);
//}
//int main(){
//    cout<<solution("110","101")<<endl;
//    return 0;
//}

//Leetcode1863
//class Solution {
//public:
//    vector<vector<int>>ret;
//    int sum;
//    int subsetXORSum(vector<int>& nums) {
//        sum = 0;
//
//        vector<int>v;
//        bachtracking(nums,v,0);
//        return sum;
//    }
//
//    void bachtracking(vector<int>nums,vector<int>v,int i){
//        if(i == nums.size()){
//            return;
//        }
//        for(int index = i;index<nums.size();index++){
//            v.push_back(nums[index]);
//            int tmp = 1;
//            for(auto e:v){
//                tmp = tmp^e;
//            }
//            sum += tmp;
//            bachtracking(nums,v,index+1);
//            v.pop_back();
//        }
//}
//};
//int main(){
//    vector<int>nums = {1,3};
//    cout<<Solution().subsetXORSum(nums);
//    return 0;
//}

////求字符串配比权重
//double getvalue(std::string s){
//    double weight = 0.1;
//    double value = 0.0;
//    for(auto e:s){
//        value += weight*e;
//        weight = weight+0.1;
//    }
//    return value;
//}
//std::string solution(std::string dna_sequence) {
//    // Please write your code here
//    //旋转字符串，按照权重求值
//    string ret = dna_sequence;
//    string restr = dna_sequence;
//    double minvalue = getvalue(dna_sequence);
//    for(int i=0;i<dna_sequence.size();i++){
//        auto e = dna_sequence.at(dna_sequence.size()-1);
//        dna_sequence.pop_back();
//        dna_sequence = e + dna_sequence;
//        double curval = getvalue(dna_sequence);
//        if(curval < minvalue){
//            ret = dna_sequence;
//            minvalue = curval;
//        }
//    }
//    return ret;
//}
//
//
//int main() {
//    // You can add more test cases here
//    std::cout << solution("ATCA") << std::endl;
//    std::cout << solution("CGAGTC") << std::endl;
//    std::cout << solution("TCATGGAGTGCTCCTGGAGGCTGAGTCCATCTCCAGTAG") << std::endl;
//    return 0;
//}

//class MyQueue {
//public:
//    MyQueue()
//    {
//
//    }
//
//    void push(int x)
//    {
//        s1.push(x);
//    }
//
//    int pop()
//    {
//        //存放返回数据
//        int ret = 0;
//        //存放临时搬运数据
//        int tmp = 0;
//        //将s1的数据放到s2中
//        while(!s1.empty())
//        {
//            tmp = s1.top();
//            s1.pop();
//            s2.push(tmp);
//        }
//        if(!s2.empty())
//        {
//            ret = s2.top();
//            s2.pop();
//        }
//        while(!s2.empty())
//        {
//            tmp = s2.top();
//            s2.pop();
//            s1.push(tmp);
//        }
//        return ret;
//    }
//
//    int peek()
//    {
//        //存放返回数据
//        int ret = 0;
//        //存放临时搬运数据
//        int tmp = 0;
//        //将s1的数据放到s2中
//        while(!s1.empty())
//        {
//            tmp = s1.top();
//            s1.pop();
//            s2.push(tmp);
//        }
//        if(!s2.empty())
//        {
//            ret = s2.top();
//        }
//        while(!s2.empty())
//        {
//            tmp = s2.top();
//            s2.pop();
//            s1.push(tmp);
//        }
//        return ret;
//    }
//
//    bool empty()
//    {
//        return s1.empty();
//    }
//private:
//    stack<int>s1;
//    stack<int>s2;
//};
//
///**
// * Your MyQueue object will be instantiated and called as such:
// * MyQueue* obj = new MyQueue();
// * obj->push(x);
// * int param_2 = obj->pop();
// * int param_3 = obj->peek();
// * bool param_4 = obj->empty();
// */
//
//int main()
//{
//    MyQueue obj;
//    obj.push(1);
//    obj.push(2);
//    cout<<obj.peek()<<endl;
//    cout<<obj.pop()<<endl;
//    cout<<obj.empty()<<endl;
//    return 0;
//}

////newcodeBM44
////堆栈法
//class Solution
//{
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param s string字符串
//     * @return bool布尔型
//     */
//    bool isValid(string s)
//    {
//        stack<char>st;
//        char topvalue = '\0';
//        for(auto e:s)
//        {
//            if(e == '(' || e == '[' || e == '{')
//            {
//                st.push(e);
//            }
//            else
//            {
//                if(st.empty())
//                    return false;
//                topvalue = st.top();
//                st.pop();
//                switch(e)
//                {
//                    case ')':
//                        if (topvalue != '(')
//                            return false;
//                        break;
//                    case ']':
//                        if (topvalue != '[')
//                            return false;
//                        break;
//                    case '}':
//                        if (topvalue != '{')
//                            return false;
//                        break;
//                    default:
//                        break;
//                }
//            }
//
//        }
//        if(!st.empty())
//            return false;
//        return true;
//    }
//};


//* Definition for singly-linked list.

////使用栈完成
//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        if(head == nullptr ||head->next == nullptr)
//            return true;
//        stack<int>st;
//        int num = 0,curnum = 1;
//        ListNode*cur = head;
//        int topvalue = 0;
//        while(cur){
//            num++;
//            cur = cur->next;
//        }
//        cur = head;
//        while(cur){
//            if(num%2 && curnum == num/2 + 1){
//                curnum++;
//                cur = cur->next;
//                continue;
//            }
//            else if(curnum > num/2){
//                if(st.empty())
//                    return false;
//                topvalue = st.top();
//                st.pop();
//                if(topvalue != cur->val)
//                    return false;
//            }else{
//                st.push(cur->val);
//            }
//            curnum++;
//            cur = cur->next;
//        }
//        if(st.empty())
//            return true;
//        return false;
//    }
//};

////反拷比对
//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        if(head ==nullptr || head->next == nullptr)
//            return true;
//        forward_list<int>li;
//        ListNode* cur = head;
//        while(cur){
//            li.push_front(cur->val);
//            cur = cur -> next;
//        }
//        cur = head;
//        for(auto e:li)
//        {
//            if(e != cur->val)
//                return false;
//            cur = cur->next;
//        }
//        return true;
//    }
//};
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

////排序复制法
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param lists ListNode类vector
//     * @return ListNode类
//     */
//
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        // write code here
//        ListNode* newhead = new ListNode(0);
//        ListNode* p = newhead;
//        multiset<int>ms;
//        for(auto e:lists){
//            ListNode *cur = e;
//            while(cur){
//                ms.insert(cur->val);
//                cur = cur->next;
//            }
//        }
//        for(auto e:ms){
//            ListNode *node = new ListNode(e);
//            node->val = e;
//            p->next = node;
//            p = p->next;
//        }
//        return newhead->next;
//    }
//};

////分治、归并法
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param lists ListNode类vector
//     * @return ListNode类
//     */
//     ListNode* merge(ListNode*list1,ListNode*list2){
//        ListNode* rethead = new ListNode(0);
//        ListNode* opret = rethead;
//        ListNode* p1 = list1;
//        ListNode* p2 = list2;
//        while(p1 && p2){
//            if(p1->val < p2->val){
//                opret->next = p1;
//                p1 = p1->next;
//            }else{
//                opret->next = p2;
//                p2 = p2->next;
//            }
//            opret = opret->next;
//        }
//        opret->next = p1==nullptr?p2:p1;
//        return rethead->next;
//    }
//    void print(ListNode* list){
//        ListNode* cur = list;
//        while(cur){
//            cout<<cur->val<<" ";
//            cur = cur->next;
//        }
//        cout<<endl;
//    }
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        // write code here
//        if(lists.size() == 0)
//            return nullptr;
//        if(lists.size() == 1)
//            return lists[0];
//        //return merge(lists[0],lists[1]);
//        int curnum = lists.size();
//        while(curnum != 1){
//            for(int i = 0;i<curnum/2;i++){
//                lists[i] = merge(lists[i], lists[curnum-1-i]);
//            }
//            curnum = curnum/2 + curnum%2;
//        }
//        return lists[0];
//    }
//};

////leetcode965
//class Solution {
//public:
//    bool isUnivalTree(TreeNode<int>* root) {
//        if(root==nullptr)
//            return true;
//        if(root->left&&root->right)
//            return (root->val==root->left->val)
//                   &&(root->val==root->right->val)
//                   &&isUnivalTree(root->left)
//                   &&isUnivalTree(root->right);
//        if(root->left)
//            return (root->val==root->left->val)
//                   &&isUnivalTree(root->left);
//        if(root->right)
//            return (root->val==root->right->val)
//                   &&isUnivalTree(root->right);
//        return true;
//    }
//};


//void quicksort(vector<int>&nums,int left,int right){
//    if(left == right || nums.size() == 0)
//        return;
//    int pl = left,pr = right,stdnum = nums[left],stdpos = pl;
//    while(pl < pr){
//        if(nums[pr] < stdnum) {
//            stdpos = pr;
//            swap(nums[pl], nums[pr]);
//            pl++;
//        }else if(nums[pl] > stdnum){
//            stdpos = pl;
//            swap(nums[pl],nums[pr]);
//            pr--;
//        }
//    }
//}

//int main(){
//    const char* str1 = "runnoode";
//    const char* str2 = "nood";
//    char* ret = strstr(str1,str2);
//    printf("&str1:%p\n",str1);
//    printf("str1:%s\n",str1);
//    printf("&ret:%p\n",ret);
//    printf("ret:%s\n",ret);
//    return 0;
//}

//Date类测试
//int main()
//{
//    Date date1(2013,9,15);
//    Date date2(2014,3,20);
//    cout<<date2 - date1<<endl;
//}

//Leetcode414
//class Solution {
//public:
//    int thirdMax(vector<int>& nums) {
//        if(nums.size() == 1)    return nums[0];
//        if(nums.size() == 2)    return nums[0]>nums[1]?nums[0]:nums[1];
//
//        sort(nums.begin(),nums.end());
//        int p = nums.size()-1;
//        //count for valid move
//        int count = 0;
//
//        while(p >= 1 && count != 2)
//        {
//            p --;
//            //valid move
//            if(nums[p] != nums[p+1])
//                count ++;
//        }
//        if(count == 2)
//            return nums[p];
//        return nums[nums.size()-1];
//    }
//};

//leetcode 1958
//class Solution {
//public:
//    int minOperations(vector<int>& nums, int x) {
//        int target = accumulate(nums.begin(),nums.end(),0) - x;
//        //no answer
//        if(target<0)return -1;
//
//        int ret = -1;
//        int left = 0,sum=0,size = nums.size();
//        for(int right =0;right<size;right++)
//        {
//            sum += nums[right];
//            while(sum>target)   sum -= nums[left++];//narrow the window
//            if(sum == target)   ret = max(ret, right-left+1);
//        }
//        return ret < 0?-1:size-ret;
//    }
//};


//leetcode 455
//class Solution {
//public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        sort(g.begin(),g.end());
//        sort(s.begin(),s.end());
//        int pg=0,ps=0,count=0;
//        //order
//        while(ps<s.size()&&pg<g.size())
//        {
//            if(s[ps++]>=g[pg])
//            {
//                pg++;
//                count++;
//            }
//        }
//        return count;
//    }
//};

////leetcode 904
//class Solution
//{
//public:
//    int totalFruit(vector<int>& fruits)
//    {
//        int size = fruits.size();
//        map<int, int> cnt;
//
//        int left = 0, ans = 0;
//        for (int right = 0; right < size; ++right)
//        {
//            ++cnt[fruits[right]];
//            while (cnt.size() > 2)
//            {
//                cnt[fruits[left]]--;
//                if (cnt[fruits[left]] == 0)
//                {
//                    cnt.erase(fruits[left]);
//                }
//                ++left;
//            }
//            ans = max(ans, right - left + 1);
//        }
//        return ans;
//    }
//};
//
//
//int main()
//{
//    vector<int>fruits = {0,1,2,2};
//    cout<<Solution().totalFruit(fruits)<<endl;
//}


//leetcode 905
//class Solution {
//public:
//    vector<int> sortArrayByParity(vector<int>& nums) {
//        int left = 0,right = nums.size()-1;
//        while(left<right)
//        {
//            if(1==nums[left]%2 && 0==nums[right]%2)
//            {
//                swap(nums[left],nums[right]);
//            }
//            while(0==nums[left]%2&&left<nums.size())
//            {
//                left++;
//            }
//            while(1==nums[right]%2&&right>=0)
//            {
//                right--;
//            }
//        }
//        return nums;
//    }
//};
//
//int main()
//{
//       vector<int>nums = {3,1,2,4};
//       nums = Solution().sortArrayByParity(nums);
//       for(auto num:nums)
//       {
//           cout<<num<<" ";
//       }
//}


//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        vector<int>ms(26,0);
//        vector<int>mp(26,0);
//
//        int lens = s.size(),lenp = p.size();
//        //
//        for(auto ch:p)
//        {
//            mp[ch-'a']++;
//        }
//        vector<int>res;
//        int left = 0,right = lenp-1;
//        //search for first window
//        for(int i=left;i<=right;i++)
//        {
//            ms[s[i]-'a']++;
//        }
//        if(ms == mp)
//        {
//            res.push_back(left);
//        }
//        while(right<lens-1)
//        {
//            right++;
//            ms[s[right]-'a']++;
//            ms[s[left]-'a']--;
//            left++;
//            if(ms == mp)
//            {
//                res.push_back(left);
//            }
//        }
//        return res;
//    }
//};

//int main()
//{
//    string s = "cbaebabacd";
//    string p = "abc";
//    vector<int>ans = Solution().findAnagrams(s,p);
//    for(auto index:ans)
//    {
//        cout<<index<<" ";
//    }
//    return 0;
//}

//
//class Solution {
//public:
//    int longestSubstring(string s, int k) {
//        if(s.size()<k)  return 0;
//        return longSubString(s,0,s.size(),k);
//    }
//    int longSubString(string s,int begin,int end,int k)
//    {
//        if(begin >= end || end-begin < k) return 0;
//        vector<int>characters(26,0);
//        for(int i = begin;i<end;i++)
//        {
//            characters[s[i] - 'a']++;
//        }
//
//        int left=0,right=0,ans = 0;
//        bool flag = true;
//        for(int i=0;i<end;i++)
//        {
//            if(characters[s[i] - 'a'] < k)
//            {
//                flag = false;
//                left = right;
//                right = i;
//                ans = max(ans,longSubString(s,left,right,k));
//            }
//        }
//        ans = right - left+1;
//        if(flag)
//            ans = max(ans,end-begin);
//        return ans;
//    }
//};
//
//int main()
//{
//    string s = "bbaaacbd";
//    cout<<Solution().longestSubstring(s,3)<<endl;
//    return 0;
//}

//leetcode 1464
//class Solution {
//public:
//    int maxProduct(vector<int>& nums) {
//        size_t size = nums.size();
//        sort(nums.begin(),nums.end());
//        return (nums[size-1]-1)*(nums[size-2]-1);
//    }
//};


//leetcode 424
//class Solution {
//public:
//    int characterReplacement(string s, int k) {
//        size_t size = s.size();
//        vector<int>character(26,0);
//        int left = 0,right = 0,maxch = 0;
//        while(right<size)
//        {
//            character[s[right]-'A']++;
//            maxch = max(maxch,character[s[right]-'A']);
//            if(right-left+1-maxch > k)
//            {
//                character[s[left]-'A']--;
//                left++;
//            }
//            right++;
//        }
//        return right-left;
//    }
//};

//leetcode 917
//class Solution {
//public:
//    string reverseOnlyLetters(string s) {
//        int left =0,right = s.size()-1;
//        while(left < right)
//        {
//            if(!isalpha(s[left]))
//            {
//                left++;
//            }
//            if(!isalpha(s[right]))
//            {
//                right--;
//            }
//            if(isalpha(s[left])&&isalpha(s[right]))
//            {
//                swap(s[left],s[right]);
//                left++;
//                right--;
//            }
//        }
//        return s;
//    }
//};

//leetcode 76
//class Solution {
//public:
//    unordered_map<char,int>tString;
//    unordered_map<char,int>subString;
//
//    string minWindow(string s, string t) {
//        if(s.size() < t.size())
//            return string();
//
//        int left=0,right=0;
//        int minStringPostion = 0,minLength = INT_MAX;
//
//        for(auto ch:t)
//        {
//            tString[ch]++;
//        }
//
//        while(right <= s.size())
//        {
//            if(isValid())
//            {
//                if(right - left  < minLength)
//                {
//                    minStringPostion = left;
//                    minLength = right - left;
//                }
//                subString[s[left]]--;
//                left++;
//            }
//            else
//            {
//                subString[s[right]]++;
//                right++;
//            }
//        }
//        if(minLength != INT_MAX)
//            return string(s,minStringPostion,minLength);
//        return string();
//    }
//    bool isValid()
//    {
//        for(auto pair:tString)
//        {
//            if(tString[pair.first] > subString[pair.first])
//                return false;
//        }
//        return true;
//    }
//};
//
//int main()
//{
//    string s = "ADOBECODEBANC";
//    string t = "ABC";
//    cout<<Solution().minWindow(s,t)<<endl;
//    return 0;
//}

//leetcode 704
//class Solution {
//public:
//    int search(vector<int>& nums, int target)
//    {
//        int left = 0,right = nums.size()-1;
//        while(left<=right)
//        {
//            int mid = (left+right)/2;
//            if(nums[mid] == target)
//                return mid;
//            else if(nums[mid] > target)
//                right = mid - 1;
//            else
//                left = mid + 1;
//        }
//        return -1;
//    }
//};

//leetcode 387
//class Solution {
//public:
//    int firstUniqChar(string s) {
//        int hash[26]={0};
//        for(int i=0;i<s.size();i++)
//        {
//            hash[s[i]-97]++;
//        }
//        for(int i=0;i<s.size();i++)
//        {
//            if(hash[s[i]-97]==1)
//                return i;
//        }
//        return -1;
//    }
//};

//leetcode 58
//class Solution {
//public:
//    int lengthOfLastWord(string s) {
//        int p = s.size() - 1;
//        int count = 0;
//        bool flag = false;
//        while(s[p] == ' ')
//            p--;
//        while(p>=0 && s[p] != ' ')
//        {
//            p--;
//            count ++;
//        }
//        return count;
//
//    }
//};


//leetcode 34
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        vector<int>ans(2);
//        int pos = find(nums,target);
//        if(pos == -1)
//        {
//            ans[0] = ans[1] = -1;
//            return ans;
//        }
//        int left = pos,right = pos;
//        while(left>=0 && nums[left]==nums[pos])
//            left--;
//        ans[0] = left + 1;
//        while(right<nums.size() && nums[right]==nums[pos])
//            right++;
//        ans[1] = right - 1;
//        return ans;
//    }
//    int find(vector<int>&nums,int target)
//    {
//        int left = 0,right = nums.size()-1,mid = 0;
//        while(left<=right)
//        {
//            mid = (left + right) / 2;
//            if(nums[mid] > target)
//            {
//                right = mid - 1;
//            }
//            else if(nums[mid] < target)
//            {
//                left = mid + 1;
//            }
//            else
//            {
//                return mid;
//            }
//        }
//        return -1;
//    }
//};

//leetcode 69
//class Solution {
//public:
//    int mySqrt(int x) {
//        if(x == 0 || x == 1)    return x;
//        int left = 0,right = x - 1;
//        long long ans = -1,mid = 0;
//        while(left <= right)
//        {
//            mid = (left + right)/2;
//            if(mid*mid < x)
//            {
//                ans = max(ans,mid);
//                left = mid + 1;
//            }
//            else if(mid*mid > x)
//            {
//                right = mid - 1;
//            }
//            else
//            {
//                return mid;
//            }
//        }
//        return ans;
//    }
//};


//leetcode 680
//class Solution {
//public:
//    bool validPalindrome(string s) {
//        int left = 0,right = s.size()-1;
//
//        while(left <= right)
//        {
//            if(s[left] == s[right])
//            {
//                left++;
//                right--;
//            }
//            else
//            {
//                return isValid(s,left+1,right) || isValid(s,left,right-1);
//            }
//        }
//        return true;
//    }
//    bool isValid(string s,int left,int right)
//    {
//        while(left <= right)
//        {
//            if(s[left] != s[right])
//                return false;
//            else
//            {
//                left++;
//                right--;
//            }
//        }
//        return true;
//    }
//};


//leetcode 47
//class Solution {
//public:
//    vector<vector<int>>ans;
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        backtracking(nums,0);
//        return ans;
//    }
//    void backtracking(vector<int> nums,int pos)
//    {
//        if(pos == nums.size()-1)
//        {
//            ans.push_back(nums);
//            return;
//        }
//
//        set<int>st;
//        for(int i=pos;i<nums.size();i++)
//        {
//            if(st.find(nums[i]) == st.end())
//            {
//                st.insert(nums[i]);
//                swap(nums[i],nums[pos]);
//                backtracking(nums,pos+1);
//                swap(nums[i],nums[pos]);
//            }
//        }
//    }
//};


//leetcode 11
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int left = 0,right = height.size()-1;
//        int MAXAREA = 0;
//        while(left<right)
//        {
//            MAXAREA = max(min(height[left],height[right])*(right-left),MAXAREA);
//            if(height[left]<height[right])
//            {
//                left++;
//            }
//            else
//            {
//                right--;
//            }
//        }
//        return MAXAREA;
//    }
//};


//leetcode 53
//法一:动态规划
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        vector<int>dp(nums.size());
//        dp[0] = nums[0];
//        int index = 1;
//        while(index < nums.size())
//        {
//            dp[index] = max(dp[index-1]+nums[index],nums[index]);
//            index++;
//        }
//        return *max_element(dp.begin(),dp.end());
//    }
//};


//法二:贪心
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int ans = nums[0];
//        int sum = 0;
//        for(auto num:nums)
//        {
//            if(sum > 0)
//                sum += num;
//            else
//                sum = num;
//            ans = max(ans,sum);
//        }
//        return ans;
//    }
//};

//int main()
//{
//    vector<int>nums = {-2,1,-3,4,-1,2,1,-5,4};
//    cout<<Solution().maxSubArray(nums)<<endl;
//    return 0;
//}

//leetcode 238
//class Solution {
//public:
//    vector<int> productExceptSelf(vector<int>& nums) {
//        size_t size = nums.size();
//        vector<int>left(size);
//        vector<int>right(size);
//        vector<int>ans(size);
//        left[0] = right[size-1] = 1;
//        int i=1;
//        while(i<size)
//        {
//            left[i] = left[i-1]*nums[i-1];
//            right[size - 1 - i] = right[size - i]*nums[size-i];
//            i++;
//        }
//        for(int i=0;i<size;i++)
//        {
//            ans[i] = left[i]*right[i];
//        }
//        return ans;
//    }
//};

//leetcode 54
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        int dir = 0;//表示前进方向，0表示向右，1表示向下，2表示向左，3表示向上
//        vector<int>ans;
//        size_t row = matrix.size(),col = matrix[0].size();
//        int i=0,j=0;
//        while(ans.size()<col*row)
//        {
//            if(dir == 0)
//            {
//                //说明未到边界且未遍历
//                if(j<=col-1 && matrix[i][j]!=101)
//                {
//                    ans.push_back(matrix[i][j]);
//                    matrix[i][j] = 101;
//                    j++;
//                }
//                    //否则越界或重复遍历，切换到左下位置，并且改变方向
//                else
//                {
//                    i++;
//                    j--;
//                    dir = 1;
//                }
//            }
//            else if(dir == 1)
//            {
//                if(i<=row-1 && matrix[i][j]!=101)
//                {
//                    ans.push_back(matrix[i][j]);
//                    matrix[i][j] = 101;
//                    i++;
//                }
//                else
//                {
//                    i--;
//                    j--;
//                    dir = 2;
//                }
//            }
//            else if(dir == 2)
//            {
//                if(j>=0&&matrix[i][j]!=101)
//                {
//                    ans.push_back(matrix[i][j]);
//                    matrix[i][j] = 101;
//                    j--;
//                }
//                else
//                {
//                    i--;
//                    j++;
//                    dir = 3;
//                }
//            }
//            else if(dir == 3)
//            {
//                if(i>=0&&matrix[i][j]!=101)
//                {
//                    ans.push_back(matrix[i][j]);
//                    matrix[i][j] = 101;
//                    i--;
//                }
//                else
//                {
//                    i++;
//                    j++;
//                    dir = 0;
//                }
//            }
//        }
//        return ans;
//    }
//};
//
//int main()
//{
//    vector<vector<int>>matrix = {{1,2,3},{4,5,6},{7,8,9}};
//    vector<int>ans = Solution().spiralOrder(matrix);
//
//    for(auto num:ans)
//    {
//        cout << num << " ";
//    }
//}


//leetcode  560
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int preNum = 0,count = 0;
//        unordered_map<int,int>mp;
//        for(auto num:nums)
//        {
//            mp[preNum]++;
//            preNum += num;
//            count += mp[preNum - k];
//        }
//        return count;
//    }
//};
//
//int main()
//{
//    vector<int>nums = {1,1,1};
//    cout<<Solution().subarraySum(nums,2)<<endl;
//
//    return 0;
//}


//leetcode 525
//class Solution {
//public:
//    int findMaxLength(vector<int>& nums) {
//        int pre =0;
//        unordered_map<int,int>mp;
//        int ans = 0;
//        mp[0] = -1;
//        for(int i=0;i<nums.size();i++)
//        {
//            if(nums[i] == 1)
//                pre++;
//            else
//                pre--;
//
//            //记录第一次出现的位置
//            if(mp[pre] == 0)
//            {
//                if((nums[0] == 0&& pre == -1)
//                   ||nums[0] == pre)
//                    ans = i;
//                else
//                    mp[pre] = i;
//            }
//            else
//                ans = max(i-mp[pre],ans);
//        }
//        return ans;
//    }
//};
//
//int main()
//{
//    vector<int>nums = {0,0,1};
//    cout<<Solution().findMaxLength(nums)<<endl;
//    return 0;
//}

//leetcode 150
//class Solution {
//public:
//    int evalRPN(vector<string>& tokens) {
//        map<string,function<int(int,int)>> opFuntions={
//                {"+",[](int x,int y)->auto{return x+y;}},
//                {"-",[](int x,int y)->auto{return x-y;}},
//                {"*",[](int x,int y)->auto{return x*y;}},
//                {"/",[](int x,int y)->auto{return x/y;}}
//        };
//        stack<string>st;
//        int top1,top2;
//        for(string str:tokens)
//        {
//            if(opFuntions[str] != nullptr)
//            {
//                top1= stoi(st.top());
//                st.pop();
//                top2 = stoi(st.top());
//                st.pop();
//                top1 = opFuntions[str](top2,top1);
//                st.push(to_string(top1));
//            }
//            else
//            {
//                st.push(str);
//            }
//        }
//        return stoi(st.top());
//    }
//};


//leetcode 面试0101
//class Solution {
//public:
//    bool isUnique(string astr) {
//        unsigned int hash = 0;
//        for(auto ch:astr)
//        {
//            if((hash & 0x01<<(ch-'a')) == 0)
//                hash |= 0x01<<(ch-'a');
//            else
//                return false;
//        }
//        return true;
//    }
//};


//leetcde 155
//法一:暴力检索
//class MinStack {
//public:
//    MinStack() {
//    }
//
//    void push(int val) {
//        st.push_back(val);
//    }
//
//    void pop() {
//        st.pop_back();
//    }
//
//    int top() {
//        return st[st.size()-1];
//    }
//
//    int getMin() {
//        return *min_element(st.begin(),st.end());
//    }
//private:
//    vector<int>st;
//};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


//法二:最小栈
//class MinStack {
//public:
//    MinStack() {
//
//    }
//
//    void push(int val) {
//        nums.push(val);
//        if(min_nums.empty() || min_nums.top()>=val)
//        {
//            min_nums.push(val);
//        }
//    }
//
//    void pop() {
//        if(min_nums.empty() || min_nums.top() == nums.top())
//            min_nums.pop();
//        nums.pop();
//    }
//
//    int top() {
//        return nums.top();
//    }
//
//    int getMin() {
//        return min_nums.top();
//    }
//private:
//    stack<int>nums;
//    stack<int>min_nums;
//};
//
///**
// * Your MinStack object will be instantiated and called as such:
// * MinStack* obj = new MinStack();
// * obj->push(val);
// * obj->pop();
// * int param_3 = obj->top();
// * int param_4 = obj->getMin();
// */

//leetcode 268

//法一:哈希
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        unordered_map<int,int>mp;
//        for(auto num:nums)
//        {
//            mp[num]++;
//        }
//        for(int i=1;i<=nums.size();i++)
//        {
//            if(mp[i] == 0)
//                return i;
//        }
//        return 0;
//    }
//};

//法二:原地哈希
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        sort(nums.begin(),nums.end());
//        for(int i=0;i<nums.size();i++)
//            if(nums[i] != i)
//                return i;
//        return nums.size();
//    }
//};

//法三:求和相减法
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        size_t size = nums.size();
//        int sum = 0;
//        sum = size*(size+1)/2;
//        for(auto num:nums)
//        {
//            sum -= num;
//        }
//        return sum;
//    }
//};

//法四:亦或
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int num = 0;
//        for(int i=0;i<nums.size();i++)
//        {
//            num ^= (i+1);
//            num ^= nums[i];
//        }
//        return num;
//    }
//};

//leetcode 232
//class MyQueue {
//public:
//    MyQueue() {
//
//    }
//
//    void push(int x) {
//        st1.push(x);
//    }
//
//    int pop()
//    {
//        if(st2.empty())
//        {
//            int tmp = 0;
//            //将st1元素放置st2中
//            while(!st1.empty())
//            {
//                tmp = st1.top();
//                st1.pop();
//                st2.push(tmp);
//            }
//        }
//        int ret = st2.top();
//        st2.pop();
//        return ret;
//    }
//
//    int peek() {
//        if(st2.empty())
//        {
//            int tmp = 0;
//            //将st1元素放置st2中
//            while(!st1.empty())
//            {
//                tmp = st1.top();
//                st1.pop();
//                st2.push(tmp);
//            }
//        }
//        return st2.top();
//    }
//
//    bool empty() {
//        return st1.empty() && st2.empty();
//    }
//    stack<int>st1;
//    stack<int>st2;
//};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//leetcode 面试0805
//class Solution {
//public:
//    int multiply(int A, int B) {
//        int ret = 0;
//        int i = 0;
//        //找到第一位不为0
//        for(;i<32;i++)
//        {
//            if((A<<i)& 0x80000000)
//                break;
//        }
//        for(;i<32;i++)
//        {
//            if((A << i) & 0x80000000)
//            {
//                ret = (ret << 1) + B;
//            }
//            else
//            {
//                ret = (ret << 1);
//            }
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//    cout<<Solution().multiply(37,5)<<endl;
//    return 0;
//}


// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) {
//         vector<vector<int>>ans(n,vector<int>(n,0));
//         int val = 1;
//         int dir = 0;//表示前进方向，0表示向右，1表示向下，2表示向左，3表示向上
//         int i=0,j=0;
//         while(val <= n*n)
//         {
//             if(dir == 0)
//             {
//                 //说明未到边界且未遍历
//                 if(j<=n-1 && ans[i][j]==0)
//                 {
//                     ans[i][j] = val;
//                     val++;
//                     j++;
//                 }
//                 //否则越界或重复遍历，切换到左下位置，并且改变方向
//                 else
//                 {
//                     i++;
//                     j--;
//                     dir = 1;
//                 }
//             }
//             else if(dir == 1)
//             {
//                 if(i<=n-1 && ans[i][j]==0)
//                 {
//                     ans[i][j] = val;
//                     val++;
//                     i++;
//                 }
//                 else
//                 {
//                     i--;
//                     j--;
//                     dir = 2;
//                 }
//             }
//             else if(dir == 2)
//             {
//                 if(j>=0&&ans[i][j]==0)
//                 {
//                     ans[i][j] = val;
//                     val++;
//                     j--;
//                 }
//                 else
//                 {
//                     i--;
//                     j++;
//                     dir = 3;
//                 }
//             }
//             else if(dir == 3)
//             {
//                 if(i>=0&&ans[i][j]==0)
//                 {
//                     ans[i][j] = val;
//                     val++;
//                     i--;
//                 }
//                 else
//                 {
//                     i++;
//                     j++;
//                     dir = 0;
//                 }
//             }
//         }
//
//         return ans;
//     }
// };
//
// int main()
// {
//     vector<vector<int>> ans = Solution().generateMatrix(4);
//     for (int i=0;i<4;i++) {
//         for (int j=0;j<4;j++) {
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


//leetcode 394
//class Solution {
//public:
//    string decodeString(string s)
//    {
//        return backtracking(s, 0, s.size());
//    }
//
//    string backtracking(string s, int begin, int end)
//    {
//        string ret;
//        for (int i = begin; i < end; )
//        {
//            if (isdigit(s[i]))
//            {
//                int time = 0;
//                while (i < end && isdigit(s[i]))
//                {
//                    time = time * 10 + (s[i] - '0');
//                    i++;
//                }
//
//                //查找需要拷贝的子串
//                int subBegin = i + 1;
//                int subEnd = subBegin;
//                int bracketCount = 1;
//                while (subEnd < end && bracketCount > 0)
//                {
//                    if (s[subEnd] == '[')
//                        bracketCount++;
//                    else if (s[subEnd] == ']')
//                        bracketCount--;
//                    subEnd++;
//                }
//
//                string subStr = backtracking(s, subBegin, subEnd - 1);
//                for (int k = 0; k < time; k++)
//                {
//                    ret += subStr;
//                }
//                i = subEnd;
//            }
//            else
//            {
//                ret += s[i];
//                i++;
//            }
//        }
//        return ret;
//    }
//};


//int main()
//{
//    cout << Solution().decodeString("100[leetcode]");
//    return 0;
//}

//leetcode 43

// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         if (num1 == "0" || num2 == "0")
//             return "0";
//         string ret,tmp = "0";
//
//         for (int i = num2.size() - 1; i >= 0; i--)
//         {
//             for (int j = 0; j < (num2[i] - '0'); j++)
//             {
//                 tmp = addStrings(num1, tmp);
//             }
//             ret += tmp[tmp.size() - 1];
//             tmp.pop_back();
//             if (tmp.size() == 0)
//             {
//                 tmp = "0";
//             }
//         }
//         reverse(ret.begin(), ret.end());
//         return tmp + ret;
//     }
//     string addStrings(string num1, string num2) {
//         int k = 0;
//         int p = 0;
//
//         string res;
//         int p1 = num1.size() - 1;
//         int p2 = num2.size() - 1;
//         while (p1 >= 0 || p2 >= 0 || k)
//         {
//             int t = 0;
//             if (p1 >= 0)
//                 t += (num1[p1] - 48);
//             if (p2 >= 0)
//                 t += (num2[p2] - 48);
//             t += k;
//             k = t / 10;
//             t = t % 10;
//
//             res += t + 48;
//             p1--;
//             p2--;
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };
//
// int main()
// {
//     cout << Solution().multiply("6", "501") << endl;
//     return 0;
// }

//leetcode 581
// class Solution {
// public:
//     int findUnsortedSubarray(vector<int> &nums)
//     {
//         vector<int> nums2 = nums;
//         sort(nums2.begin(), nums2.end());
//         int left = 0, right = nums.size() - 1;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] != nums2[i])
//             {
//                 left = i;
//                 break;
//             }
//             if (i == nums.size() - 1)
//                 left = i;
//         }
//         for (int i = nums.size() - 1; i >= 0; i--)
//         {
//             if (nums[i] != nums2[i])
//             {
//                 right = i;
//                 break;
//             }
//         }
//         return left == right ? 0 : right - left + 1;
//     }
// };

//leetcode 59
// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) {
//         vector<vector<int>>ans(n,vector<int>(n,0));
//         int val = 1;
//         int dir = 0;//表示前进方向，0表示向右，1表示向下，2表示向左，3表示向上
//         int i=0,j=0;
//         while(val <= n*n)
//         {
//             if(dir == 0)
//             {
//                 //说明未到边界且未遍历
//                 if(j<=n-1 && ans[i][j]==0)
//                 {
//                     ans[i][j] = val;
//                     val++;
//                     j++;
//                 }
//                 //否则越界或重复遍历，切换到左下位置，并且改变方向
//                 else
//                 {
//                     i++;
//                     j--;
//                     dir = 1;
//                 }
//             }
//             else if(dir == 1)
//             {
//                 if(i<=n-1 && ans[i][j]==0)
//                 {
//                     ans[i][j] = val;
//                     val++;
//                     i++;
//                 }
//                 else
//                 {
//                     i--;
//                     j--;
//                     dir = 2;
//                 }
//             }
//             else if(dir == 2)
//             {
//                 if(j>=0&&ans[i][j]==0)
//                 {
//                     ans[i][j] = val;
//                     val++;
//                     j--;
//                 }
//                 else
//                 {
//                     i--;
//                     j++;
//                     dir = 3;
//                 }
//             }
//             else if(dir == 3)
//             {
//                 if(i>=0&&ans[i][j]==0)
//                 {
//                     ans[i][j] = val;
//                     val++;
//                     i--;
//                 }
//                 else
//                 {
//                     i++;
//                     j++;
//                     dir = 0;
//                 }
//             }
//         }
//
//         return ans;
//     }
// };

//leetcode 104
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root)
//             return max(maxDepth(root->left),maxDepth(root->right)) + 1;
//         return 0;
//     }
// };

//leetcode 3
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         vector<int>last(128,-1);
//         int res = 0,start = 0;
//         for(int i=0;i<s.size();i++)
//         {
//             start = max(start,last[s[i]] + 1);
//             res= max(res,i - start + 1);
//             last[s[i]] = i;
//         }
//         return res;
//     }
// };

//leetcode面试0204
// template<class T>
// class Solution {
// public:
//     ListNode<T>* partition(ListNode<T>* head, int x)
//     {
//         ListNode<T>* largeHead = new ListNode<T>(),* smallHead = new ListNode<T>();
//         ListNode<T>* p = head;
//         while(p)
//         {
//             if(p->val>=x)
//             {
//                 addListNode(largeHead,p);
//             }
//             else
//             {
//                 addListNode(smallHead,p);
//             }
//             p = p->next;
//         }
//         p = smallHead;
//         while(p->next)
//         {
//             p = p->next;
//         }
//         p->next = largeHead->next;
//         return smallHead->next;
//     }
//     void addListNode(ListNode<T>*& head,ListNode<T>* node)
//     {
//         ListNode<T>* p =head;
//         while(p->next)
//         {
//             p = p->next;
//         }
//         p->next = node;
//     }
// };
//
// int main()
// {
//     vector<int>nums = {1,4,3,2,5,2};
//     int x = 3;
// }

//leetcode	108
// class Solution {
// public:
// 	TreeNode<int>* sortedArrayToBST(vector<int>& nums)
// 	{
// 		if(nums.size() == 0)    return nullptr;
// 		return backtraching(nums,0,nums.size()-1);
// 	}
// 	TreeNode<int>* backtraching(vector<int>& nums,int begin,int end)
// 	{
// 		if(begin > end)
// 			return nullptr;
//
// 		int mid = (begin + end)/2;
// 		TreeNode<int>* root = new TreeNode<int>(nums[mid]);
// 		root->left = backtraching(nums,begin,mid-1);
// 		root->right = backtraching(nums,mid+1,end);
// 		return root;
//
// 	}
// };


//leetcode 26
// class Solution
// {
// public:
//     int removeDuplicates(vector<int>& nums)
//     {
//         size_t size = nums.size();
//         if(size == 0 || size == 1)
//             return size;
//         //统计重复出现的数字个数，用于移动数字
//         int numCount = 0;
//         for(int i=1;i<size;i++)
//         {
//             //如果两个数字相同，则将其前移
//             if(nums[i] == nums[i-1])
//             {
//                 numCount++;
//                 nums[i - numCount] = nums[i];
//             }
//         }
//         return size - numCount;
//     }
// };
//
// int main()
// {
//     vector<int>nums = {1,1,2};
//     cout<<"length: "<<Solution().removeDuplicates(nums)<<endl;
// 	for (auto num:nums)
// 	{
// 		cout<<num<<" ";
// 	}
// 	cout<<endl;
//     return 0;
// }


//lletcode  LCR187
//法一:使用队列模拟约瑟夫环(超时)
// class Solution {
// public:
// 	int iceBreakingGame(int num, int target)
// 	{
// 		//使用队列模拟约瑟夫环
// 		queue<int>q;
// 		for(int i=0;i<num;i++)
// 		{
// 			q.emplace(i);
// 		}
//
// 		while(q.size()>1)
// 		{
// 			for(int i = 1;i<target;i++)
// 			{
// 				q.emplace(q.front());
// 				q.pop();
// 			}
// 			q.pop();
// 		}
// 		return q.front();
// 	}
// };


//法二:使用数组模拟约瑟夫环(超时)
// class Solution {
// public:
// 	int iceBreakingGame(int num, int target)
// 	{
// 		vector<int>loop(num);
// 		int cnt = 0;
// 		for(int i=0;i<num;i++)
// 		{
// 			loop[i] = i;
// 		}
// 		int i = 0,k = 1;
// 		while(cnt < num-1)
// 		{
// 			if(i == num)
// 				i = 0;
// 			//如果该位置玩家已经淘汰，跳过
// 			if(loop[i] == -1)
// 			{
// 				i++;
// 			}
// 			else
// 			{
// 				if(k == target)
// 				{
// 					loop[i] = -1;
// 					cnt++;
// 					k = 0;
// 				}
// 				k++;
// 				i++;
// 			}
// 		}
// 		//返回最后赢家
// 		return *max_element(loop.begin(),loop.end());
// 	}
// };


//法三:循环链表模拟约瑟夫环
// class LinkNode
// {
// public:
// 	LinkNode(int num = 0):val(num),next(nullptr),prev(nullptr)
// 	{}
//
// public:
// 	LinkNode* next;
// 	LinkNode* prev;
// 	int val;
// };
//
//
//
// class Solution
// {
// public:
// 	int iceBreakingGame(int num, int target)
// 	{
// 		if(num == 1 || num == 0)
// 			return num;
// 		//创建头节点
// 		LinkNode* head = new LinkNode(0);
// 		LinkNode* p = head;
// 		for(int i = 0;i < num;i++)
// 		{
// 			LinkNode* node = new LinkNode(i);
// 			p->next = node;
// 			node->prev = p;
// 			node->next = head;
// 			head->prev = node;
// 			p = p->next;
// 		}
//
// 		int k = 1;
// 		p = head;
// 		//开始游戏
// 		while(head->next != head)
// 		{
// 			if(k == target)
// 			{
// 				cout<<p->val<<" 号玩家被淘汰"<<endl;
// 				LinkNode* tmp = p;
// 				p->prev ->next = p->next;
// 				p->next ->prev = p->prev;
// 				p = p->next;
// 				delete tmp;
// 				k = 1;
// 			}
// 			else
// 			{
// 				k++;
// 				p = p->next;
// 			}
// 		}
// 		return head->val;
// 	}
// };
//
// int main()
// {
// 	Solution().iceBreakingGame(5,3);
// }

//法四:递归
// class Solution
// {
// public:
// 	int iceBreakingGame(int num, int target)
// 	{
// 		if(num == 1)
// 			return 0;
// 		int x = iceBreakingGame(num - 1,target);
// 		return (x + target)%num;
// 	}
// };

//法五:数学公式法
// class Solution
// {
// public:
// 	int iceBreakingGame(int num, int target)
// 	{
// 		//当只剩下一个玩家，下标为0
// 		int f = 0;
//
// 		for(int i=2;i<=num;i++)
// 		{
// 			f = (f+target)%i;
// 		}
// 		return f;
// 	}
// };


//leetcode 91
// class Solution
// {
// public:
// 	int numDecodings(string s)
// 	{
// 		if(s.size() == 0 || s[0] == '0')
// 		{
// 			return 0;
// 		}
// 		if(s.size() == 1)
// 			return 1;
// 		vector<int>dp(s.size());
// 		if(s[0] >= '1'&&s[0] <= '9') dp[0] = 1;
// 		else dp[0] = 0;
//
// 		if(s[1] >= '1'&&s[1] <= '9')    dp[1]+=1;
// 		if(isvaild(s[0],s[1]))  dp[1] += 1;
//
// 		for(int i=2;i<s.size();i++)
// 		{
// 			if(s[i] >= '1'&&s[i] <= '9')
// 				dp[i] += dp[i-1];
// 			if(isvaild(s[i-1],s[i]))
// 				dp[i] += dp[i-2];
// 		}
// 		return dp.back();
// 	}
//
// 	bool isvaild(char ch1,char ch2)
// 	{
// 		int num = (ch1 - '0')*10 + ch2 - '0';
// 		if(num >= 10&&num <= 26)
// 			return true;
// 		return false;
// 	}
// };


//leetcode 206
// class Solution
// {
// public:
// 	ListNode* reverseList(ListNode* head)
// 	{
// 		//递归:
// 		if(head == nullptr || head->next == nullptr)
// 			return head;
// 		ListNode* newhead = reverseList(head->next);
// 		ListNode* p = newhead;
// 		while(p->next)
// 		{
// 			p = p->next;
// 		}
// 		p->next = head;
// 		head->next = nullptr;
// 		return newhead;
// 	}
// };

//leetcode 113
//法一:dfs
// class Solution
// {
// public:
// 	vector<vector<int>>ans;
// 	vector<vector<int>> pathSum(TreeNode* root, int targetSum)
// 	{
// 		backtracking(root,targetSum,vector<int>(),0);
// 		return ans;
// 	}
// 	void backtracking(TreeNode* root,int targetSum,vector<int>path,int sum)
// 	{
// 		if(root == nullptr)
// 			return;
// 		sum += root->val;
// 		path.push_back(root->val);
// 		if(root->left == nullptr&&root->right == nullptr && sum == targetSum)
// 		{
// 			ans.push_back(path);
// 			return;
// 		}
// 		backtracking(root->left,targetSum,path,sum);
// 		backtracking(root->right,targetSum,path,sum);
// 	}
// };

//dfs
// class Solution
// {
// public:
// 	vector<vector<int>>ans;
// 	vector<int>path;
// 	vector<vector<int>> pathSum(TreeNode* root, int targetSum)
// 	{
// 		backtracking(root,targetSum,0);
// 		return ans;
// 	}
// 	void backtracking(TreeNode* root,int targetSum,int sum)
// 	{
// 		if(root == nullptr)
// 			return;
// 		sum += root->val;
// 		path.emplace_back(root->val);
// 		if(root->left == nullptr&&root->right == nullptr)
// 		{
// 			if(sum == targetSum)
// 			{
// 				ans.emplace_back(path);
// 			}
// 			path.pop_back();
// 			return;
// 		}
// 		backtracking(root->left,targetSum,sum);
// 		backtracking(root->right,targetSum,sum);
// 		path.pop_back();
// 	}
// };


//leetcode 89
// class Solution
// {
// public:
//     vector<int> grayCode(int n)
//     {
//         vector<int>ans(1<<n);
//         for(int i=0;i<ans.size();i++)
//         {
//             ans[i] = i^(i/2);
//         }
//         return ans;
//     }
// };


//leetcode 662
// class Solution
// {
// public:
//     //广度优先
//     int widthOfBinaryTree(TreeNode* root)
//     {
//         //0.返回0或1的情况
//         if(root == nullptr) return 0;
//         if(root->left == nullptr && root->right == nullptr) return 1;
//
//         //1。广度优先，创建两个队列存放节点和节点索引
//         queue<TreeNode*> nodes;
//         queue<unsigned long long> nodeIndex;
//         nodes.push(root);
//         nodeIndex.push(1);
//         unsigned long long ans = 0;
//         while(nodes.size() > 0)
//         {
//             //获取每一层的元素个数
//             size_t size = nodes.size();
//             //存储每一层的初始索引
//             unsigned long long initIndex = nodeIndex.front();
//             unsigned long long index = initIndex;
//
//             for(int i=0;i<size;i++)
//             {
//                 //将头节点出队列
//                 TreeNode* node = nodes.front();
//                 nodes.pop();
//                 index = nodeIndex.front();
//                 nodeIndex.pop();
//                 //如果左右节点不为空，入队列
//                 if(node->left)
//                 {
//                     nodes.push(node->left);
//                     nodeIndex.push(index*2);
//                 }
//                 if(node->right)
//                 {
//                     nodes.push(node->right);
//                     nodeIndex.push(index*2+1);
//                 }
//             }
//             //2.每次遍历完成一层，更新一次最大宽度
//             ans = max<long long>(ans,index-initIndex+1);
//         }
//         return ans;
//     }
// };

//leetcode LCR125
//解题思路，使用两个栈模拟队列 — — — —使用两个栈来模拟两个书车
// class CQueue {
// public:
// 	CQueue()
// 	{}
//
// 	//往st1中插入数据
// 	void appendTail(int value)
// 	{
// 		if(value >= 1&&value <= 10000)
// 		{
// 			st1.push(value);
// 		}
// 	}
//
// 	int deleteHead()
// 	{
// 		//两个书车都是空的，无书可借
// 		if(st1.empty()&&st2.empty())
// 		{
// 			return -1;
// 		}
// 		if(st2.empty())
// 		{
// 			while(!st1.empty())
// 			{
// 				st2.push(st1.top());
// 				st1.pop();
// 			}
// 		}
// 		int ans = st2.top();
// 		st2.pop();
// 		return ans;
// 	}
//
// private:
// 	stack<int>st1;
// 	stack<int>st2;
// };



//leetcode 103
// 法一: 维护两个栈，st1用于存从左到右遍历的节点，st2用于存放从右向左遍历的节点
// st1中节点的子节点按照左孩子->右孩子的顺序插入st2中，st2中节点大的子节点按照右孩子->左孩子的顺序插入st1中
// class Solution
// {
// public:
// 	vector<vector<int>> zigzagLevelOrder(TreeNode* root)
// 	{
// 		if(root == nullptr)
// 			return vector<vector<int>>();
// 		stack<TreeNode*> st1;
// 		stack<TreeNode*> st2;
//
// 		vector<vector<int>>ans;
// 		//将根节点放入st1中
// 		st1.push(root);
// 		//只有st1和st2都为空才退出
// 		while(!(st1.empty()&&st2.empty()))
// 		{
// 			vector<int> tmp;
// 			tmp.clear();
// 			while(!st1.empty())
// 			{
// 				TreeNode* node = st1.top();
// 				st1.pop();
// 				tmp.emplace_back(node->val);
// 				if(node->left != nullptr)
// 					st2.push(node->left);
// 				if(node->right != nullptr)
// 					st2.push(node->right);
// 			}
// 			if(tmp.size() > 0)
// 				ans.push_back(tmp);
// 			tmp.clear();
//
// 			while(!st2.empty())
// 			{
// 				TreeNode* node = st2.top();
// 				st2.pop();
// 				tmp.emplace_back(node->val);
// 				if(node->right != nullptr)
// 					st1.push(node->right);
// 				if(node->left != nullptr)
// 					st1.push(node->left);
// 			}
// 			if(tmp.size() > 0)
// 				ans.push_back(tmp);
// 		}
// 		return ans;
// 	}
// };

//法二:BFS
// 法二:广度优先，遍历每一层的节点
// class Solution
// {
// public:
// 	vector<vector<int>> zigzagLevelOrder(TreeNode* root)
// 	{
// 		vector<vector<int>> ans;
// 		if (root == nullptr) return ans;
//
// 		queue<TreeNode*> nodes;
// 		nodes.push(root);
// 		//记录遍历方向
// 		bool leftToRight = true;
//
// 		while (!nodes.empty())
// 		{
// 			//获取队列中节点的个数
// 			int levelSize = nodes.size();
// 			vector<int> tmpNodes(levelSize);
//
// 			for (int i = 0; i < levelSize; ++i)
// 			{
// 				TreeNode* node = nodes.front();
// 				nodes.pop();
// 				//判断队列方向
// 				int index = leftToRight ? i : levelSize - 1 - i;
// 				tmpNodes[index] = node->val;
//
// 				if (node->left != nullptr)
// 					nodes.push(node->left);
// 				if (node->right != nullptr)
// 					nodes.push(node->right);
// 			}
//
// 			ans.emplace_back(tmpNodes);
// 			//改变方向
// 			leftToRight = !leftToRight;
// 		}
//
// 		return ans;
// 	}
// };