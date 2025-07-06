/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
public:
    // recursion
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     traverse(result, root);
    //     return result;
    // }

    // void traverse(vector<int>& result, TreeNode* cur) {
    //     if (cur == nullptr) {
    //         return;
    //     }
    //     traverse(result, cur->left);
    //     result.push_back(cur-> val);
    //     traverse(result, cur->right);
    // }

    // iteration
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode *curNode = root;
        stack<TreeNode *> local_stack;

        while(! local_stack.empty() || curNode != nullptr) {
            while(curNode) {
                local_stack.push(curNode);
                curNode = curNode->left;
            }

            curNode = local_stack.top();
            local_stack.pop();
            result.push_back(curNode->val);

            curNode = curNode->right;
        }

        return result;
    }

    // unified iteration
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     stack<TreeNode *> local_stack;
    //     if (root == nullptr)
    //         return result;

    //     TreeNode *cur;
    //     local_stack.push(root);
    //     while (!local_stack.empty())
    //     {
    //         cur = local_stack.top();
    //         local_stack.pop();

    //         // visited node
    //         if (cur == nullptr) {
    //             // get this node into result
    //             cur = local_stack.top();
    //             local_stack.pop();
    //             result.push_back(cur->val);
    //         } else {
    //             // left mid right
    //             if (cur-> right)
    //                 local_stack.push(cur->right);
    //             local_stack.push(cur);
    //             local_stack.push(nullptr);
    //             if (cur->left)
    //                 local_stack.push(cur->left);
    //         }
    //     }
    //     return result;
    // }
};
// @lc code=end

