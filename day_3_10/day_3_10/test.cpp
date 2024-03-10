#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

//Leetcode 1137
class Solution1 {
public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n < 3)
            return 1;
        int t0 = 0;
        int t1 = 1;
        int t2 = 1;

        for (int i = 3; i <= n; i++) {
            int tmp = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = tmp;
        }
        return t2;
    }
};


//¶¯Ì¬¹æ»®
class Solution {
public:
    int tribonacci(int n) {
        vector<int>t = { 0,1,1 };
        for (int i = 3; i <= n; i++) {
            t.push_back(t[i - 1] + t[i - 2] + t[i - 3]);
        }
        return t[n];
    }
};

    

//Leetcode509
class Solution2 {
public:
    int fib(int n) {
        if (n == 0)return 0;
        if (n < 3)return 1;
        int t0 = 1;
        int t1 = 1;
        for (int i = 3; i <= n; i++) {
            int tmp = t0 + t1;
            t0 = t1;
            t1 = tmp;
        }
        return t1;
    }
};

//Leetcode 70
class Solution3 {
public:
    int climbStairs(int n) {
        if (n <= 3)return n;
        int t1 = 1;
        int t2 = 2;
        for (int i = 3; i <= n; i++) {
            int tmp = t1 + t2;
            t1 = t2;
            t2 = tmp;
        }
        return t2;
    }
};




int main() {
	return 0;
}