/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    long long previous = LLONG_MIN;

public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        if (!isValidBST(root->left)) {
            return false;
        }

        if (root->val <= previous) {
            return false;
        }
        previous = root->val;

        return isValidBST(root->right);
    }
};
// @lc code=end

