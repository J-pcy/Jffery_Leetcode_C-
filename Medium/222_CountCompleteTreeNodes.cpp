/*
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2^h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
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
public:
/*
    //Time Limit Exceeded
    int countNodes(TreeNode* root) {
        dfs(root);
        return numNode;
    }
private:
    int numNode;
    void dfs(TreeNode* root) {
        if (!root) return;
        numNode++;
        dfs(root->left);
        dfs(root->right);
    }*/
/*
    int countNodes(TreeNode* root) {
        int leftH = getLeftHeight(root);
        int rightH = getRightHeight(root);
        if (leftH == rightH) return pow(2, leftH) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
private:
    int getLeftHeight(TreeNode* node) {
        if (!node) return 0;
        return getLeftHeight(node->left) + 1;
    }
    int getRightHeight(TreeNode* node) {
        if (!node) return 0;
        return getRightHeight(node->right) + 1;
    }*/
    int countNodes(TreeNode* root) {
        int leftH = 0, rightH = 0;
        for (TreeNode *p = root; p; p = p->left) ++leftH;
        for (TreeNode *p = root; p; p = p->right) ++rightH;
        if (leftH == rightH) return pow(2, leftH) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};