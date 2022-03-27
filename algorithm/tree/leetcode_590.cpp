// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_590_test.hpp"

namespace leetcode_590 {

void real_action(const Node *const root, vector<int32_t> &vec) {
    if (root == nullptr) {
        return;
    }
    for (const auto child: root->children) {
        real_action(child, vec);
    }
    vec.push_back(root->val);
}

vector<int32_t> leetcode_590::postorder(const Node *const root) {
    vector<int32_t> vec;
    real_action(root, vec);
    return vec;
}

vector<int32_t> leetcode_590::postorderIter(const Node *const root) {
    if (root == nullptr) {
        return {};
    }
    list<int32_t> nodes;
    for (stack<const Node *> sta{{root}}; !sta.empty();) {
        const auto *const head = sta.top();
        sta.pop();
        nodes.push_front(head->val);
        for (const auto iter: head->children) {
            sta.push(iter);
        }
    }
    return {nodes.cbegin(), nodes.cend()};
}

}