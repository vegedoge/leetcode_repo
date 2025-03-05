/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

#include<memory>
// @lc code=start
class MyLinkedList {
public:

    struct LinkedNode {
        int val;
        std::unique_ptr<LinkedNode> next;
        LinkedNode(int x) : val(x), next(nullptr) {}
    };
    MyLinkedList()
    {
        _dummyHead = std::make_unique<LinkedNode>(0);
        _size = 0;
    }

    ~MyLinkedList() = default;

    int get(int index) {
        if (index > _size-1) {
            return -1;
        }
        LinkedNode* current = _dummyHead->next.get();
        while(index--) {
            current = current->next.get();
        }
        return current->val;
    }

    void addAtHead(int val) {
        std::unique_ptr<LinkedNode> new_head = std::make_unique<LinkedNode>(val);
        new_head->next = std::move(_dummyHead->next);
        _dummyHead->next = std::move(new_head);
        _size++;
    }

    void addAtTail(int val) {
        std::unique_ptr<LinkedNode> new_tail = std::make_unique<LinkedNode>(val);
        LinkedNode *current = _dummyHead.get();
        while(current->next != nullptr) {
            current = current->next.get();
        }
        current->next = std::move(new_tail);
        _size++;
    }

    void addAtIndex(int index, int val) {
        std::unique_ptr<LinkedNode> new_node = std::make_unique<LinkedNode>(val);
        LinkedNode *current = _dummyHead.get();
        if (index > _size)
            return;
        else if(index < 0) {
            index = 0;
        }
        while(index--) {
            current = current->next.get();
        }
        new_node->next = std::move(current->next);
        current->next = std::move(new_node);
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index > _size - 1) {
            return;
        }
        LinkedNode *current = _dummyHead.get();
        while(index--) {
            current = current->next.get();
        }
        current->next = std::move(current->next->next);
        _size--;
    }

private:
    int _size;
    std::unique_ptr<LinkedNode> _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

