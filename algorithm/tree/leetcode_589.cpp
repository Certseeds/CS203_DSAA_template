// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_589_test.hpp"

namespace leetcode_589 {

void real_action(const Node *const root, vector<int32_t> &vec) {
    if (root == nullptr) {
        return;
    }
    vec.push_back(root->val);
    for (const auto child: root->children) {
        real_action(child, vec);
    }
}

vector<int32_t> leetcode_589::preorder(const Node *const root) {
    vector<int32_t> vec;
    real_action(root, vec);
    return vec;
}

vector<int32_t> leetcode_589::preorderIter(const Node *const root) {
    if (root == nullptr) {
        return {};
    }
    vector<int32_t> vec{};
    const auto func = [&vec](const Node *const node) {
        vec.push_back(node->val);
    };
    for (stack<const Node *> sta{{root}}; !sta.empty();) {
        const auto *const head = sta.top();
        sta.pop();
        func(head);
        for (auto iter{head->children.rbegin()}; iter != head->children.rend(); iter++) {
            sta.push(*iter);
        }
    }
    return vec;
}

}
