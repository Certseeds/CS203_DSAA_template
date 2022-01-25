/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanoseeds

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
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
    for (stack<const Node *> sta({root}); !sta.empty();) {
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