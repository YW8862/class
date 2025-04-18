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



//ʵ��KMP�㷨
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

    //�ж�һ�������Ƿ�Ϸ������Ƿ�Խ���������Ͻǰ���
    bool isValid(vector<vector<int> >& m, int x, int y)
    {   
        return y >= x && x >= 0 && x < m.size() && y >= 0 && y < m[0].size();
    }

    //x,y��ʾ��ǰ���꣬dir��ʾ��һ���������ⲽ�ķ���
    //0��ʾ�޷��򣬼��ս����ͼ��1��ʾ���ң�2��ʾ���£�3��ʾ����4��ʾ����
    void bfs(vector<vector<int> >& m, int x, int y, int dir)
    {
        //���λ��
        if (m[x][y] == 1)
            m[x][y] = -1;
        else
            return;

        //��ʾ��ߺϷ�����δ������
        if (dir != 1 && isValid(m, x, y - 1))
        {
            bfs(m, x, y - 1, 3);
        }

        //��ʾ����Ϸ�����δ������
        if (dir != 2 && isValid(m, x - 1, y))
        {
            bfs(m, x, y - 1, 4);
        }

        //��ʾ�ұߺϷ���δ������
        if (dir != 3 && isValid(m, x, y + 1))
        {
            bfs(m, x, y + 1, 1);
        }

        //��ʾ����Ϸ���δ������
        if (dir != 4 && isValid(m, x + 1, y))
        {
            bfs(m, x + 1, y, 2);
        }
    }

    int citys(vector<vector<int> >& m) {
        int n = m.size();
        // write code here
        //˫��ͼ��������
        //�������
        int islandCnt = 0;
        //������ȱ������죬����������λ�ñ��Ϊ-1        
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