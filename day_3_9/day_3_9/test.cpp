#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        
        int left = 0;
        int right = 0;
        int res = 0;

        for (int i = 0; i < nums.size()-1; i++) {
            right = nums[i + 1] - nums[i];
            if (right == 0)
                continue;
            if (right * left <= 0) {
                res++;
                left = right;
            }
        }
        return res+1;
    }
};
