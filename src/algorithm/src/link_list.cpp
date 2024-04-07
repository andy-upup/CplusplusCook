#include "link_list.h"

namespace algo {

// 160
// input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
// output: Intersected at '8'
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) {
        return nullptr;
    }
    ListNode* nodex = headA;
    ListNode* nodey = headB;
    while (nodex != nodey) {
        nodex = nodex ? nodex->next : headB;
        nodey = nodey ? nodey->next : headA;
    }
    return nodex;
}

// 206
// input: head = [1,2,3,4,5]
// output: [5,4,3,2,1]
ListNode* reverseList(ListNode* head) {
    if (!head) {
        return nullptr;
    }
    ListNode* last = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;
    while (current) {
        next = current->next;
        current->next = last;
        last = current;
        current = next;
    }
    return last;
}

// 141
// input:
// output:
bool hasCycle(ListNode *head) {
    if (!head) {
        return false;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

// 142
// input:
// output:
ListNode *detectCycle(ListNode *head) {
    if (!head) {
        return nullptr;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    return nullptr;
}

// 21
// input: l1 = [1,2,4], l2 = [1,3,4]
// output: [1,1,2,3,4,4]
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }
    ListNode* node1 = list1;
    ListNode* node2 = list2;
    ListNode* head = nullptr;
    if (node1->val < node2->val) {
        head = node1;
        node1 = node1->next;
    } else {
        head = node2;
        node2 = node2->next;
    }
    ListNode* node = head;
    while (node1 && node2) {
        if (node1->val < node2->val) {
            node->next = node1;
            node1 = node1->next;
        } else {
            node->next = node2;
            node2 = node2->next;
        }
        node = node->next;
    }
    if (node1) {
        node->next = node1;
    } else {
        node->next = node2;
    }
    return head;
}

// 2
// input: l1 = [2,4,3], l2 = [5,6,4]
// output: [7,0,8]
// explain: 342 + 465 = 807
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* head = nullptr;
    ListNode* node = nullptr;
    while (l1 || l2) {
        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum %= 10;
        if (!head) {
            head = node = new ListNode(sum);
        } else {
            node->next = new ListNode(sum);
            node = node->next;
        }
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (carry) {
        node->next = new ListNode(carry);
    }
    return head;
}

// 19
// input: head = [1,2,3,4,5], n = 2
// output: [1,2,3,5]
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* node1 = head;
    for (int i = 0; i < n; ++i) {
        node1 = node1->next;
    }
    ListNode* new_head = new ListNode(-1);
    ListNode* last = new_head;
    new_head->next = head;
    last->next = head;
    ListNode* node2 = head;
    while (node1) {
        node1 = node1->next;
        last = node2;
        node2 = node2->next;
    }
    last->next = node2->next;
    return new_head->next;
}

// 24
// input: head = [1,2,3,4]
// output: [2,1,4,3]
ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    std::stack<ListNode*> st_node;
    ListNode* node = new ListNode(-1);
    ListNode* current = head;
    head = node;
    while (current && current->next) {
        st_node.push(current);
        st_node.push(current->next);
        current = current->next->next;

        node->next = st_node.top();
        st_node.pop();
        node = node->next;
        node->next = st_node.top();
        st_node.pop();
        node = node->next;
    }
    node->next = current;
    return head->next;
}

// 138
// input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Node* copyRandomList(Node* head) {
    if (!head) {
        return nullptr;
    }
    Node* node = head;
    while (node) {
        Node* copy = new Node(node->val);
        copy->next = node->next;
        node->next = copy;
        node = copy->next;
    }
    Node* copy_head = head->next;
    node = head;
    while (node) {
        if (node->random) {
            node->next->random = node->random->next;
        }
        node = node->next->next;
    }
    node = head;
    while (node->next) {
        Node* copy = node->next;
        node->next = copy->next;
        node = copy;
    }
    return copy_head;
}

// 148
// input: head = [4,2,1,3]
// output: [1,2,3,4]
ListNode* mergeList(ListNode* node1, ListNode* node2) {
    ListNode* head = new ListNode(-1);
    ListNode* tail = head;
    while (node1 && node2) {
        if (node1->val < node2->val) {
            tail->next = node1;
            node1 = node1->next;
        } else {
            tail->next = node2;
            node2 = node2->next;
        }
        tail = tail->next;
    }
    if (node1) {
        tail->next = node1;
    } else {
        tail->next = node2;
    }
    return head->next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* node1 = head;
    // 这里node2取head->next是为了当链表长度为偶数时，可以从头中间断开，
    // 以长度为2为例，如果node2取head，则会陷入死循环
    ListNode* node2 = head->next;
    while (node2 && node2->next) {
        node1 = node1->next;
        node2 = node2->next->next;
    }
    node2 = node1->next;
    node1->next = nullptr;
    return mergeList(sortList(head), sortList(node2));
}

// 146
// input: ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//        [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// output: [null, null, null, 1, null, -1, null, -1, 3, 4]
class LRUCache {
private:
    std::unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int _size;
    int _capacity;
public:
    void removeNode(DLinkedNode* node) { // 删除节点，即短接当前节点
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DLinkedNode* node) { // 实际是在head后面插入新节点
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() { // 实际删除尾节点之前的节点
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

    LRUCache(int capacity) {
        _capacity = capacity;
        _size = 0;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++_size;
            if (_size > _capacity) {
                DLinkedNode* rm = removeTail();
                cache.erase(rm->key);
                delete rm;
                --_size;
            }
        } else {
            DLinkedNode* node = cache[key];
            node->val = value;
            moveToHead(node);
        }
    }
};

} // namespace algo