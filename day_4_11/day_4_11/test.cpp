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



////N�ʺ�
//class Solution {
//public:
//    vector<vector<string>> solveNQueens(int n) {
//        vector<vector<string>> result;
//        vector<string> board(n, string(n, '.')); // ��ʼ��������
//
//        solveNQueensDFS(board, 0, result);
//
//        return result;
//    }
//
//private:
//    void solveNQueensDFS(vector<string>& board, int row, vector<vector<string>>& result) {
//        int n = board.size();
//        if (row == n) {
//            result.push_back(board);
//            return;
//        }
//
//        for (int col = 0; col < n; ++col) {
//            if (isValid(board, row, col, n)) {
//                board[row][col] = 'Q'; // ���ûʺ�
//                solveNQueensDFS(board, row + 1, result); // �ݹ鴦����һ��
//                board[row][col] = '.'; // ���ݣ�������ǰλ�õĻʺ�
//            }
//        }
//    }
//
//    bool isValid(vector<string>& board, int row, int col, int n) {
//        // ������Ƿ��лʺ��ͻ
//        for (int i = 0; i < row; ++i) {
//            if (board[i][col] == 'Q') {
//                return false;
//            }
//        }
//
//        // ������������¶Խ����Ƿ��лʺ��ͻ
//        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
//            if (board[i][j] == 'Q') {
//                return false;
//            }
//        }
//
//        // ������������¶Խ����Ƿ��лʺ��ͻ
//        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
//            if (board[i][j] == 'Q') {
//                return false;
//            }
//        }
//
//        return true;
//    }
//};

