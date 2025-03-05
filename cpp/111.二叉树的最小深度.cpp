/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */
#include<queue>
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
    int minDepth(TreeNode* root) {
        std::queue<TreeNode *> node_q;
        int depth = 0;
        int min_depth = __INT16_MAX__;
        int size;
        if (root == nullptr) {
            return 0;
        }
        node_q.push(root);
        while(!node_q.empty()) {
            depth++;
            size = node_q.size();
            while(size--) {
                TreeNode* cur = node_q.front();
                node_q.pop();
                if(cur->left)
                    node_q.push(cur->left);
                if(cur->right)
                    node_q.push(cur->right);
                if(!(cur->left || cur->right)) {
                    min_depth = min(min_depth, depth);
                }
            }
        }
        return min_depth;
    }
};
// @lc code=end

