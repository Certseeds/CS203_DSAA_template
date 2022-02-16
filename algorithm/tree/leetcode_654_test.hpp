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
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_654_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_654_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_654 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_654 final {
    static TreeNode *constructMaximumBinaryTree(const vector<int32_t> &nums);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_654]", "[test_654]") {
    const vector<int32_t> input{3, 2, 1, 6, 0, 5};
    const vector<int32_t> result{6,
                                 3, 5,
                                 TreeNode::No, 2, 0, TreeNode::No,
                                 TreeNode::No, 1, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No};
    auto *const resultPtr = leetcode_654::constructMaximumBinaryTree(input);
    const TreeNodeLink link{resultPtr};
    CHECK(TREE_NODE::judge_equal(resultPtr, result));
}

TEST_CASE("test_case 2 [test_654]", "[test_654]") {
    const vector<int32_t> input{3, 2, 1};
    const vector<int32_t> result{3, TreeNode::No, 2, TreeNode::No, 1, TreeNode::No, TreeNode::No};
    auto *const resultPtr = leetcode_654::constructMaximumBinaryTree(input);
    const TreeNodeLink link{resultPtr};
    CHECK(TREE_NODE::judge_equal(resultPtr, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_654_HPP
