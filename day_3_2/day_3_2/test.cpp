#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
#include<vector>
using namespace std;
// string::find_first_of
#include <iostream>       // std::cout
#include <string>         // std::string
#include <cstddef>        // std::size_t
//
//int main()
//{
//    std::string str("Please, replace the vowels in this sentence by asterisks.");
//    std::size_t found = str.find_first_of("aeiou");
//    while (found != std::string::npos)
//    {
//        str[found] = '*';
//        found = str.find_first_of("aeiou", found + 1);
//    }
//
//    std::cout << str << '\n';
//
//    return 0;
//}

//Leetcode LCR192
class Solution1 {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int index = 0, n = str.size(), sign = 1, res = 0;
        // 处理前置空格
        while (index < n && str[index] == ' ') {
            ++index;
        }
        // 处理符号
        if (index < n && (str[index] == '+' || str[index] == '-')) {
            sign = str[index++] == '+' ? 1 : -1;
        }
        // 处理数字
        while (index < n && isdigit(str[index])) {
            int digit = str[index] - '0';
            // 判断是否溢出
            if (res > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + digit;
            ++index;
        }
        return res * sign;
    }
};

//Leetcode 125
//双指针
class Solution2 {
public:
    bool isPalindrome(string s) {
        if (s.size() == 1)
            return true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 65 && s[i] <= 90)
                s[i] += 32;
        }

        int left = 0;
        int right = s.size() - 1;
        while (left <= right)
        {
            while (!isalnum(s[left]) && left <= right)
                left++;
            while (!isalnum(s[right]) && left <= right)
                right--;
            if (!isalnum(s[left]) || !isalnum(s[right]))
                return true;
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else
                return false;
        }
        return true;
    }
};


//Leetcode 415

class Solution3 {
public:
    string addStrings(string num1, string num2) {
        int k = 0;
        int p = 0;

        string res;
        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;
        while (p1 >= 0 || p2 >= 0 || k)
        {
            int t = 0;
            if (p1 >= 0)
                t += (num1[p1] - 48);
            if (p2 >= 0)
                t += (num2[p2] - 48);
            t += k;
            k = t / 10;
            t = t % 10;

            res += t + 48;
            p1--;
            p2--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


//Leetcode LCR 192
//
class Solution4 {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;
        int index = 0, n = str.size(), sign = 1, res = 0;
        // 处理前置空格
        while (index < n && str[index] == ' ') {
            ++index;
        }

        // 处理符号
        if (index < n && (str[index] == '+' || str[index] == '-')) {
            sign = str[index++] == '+' ? 1 : -1;
        }

        // 处理数字
        while (index < n && isdigit(str[index])) {
            int digit = str[index] - '0';
            // 判断是否溢出
            if (res > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + digit;
            ++index;
        }
        return res * sign;
    }
};


//Leetcode 344
class Solution5 {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

//Leetcode 377
class Solution6 {
public:
    int firstUniqChar(string s) {
        int hash[26] = { 0 };
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 97]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i] - 97] == 1)
                return i;
        }
        return -1;
    }
};

//Leetcode 125
//
class Solution7 {
public:
    bool isPalindrome(string s) {
        if (s.size() == 1)
            return true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 65 && s[i] <= 90)
                s[i] += 32;
        }
        int left = 0;
        int right = s.size() - 1;
        while (left <= right)
        {
            while (!isalnum(s[left]) && left <= right)
                left++;
            while (!isalnum(s[right]) && left <= right)
                right--;
            if (!isalnum(s[left]) || !isalnum(s[right]))
                return true;
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else
                return false;
        }
        return true;
    }
};

//int main(int argc, char* argv[])
//
//{
//
//	string strText = "How are you?";
//
//	string strSeparator = " ";
//
//	string strResult;
//
//	int size_pos = 0;
//
//	int size_prev_pos = 0;
//
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos){
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//		size_prev_pos = ++size_pos;
//	}
//
//	if (size_prev_pos != strText.size()){
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//	}
//	cout << endl;
//	return 0;
//
//}




//Leetcode 110
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution8 {
public:
    bool isBalanced(TreeNode* root) {
        return get_height(root) != -1;
    }
    int get_height(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int left = get_height(root->left);
        if (left == -1)
            return -1;
        int right = get_height(root->right);
        if (right == -1)
            return -1;
        return abs(left - right) < 2 ? max(left, right) + 1 : -1;

    }
};

class Solution9 {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int hleft = get_height(root->left);
        int hright = get_height(root->right);
        return abs(hleft - hright) < 2
            && isBalanced(root->left)
            && isBalanced(root->right);
    }
    int get_height(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        return max(get_height(root->left), get_height(root->right)) + 1;

    }
};


//Leetcode 101
class Solution10 {
public:
    bool isSymmetric(TreeNode* root) {
        return fun(root, root);
    }
    bool fun(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2)
            return false;
        return fun(root1->left, root2->right)
            && fun(root1->right, root2->left)
            && root1->val == root2->val;
    }
};




int main()
{
	//string s = "-91283472332";
	//cout<<Solution().myAtoi(s) << endl;;

    //string s = "A man, a plan, a canal: Panama";
    //cout<<Solution2().isPalindrome(s) << endl;


	return 0;
}