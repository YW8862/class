#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

//int main() {
//    string s;
//    char ch;
//    int num = 0;
//    cin >> s;
//    cin >> ch;
//    for (int i = 0; i <= s.size(); i++) {
//        string cpstring = s;
//        
//        cpstring.insert(i, 1, ch);
//        string ss = cpstring;
//        reverse(cpstring.begin(), cpstring.end());
//        if (cpstring == ss)
//            num++;
//    }
//    cout << num << endl;
//}
// 

//int main() {
//	int temp = 0;
//	for (int i = 0; i < 100; i++)
//		temp = temp++;
//	cout << temp;
//	return 0;
//}

//int main() {
//    size_t size = 0;
//    cin >> size;
//    int* nums = new int[size];
//    for (int i = 0; i < size; i++) {
//        cin >> nums[i];
//    }
//    int ret = nums[0];
//    int i = 0;
//    int Max = 0;
//    while (i < size) {
//        Max = max(Max, ret);
//        
//        if (ret < 0)
//            ret = 0;
//        ret += nums[i];
//        
//        i++;
//    }
//    Max = max(Max, ret);
//    cout << Max << endl;
//    return 0;
//}


class Solution {
public:
    static vector<vector<string>> ret;
    static vector<string> arr;

    void set(int**& board, int n, int row, int col) {
        // 将同行改为不可放置
        for (int i = 0; i < n; i++)
            board[row][i] = 2;
        // 同列改为不可放置
        for (int j = 0; j < n; j++)
            board[j][col] = 2;
        // 右下不可放置
        for (int i = row + 1, j = col + 1; i < n && j < n; i++, j++) {
            board[i][j] = 2;
        }
        // 左下角不可放置
        for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
            board[i][j] = 2;
        }
    }

    void Queen(int** board, int n, int row) {
        if (n == row) {
            for (int i = 0; i < n; i++) {
                string s;
                for (int j = 0; j < n; j++)
                    if (board[i][j] == 1)
                        s += 'Q';
                    else
                        s += '.';
                arr.push_back(s);
            }
            ret.push_back(arr);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (board[row - 1][i] == 0) {
                board[row - 1][i] = 1;
                set(board, n, row - 1, i);
                Queen(board, n, row + 1);
                arr.clear();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        int** board = new int* [n];
        for (int i = 0; i < n; i++)
            board[i] = new int[n];
        Queen(board, n, 1);
        return Solution::ret;
    }
};

int main() {
    vector<vector<string>>ret = Solution().solveNQueens(10);
    return 0;
}