/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    int result;
    void helper(TreeNode* root, int temp) {
        if (!root->left && !root->right) {
            temp = 10 * temp + root->val;
            result += temp;
            return;
        }

        if (root->left) {
            helper(root->left, 10 * temp + root->val);
        }

        if (root->right) {
            helper(root->right, 10 * temp + root->val);
        }

        return;
    }

public:
    int sumNumbers(TreeNode* root) {
        result = 0;
        helper(root, 0);
        return result;
    }
};
// @lc code=end

