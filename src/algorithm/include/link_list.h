#ifndef LINK_LIST_H_
#define LINK_LIST_H_
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

namespace algo {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

class DLinkedNode {
public:
    int key, val;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), val(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _val): key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

} // namespace algo
#endif