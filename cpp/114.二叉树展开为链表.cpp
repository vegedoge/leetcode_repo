/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
#include<stack>
#include<vector>
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        std::stack<TreeNode *> local_stack;
        std::vector<TreeNode *> results;
        local_stack.push(root);

        TreeNode *pre = nullptr;  // for in place solution

        while(!local_stack.empty()) {
            TreeNode *cur = local_stack.top();
            local_stack.pop();

            results.push_back(cur);

            if (cur == nullptr) {
                continue;
            }

            // inplace
            if (pre != nullptr) {
                pre->right = cur;
                pre->left = nullptr;
            }

            if (cur->right)
            {
                local_stack.push(cur->right);
            }

            if (cur->left) {
                local_stack.push(cur->left);
            }

            pre = cur;
        }

        // for(int i = 0; i < results.size() - 1; i++) {
        //     results[i]->left = nullptr;
        //     results[i]->right = results[i + 1];
        // }
    }
};
// @lc code=end

