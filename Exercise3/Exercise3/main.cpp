#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//int main() {
//    //��������
//    int v = 0, n = 0;
//    cin >> v >> n;
//    vector<int> nums(n);
//    for (int i = 0; i < n; i++)
//    {
//        cin >> nums[i];
//    }
//    //1.ȷ��dp[i][j]�ĺ���
//    //i��ʾ����������j��ʾ��������
//    //dp[i][j]��ʾ������Ϊi��ʱ�򣬲��Ҵ���v[0]~v[j]����Ʒʱ������ֵ
//    vector<vector<int>> dp(v + 1, vector<int>(n));
//
//    //2.ȷ������ʽ
//    //������j��ƷΪ dp[i][j-1]
//    //����j��ƷΪ dp[i-1][j-vi]+vj
//    //dp[i][j] = max(dp[i][j-1],dp[i-1][j-vi]+vi)
//    //3.��ʼ��
//    //ȫ����ʼ��Ϊ0����
//    //��ʼ����һ�м���
//    for (int i = nums[0]; i <= v; i++)
//    {
//        dp[i][0] = nums[0];
//    }
//
//    //4.����
//    //��һ������Ϊ0��ȫ��Ϊ0
//    for (int i = 1; i <= v; i++)
//    {
//        for (int j = 1; j < n; j++)
//        {
//            //����ݻ�С�ڸ���Ʒ�����ֱ�ӵ��ڲ����������
//            if (i < nums[j])
//            {
//                dp[i][j] = dp[i][j - 1];
//            }
//            else
//            {
//                //dp[i][j]Ϊ������nums[j]�Ͱ���nums[j]�Ľϴ���
//                dp[i][j] = max(dp[i][j - 1], dp[i - nums[j]][j - 1] + nums[j]);
//            }
//        }
//    }
//    cout << v-dp[v][n - 1] << endl;
//}

////ʵ��KMP�㷨
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

////�������� dfs
//class Solution {
//public:
//
//    // �����������������ͨ����
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
//            //˵��û�б�����
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
//			//�����
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
//        //��ջ
//        stack<string> st1;
//        //���ڷ�ת����ջ
//        stack<string> st2;
//        for (auto& str : result)
//        {
//            //���Ŀ¼Ϊ�ջ���Ϊ��·��
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


