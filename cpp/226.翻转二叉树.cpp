/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */
#include<stack>
#include<algorithm>
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
    // TreeNode* invertTree(TreeNode* root) {
    //     if (root==nullptr) {
    //         return root;
    //     }
    //     traverseInvert(root);
    //     return root;
    // }

    // void traverseInvert(TreeNode* root) {
    //     TreeNode *temp = root->left;
    //     root->left = root->right;
    //     root->right = temp;
    //     if(root->left) {
    //         traverseInvert(root->left);
    //     }
    //     if(root->right) {
    //         traverseInvert(root->right);
    //     }
    // }

    TreeNode* invertTree(TreeNode* root) {
        if (root==nullptr) {
            return root;
        }
        std::stack<TreeNode*> local_stack;
        TreeNode *cur_node;
        local_stack.push(root);
        while(!local_stack.empty()) {
            cur_node = local_stack.top();
            local_stack.pop();
            std::swap(cur_node->left, cur_node->right);
            if(cur_node->right) {
                invertTree(cur_node->right);
            }
            if (cur_node->left) {
                invertTree(cur_node->left);
            }
        }
        return root;
    }
};
// @lc code=end

