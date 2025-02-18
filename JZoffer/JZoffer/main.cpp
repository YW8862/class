#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;


//JZ3
//class Solution
//{
//public:
//    int duplicate(vector<int>& numbers)
//    {
//        vector<int>nums(numbers.size(), 0);
//        for (auto num : numbers)
//        {
//            if (nums[num]++ > 0)
//                return num;
//        }
//        return -1;
//    }
//};


//JZ5
//class Solution {
//public:
//    string replaceSpace(string s)
//    {
//        size_t pos = 0;
//        while (true)
//        {
//            pos = s.find(' ', pos);
//            if (pos == string::npos)
//                break;
//            s.erase(pos, 1);
//            s.insert(pos, "%20");
//        }
//        return s;
//    }
//};
//
//int main()
//{
//    cout << Solution().replaceSpace("We Are Happy") << endl;
//    return 0;
//}


//JZ6
//class Solution {
//public:
//    vector<int> printListFromTailToHead(ListNode* head) {
//        vector<int>ret;
//        ListNode* p = head;
//        while (p)
//        {
//            ret.push_back(p->val);
//            p = p->next;
//        }
//        reverse(ret.begin(), ret.end());
//        return ret;
//    }
//};


//JZ9
//class Solution
//{
//public:
//    void push(int node) {
//        //直接往stack1中入栈
//        stack1.push(node);
//    }
//
//    int pop() {
//        //1.如果stack2为空，则将stack1中的所有元素移动到stack2中
//        if (stack2.empty())
//        {
//            while (!stack1.empty())
//            {
//                stack2.push(stack1.top());
//                stack1.pop();
//            }
//        }
//        int tmp = stack2.top();
//        stack2.pop();
//        return tmp;
//    }
//
//private:
//    stack<int> stack1;
//    stack<int> stack2;
//};


//JZ10
//class Solution {
//public:
//
//    int Fibonacci(int n)
//    {
//        vector<int>dp(n, 0);
//        dp[0] = dp[1] = 1;
//        for (int i = 2; i < n; i++)
//        {
//            dp[i] = dp[i - 1] + dp[i - 2];
//        }
//        return dp[n - 1];
//    }
//};

//JZ8
//class Solution {
//public:
//    TreeLinkNode* GetNext(TreeLinkNode* pNode)
//    {
//        //0.如果该节点为空，则返回空节点
//        if (pNode == nullptr)
//            return nullptr;
//        //1.如果该节点存在右子树，寻找右子树的最左节点
//        if (pNode->right)
//        {
//            pNode = pNode->right;
//            while (pNode->left)
//            {
//                pNode = pNode->left;
//            }
//            return pNode;
//        }
//        //2.如果该节点无右子树，则判断其为上级节点的左树还是右树
//        while (pNode->next && pNode->next->right == pNode)
//        {
//            pNode = pNode->next;
//        }
//        return pNode->next;
//    }
//};


//JZ30
//class Solution
//{
//public:
//    void push(int value)
//    {
//        nums.push(value);
//        if (min_nums.empty() || min_nums.top() >= value)
//        {
//            min_nums.push(value);
//        }
//    }
//    void pop()
//    {
//        if (nums.top() == min_nums.top())
//        {
//            min_nums.pop();
//        }
//        nums.pop();
//    }
//    int top()
//    {
//        return nums.top();
//    }
//    int min()
//    {
//        return min_nums.top();
//    }
//private:
//    stack<int>nums;
//    stack<int>min_nums;
//};
