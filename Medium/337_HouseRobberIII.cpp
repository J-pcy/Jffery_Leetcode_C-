/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
/*
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        return helper(root, m);
    }
private:
    int helper(TreeNode* node, unordered_map<TreeNode*, int>& m) {
        if (!node) return 0;
        if (m.count(node)) return m[node];
        int val = 0;
        if (node->left) {
            val += helper(node->left->left, m) + helper(node->left->right, m);
        }
        if (node->right) {
            val += helper(node->right->left, m) + helper(node->right->right, m);
        }
        val = max(val + node->val, helper(node->left, m) + helper(node->right, m));
        m[node] = val;
        return val;
    }*/
public:
    int rob(TreeNode* root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
private:
    vector<int> helper(TreeNode* node) {
        if (!node) return vector<int>(2, 0);
        vector<int> left = helper(node->left);
        vector<int> right = helper(node->right);
        vector<int> res(2, 0);
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = left[0] + right[0] + node->val;
        return res;
    }
};