/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

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
#include "leetcode_530_test.hpp"

namespace leetcode_530 {

int32_t leetcode_530::getMinimumDifference(TreeNode *root) {
    if (root == nullptr) {
        return std::numeric_limits<int32_t>::max();
    }
    const auto *left = root->left;
    const auto *right = root->right;
    while (left != nullptr && left->right != nullptr) {
        left = left->right;
    }
    while (right != nullptr && right->left != nullptr) {
        right = right->left;
    }
    int32_t left_son_diff{std::numeric_limits<int32_t>::max()}, right_son_diff{std::numeric_limits<int32_t>::max()};
    if (left != nullptr) {
        left_son_diff = root->val - left->val;
    }
    if (right != nullptr) {
        right_son_diff = right->val - root->val;
    }
    const int32_t left_will_return = getMinimumDifference(root->left);
    const int32_t right_will_return = getMinimumDifference(root->right);
    return std::min({left_son_diff, right_son_diff, left_will_return, right_will_return});
}

int32_t leetcode_530::getMinimumDifference2(TreeNode *root) {
    if (root == nullptr) {
        return std::numeric_limits<int32_t>::max();
    }
    stack<TreeNode *> sta;
    int32_t lastValue{-0x3f3f3f3f}, will_return{std::numeric_limits<int32_t>::max()};
    for (TreeNode *head = root; head != nullptr || !sta.empty(); head = head->right) {
        while (head != nullptr) {
            sta.push(head);
            head = head->left;
        }
        head = sta.top();
        sta.pop();
        will_return = std::min(will_return, head->val - lastValue);
        lastValue = head->val;
    }
    return will_return;
}
}