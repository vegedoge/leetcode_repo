/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int traverse(TreeNode *root)
    {
        // null节点等于被cover了
        if (root == nullptr) {
            return 1;
        }

        int left = traverse(root->left);
        int right = traverse(root->right);

        // 左右都被覆盖了
        if (left == 1 && right == 1) {
            return 0;
            // 左右有一个没有被覆盖
            // 0 - 1, 1 - 0, 0 - 2, 2 - 0, 0 - 0
        } else if (left == 0 || right == 0) {
            result += 1;
            return 2;
            // 左边或者右边是cam
            // 1 - 2, 2 - 1, 2 - 2
        } else if (left == 2 || right == 2) {
            return 1;
        } else {
            return -1;// 不会到这
        }
    }
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (traverse(root) == 0) {
            // 根节点左右都被覆盖 也要再加一个
            result += 1;
        }

        return result;
    }
};
// @lc code=end

