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
        nodes.insert(nodes.cbegin(), head->val);
        for (const auto iter: head->children) {
            sta.push(iter);
        }
    }
    return {nodes.cbegin(), nodes.cend()};
}

}