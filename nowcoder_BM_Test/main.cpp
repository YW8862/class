/**
  ******************************************************************************
  * @file           : 牛客面试101刷题代码
  * @author         : YANGWEI
  * @brief          : None
  * @attention      : None
  * @date           :
  ******************************************************************************
  */

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
#include "Date.h"
using  namespace std;
using namespace myClass;
//单链表定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//模板树节点定义
template<class T>
class TreeNode{
public:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(T x):val(x),left(nullptr),right(nullptr){}
    TreeNode(T x,TreeNode*left,TreeNode*right):val(x),left(left),right(right){}
};

template<class T>
class Tree{
public:
    TreeNode<T>*root;
    void _preorder(TreeNode<T> *root){
        if(root==nullptr)return;
        cout<<root->val<<" ";
        _preorder(root->left);
        _preorder(root->right);
    }
    void _inorder(TreeNode<T> *root){
        if(root==nullptr)return;
        _inorder(root->left);
        cout<<root->val<<" ";
        _inorder(root->right);
    }
    void _postorder(TreeNode<T> *root){
        if(root==nullptr)return;
        _postorder(root->left);
        _postorder(root->right);
        cout<<root->val<<" ";
    }
    TreeNode<T>* _init(vector<T> list,int pos){
        if(pos>=list.size()||list[pos]==INT_MIN)return nullptr;
        TreeNode<T> *node = new TreeNode<T>(list[pos]);
        node->left = _init(list,2*pos+1);
        node->right = _init(list,2*pos+2);
        return node;
    }
public:
    Tree(initializer_list<T> list){
        root = _init(list,0);
    }


    void preorder(){
        _preorder(root);
    }

    void inorder(){
        _inorder(root);
    }
    void postorder(){
        _postorder(root);
    }
};

//BM1
//class Solution {
//public:
//    ListNode* ReverseList(ListNode* head) {
//        if(head == nullptr) return head;
//        if(head->next == nullptr)
//            return head;
//        //倒置后面的节点
//        ListNode* newhead = ReverseList(head->next);
//        head -> next = nullptr;
//        ListNode* p = newhead;
//        while(p->next)
//        {
//            p = p->next;
//        }
//        p->next = head;
//        return newhead;
//    }
//};


