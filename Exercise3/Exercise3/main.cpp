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