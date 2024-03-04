#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

//Leetcode 6

class Solution1 {
public:
    string convert(string s, int numRows) {
        if (numRows < 2)
            return s;
        string res;
        vector<string>strs;
        for (int i = 0; i < numRows; i++) {
            strs.push_back("");
        }

        int i = 0;
        int flag = 0;//0表示正向，q表示反向
        for (auto e : s) {
            strs[i] += e;
            if (flag == 0) {
                if (i == numRows - 1) {
                    flag = 1;
                    i--;
                }
                else {
                    i++;
                }
            }
            else {
                if (i == 0) {
                    flag = 0;
                    i++;
                }
                else {
                    i--;
                }
            }

        }
        for (auto e : strs) {
            res += e;
        }
        return res;
    }
};

//Leetcode217

class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return false;
        sort(nums.begin(), nums.end());
        int slow = 0;
        int fast = 1;
        while (fast < nums.size()) {
            if (nums[fast++] == nums[slow++])
                return true;
        }
        return false;
    }
};

class Solution3 {
public:
    int reverse(int x) {
        int n = 0;
        int res = 0;
        int tmp = 0;
        int flag = 1;

        while (x) {
            if (res > pow(2, 31) / 10 || res < -pow(2, 31) / 10)
                return 0;
            tmp = x % 10;
            x /= 10;
            res = res * 10 + tmp;
        }
        return res * flag;
    }
};


int main()
{

    string s = "AB";
    //cout << Solution1().convert(s, 1) << endl;
    cout << Solution3().reverse(-2147483648) << endl;
	return 0;
}
