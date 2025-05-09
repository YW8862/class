#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//int main() {
//    //背包问题
//    int v = 0, n = 0;
//    cin >> v >> n;
//    vector<int> nums(n);
//    for (int i = 0; i < n; i++)
//    {
//        cin >> nums[i];
//    }
//    //1.确定dp[i][j]的含义
//    //i表示背包容量，j表示物体重量
//    //dp[i][j]表示在容量为i的时候，并且存在v[0]~v[j]的物品时，最大价值
//    vector<vector<int>> dp(v + 1, vector<int>(n));
//
//    //2.确定递推式
//    //不计入j物品为 dp[i][j-1]
//    //计入j物品为 dp[i-1][j-vi]+vj
//    //dp[i][j] = max(dp[i][j-1],dp[i-1][j-vi]+vi)
//    //3.初始化
//    //全部初始化为0即可
//    //初始化第一列即可
//    for (int i = nums[0]; i <= v; i++)
//    {
//        dp[i][0] = nums[0];
//    }
//
//    //4.遍历
//    //第一行容量为0，全部为0
//    for (int i = 1; i <= v; i++)
//    {
//        for (int j = 1; j < n; j++)
//        {
//            //如果容积小于该物品体积，直接等于不包含的体积
//            if (i < nums[j])
//            {
//                dp[i][j] = dp[i][j - 1];
//            }
//            else
//            {
//                //dp[i][j]为不包含nums[j]和包含nums[j]的较大者
//                dp[i][j] = max(dp[i][j - 1], dp[i - nums[j]][j - 1] + nums[j]);
//            }
//        }
//    }
//    cout << v-dp[v][n - 1] << endl;
//}

////实现KMP算法
//vector<int> buildNext(string str)
//{
//	vector<int> next(str.size());
//	int prefixLen = 0;
//	int i = 1;
//	while (i < str.size())
//	{
//		if (str[i] == str[next[prefixLen]])
//		{
//			prefixLen++;
//			next[i] = prefixLen;
//			i++;
//		}
//		else
//		{
//			if (prefixLen == 0)
//			{
//				prefixLen = 0;
//				next[i] = 0;
//				i++;
//			}
//			else
//			{
//				prefixLen = next[prefixLen - 1];
//			}
//		}
//	}
//	return next;
//}
//
///**
// * @brief 
// * @param str1 
// * @param str2 
// * @return 
// */
//int kmpSearch(string str1,string str2)
//{
//
//	return 1;
//}
//
//int main()
//{
//	vector<int> next = buildNext("ABACABAB");
//	for (int i = 0; i < next.size(); i++)
//	{
//		cout << next[i] << " ";
//	}
//
//	return 0;
//}

////岛屿问题 dfs
//class Solution {
//public:
//
//    // 深度优先搜索遍历连通区域
//    void dfs(vector<vector<int>>& m, int node,vector<bool> &visited) 
//    {
//        visited[node] = true;
//        for (int i = 0; i < m.size(); i++)
//        {
//            if (m[node][i] == 1 && !visited[i])
//            {
//                dfs(m, i, visited);
//            }
//        }
//    }
//
//    int citys(vector<vector<int>>& m) {
//        int n = m.size();
//        int islandCnt = 0;
//        if (n == 0)
//            return 0;
//        vector<bool> visited(n, false);
//        for (int i = 0; i < n; i++)
//        {
//            //说明没有遍历过
//            if (!visited[i])
//            {
//                islandCnt++;
//                dfs(m, i, visited);
//            }
//        }
//        return islandCnt;
//    }
//};
//
//
//int main()
//{
//    vector<vector<int>> m = { {0,0,1},{0,0,0},{1,0,0} };
//    cout << Solution().citys(m) << endl;
//}

//namespace ns_ptr
//{
//	template<typename T>
//	class shared_ptr
//	{
//	public:
//		shared_ptr() :cnt(nullptr), ptr(nullptr)
//		{
//		}
//
//		shared_ptr(T* _ptr) :cnt(new int(1)), ptr(_ptr)
//		{
//		}
//
//		shared_ptr(const shared_ptr<T>& other) :cnt(other.cnt), ptr(other.ptr)
//		{
//			addCount();
//		}
//
//		~shared_ptr()
//		{
//			showCnt();
//			delCount();
//		}
//
//		void addCount()
//		{
//			++(*cnt);
//		}
//
//		void delCount()
//		{
//			if (--(*cnt) == 0)
//			{
//				delete ptr;
//				delete cnt;
//			}
//		}
//
//		shared_ptr operator=(const shared_ptr<T>& other)
//		{
//			if (other.ptr == ptr)	return *this;
//			//解除绑定
//			delCount();
//			//
//			ptr = other.ptr;
//			cnt = other.cnt;
//			addCount();
//
//			return *this;
//		}
//
//		T& operator *()
//		{
//			return *ptr;
//		}
//
//		T* operator->()
//		{
//			return ptr;
//		}
//
//		void showCnt()
//		{
//			printf("&p:%p  cnt:%d\n", this, *cnt);
//		}
//
//	private:
//		int* cnt;
//		T* ptr;
//	};
//};
//
//
//int main()
//{
//	int *a = new int(1024);
//	ns_ptr::shared_ptr<int> sp1 = a;
//	cout << *sp1 << endl;
//	cout << "---------------------" << endl;
//	ns_ptr::shared_ptr<int> sp2 = sp1;
//	cout << *sp2 << endl;
//	return 0;
//}


//leetcode 71
//class Solution
//{
//public:
//    vector<string> split(const string& str)
//    {
//        if (str.size() == 0)
//            return {};
//        vector<string> result;
//        int begin = 0;
//        int end = str.find("/");
//        while (end != string::npos)
//        {
//            result.push_back(str.substr(begin, end - begin));
//            begin = end + 1;
//            end = str.find("/", begin);
//        }
//        result.push_back(str.substr(begin));
//        return result;
//    }
//
//    string simplifyPath(string path)
//    {
//        vector<string> result = split(path);
//        //正栈
//        stack<string> st1;
//        //用于反转的逆栈
//        stack<string> st2;
//        for (auto& str : result)
//        {
//            //如果目录为空或者为本路径
//            if (str == "" || str == ".")
//                continue;
//            if (str == ".." && !st1.empty())
//                st1.pop();
//            else if (str != "." && str != ".." && str != "")
//            {
//                st1.push(str);
//            }
//        }
//
//        while (!st1.empty())
//        {
//            st2.push(st1.top());
//            st1.pop();
//        }
//
//        string finalPath;
//        while (!st2.empty())
//        {
//            finalPath += "/";
//            finalPath += st2.top();
//            st2.pop();
//        }
//        if (finalPath.size() == 0)
//            finalPath = "/";
//
//        return finalPath;
//    }
//};


