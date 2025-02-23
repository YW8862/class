#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <limits>
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


//JZ13
//class Solution
//{
//public:
//    int movingCount(int threshold, int rows, int cols)
//    {
//        vector<vector<int>> matrix(rows);
//        int cnt = 0;
//        for (int i = 0; i < rows; i++)
//        {
//            //矩阵填充1表示未遍历，否则为已经遍历
//            matrix[i] = vector<int>(cols, 1);
//        }
//
//        backtraching(matrix, threshold, 0, 0, 0, cnt);
//        return cnt;
//    }
//    //x表示当前的x坐标，y表示y坐标，dir表示调取的方向
//    //0表示无方向，用于处理（0,0），1表示向右，2表示向下，3表示向左，4表示向上
//    void backtraching(vector<vector<int>>& matrix, int threshole, int x, int y, int dir, int& cnt)
//    {
//        //表示已经遍历过，不再遍历
//        if (!isValid(x, y, matrix))
//        {
//            return;
//        }
//        //如果符合条件，则计数，并且继续递归
//        if (getNum(x) + getNum(y) <= threshole)
//        {
//            cnt++;
//            matrix[y][x] = 0;
//            //如果不是从右边来，则遍历右边
//            if (dir != 3)
//                backtraching(matrix, threshole, x + 1, y, 1, cnt);
//            //如果不是从下边来，则遍历下边
//            if (dir != 4)
//                backtraching(matrix, threshole, x, y + 1, 2, cnt);
//            //如果不从左边来的，则遍历左边
//            if (dir != 1)
//                backtraching(matrix, threshole, x - 1, y, 3, cnt);
//            //如果不从上边来，则遍历上边
//            if (dir != 2)
//                backtraching(matrix, threshole, x, y - 1, 4, cnt);
//        }
//    }
//private:
//    int getNum(int num)
//    {
//        int sum = 0;
//        while (num)
//        {
//            sum += num % 10;
//            num /= 10;
//        }
//        return sum;
//    }
//
//    bool isValid(int x, int y, const vector<vector<int>>& matrix)
//    {
//        if (x >= matrix[0].size() || x < 0 || y >= matrix.size() || y < 0 || matrix[y][x] == 0)
//            return false;
//        return true;
//    }
//};
//
//
//int main()
//{
//    cout << Solution().movingCount(1, 2, 3) << endl;
//    return 0;
//}


//JZ14 剪绳子
//class Solution
//{
//public:
//    int cutRope(int n)
//    {
//        int maxProduct = 0;
//        for (int i = 2; i < n; i++)
//        {
//            //平均每一段的长度
//            int avrPart = n / i;
//            //剩下的长度
//            int left = n % i;
//            int tmp = 1;
//            for (int j = 0; j < i; j++)
//            {
//                if (j < left)
//                    tmp *= avrPart + 1;
//                else
//                    tmp *= avrPart;
//            }
//            maxProduct = max(maxProduct, tmp);
//        }
//        return maxProduct;
//    }
//};



//JZ16 数值的整数次方
// 定义一个极小的常量
//const double EPSILON = 1e-9;
//
//bool isZero(double num) {
//    return std::fabs(num) < EPSILON;
//}
//
//
//class Solution
//{
//public:
//    double Power(double base, int exponent)
//    {
//        if (fabs(base) < 1e-15)
//            return 0;
//        if (exponent == 0)
//            return 1;
//
//        int absExponent = abs(exponent);
//        double result = 1.0;
//        for (int i = 0; i < absExponent; i++)
//        {
//            result *= base;
//        }
//
//        if (exponent < 0)
//            result = 1.0 / result;
//        return result;
//    }
//};


//JZ18 删除链表的节点
//class Solution
//{
//public:
//    ListNode* deleteNode(ListNode* head, int val)
//    {
//        //如果头节点为目标节点，直接返回其下一个节点
//        if (head->val == val)
//            return head->next;
//
//        ListNode* preNode = head;
//        ListNode* pNode = head->next;
//        while (pNode->next)
//        {
//            if (pNode->val == val)
//            {
//                preNode->next = pNode->next;
//                break;
//            }
//            preNode = pNode;
//            pNode = pNode->next;
//        }
//        return head;
//    }
//};