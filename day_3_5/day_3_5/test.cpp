#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;


//Leetcode2894
class Solution1 {
public:
    int differenceOfSums(int n, int m) {
        int res;
        for (int i = 0; i <= n; i++) {
            if (i % m) {
                res += i;
            }
            else {
                res -= i;
            }
        }
        return res;
    }
};


int main() {
	string s = "andurnvrs";
	string::iterator it = s.begin();
	while (it != s.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	return 0;
}
