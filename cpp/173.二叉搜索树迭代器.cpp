/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
#include<stack>
class BSTIterator {
private:
    stack<TreeNode *> local_stack;
    TreeNode *cur;

public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }

    int next() {
        while(cur) {
            local_stack.push(cur);
            cur = cur->left;
        }

        cur = local_stack.top();
        local_stack.pop();

        int ret = cur->val;
        cur = cur->right;

        return ret;
    }

    bool hasNext() {
        return (!local_stack.empty() || cur);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

