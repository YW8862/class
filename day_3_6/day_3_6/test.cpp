#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0
            || matrix[0][0] > target
            || matrix[matrix.size() - 1][matrix[0].size() - 1] < target)
            return false;
        int i = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for (i = 0; i<m; i++) {
            if (matrix[i][0] <= target && matrix[i][n - 1] >= target)
                break;
        }
        if (i == m)
            --i;
        int left = 0;
        int right = n - 1;
        int mid = (left + right) / 2;
        while (left <= right) {
            if (matrix[i][mid] == target)
                return true;
            if (matrix[i][mid] > target) {
                right = mid - 1;
            }
            else
                left = mid + 1;
            mid = (left + right) / 2;
        }
        return false;
    }
};


class Solution2 {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max = 0;
        for (auto e : sentences) {
            int pos = e.find(' ');
            int x = 1;
            while (pos != string::npos) {
                x++;
                pos = e.find(' ',pos + 1);
            }
            if (x > max)
                max = x;
        }
        return max;
    }
};


bool half_search(vector<int>num,int target) {
    int left = 0;
    int right = num.size() - 1;
    int mid = (left + right) / 2;

    while (left <= right) {
        if (num[mid] == target)
            return true;
        if (num[mid] > target) {
            right = mid - 1;
        }
        else
            left = mid + 1;
        mid = (left + right) / 2;
    }
    return false;
}

int main() {
    vector<vector<int>> num = { {1},{3} };
    vector<string>strings = { "alice and bob love leetcode", "i think so too", "this is great thanks very much" };
    cout << Solution2().mostWordsFound(strings) << endl;;
    //cout << Solution1().searchMatrix(num, 2)<<endl;
	return 0;
}