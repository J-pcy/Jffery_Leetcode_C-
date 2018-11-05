/*
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Consider the following binary search tree: 

     5
    / \
   2   6
  / \
 1   3
Example 1:

Input: [5,2,6,1,3]
Output: false
Example 2:

Input: [5,2,1,3,6]
Output: true
Follow up:
Could you do it using only constant space complexity?
*/

class Solution {
public:
/*
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        stack<int> s;
        for (auto a: preorder) {
            if (a < low) return false;
            while (!s.empty() && a > s.top()) {
                low = s.top();
                s.pop();
            }
            s.push(a);
        }
        return true;
    }*/
    bool verifyPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1, INT_MIN, INT_MAX);
    }
    bool helper(vector<int>& preorder, int start, int end, int lower, int upper) {
        if (start > end) return true;
        int val = preorder[start], i = 0;
        if (val <= lower || val >= upper) return false;
        for (i = start + 1; i <= end; ++i) {
            if (preorder[i] > val) break;
        }
        return helper(preorder, start + 1, i - 1, lower, val) && helper(preorder, i, end, val, upper);
    }
};