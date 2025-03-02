/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */
#include <vector>
#include <algorithm>
using namespace std;
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
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     traverse(result, root);
    //     return result;
    // }

    // void traverse(vector<int>& result, TreeNode* cur) {
    //     if (cur == nullptr) {
    //         return;
    //     }
    //     traverse(result, cur->left);
    //     traverse(result, cur->right);
    //     result.push_back(cur->val);
    // }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> local_stack;

        if (root == nullptr)
            return result;

        local_stack.push(root);
        while (!local_stack.empty()) {
            TreeNode *r_node = local_stack.top();
            local_stack.pop();
            result.push_back(r_node->val);

            if (r_node -> left) {
                local_stack.push(r_node->left);
            }

            if (r_node -> right) {
                local_stack.push(r_node->right);
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

