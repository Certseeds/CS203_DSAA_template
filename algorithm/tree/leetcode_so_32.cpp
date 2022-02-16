/*
MIT License

CS203_DSAA_template

Copyright (C) 2022 nanoseeds

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
#include "leetcode_so_32_test.hpp"
#include "traverse.cpp"
#include <queue>

namespace leetcode_so_32 {
using std::queue;
using namespace Tree_Traverse;

vector<int32_t> leetcode_so_32::levelOrderFst(TreeNode *root) {
    if (root == nullptr) {
        return {};
    }
    vector<int32_t> will_return{};
    const auto func = [&will_return](const auto node) {
        will_return.push_back(node->val);
    };
    iter::level(root, func);
    return will_return;
}

vector<vector<int32_t>> leetcode_so_32::levelOrderTrd(TreeNode *root) {
    if (root == nullptr) {
        return {};
    }
    vector<vector<int32_t>> will_return{};
    bool shift{true};
    for (queue<const TreeNode *> now{{root}}, next{}; !now.empty();) {
        vector<int32_t> line{};
        while (!now.empty()) {
            const auto *const head = now.front();
            now.pop();
            line.push_back(head->val);
            if (head->left != nullptr) {
                next.push(head->left);
            }
            if (head->right != nullptr) {
                next.push(head->right);
            }
        }
        if (shift) {
            will_return.emplace_back(line.begin(), line.end());
        } else {
            will_return.emplace_back(line.rbegin(), line.rend());
        }
        shift = !shift;
        std::swap(now, next);
    }
    return will_return;
}

}