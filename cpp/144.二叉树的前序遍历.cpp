/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include <vector>
#include <stack>
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
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     traverse(result, root);
    //     return result;
    // }

    // void traverse(vector<int>& result, TreeNode* cur) {
    //     if (cur == nullptr) {
    //         return;
    //     }
    //     result.push_back(cur->val);
    //     traverse(result, cur->left);
    //     traverse(result, cur->right);
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> local_stack;

        if (root == nullptr)
            return result;

        local_stack.push(root);
        while (!local_stack.empty()) {
            TreeNode* r_node = local_stack.top();
            local_stack.pop();
            result.push_back(r_node->val);
            if (r_node->right != nullptr)
            {
                local_stack.push(r_node->right);
            }
            if (r_node->left != nullptr) {
                local_stack.push(r_node->left);
            }
        }
        return result;
    }
};
// @lc code=end

