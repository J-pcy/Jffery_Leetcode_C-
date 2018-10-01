/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

class Solution {
public:
/*
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        for (int i = 0; i < matrix.size(); i++) {
            vector<int> tmp(matrix[i].size(), 0);
            for (int k = i; k < matrix.size(); k++) {
                for (int j = 0; j < matrix[k].size(); j++) {
                    if (matrix[k][j] == '1') tmp[j]++;
                }
                res = max(res, getSqureArea(tmp, k - i + 1));
            }
        }
        return res;
    }
private:
    int getSqureArea(vector<int> v, int n) {
        if (v.size() < n) return 0;
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != n) cnt = 0;
            else cnt++;
            if (cnt == n) return n * n;
        }
        return 0;
    }*/
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) dp[i][j] = matrix[i][j] - '0';
                else {
                    if (matrix[i][j] == '1') {
                        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    }
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};