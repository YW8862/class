#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

template<typename T1, typename T2>
T1 mymax(T1 x,T2 y)
{
    return x > y ? x : y;
}


//Leetcode LCR133
class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        int i = 0;
        int num = 0;
        while (i < 32)
        {
            if ((n >> i) & 1)
                num++;
            i++;
        }
        return num;
    }
};

//Leetcode LCR 70
class Solution2 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            res = res ^ nums[i];
        }
        return res;
    }
};


//Leetcode 2171
// 
// 暴力破解 
class Solution3 {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long res = 99999999;

        int max_num = beans[0];

        for (auto e : beans)
        {
            if (e > max_num)
                max_num = e;
        }

        for (int i = 0; i <= max_num; i++)
        {
            int p = 0;
            for (auto e : beans)
            {
                if (e > i)
                    p += (e - i);
                else if (e < i)
                    p += e;
            }
            if (p < res)
                res = p;
        }
        return res;
    }
};

// 暴力破解
class Solution4 {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long res = 999999999999;
        
        for (auto e : beans)
        {
            long long tmp = 0;
            for (auto p : beans)
            {
                if (p > e)
                    tmp += p - e;
                else if (p < e)
                    tmp += p;
            }
            if (tmp < res)
                res = tmp;
        }
        return res;
    }
};

//矩阵求和
class Solution5 {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long sum = 0;
        long long max_num = 0;
        sort(beans.begin(), beans.end());

        for (auto e : beans)
        {
            sum += e;
        }

        int len = beans.size();
        for (long long i = 0; i < len; i++)
        {
            max_num = mymax<long long, long long>(max_num, beans[i] * (len - i));
        }
        return sum - max_num;
    }
};

//Leetcode 2120
class Solution6 {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int>res;
        for (int i = 0; i < s.size(); i++)
        {
            int x = startPos[0];
            int y = startPos[1];
            int option = 0;
            for (int j = i; j < s.size(); j++)
            {
                switch (s[j])
                {
                case 'U':
                    x--;
                    break;
                case 'D':
                    x++;
                    break;
                case 'L':
                    y--;
                    break;
                case 'R':
                    y++;
                    break;
                default:
                    break;
                }
                if (x >= 0 && x < n && y >= 0 && y < n)
                    option++;
                else
                    break;
            }
            res.push_back(option);
        }
        return res;
    }
};

int main()
{
    vector<int>num = { 2,10,3,2 };
    //cout << Solution3().minimumRemoval(num)<<endl;
    //cout << Solution5().minimumRemoval(num) << endl;
    vector<int>pos = { 0,1 };

    string s = "RRDDLU";
    vector<int>res = Solution6().executeInstructions(3, pos, s);
    for (auto e : res)
    {
        cout << e << " ";
    }
}
