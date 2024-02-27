#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//Leetcode 357
//直接保存前n位数不重复个数
class Solution1 {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int>num = { 1,9,81,648,4536,27216,136080,544320,1632960 };
        int res = 0;
        for (int i = 0; i<=n; i++)
        {
            res += num[i];
        }
        return res;
    }
};


//  排列组合计算不重复的个数
class Solution2 {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        int res = 10, tmp = 9;
        for (int i = 0; i < n-1; i++)
        {
            tmp *= 9 - i;
            res += tmp;
        }
        return res;

    }
};

class Solution3 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> res;
        for (auto e : matrix)
            for (auto f : e)
                res.push_back(f);
        sort(res.begin(),res.end());
        return res[k - 1];
    }
};

//Leetcode 88
//先合并再排序
class Solution4 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

//从前往后插入排序
class Solution5 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int>res;
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
            }

            else
            {
                res.push_back(nums2[j]);
                j++;
            }
        }
        for (; i < m; i++)
        {
            res.push_back(nums1[i]);
        }
        for (; j < n; i++)
        {
            res.push_back(nums2[j]);
        }
        nums1 = res;
    }
};

//从后往前插入排序

class Solution6 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        vector<int>::reverse_iterator rit = nums1.rbegin();

        while (i >= 0 && j >= 0)
        {
            if (nums2[j] >= nums1[i])
            {
                *rit = nums2[j];
                j--;
            }
            else
            {
                *rit = nums1[i];
                i--;
            }
            rit++;
        }

        while (rit != nums1.rend())
        {
            if (j >= 0)
            {
                *rit = nums2[j];
                j--;
            }
            else if (i >= 0)
            {
                *rit = nums1[i];
                i--;
            }
            rit++;
        }
    }
};


//Leetcode 27
//创建辅助容器
class Solution7 {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>res;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
                res.push_back(nums[i]);
        }
        nums = res;
        res.resize(nums.size());
        return nums.size();
    }
};

//双指针法（双头指针后移）
class Solution8 {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }
        nums.resize(left);
        return left;
    }
};


//首尾指针
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            }
            else {
                left++;
            }
        }
        return left;
    }
};



//int main()
//{
//    //vector<vector<int>>num = { {2,4,1,45,2},{67,32,879,245,67},{89,35,87,343,768},{12,46,345,546,13},{1,435,12,654,343,23} };
//    //cout << Solution1().countNumbersWithUniqueDigits(2) << endl;
//    //cout << Solution2().countNumbersWithUniqueDigits(2) << endl;
//    //cout << Solution3().kthSmallest(num,4) << endl;
//    vector<int>nums1 = { 1,4,6,8,11,34,56,56,67,0,0,0,0,0,0,0,0 };
//    //vector<int>nums2 = { 1,2,4,5,6,7,8,9};
//    //Solution5().merge(nums1, 9, nums2, 8);
//    //for (auto e : nums1)
//    //{
//    //    cout << e << " ";
//    //}
//    //cout << endl;
//
//    //Solution6().merge(nums1, 9, nums2, 8);
//    //for (auto e : nums1)
//    //{
//    //    cout << e << " ";
//    //}
//    //cout << endl;
//    //cout << Solution7().removeElement(nums1, 0) << endl<<endl;
//    //for (auto e : nums1)
//    //{
//    //    cout << e << " ";
//    //}
//    //cout << endl;
//    vector<int>nums2 = { 0,1,2,2,3,0,4,2 };
//    cout << Solution().removeElement(nums2, 2) << endl << endl;
//    for (auto e : nums2)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

int main()
{
    ////反向迭代器
    //string s = "hello world";
    //string::reverse_iterator rit = s.rbegin();

    //while (rit != s.rend())
    //{
    //    cout << *rit << " ";
    //    (*rit)++;
    //    rit++;
    //}

    //vs2022扩容机制
    string s = "hello world!";
    int sz = s.capacity();
    int i = 10000;
    while (i--)
    {
        s.push_back('c');
        if (sz != s.capacity())
        {
            sz = s.capacity();
            cout << sz << endl;
        }
    }


    return 0;
}