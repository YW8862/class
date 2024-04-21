#include"RBTree.h"
#include<iostream>
using namespace std;

namespace Myset {
	template<class K>
	class set {
	public:
		class keyOfT {
		public:
			const K& operator()(const K& key) {
				return key;
			}
		};

		//迭代器
		typedef typename RBTree<K, const K, keyOfT>::iterator iterator;

		//数据插入
		bool Insert(const K& key) {
			return rbtree.Insert(key);
		}

		//中序遍历
		void InOrder() {
			rbtree.In_Order();
		}

		iterator& begin() {
			return rbtree.begin();
		}

		iterator& end() {
			return rbtree.end();
		}


	private:
		RBTree<K,K, keyOfT> rbtree;
		
	};
}