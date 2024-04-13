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
	pair<K, V> _data;
	State _state;
};

template<class K>
class HashFunc{
public:
    size_t operator()(const K&key){
        return (size_t)key;
    }
};

class HashFuncString{
public:
    size_t operator()(const string&s){
        size_t cnt = 0;
        for(auto e:s){
            cnt += e;
        }
        return cnt;
    }
};

template<class K,class V,class Hash = HashFunc<K>>
class hashTable {
public:
    typedef HashData<K,V> hashData;

    hashTable(size_t size = 10 ):_n(0){
        _table.resize(size);
    }

    bool Insert(const pair<K,V>&kv){
        //如果哈希表的哈希因子超过0.7,进行扩容

        if((double)_n/(double)_table.size() >0.7) {
            //1.直接扩容法
//            vector<pair<K,V>> newtable (2 * _table.size());
//            for(auto e:_table){
//                size_t hashpos = e.first % newtable.size();
//                while(newtable[hashpos]._state == EXIST){
//                    ++hashpos;
//                    hashpos %= newtable.size();
//                }
//                _table.swap(newtable);
//            }

        //2.利用构造函数插入(现代写法)
            size_t newsize = 2*_table.size();
            hashTable<K,V,Hash> newtable(newsize);
            for(auto e:_table){
                if(e._state == EXIST)
                    newtable.Insert(e._data);
            }
            _table.swap(newtable._table);
        }

        size_t hashpos = hs(kv.first) % _table.size();
        while(_table[hashpos]._state == EXIST){
            ++hashpos;
            hashpos %= _table.size();
        }
        _table[hashpos]._data = kv;
        _table[hashpos]._state = EXIST;
        ++ _n;
        return true;
    }

    hashData* find(const K&key){
        size_t hashpos = hs(key) % _table.size();
        while(_table[hashpos]._state != EMPTY){
            if(key == _table[hashpos]._data.first
            &&_table[hashpos]._state != DELETE)
                return &_table[hashpos];
            else
                ++ hashpos;
        }
    }

    bool Erase(const K&key){
        if(hashData* pos = this->find(key)){
            _n--;
            pos->_state = DELETE;
            return true;
        }
        else{
            return false;
        }
    }

private:
	vector<HashData<K,V>> _table;
    size_t _n;
    Hash hs;
};