/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> this_level;
        vector<vector<int>> result;
        std::queue<TreeNode*> local_queue;
        int size;
        TreeNode *cur_node;

        if (root == nullptr) {
            return result;
        }
        local_queue.push(root);
        while(!local_queue.empty()) {
            size = local_queue.size();
            this_level.clear();
            while (size--)
            {
                cur_node = local_queue.front();
                local_queue.pop();
                this_level.push_back(cur_node->val);
                if(cur_node->left) {
                    local_queue.push(cur_node->left);
                }
                if(cur_node->right) {
                    local_queue.push(cur_node->right);
                }
            }
            result.push_back(this_level);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

