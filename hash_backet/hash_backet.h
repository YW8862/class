//
// Created by YANGWEI on 24-4-14.
//

#ifndef HASH_BACKET_HASH_BACKET_H
#define HASH_BACKET_HASH_BACKET_H
#include<bits\stdc++.h>
using namespace std;

template<class K>
class HashFunc{
public:
    size_t operator()(const K&key){
        return (size_t)key;
    }
};

template<>
class HashFunc<string>{
public:
    size_t operator()(const string&s){
       size_t key = 0;
       for(auto e:s){
           key += e;
       }
       return key;
    }
};

template<class K,class V>
struct hashNode{

    hashNode(const pair<K,V>&kv):_kv(kv),_next(nullptr){}
    ~hashNode(){
        delete _next;_next = nullptr; delete _kv;
    }
    hashNode*_next;
    pair<K,V> _kv;
};

template<class K,class V,class Hash = HashFunc<K>>
class hash_backet{
    typedef hashNode<K,V> Node;
public:
    hash_backet(size_t size = 10):_n(0){
        _table.resize(size);
    }

    bool Insert(const pair<K,V>&kv){
        size_t hashpos =hs(kv.first) % _table.size();
        Node* node = new hashNode<K,V>(kv);
        node->_next = _table[hashpos]->_next;
        _table[hashpos] = node;
        _n++;
        return true;
    }

    Node* Find(const pair<K,V>&kv){
        size_t hashpos = hs(kv.first) % _table.size();
        Node* cur = _table[hashpos];
        while(cur->_kv != kv&&cur != nullptr){
            cur = cur->_next;
        }
        return cur;
    }

    bool Erase(const pair<K,V>&kv){
        size_t hashpos = hs(kv.first)%_table.size();
        Node*p =nullptr;
        Node* cur = _table[hashpos];
        //头结点就是需要删除的节点
        if(_table[hashpos]->_kv == kv){
            _table[hashpos] = cur->_next;
            delete cur;
            --_n;
            return true;
        }
        //寻找需要删除的节点
        while(cur->_kv != kv&&cur != nullptr){
            p = cur;
            cur = cur->_next;
        }
        //没有找到，删除失败，返回false
        if(cur==nullptr)
            return false;
        //找到了，并且进行删除
        p->_next = cur->_next;
        delete cur;
        --_n;
        return true;
    }

private:
    size_t _n;
    vector<Node*> _table;
    Hash hs;
};

#endif //HASH_BACKET_HASH_BACKET_H
