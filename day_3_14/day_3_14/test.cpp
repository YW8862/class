#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;



//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//
//    int n = 0;
//    cin >> n;
//    vector<int>lel;
//
//    for (int i = 0; i < 3 * n; i++) {
//        int a = 0;
//        cin >> a;
//        lel.push_back(a);
//    }
//    sort(lel.begin(), lel.end());
//    long long res = 0;
//
//    for (int j = n; j < 3 * n; j += 2) {
//        res += lel[j];
//    }
//    cout << res;
//}

//
//class person {
//protected:
//	string name;
//	string gender;
//	int age;
//public:
//	void print() {
//		cout << name << gender << age << endl;
//	}
//};
//
//class stu :public person {
//protected:
//	int _stuid;
//
//};


//#include <iostream>
//#include<cstring>
//using namespace std;

int main() {
    string s1;
    string s2;
	char ch;
	ch = cin.get();
	while (  ch != '\n') {	
		s1 += ch;
		ch = cin.get();
	}

    ch = cin.get();
    while (ch != '\n') {
        s2 += ch;
        ch = cin.get();
    }


    int hash[128] = { 0 };
    for (auto e : s2) {
        hash[e] = 1;
    }
    for (auto e : s1) {
        if (hash[e] == 0)
            cout << e;
    }
    cout << endl;

    return 0;
}