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

		//������
		typedef typename RBTree<K, const K, keyOfT>::iterator iterator;

		//���ݲ���
		bool Insert(const K& key) {
			return rbtree.Insert(key);
		}

		//�������
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