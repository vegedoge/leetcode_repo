/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
private:
    unordered_map<int, int> root_index_in_inorder;
    TreeNode* buildSubTree(const vector<int>& inorder, const vector<int>& postorder,
                            int post_start, int post_end,
                            int in_start, int in_end) 
    {
        if (post_start > post_end || in_start > in_end) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(postorder[post_end]);
        int root_index = root_index_in_inorder[postorder[post_end]];

        int left_sub_tree_size = root_index - in_start;
        int right_sub_tree_size = in_end - root_index;

        root->left = buildSubTree(inorder, postorder, post_start, post_start + left_sub_tree_size - 1,
                                  in_start, root_index - 1);

        root->right = buildSubTree(inorder, postorder, post_end - right_sub_tree_size, post_end - 1,
                                   root_index + 1, in_end);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            root_index_in_inorder[inorder[i]] = i;
        }

        return buildSubTree(inorder, postorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
};
// @lc code=end

