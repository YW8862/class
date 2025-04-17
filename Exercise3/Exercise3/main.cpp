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

vector<int> buildNext(string str)
{
	vector<int> next(str.size());
	int prefixLen = 0;
	int i = 1;
	while (i < str.size())
	{
		if (str[i] == str[next[prefixLen]])
		{
			prefixLen++;
			next[i] = prefixLen;
			i++;
		}
		else
		{
			if (prefixLen == 0)
			{
				prefixLen = 0;
				next[i] = 0;
				i++;
			}
			else
			{
				prefixLen = next[prefixLen - 1];
			}
		}
	}
	return next;
}


//int kmpSearch(string str1,string str2)
//{
//	
//}

int main()
{
	vector<int> next = buildNext("ABACABAB");
	for (int i = 0; i < next.size(); i++)
	{
		cout << next[i] << " ";
	}

	return 0;
}