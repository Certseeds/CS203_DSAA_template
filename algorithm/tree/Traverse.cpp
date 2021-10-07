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

#include "TreeNode.hpp"
using TREE_NODE::TreeNode;
using Catch::Matchers::Equals;
using std::cout;
using std::stack;
using std::vector;
using action = const std::function<void(const TreeNode<int32_t> *)> &;
static constexpr char end{'\n'}, space{' '};

//auto func1 = [](const TreeNode* tn) -> void { cout << tn->val << space; };
void pre_rec(const TreeNode<int32_t> *root, action func) {
    if (root == nullptr) {
        return;
    }
    func(root);
    pre_rec(root->left, func);
    pre_rec(root->right, func);
}

void pre_iter1(const TreeNode<int32_t> *root, action func) {
    if (root == nullptr) {
        return;
    }
    stack<const TreeNode<int32_t> *> sta;
    sta.push(root);
    while (!sta.empty()) {
        const TreeNode<int32_t> *head = sta.top();
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

void pre_iter2(TreeNode<int32_t> *root, action func) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode<int32_t> *> sta;
    TreeNode<int32_t> *head = root;
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

void pre_iter3(TreeNode<int32_t> *root, action func) {
    //作者：sonp
    //链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/mo-fang-di-gui-zhi-bian-yi-xing-by-sonp/
    if (root == nullptr) {
        return;
    }
    stack<TreeNode<int32_t> *> sta;
    sta.push(root);
    while (!sta.empty()) {
        TreeNode<int32_t> *head = sta.top();
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

void in_rec(const TreeNode<int32_t> *root, action func) {
    if (root == nullptr) {
        return;
    }
    in_rec(root->left, func);
    func(root);
    in_rec(root->right, func);
}

void in_iter(TreeNode<int32_t> *root, action func) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode<int32_t> *> sta;
    TreeNode<int32_t> *head = root;
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

void in_iter2(TreeNode<int32_t> *root, action func) {
    //作者：sonp
    //链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/mo-fang-di-gui-zhi-bian-yi-xing-by-sonp/
    if (root == nullptr) {
        return;
    }
    stack<TreeNode<int32_t> *> sta;
    sta.push(root);
    while (!sta.empty()) {
        TreeNode<int32_t> *head = sta.top();
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

void post_rec(const TreeNode<int32_t> *root, action func) {
    if (root == nullptr) {
        return;
    }
    post_rec(root->left, func);
    post_rec(root->right, func);
    func(root);
}

void post_iter(TreeNode<int32_t> *root, action func) {
    //作者：sonp
    //链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/mo-fang-di-gui-zhi-bian-yi-xing-by-sonp/
    if (root == nullptr) {
        return;
    }
    stack<TreeNode<int32_t> *> sta;
    sta.push(root);
    while (!sta.empty()) {
        TreeNode<int32_t> *head = sta.top();
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

TEST_CASE("traverse basic", "[tree traverse]") {
    const vector<string> name{"", "pre order", "in order", "post order"};
    constexpr int32_t tree_nodes = 32;
    static int32_t count = 0;
    vector<int32_t> vec(tree_nodes);
    std::iota(vec.begin(), vec.end(), 0);
    vector<TreeNode<int32_t> *> numvec = TREE_NODE::numToTree<int32_t>(vec);
    TreeNode<int32_t> *head = numvec[0];
    static vector<int32_t> last(tree_nodes);
    vector<int32_t> res;
    auto func2 = [&res](const TreeNode<int32_t> *tn) -> void { res.push_back(tn->val); };
    SECTION("pre_rec") {
        count++;
        pre_rec(head, func2);
    }SECTION("pre_iter1") {
        pre_iter1(head, func2);
        CHECK_THAT(res, Equals(last));
    }SECTION("pre_iter2") {
        pre_iter2(head, func2);
        CHECK_THAT(res, Equals(last));
    }SECTION("pre_iter3") {
        pre_iter3(head, func2);
        CHECK_THAT(res, Equals(last));
    }
    INFO("pre order finish");
    SECTION("in_rec") {
        count++;
        in_rec(head, func2);
    }SECTION("in_iter") {
        in_iter(head, func2);
        CHECK_THAT(res, Equals(last));
    }SECTION("in_iter2") {
        in_iter2(head, func2);
        CHECK_THAT(res, Equals(last));
    }
    INFO("in order finish");
    SECTION("post_iter") {
        count++;
        post_iter(head, func2);
    }SECTION("post_rec") {
        post_rec(head, func2);
        CHECK_THAT(res, Equals(last));
    }
    std::copy(std::begin(res), std::end(res), std::begin(last));
    std::copy(std::begin(res), std::end(res), std::ostream_iterator<int>{std::cout, " "});
    std::for_each(std::begin(numvec), std::end(numvec), [](TreeNode<int32_t> *node) { delete node; });
    cout << name[count] << end;
    res.clear();
}