#include"RBTree.h"
#include<iostream>
using namespace std;

namespace Mymap {
	template<class K, class V>
	class map {
	public:
		class keyOfT {
		public:
			const K& operator()(const pair<K, V>& _pair){
				return _pair.first;
			}
		};

		//������
		typedef typename RBTree<K, const pair<K, V>, keyOfT>::iterator iterator;

		//���ݲ���
		bool Insert(const pair<K, V>& _pair) {
			return rbtree.Insert(_pair);
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
		RBTree<K, pair<K, V>,keyOfT> rbtree;

	};
	
}