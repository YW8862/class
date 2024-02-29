#include <iostream>
#include<math.h>
#include<vector>
using namespace std;


////牛客HJ99
//int main() {
//    int n = 0;
//    cin >> n;
//    int res = 2;
//    for (int i = 2; i <= n; i++)
//    {
//        int num = 1;
//        int j = i;
//        while (j /= 10)
//        {
//            num++;
//        }
//        int x = i * i;
//        if ((x - i) % (int)pow(10, num) == 0)
//            res++;
//    }
//    cout << res << endl;
//}
// 64 位输出请用 printf("%lld")


class Solution1 {
public:

    int FirstNotRepeatingChar(string str) {
        // write code here
        int hash[128] = { 0 };
        for (int i = 0; i < str.size(); i++) {
            hash[str[i]]++;
        }
        for (int i = 0; i < str.size(); i++) {
            if (hash[str[i]] == 1)
                return i;
        }
        return -1;

    }
};

//Leetcode 面试题0101
class Solution2{
public:
    bool isUnique(string astr) {
        int hash[123] = { 0 };
        for (auto e : astr)
        {
            hash[e]++;
        }
        for (auto e : astr)
        {
            if (hash[e] > 1)
                return false;
        }
        return true;
    }
};

//Leetcode189
//循环替换
class Solution3 {
public:
    void rotate(vector<int>& nums, int k) {
        int left = 0;
        vector<int>nums1;
        for (int i = 0; i < nums.size(); i++)
        {
            int j = 0;
            j = (i + nums.size() - k);
            while (j < 0)
            {
                j += nums.size();
            }
            j=j% nums.size();
            nums1.push_back(nums[j]);
        }
        nums = nums1;
    }
};

//Leetcode 121
//暴力破解
class Solution4 {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 0;
        int max_profit = 0;
        for (; left < prices.size(); left++)
        {
            for (right = left + 1; right < prices.size(); right++)
            {
                if (prices[right] < prices[left])
                    continue;
                if (prices[right] - prices[left] > max_profit)
                    max_profit = prices[right] - prices[left];
            }
        }
        return max_profit;
    }
};

//Leetcode 121
//动态规划
class Solution5 {
public:
    int maxProfit(vector<int>& prices) {
        int cost = 999999999;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            cost = min(prices[i], cost);
            profit = max(prices[i] - cost, profit);
        }
        return profit;
    }
};


int main()
{
    vector<int>nums = { 1,2,3 };
    Solution3().rotate(nums, 4);
    for (auto e : nums)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}