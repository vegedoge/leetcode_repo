/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
#include <unordered_map>

class Solution {
private:
    int result;
public:
    void dfs(std::unordered_map<long long, int>& preSum, long long curSum, int targetSum, TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }

        curSum += cur->val;

        // 找到以当前节点为终点的
        if (preSum.count(curSum - targetSum)) {
            result += preSum[curSum - targetSum];
        }

        // 处理当前节点为中转的
        preSum[curSum]++;
        dfs(preSum, curSum, targetSum, cur->left);
        dfs(preSum, curSum, targetSum, cur->right);
        preSum[curSum]--;

        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        result = 0;
        std::unordered_map<long long, int> preSum;
        long long curSum = 0;
        // 需要一条路 说明从任意位置到root(0) 都是有路的
        // 比如curSum - targetSum == 0 count一下是1
        preSum[0] = 1;
        dfs(preSum, curSum, targetSum, root);

        return result;
    }
};
// @lc code=end

