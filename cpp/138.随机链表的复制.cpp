/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    // hash table, first init mapping, then double iteration to init random
    unordered_map<Node *, Node *> map;
    if(head == nullptr) {
        return nullptr;
    }
    Node *cur = head;
    while(cur!=nullptr){
        map[cur] = new Node(cur->val);
        cur = cur->next;
    }

    // double iteration
    cur = head;
    while(cur!=nullptr) {
        map[cur]->next = map[cur->next];
        map[cur]->random = map[cur->random];
        cur = cur->next;
    }

    return map[head];
    }
};
// @lc code=end

