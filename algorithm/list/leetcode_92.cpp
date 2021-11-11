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
#include "leetcode_92_test.hpp"

namespace leetcode_92 {
template<typename T>
struct TreeNode {
    T val{static_cast<T>(0)};
    TreeNode<T> *left{nullptr}, *right{nullptr};

    virtual ~TreeNode() = default;
};

template<typename T>
struct AVLTreeNode : public TreeNode<T> {
    size_t height{0};
};

ListNode *leetcode_92::reverseBetween(ListNode *head, int32_t left, int32_t right) {
    AVLTreeNode<int32_t> x;
    x.left = new AVLTreeNode<int32_t>();
    ListNode will_return(-1);
    will_return.next = head;
    ListNode *pre{&will_return};
    for (int32_t i{0}; i < left - 1; i++) {
        pre = pre->next;
    }
    ListNode *iter{pre->next};

    for (int32_t i{left}; i < right; i++) {
        ListNode *next{iter->next};
        ListNode *const prenext = pre->next;
        iter->next = next->next;
        pre->next = next;
        next->next = prenext;
    }
    delete x.left;
    return will_return.next;
}
}

