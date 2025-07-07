/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
#include<vector>

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//     };

class Solution {
private:
    TreeNode* buildSubTree(const std::vector<int>& nums, int begin, int end) {

        if (begin > end) {
            return nullptr;
        }
        int root_index = begin + (end - begin) / 2;
        TreeNode *root = new TreeNode(nums[root_index]);

        root->left = buildSubTree(nums, begin, root_index - 1);
        root->right = buildSubTree(nums, root_index + 1, end);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return buildSubTree(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

