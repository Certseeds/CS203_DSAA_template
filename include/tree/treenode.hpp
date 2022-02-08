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
#ifndef CS203_DSAA_TEMPLATE_INCLUDES_TREENODE_HPP
#define CS203_DSAA_TEMPLATE_INCLUDES_TREENODE_HPP

#include <tree/treenode_template.hpp>
#include <vector>
#include <queue>

namespace TREE_NODE {
using TREE_NODE_TEMP::TreeNodeTemp;
using std::vector;
using std::queue;

template<typename T>
struct TreeNode : public TreeNodeTemp<T, TreeNode> {
private:
    using base = TreeNodeTemp<T, TreeNode>;
public:
    explicit TreeNode(T x) : base(x) {}

    static constexpr const T No{static_cast<T>(-100000)};
};

template<typename T>
static void organize(vector<TreeNode<T> *> Tree) {
    size_t tree_size{Tree.size()};
    for (size_t i{0}; i < tree_size; i++) {
        if (Tree[i] != nullptr) {
            Tree[i]->left = (2 * i + 1 < tree_size) ? Tree[2 * i + 1] : nullptr;
            Tree[i]->right = (2 * i + 2 < tree_size) ? Tree[2 * i + 2] : nullptr;
        }
    }
}

template<typename T>
static vector<TreeNode<T> *> numToTree(const vector<T> &nums) {
    const auto nums_size{nums.size()};
    vector<TreeNode<T> *> will_return(nums_size, nullptr);
    for (size_t i{0}; i < nums_size; i++) {
        will_return[i] = (nums[i] != TreeNode<T>::No) ? new TreeNode<T>(nums[i]) : nullptr;
    }
    organize(will_return);
    return will_return;
}

template<typename T>
static bool judge_equal(TreeNode<T> *const root, const vector<T> &vec) {
    queue<TreeNode<T> *> que{{root}};
    vector<T> nums{};
    while (!que.empty()) {
        const TreeNode<T> *const head = que.front();
        que.pop();
        if (head == nullptr) {
            nums.push_back(TreeNode<T>::No);
            continue;
        }
        nums.push_back(head->val);
        que.push(head->left);
        que.push(head->right);
    }
    if (nums.size() != vec.size()) {
        return false;
    }
    bool will_return{true};
    for (size_t i{0}; i < nums.size(); i++) {
        will_return = will_return && (nums[i] == vec[i]);
    }
    return will_return;
}
};

#endif  //CS203_DSAA_TEMPLATE_INCLUDES_TREENODE_HPP