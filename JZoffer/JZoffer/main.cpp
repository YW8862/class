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
//        //ֱ����stack1����ջ
//        stack1.push(node);
//    }
//
//    int pop() {
//        //1.���stack2Ϊ�գ���stack1�е�����Ԫ���ƶ���stack2��
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
//        //0.����ýڵ�Ϊ�գ��򷵻ؿսڵ�
//        if (pNode == nullptr)
//            return nullptr;
//        //1.����ýڵ������������Ѱ��������������ڵ�
//        if (pNode->right)
//        {
//            pNode = pNode->right;
//            while (pNode->left)
//            {
//                pNode = pNode->left;
//            }
//            return pNode;
//        }
//        //2.����ýڵ��������������ж���Ϊ�ϼ��ڵ��������������
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
//            //�������1��ʾδ����������Ϊ�Ѿ�����
//            matrix[i] = vector<int>(cols, 1);
//        }
//
//        backtraching(matrix, threshold, 0, 0, 0, cnt);
//        return cnt;
//    }
//    //x��ʾ��ǰ��x���꣬y��ʾy���꣬dir��ʾ��ȡ�ķ���
//    //0��ʾ�޷������ڴ���0,0����1��ʾ���ң�2��ʾ���£�3��ʾ����4��ʾ����
//    void backtraching(vector<vector<int>>& matrix, int threshole, int x, int y, int dir, int& cnt)
//    {
//        //��ʾ�Ѿ������������ٱ���
//        if (!isValid(x, y, matrix))
//        {
//            return;
//        }
//        //�����������������������Ҽ����ݹ�
//        if (getNum(x) + getNum(y) <= threshole)
//        {
//            cnt++;
//            matrix[y][x] = 0;
//            //������Ǵ��ұ�����������ұ�
//            if (dir != 3)
//                backtraching(matrix, threshole, x + 1, y, 1, cnt);
//            //������Ǵ��±�����������±�
//            if (dir != 4)
//                backtraching(matrix, threshole, x, y + 1, 2, cnt);
//            //�������������ģ���������
//            if (dir != 1)
//                backtraching(matrix, threshole, x - 1, y, 3, cnt);
//            //��������ϱ�����������ϱ�
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


//JZ14 ������
//class Solution
//{
//public:
//    int cutRope(int n)
//    {
//        int maxProduct = 0;
//        for (int i = 2; i < n; i++)
//        {
//            //ƽ��ÿһ�εĳ���
//            int avrPart = n / i;
//            //ʣ�µĳ���
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



//JZ16 ��ֵ�������η�
// ����һ����С�ĳ���
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


//JZ18 ɾ������Ľڵ�
//class Solution
//{
//public:
//    ListNode* deleteNode(ListNode* head, int val)
//    {
//        //���ͷ�ڵ�ΪĿ��ڵ㣬ֱ�ӷ�������һ���ڵ�
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