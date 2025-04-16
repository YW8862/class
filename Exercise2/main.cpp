#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <string.h>
#include <numeric>
#include <map>
#include <unordered_map>
#include <functional>
#include <cassert>
#include <queue>
#include <unordered_set>
using namespace std;

//??????????
template <class T>
class ListNode
{
public:
    T val;
    ListNode *next;

    ListNode() : val(0), next(nullptr)
    {}

    explicit ListNode(T x) : val(x), next(nullptr)
    {}

    ListNode(T x, ListNode *next) : val(x), next(next)
    {}

    ListNode(const ListNode& node) = default;
};


//??????????
template<class T>
class TreeNode {
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(T x): val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(T x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {
    }
};

template<class T>
class Tree {
public:
    TreeNode<T> *root;

    void _preorder(TreeNode<T> *root) {
        if (root == nullptr)return;
        cout << root->val << " ";
        _preorder(root->left);
        _preorder(root->right);
    }

    void _inorder(TreeNode<T> *root) {
        if (root == nullptr)return;
        _inorder(root->left);
        cout << root->val << " ";
        _inorder(root->right);
    }

    void _postorder(TreeNode<T> *root) {
        if (root == nullptr)return;
        _postorder(root->left);
        _postorder(root->right);
        cout << root->val << " ";
    }

    TreeNode<T> *_init(vector<T> list, int pos) {
        if (pos >= list.size() || list[pos] == INT_MIN)
        	return nullptr;
        TreeNode<T> *node = new TreeNode<T>(list[pos]);
        node->left = _init(list, 2 * pos + 1);
        node->right = _init(list, 2 * pos + 2);
        return node;
    }

public:
    Tree(initializer_list<T> list) {
        root = _init(list, 0);
    }


    void preorder() {
        _preorder(root);
    }

    void inorder() {
        _inorder(root);
    }

    void postorder() {
        _postorder(root);
    }
};


//leetcode931
// class Solution
// {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix)
//     {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         //1.确定数组及下标含义
//         //dp[i][j]表示从i,j下坠的最小和
//         //vector<vector<int>> dp(m,vector<int>(n,0));
//         //2.确定递推式
//         //dp[i][j] = max<int>({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]})
//         //3.初始化
//         //初始化第一行即可
//         // for(int i=0;i<n;i++)
//         // {
//         //     dp[0][i] = matrix[0][i];
//         // }
//         //4.遍历
//         for(int i=1;i<m;i++)
//         {
//             for(int j = 0;j<n;j++)
//             {
//                 matrix[i][j] = min<int>({getNum(matrix,i-1,j-1),
//                                     getNum(matrix,i-1,j),
//                                     getNum(matrix,i-1,j+1)})
//                                     + matrix[i][j];
//             }
//         }
//
//         //5.打印数组
//         for(int i=0;i<m;i++)
//         {
//             for(int j = 0;j < n;j++)
//             {
//                 cout<<matrix[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         return *min_element(matrix[m-1].begin(),matrix[m-1].end());
//     }
//     //用户获取上一行的数字
//     int getNum(vector<vector<int>>& matrix,int i,int j)
//     {
//         if(i >= matrix.size() || j>= matrix[0].size())
//         {
//             return INT_MAX;
//         }
//         return matrix[i][j];
//     }
//
// };


//leetcode 51 N皇后
// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n)
//     {
//         vector<vector<char>> martix(n,vector<char>(n,'.'));
//         backtracking(martix,0,n);
//         return ans;
//     }
//
//     //回溯
//     void backtracking(vector<vector<char>> &matrix,int row,int n)
//     {
//         //到达最后一行，检查是否合法，合法的保存返回
//         if(row == n)
//         {
//             return;
//         }
//
//         //没有到达最后一行,从0开始遍历
//         for(int i=0;i<n;i++)
//         {
//             matrix[row][i] = 'Q';
//             if(isCorrect(matrix,row,i,n))
//             {
//                 if(row == n-1)
//                 {
//                     savePath(matrix,n);
//                 }
//                 backtracking(matrix,row+1,n);
//             }
//             //恢复
//             matrix[row][i] = '.';
//         }
//     }
//
//     //检查该位置是否合法
//     bool isCorrect(vector<vector<char>> &martix,int row,int col,int n)
//     {
//         //判断正上方有无皇后
//         for(int i=0;i<row;i++)
//         {
//             if(martix[i][col] == 'Q')
//             {
//                 return false;
//             }
//         }
//
//         //判断左上角有无皇后
//         int preRow = row - 1;;
//         int preCol = col - 1;
//         while(preRow >=0 && preCol >= 0)
//         {
//             if(martix[preRow][preCol] == 'Q')
//             {
//                 return false;
//             }
//             row--;
//             col--;
//         }
//
//         //判断右上角有无皇后
//         preRow = row - 1;
//         preCol = col + 1;
//         while(preRow >= 0&&preCol < n)
//         {
//             if(martix[preRow][preCol] == 'Q')
//             {
//                 return false;
//             }
//             row--;
//             col++;
//         }
//         return true;
//     }
//
//     void savePath(vector<vector<char>> &martix,int n)
//     {
//         vector<string> temp;
//         for(int i=0;i<n;i++)
//         {
//             string s;
//             for(int j=0;j<n;j++)
//             {
//                 s += martix[i][j];
//             }
//             temp.push_back(move(s));
//         }
//         ans.push_back(move(temp));
//     }
//
//     vector<vector<string>> ans;
// };
//
// int main()
// {
//     vector<vector<string>> ans = Solution().solveNQueens(4);
//     for (auto vstrs:ans)
//     {
//         for (auto str:vstrs)
//         {
//             cout << str << endl;
//         }
//         cout << endl;
//     }
//     return 0;
// }


//
// int main()
// {
//
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    //背包问题
    int v = 0,n = 0;
    cin>>v>>n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    //1.确定dp[i][j]的含义
    //i表示背包容量，j表示物体重量
    //dp[i][j]表示在容量为i的时候，并且存在v[0]~v[j]的物品时，最大价值
    vector<vector<int>> dp(v+1,vector<int>(n));

    //2.确定递推式
    //不计入j物品为 dp[i][j-1]
    //计入j物品为 dp[i-1][j-vi]+vj
    //dp[i][j] = max(dp[i][j-1],dp[i-1][j-vi]+vi)
    //3.初始化
    //全部初始化为0即可
    //初始化第一列即可
    for(int i=nums[0];i<=v;i++)
    {
        dp[i][0] = nums[0];
    }

    //4.遍历
    //第一行容量为0，全部为0
    for(int i=1;i<=v;i++)
    {
        for(int j=1;i<n;j++)
        {
            //如果容积小于该物品体积，直接等于不包含的体积
            if(i < nums[j])
            {
                dp[i][j] = dp[i][j-1];
            }
            else
            {
                //dp[i][j]为不包含nums[j]和包含nums[j]的较大者
                dp[i][j] = max(dp[i][j-1],dp[i-nums[j]][j-1]+nums[j]);
            }
        }
    }
    cout<<dp[v][n-1]<<endl;
}

