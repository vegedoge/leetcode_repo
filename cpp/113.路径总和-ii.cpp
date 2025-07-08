/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
#include<vector>
class Solution {
private:
    std::vector<std::vector<int>> results;
    std::vector<int> temp_result;

    void findPath(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return;
        }

        int val = root->val;
        temp_result.push_back(val);

        if (!root->left && !root->right) {
            if (targetSum == val) {
                results.push_back(temp_result);
                temp_result.pop_back();
                return;
            }
        }
        
        findPath(root->left, targetSum - val);
        findPath(root->right, targetSum - val);

        temp_result.pop_back();
        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        findPath(root, targetSum);
        return results;
    }
};
// @lc code=end

