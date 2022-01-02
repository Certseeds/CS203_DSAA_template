/*
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2020-07-30 10:30:53
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-30 18:18:53
 */
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

#include <catch_main.hpp>
#include <functional>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

#include "tree/treenode_.hpp"

namespace Tree_Traverse {
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using Catch::Matchers::Equals;
using std::cout;
using std::stack;
using std::vector;
using action = const std::function<void(const TreeNode *)> &;
static constexpr char end{'\n'}, space{' '};

namespace rec {
void pre(const TreeNode *root, action func) {
    if (root == nullptr) {
        return;
    }
    func(root);
    pre(root->left, func);
    pre(root->right, func);
}

void in(const TreeNode *root, action func) {
    if (root == nullptr) {
        return;
    }
    in(root->left, func);
    func(root);
    in(root->right, func);
}

void post(const TreeNode *root, action func) {
    if (root == nullptr) {
        return;
    }
    post(root->left, func);
    post(root->right, func);
    func(root);
}
}

namespace iter{

void pre1(const TreeNode *root, action func) {
    if (root == nullptr) {
        return;
    }
    stack<const TreeNode *> sta;
    sta.push(root);
    while (!sta.empty()) {
        const TreeNode *head = sta.top();
        sta.pop();
        func(head);
        if (head->right != nullptr) {
            sta.push(head->right);
        }
        if (head->left != nullptr) {
            sta.push(head->left);
        }
    }
}

void pre2(const TreeNode *root, action func) {
    if (root == nullptr) {
        return;
    }
    stack<const TreeNode *> sta;
    const TreeNode *head = root;
    while (head != nullptr || !sta.empty()) {
        while (head != nullptr) {
            func(head);
            sta.push(head->right);
            head = head->left;
        }
        head = sta.top();
        sta.pop();
    }
}

void pre3(const TreeNode *root, action func) {
    //作者：sonp
    //链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/mo-fang-di-gui-zhi-bian-yi-xing-by-sonp/
    if (root == nullptr) {
        return;
    }
    stack<const TreeNode *> sta;
    sta.push(root);
    while (!sta.empty()) {
        const TreeNode *head = sta.top();
        sta.pop();
        if (head != nullptr) {
            if (head->right != nullptr) {
                sta.push(head->right);
            }
            if (head->left != nullptr) {
                sta.push(head->left);
            }
            sta.push(head);
            sta.push(nullptr);
        } else {
            func(sta.top());
            sta.pop();
        }
    }
}


void in(const TreeNode *root, action func) {
    if (root == nullptr) {
        return;
    }
    stack<const TreeNode *> sta;
    const TreeNode *head = root;
    while (head != nullptr || !sta.empty()) {
        while (head != nullptr) {
            sta.push(head);
            head = head->left;
        }
        head = sta.top();
        sta.pop();
        func(head);
        head = head->right;
    }
}

void in2(const TreeNode *root, action func) {
    //作者：sonp
    //链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/mo-fang-di-gui-zhi-bian-yi-xing-by-sonp/
    if (root == nullptr) {
        return;
    }
    stack<const TreeNode *> sta;
    sta.push(root);
    while (!sta.empty()) {
        const TreeNode *head = sta.top();
        sta.pop();
        if (head != nullptr) {
            if (head->right != nullptr) {
                sta.push(head->right);
            }
            sta.push(head);
            sta.push(nullptr);
            if (head->left != nullptr) {
                sta.push(head->left);
            }
        } else {
            func(sta.top());
            sta.pop();
        }
    }
}

void post(const TreeNode *root, action func) {
    //作者：sonp
    //链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/mo-fang-di-gui-zhi-bian-yi-xing-by-sonp/
    if (root == nullptr) {
        return;
    }
    stack<const TreeNode *> sta;
    sta.push(root);
    while (!sta.empty()) {
        const TreeNode *head = sta.top();
        sta.pop();
        if (head != nullptr) {
            sta.push(head);
            sta.push(nullptr);
            if (head->right != nullptr) {
                sta.push(head->right);
            }
            if (head->left != nullptr) {
                sta.push(head->left);
            }
        } else {
            func(sta.top());
            sta.pop();
        }
    }
}
}
}