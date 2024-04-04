//
// Created by YANGWEI on 2024/4/4.
//

#ifndef RBTREE_RBTREE_H
#define RBTREE_RBTREE_H
#include<bits/stdc++.h>
using namespace std;
enum COL   //颜色枚举变量
{
    RED,
    BLACK
};

template<class K,class V>
class RBTreeNode{
public:
    pair<K, V> _kv;
    RBTreeNode<K, V>* _left;
    RBTreeNode<K, V>* _right;
    RBTreeNode<K, V>* _parent;
    COL _col;

    RBTreeNode(const pair<K,V>& kv)
            :_kv(kv)
            ,_left(nullptr)
            ,_right(nullptr)
            ,_parent(nullptr)
            ,_col(RED)
    {}
    void print(){
        cout<<_kv.first<<":"<<_kv.second<<endl;
    }

};

template<class K,class V>
class RBTree
{
    typedef RBTreeNode<K, V> Node;
public:
    bool Insert(const pair<K, V>& kv)
    {
        if (_root == nullptr)
        {
            _root = new Node(kv);
            _root->_col = BLACK;
            return true;
        }

        Node* parent = nullptr;
        Node* cur = _root;
        while (cur)
        {
            if (cur->_kv.first > kv.first)
            {
                parent = cur;
                cur = cur->_left;
            }
            else if (cur->_kv.first < kv.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else
                return false;
        }

        cur = new Node(kv);
        if (parent->_kv.first > kv.first)
            parent->_left = cur;
        else
            parent->_right = cur;
        cur->_parent = parent;
        while (parent && parent->_col == RED)
        {
            Node* grandfather = parent->_parent;
            if (grandfather->_left == parent)   //parent在grandfather的左边
            {
                Node* uncle = grandfather->_right;
                if (uncle && uncle->_col == RED)   //uncle存在且为红色 ： 变色
                {
                    parent->_col = uncle->_col = BLACK;
                    grandfather->_col = RED;
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else   //uncle不存在或uncle存在且为黑  ： 旋转+变色
                {
                    //       g
                    //    p     u
                    //  c
                    if (cur == parent->_left)  //右旋g
                    {
                        RotateR(grandfather);
                        parent->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    else   //左右双旋
                    {
                        //      g
                        //  p        u
                        //     c
                        RotateL(parent);    //左旋p
                        RotateR(grandfather);   //右旋g
                        cur->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    break;
                }
            }
            else     //parent在grandfather的右边
            {
                Node* uncle = grandfather->_left;
                if (uncle && uncle->_col == RED)   //uncle存在且为红
                {
                    parent->_col = uncle->_col = BLACK;
                    grandfather->_col = RED;
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else      //uncle不存在或者uncle存在且为黑
                {
                    //     g
                    //         p
                    //             c
                    if (parent->_right == cur)  //左旋g
                    {
                        RotateL(grandfather);
                        parent->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    else    //右左双旋
                    {
                        //     g
                        //          p
                        //      c
                        RotateR(parent);    //右旋p
                        RotateL(grandfather);   //左旋g
                        grandfather->_col = RED;
                        cur->_col = BLACK;
                    }
                    break;
                }
            }
        }

        _root->_col = BLACK;
        return true;
    }

    void RotateL(Node* parent)   //左旋
    {
        Node* cur = parent->_right;
        Node* curleft = cur->_left;
        Node* ppnode = parent->_parent;

        parent->_right = curleft;
        cur->_left = parent;
        if (curleft)
            curleft->_parent = parent;
        parent->_parent = cur;
        if (ppnode == nullptr)
        {
            _root = cur;
            cur->_parent = nullptr;
        }
        else
        {
            if (ppnode->_left == parent)
                ppnode->_left = cur;
            else
                ppnode->_right = cur;
            cur->_parent = ppnode;
        }
    }

    void RotateR(Node* parent)    //右旋
    {
        Node* cur = parent->_left;
        Node* curright = cur->_right;
        Node* ppnode = parent->_parent;

        parent->_left = curright;
        cur->_right = parent;
        if (curright)
            curright->_parent = parent;
        parent->_parent = cur;
        if (ppnode == nullptr)
        {
            _root = cur;
            cur->_parent = nullptr;
        }
        else
        {
            if (ppnode->_left == parent)
                ppnode->_left = cur;
            else
                ppnode->_right = cur;
            cur->_parent = ppnode;
        }
    }

    bool isBlance()
    {
        return isBlance(_root);   //封装一层，便于调用
    }

    bool isBlance(Node* root)
    {
        if (root == nullptr)   //空树也是红黑树
            return true;

        if (_root->_col != BLACK)   //检查根节点是否是黑色
        {
            cout << "根节点不是黑色" << endl;
            return false;
        }
        //统计某一路径上的黑节点数作为基准值
        int benchmark = 0;  //基准值
        Node* cur = _root;
        while (cur)
        {
            if (cur->_col == BLACK)
                benchmark++;
            cur = cur->_left;
        }

        return Chick(root, 0, benchmark);

    }

    bool Chick(Node* root, int blacknum, int benchmark)
    {
        if (root == nullptr)     //此时走完一条路径，比较黑节点数是否等于基准值
        {
            if (blacknum != benchmark)
                return false;
            return true;
        }
        if (root->_col == BLACK)   //统计一条路径上的黑节点的个数
            blacknum++;
        return Chick(root->_left, blacknum, benchmark)&& Chick(root->_right, blacknum, benchmark);   //递归它的左树和右树
    }
    //查找key的节点
    Node*Find(K key){
        return find(_root,key);
    }

    //中序遍历
    void In_Order(){
        inOrder(_root);
    }

    // 获取红黑树最左侧节点
    Node* LeftMost(){
        getLeft(_root);
    }

    // 获取红黑树最右侧节点
    Node* RightMost(){
        return getRight(_root);
    }

private:
    Node* _root = nullptr;

    Node*find(Node* root,K key){

        if(root == nullptr||root->_kv.first == key)
            return root;
        Node* left = find(root->_left,key);
        Node*right = find(root->_right,key);
        return left? left : right;
    }

    void inOrder(Node*root){
        if(root==nullptr)
            return;
        inOrder(root->_left);
        cout<<root->_kv.first<<":"<<root->_kv.second<<endl;
        inOrder(root->_right);
    }

    Node* getLeft(Node*root){
        if(root==nullptr||root->_left==nullptr)
            return root;
        return getLeft(root->_left);
    }

    Node* getRight(Node*root){
        if(root==nullptr||root->_right==nullptr)
            return root;
        return getRight(root->_right);
    }

};
#endif //RBTREE_RBTREE_H
