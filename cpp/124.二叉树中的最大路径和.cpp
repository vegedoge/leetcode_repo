/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
public:
    int result;
    int dfs(TreeNode *root)
    {
        if (root == nullptr) {
            return 0;
        }
        // 获取左右的最大路径和
        int left_max = max(0, dfs(root->left));
        int right_max = max(0, dfs(root->right));

        // 1. 不经过父节点 左中右遍历
        int left_root_right_val = left_max + root->val + right_max;

        result = max(result, left_root_right_val);

        // 2. 经过父节点， 左root father或者右 root father
        // 向父节点返回单边最大值
        int root_with_father_val = root->val + max(left_max, right_max);
        return root_with_father_val;
    }
    int maxPathSum(TreeNode *root)
    {
        result = INT_MIN;
        dfs(root);
        return result;
    }
};
// @lc code=end

