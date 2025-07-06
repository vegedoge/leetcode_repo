/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include <vector>
#include <unordered_map>
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
private:
    unordered_map<int, int> root_in_order_map;

    TreeNode *buildSubTree(const vector<int>& preorder, const vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end)
    {
        if (pre_start > pre_end || in_start > in_end) {
            return nullptr; // why?
        }

        int root_val = preorder[pre_start];
        // new在堆上分配 但是TreeNode直接实现在栈上局部实现
        TreeNode *root = new TreeNode(root_val);

        int root_in_inorder_index = root_in_order_map[root_val];

        int left_sub_tree_size = root_in_inorder_index - in_start;
        int right_sub_tree_size = in_end - root_in_inorder_index;

        root->left = buildSubTree(preorder, inorder, pre_start + 1, pre_start + left_sub_tree_size,
                                  in_start, root_in_inorder_index - 1);

        root->right = buildSubTree(preorder, inorder, pre_start + 1 + left_sub_tree_size, pre_end,
                                   root_in_inorder_index + 1, in_end);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            root_in_order_map[inorder[i]] = i;
        }
        return buildSubTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
// @lc code=end

