/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanoseeds

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
#include "leetcode_113_test.hpp"
#include <queue>

namespace leetcode_113 {
using std::queue;


vector<vector<int>> leetcode_113::pathSum(TreeNode *root, int target) {
    vector<vector<int32_t>> sums;
    if (root == nullptr) {
        return sums;
    }
    for (queue<std::pair<TreeNode *, const vector<int32_t>>> now{{{root, {root->val}}}}; !now.empty();) {
        const auto[head, vec] = now.front();
        now.pop();
        if (head->val == target && head->left == nullptr && head->right == nullptr) {
            sums.push_back(vec);
            continue;
        }
        if (head->left != nullptr) {
            vector<int32_t> path{vec};
            path.push_back(head->left->val);
            head->left->val += head->val;
            now.emplace(head->left, path);
        }
        if (head->right != nullptr) {
            vector<int32_t> path{vec};
            path.push_back(head->right->val);
            head->right->val += head->val;
            now.emplace(head->right, path);
        }
    }
    return sums;
}


}