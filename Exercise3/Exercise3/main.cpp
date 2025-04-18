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



//实现KMP算法
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
//
////int kmpSearch(string str1,string str2)
////{
////	
////}
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




class Solution {
public:

    //判断一个坐标是否合法，即是否越界且在左上角半区
    bool isValid(vector<vector<int> >& m, int x, int y)
    {   
        return y >= x && x >= 0 && x < m.size() && y >= 0 && y < m[0].size();
    }

    //x,y表示当前坐标，dir表示上一步到现在这步的方向
    //0表示无方向，即刚进入地图，1表示向右，2表示向下，3表示向左，4表示向上
    void bfs(vector<vector<int> >& m, int x, int y, int dir)
    {
        //标记位置
        if (m[x][y] == 1)
            m[x][y] = -1;
        else
            return;

        //表示左边合法并且未遍历过
        if (dir != 1 && isValid(m, x, y - 1))
        {
            bfs(m, x, y - 1, 3);
        }

        //表示上面合法并且未遍历过
        if (dir != 2 && isValid(m, x - 1, y))
        {
            bfs(m, x, y - 1, 4);
        }

        //表示右边合法且未遍历过
        if (dir != 3 && isValid(m, x, y + 1))
        {
            bfs(m, x, y + 1, 1);
        }

        //表示下面合法且未遍历过
        if (dir != 4 && isValid(m, x + 1, y))
        {
            bfs(m, x + 1, y, 2);
        }
    }

    int citys(vector<vector<int> >& m) {
        int n = m.size();
        // write code here
        //双向图岛屿问题
        //深度优先
        int islandCnt = 0;
        //广度优先遍历岛屿，将遍历过的位置标记为-1        
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (m[i][j] == 1)
                {
                    islandCnt++;
                    bfs(m, i, j, 0);
                }
            }
        }
        return islandCnt;
    }
};


int main()
{
    vector<vector<int>> m = { {1,1,0},{1,1,0},{0,0,1} };
    cout << Solution().citys(m) << endl;
}