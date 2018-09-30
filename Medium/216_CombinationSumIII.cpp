/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(k, n, 1, tmp, res);
        return res;
    }
private:
    void dfs(int k, int n, int index, vector<int>& tmp, vector<vector<int>>& res) {
        if (tmp.size() == k && n == 0) {
            res.push_back(tmp);
        }
        for (int i = index; i <= 9; i++) {
            if (n - i < 0) break;
            else {
                tmp.push_back(i);
                dfs(k, n - i, i + 1, tmp, res);
                tmp.pop_back();
            }
        }
    }
};