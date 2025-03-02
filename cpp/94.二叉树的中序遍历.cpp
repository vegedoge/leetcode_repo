/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     traverse(result, root);
    //     return result;
    // }

    // void traverse(vector<int>& result, TreeNode* cur) {
    //     if (cur == nullptr) {
    //         return;
    //     }
    //     traverse(result, cur->left);
    //     result.push_back(cur-> val);
    //     traverse(result, cur->right);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> local_stack;
        if (root == nullptr)
            return result;

        TreeNode *r_node = root;
        while (!local_stack.empty() || r_node != nullptr)
        {
            while(r_node != nullptr) {
                local_stack.push(r_node);
                r_node = r_node->left;
            }

            r_node = local_stack.top();
            local_stack.pop();
            result.push_back(r_node->val);

            r_node = r_node->right;
        }
        return result;
    }
};
// @lc code=end

