#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;


////set和multiset的使用
//
//int main() {
//	set<int> s = { 2,1,4,6,3,5,8,9,4,32,6,2 };
//	for(auto e : s) {
//		cout << e << " ";
//	}
//	cout << endl;
//	set<int>::iterator small = s.lower_bound(5);
//	set<int>::iterator big = s.upper_bound(10);
//	s.erase(small, big);
//
//	for (auto e : s) {
//		cout << e << " ";
//	}
//	cout << endl;
//
//	multiset<int> s2 = { 2,1,3,5,6,3,2,5,7,3,4,5,2,4,2,6 };
//	for (auto e : s2) {
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}



//map的使用
//int main() {
//	map<string, int>m;
//	m.insert(pair<string,int>("banana", 1));
//	pair<string, int>ky("apple", 2);
//	m.insert(ky);
//	m.insert({ "pear", 2 });
//	m.insert({ "pear", 3 });
//	map<string, int>::iterator it = m.begin();
//	while (it != m.end()) {
//		cout << (*it).first << ":" << (*it).second << endl;
//		it++;
//	}
//
//	for (auto e : m) {
//		cout << e.first<<":"<<e.second << " ";
//	}
//	cout << endl;
//	return 0;
//}

//multimap的使用
//int main() {
//	multimap<string, string>m;
//	m.insert({ "pear","梨" });
//	m.insert({ "apple","苹果" });
//	m.insert({ "banana","香蕉" });
//	m.insert({ "banana","香蕉" });
//	auto it = m.begin();
//	while (it != m.end()) {
//		cout << it->first << ":" << it->second << endl;
//		it++;
//	}
//	return 0;
//}

//int main() {
//
//	map<string, string>m;
//
//	m.insert({ "pear","梨" });
//	m.insert({ "apple","苹果" });
//	m.insert({ "banana","香蕉" });
//	cout << m["pear"] << endl;
//	return 0;
//}


////Leetcode692
//class Solution {
//public:
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        map<string, int>m;
//        for (auto word : words) {
//            m[word]++;
//        }
//        vector<pair<string, int>>v;
//        for (auto e : m) {
//            v.push_back(e);
//        }
//        sort(v.begin(), v.end(), [&](const pair<string, int>p1, const pair<string, int>p2)->bool {
//            if (p1.second == p2.second)
//                return p1.first < p2.first;
//            return p1.second > p2.second; });
//        vector<string>ret;
//        for (int i = 0; i < k; i++) {
//            ret.push_back(v[i].first);
//        }
//        return ret;
//    }
//};
//
//int main() {
//    vector<string> words = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
//    vector<string>res = Solution().topKFrequent(words, 4);
//    for (auto e : res) {
//        cout << e << endl;
//    }
//    return 0;
//}


////Leetcode692
//class Solution {
//public:
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        map<string, int>m;
//        for (auto word : words) {
//            m[word]++;
//        }
//        vector<string>ret;
//        for (auto word : m) {
//            ret.push_back(word.first);
//        }
//        sort(ret.begin(), ret.end(), [&](const string s1, const string s2)->bool {
//            if (m[s1] == m[s2])
//                return s1 < s2;
//            return m[s1] > m[s2]; });
//        ret.resize(k);
//        return ret;
//    }
//};
//
//
//int main() {
//    vector<string> words = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
//    vector<string>res = Solution().topKFrequent(words, 4);
//    for (auto e : res) {
//        cout << e << endl;
//    }
//    return 0;
//}

//Leetcode349
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ret;
        map<int, int>m;
        for (auto e : nums1) {
            m[e]++;
        }
        set<int>s(nums2.begin(), nums2.end());
        for (auto e : s) {
            if (m[e])
                ret.push_back(e);
        }
        return ret;
    }
};