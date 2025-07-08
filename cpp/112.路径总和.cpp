/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    int temp_sum = 0;
public:
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     // check empty tree
    //     if (!root) {
    //         return false;
    //     }

    //     temp_sum += root->val;

    //     // check leaf
    //     if (!root->left && !root-> right) {
    //         if (temp_sum == targetSum) {
    //             return true;
    //         } else {
    //             temp_sum -= root->val;
    //             return false;
    //         }
    //     }

    //     // dfs
    //     if (root->right) {
    //         if (hasPathSum(root->right, targetSum)) {
    //             return true;
    //         }
    //     }

    //     if (root->left) {
    //         if (hasPathSum(root->left, targetSum)) {
    //             return true;
    //         } 
    //     }

    //     temp_sum -= root->val;
    //     return false;
    // }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        int val = root->val;

        if(!root->left && !root->right) {
            if (val == targetSum) {
                return true;
            }
        }

        return hasPathSum(root->left, targetSum - val) || hasPathSum(root->right, targetSum - val);
    }
};
// @lc code=end

