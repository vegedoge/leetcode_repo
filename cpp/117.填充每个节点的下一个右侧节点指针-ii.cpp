/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#include<queue>
#include<vector>



// while(size--) 循环体 里面的size--在条件判断后立即触发 和for不同
class Solution {
public:
    Node* connect(Node* root) {
        int size;
        Node *cur_node;

        if (root == nullptr) {
            return nullptr;
        }

        std::queue<Node*> local_queue;
        local_queue.push(root);

        while(!local_queue.empty()) {
            int size = local_queue.size();
            while (size--) {
                Node *cur_node = local_queue.front();
                local_queue.pop();

                if(size == 0) {
                    cur_node->next = nullptr;
                } else {
                    Node* next_node = local_queue.front();
                    cur_node->next = next_node;
                }

                if (cur_node->left) {
                    local_queue.push(cur_node->left);
                }
                if (cur_node->right) {
                    local_queue.push(cur_node->right);
                }
            }
        }

        return root;
    }
};
// @lc code=end

