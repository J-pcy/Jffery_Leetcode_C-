/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node p is the node with the smallest key greater than p.val.

Example 1:
Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.

Example 2:
Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.

Note:

If the given node has no in-order successor in the tree, return null.
It's guaranteed that the values of the tree are unique.
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        TreeNode* tmp = root;
        bool pflag = false;
        while (tmp || !s.empty()) {
            while (tmp) {
                s.push(tmp);
                tmp = tmp -> left;
            }
            tmp = s.top();
            s.pop();
            if (pflag) return tmp;
            if (tmp == p) pflag = true;
            tmp = tmp -> right;
        }
        return NULL;
    }
    */
    /*
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) return NULL;
        inorder(root, p);
        return suc;
    }
    void inorder(TreeNode* root, TreeNode* p) {
        if (!root) return;
        inorder(root -> left, p);
        if (pre == p) suc = root;
        pre = root;
        inorder(root -> right, p);
    }
    
private:
    TreeNode* pre = NULL, *suc = NULL;
    */
    /*
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) return NULL;
        TreeNode* res = NULL;
        while (root) {
            if (root -> val > p -> val) {
                res = root;
                root = root -> left;
            } else root = root -> right;
        }
        return res;
    }
    */
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) return NULL;
        if (root -> val <= p -> val) {
            return inorderSuccessor(root -> right, p);
        } else {
            TreeNode* left = inorderSuccessor(root->left, p);
            return left ? left : root;
        }
    }
};