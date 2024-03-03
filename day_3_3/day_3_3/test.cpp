#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;


//Leetcode 860

class Solution1 {
public:
    bool lemonadeChange(vector<int>& bills) {
        int x = 0;
        int y = 0;
        for (auto e : bills) {
            if (e == 5) {
                x++;
            }
            else if (e == 10) {
                if (x > 0) {
                    x--;
                    y++;
                }

                else
                    return false;
            }
            else {
                if (x > 0 && y > 0) {
                    x--;
                    y--;
                }
                else if (x >= 3) {
                    x -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};

//Leetcode 2208

class Solution2 {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>heap;
        double sum = 0.0;
        for (auto e : nums) {
            heap.push(e);
            sum += e;
        }
        sum /= 2.0;
        int count = 0;
        while (sum > 0) {
            double t = heap.top() / 2.0;
            heap.pop();
            sum -= t;
            count++;
            heap.push(t);
        }
        return count;
    }
};

class Solution4 {
public:

    string largestNumber(vector<int>& nums) {
        vector<string>strs;
        for (int x : nums) {
            strs.push_back(to_string(x));
        }
        sort(strs.begin(), strs.end(), [](const string& s1, const string& s2) {
            return s1 + s2 > s2 + s1;
            });

        string res;
        for (auto& e : strs) {
            res += e;
        }
        if (res[0] == '0')
            return "0";
        return res;
    }
};

int main()
{
    vector<int>bills = { 3,30,34,5,9 };
    //cout<<Solution1().lemonadeChange(bills) << endl;
    cout << Solution4().largestNumber(bills) << endl;
    return 0;
}