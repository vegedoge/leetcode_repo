/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
#include <vector>
using namespace std;
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> this_level;
        vector<vector<int>> result;
        int size;
        TreeNode* cur_node;
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode*> local_queue;
        local_queue.push(root);

        while(!local_queue.empty()) {
            size = local_queue.size();
            while(size--) {
                cur_node = local_queue.front();
                local_queue.pop();
                this_level.push_back(cur_node->val);
                if(cur_node->left)
                    local_queue.push(cur_node->left);
                if(cur_node->right)
                    local_queue.push(cur_node->right);
            }
            result.push_back(this_level);
            this_level.clear();
        }
        return result;
    }
};
// @lc code=end

