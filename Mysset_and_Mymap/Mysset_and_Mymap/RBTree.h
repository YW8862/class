#ifndef RBTREE_RBTREE_H
#define RBTREE_RBTREE_H
#include<bits/stdc++.h>
using namespace std;
//颜色枚举变量
enum COL   {
    RED,
    BLACK
};


//红黑树节点
template<class T>
class RBTreeNode{
public:
    T _kv;
    RBTreeNode<T>* _left;
    RBTreeNode<T>* _right;
    RBTreeNode<T>* _parent;
    COL _col;

    RBTreeNode(const T& kv)
            :_kv(kv)
            ,_left(nullptr)
            ,_right(nullptr)
            ,_parent(nullptr)
            ,_col(RED)
    {}

};


//迭代器
template<class T>
struct RBTreeIterator{
    typedef RBTreeNode<T> Node;
    typedef RBTreeIterator<T> Self;

    Node* _node;

    RBTreeIterator(Node* node)
        :_node(node)
    {}

    T& operator*(){
        return _node->_kv;
    }

    T* operator->(){
        return &_node->_kv;
    }

    Self& operator++(){
        if (_node->_right){
            // 右子树的中序第一个(最左节点)
            Node* subLeft = _node->_right;
            while (subLeft->_left){
                subLeft = subLeft->_left;
            }

            _node = subLeft;
        }
        else{
            // 祖先里面孩子是父亲左的那个
            Node* cur = _node;
            Node* parent = cur -> _parent;
            while (parent && cur == parent->_right){
                cur = parent;
                parent = cur->_parent;
            }

            _node = parent;
        }

        return *this;
    }

    Self& operator--(){
        // 
        return *this;
    }

    bool operator!=(const Self& s){
        return _node != s._node;
    }

    bool operator ==(const Self & s){
        return _node == s._node;
    }
};


//红黑树
template<class K,class T,class KeyOfT>
class RBTree{
public:
    typedef RBTreeNode<T> Node;
    typedef RBTreeIterator<T> iterator;
    KeyOfT kot;

    //迭代器
    const iterator& begin()const {
        Node* cur = _root;
        while (cur->_left) {
            cur = cur->_left;
        }
        return iterator(cur);
    }

    iterator& begin() {
        Node* cur = _root;
        while (cur->_left) {
            cur = cur->_left;
        }
        return iterator(cur);
    }

    const iterator& end()const {
        return Node(nullptr);
    }

    iterator& end() {
        return Node(nullptr);
    }

    //插入
    bool Insert(const T& kv){
        if (_root == nullptr){
            _root = new Node(kv);
            _root->_col = BLACK;
            return true;
        }

        Node* parent = nullptr;
        Node* cur = _root;
        while (cur){
            if (kot(cur->_kv) > kot(kv)){
                parent = cur;
                cur = cur->_left;
            }
            else if (kot(cur->_kv) < kot(kv)){
                parent = cur;
                cur = cur->_right;
            }
            else
                return false;
        }

        cur = new Node(kv);
        if (kot(parent->_kv) > kot(kv))
            parent->_left = cur;
        else
            parent->_right = cur;
        cur->_parent = parent;
        while (parent && parent->_col == RED){
            Node* grandfather = parent->_parent;
            //parent在grandfather的左边

            if (grandfather->_left == parent){
                Node* uncle = grandfather->_right;

                //uncle存在且为红色 ： 变色
                if (uncle && uncle->_col == RED)  {
                    parent->_col = uncle->_col = BLACK;
                    grandfather->_col = RED;
                    cur = grandfather;
                    parent = cur->_parent;
                }

                //uncle不存在或uncle存在且为黑  ： 旋转+变色
                else   {
                    //       g
                    //    p     u
                    //  c
                    //右旋g
                    if (cur == parent->_left)  {
                        RotateR(grandfather);
                        parent->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    //左右双旋
                    else   {
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

            //parent在grandfather的右边
            else  {
                Node* uncle = grandfather->_left;
                //uncle存在且为红
                if (uncle && uncle->_col == RED)   {
                    parent->_col = uncle->_col = BLACK;
                    grandfather->_col = RED;
                    cur = grandfather;
                    parent = cur->_parent;
                }

                //uncle不存在或者uncle存在且为黑
                else  {
                    //     g
                    //         p
                    //             c
                    //左旋g
                    if (parent->_right == cur)  {
                        RotateL(grandfather);
                        parent->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    //右左双旋
                    else    {
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

    //左旋
    void RotateL(Node* parent)   {
        Node* cur = parent->_right;
        Node* curleft = cur->_left;
        Node* ppnode = parent->_parent;

        parent->_right = curleft;
        cur->_left = parent;
        if (curleft)
            curleft->_parent = parent;
        parent->_parent = cur;
        if (ppnode == nullptr){
            _root = cur;
            cur->_parent = nullptr;
        }
        else{
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

        if (ppnode == nullptr){
            _root = cur;
            cur->_parent = nullptr;
        }
        else{
            if (ppnode->_left == parent)
                ppnode->_left = cur;
            else
                ppnode->_right = cur;
            cur->_parent = ppnode;
        }
    }

    bool isBlance(){
        return isBlance(_root);   //封装一层，便于调用
    }

    bool isBlance(Node* root){
        if (root == nullptr)   //空树也是红黑树
            return true;

        //检查根节点是否是黑色
        if (_root->_col != BLACK)   {
            cout << "节点不是黑色" << endl;
            return false;
        }
        //统计某一路径上的黑节点数作为基准值
        int benchmark = 0;  //基准值
        Node* cur = _root;

        while (cur){
            if (cur->_col == BLACK)
                benchmark++;
            cur = cur->_left;
        }

        return Chick(root, 0, benchmark);

    }

    bool Chick(Node* root, int blacknum, int benchmark){
        //此时走完一条路径，比较黑节点数是否等于基准值
        if (root == nullptr)     {
            if (blacknum != benchmark)
                return false;
            return true;
        }

        //统计一条路径上的黑节点的个数
        if (root->_col == BLACK)   
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

        if(root == nullptr||kot(root->_kv) == key)
            return root;
        Node* left = find(root->_left,key);
        Node*right = find(root->_right,key);
        return left? left : right;
    }

    void inOrder(Node*root){
        if(root==nullptr)
            return;
        inOrder(root->_left);
        cout<<kot(root->_kv)<<endl;
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
