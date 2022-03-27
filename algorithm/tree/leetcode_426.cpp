// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_426_test.hpp"
#include <stack>

namespace leetcode_426 {
using std::stack;

Node *leetcode_426::treeToDoublyList(Node *root) {
    if (root == nullptr) {
        return nullptr;
    }
    Node *base{nullptr};
    Node *head = root;
    bool temp{false};
    for (stack<Node *> sta; head != nullptr || !sta.empty(); head = head->right) {
        for (; head != nullptr; head = head->left) {
            sta.push(head);
        }
        head = sta.top();
        sta.pop();
        if (base != nullptr) {
            base->right = head;
        }
        head->left = base;
        if (!temp) {
            root = head;
            temp = true;
        }
        base = head;
    }
    root->left = base;
    base->right = root;
    return root;
}
}