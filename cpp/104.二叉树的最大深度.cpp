/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
#include <queue>

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
    // int maxDepth(TreeNode* root) {
    //     return getDepth(root);
    // }

    // int getDepth(TreeNode* node) {
    //     if (node == nullptr)
    //         return 0;
    //     int l_depth = getDepth(node->left);
    //     int r_depth = getDepth(node->right);
    //     return 1 + max(l_depth, r_depth);
    // }

    int maxDepth(TreeNode* root) {
        std::queue<TreeNode*> node_q;
        int size;
        int depth;
        TreeNode *local_node;
        if (root == nullptr)
            return 0;
        node_q.push(root);
        while(!node_q.empty()) {
            size = node_q.size();
            while(size--) {
                local_node = node_q.front();
                node_q.pop();
                if (local_node->left) {
                    node_q.push(local_node->left);
                }
                if (local_node->right) {
                    node_q.push(local_node->right);
                }
            }
            depth++;
        }
        return depth;
    }
};
// @lc code=end

