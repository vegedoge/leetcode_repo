/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
#include<stack>
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
    // recursion
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr)
            return true;
        return compare(root->left, root->right);
    }

    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right != nullptr) {
            return false;
        } else if (left != nullptr && right == nullptr) {
            return false;
        } else if (left == nullptr && right == nullptr) {
            return true;
        } else {
            if (left -> val == right -> val) {
                bool outer = compare(left->left, right->right);
                bool inner = compare(left->right, right->left);
                return outer && inner;
            } else {
                return false;
            }
        } 
    }

    // iteration
    bool isSysmmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        TreeNode* l_node;
        TreeNode *r_node;
        int size;
        std::stack<TreeNode *> st;
        st.push(root->left);
        st.push(root->right);

        while(!st.empty()) {
            size = st.size();
            r_node = st.top();
            st.pop();
            l_node = st.top();
            st.pop();

            if (!l_node && !r_node) {
                continue;
            }
            if(!l_node || !r_node || (r_node->val != l_node ->val)) {
                return false;
            }

            st.push(l_node->right);
            st.push(r_node->left);
            st.push(l_node->left);
            st.push(r_node->right);
            
        }
        return true;
    }
};
// @lc code=end

