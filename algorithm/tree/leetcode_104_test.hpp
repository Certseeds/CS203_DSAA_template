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
//@Tag tree
//@Tag 树
//@Plan 数据结构入门 Day11
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_104_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_104_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <stack>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>

namespace leetcode_104 {

using std::stack;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

struct leetcode_104 {
    static int32_t maxDepth(TreeNode *root);
};

TEST_CASE("test_case 1 [test_104]", "[test_104]") {
    const vector<int32_t> vec{3, 9, 20, TreeNode::No, TreeNode::No, 15, 7};
    static constexpr const auto result{3};
    vector<TreeNode *> numVec = numToTree<int32_t>(vec);
    CHECK(result == leetcode_104::maxDepth(numVec[0]));
    const TreeNodeLink link{numVec[0]};
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_104_TEST_HPP
