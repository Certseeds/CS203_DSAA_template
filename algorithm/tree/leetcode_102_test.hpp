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
//@Tag tree
//@Tag 树
//@Sword-Offer 32-II
//@Plan 数据结构入门 Day11

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_102_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_102_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_102 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using TREE_NODE::numToTree;

struct leetcode_102 {
    static vector<vector<int>> levelOrder(TreeNode *root);
};

using Catch::Matchers::Equals;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_102]", "[test_102]") {
    const vector<int32_t> vec{3,
                              9, 20,
                              TreeNode::No, TreeNode::No, 15, 7};
    const vector<vector<int32_t>> result{{3},
                                         {9,  20},
                                         {15, 7}};
    vector<TreeNode *> numvec = numToTree<int32_t>(vec);
    const TreeNodeLink link{numvec[0]};
    CHECK_THAT(result, Equals(leetcode_102::levelOrder(numvec[0])));
}

TEST_CASE("test_case 2 [test_102]", "[test_102]") {
    const vector<int32_t> vec{1};
    const vector<vector<int32_t>> result{{1},};
    vector<TreeNode *> numvec = numToTree<int32_t>(vec);
    const TreeNodeLink link{numvec[0]};
    CHECK_THAT(result, Equals(leetcode_102::levelOrder(numvec[0])));
}

TEST_CASE("test_case 3 [test_102]", "[test_102]") {
    const vector<vector<int32_t>> result{};
    CHECK_THAT(result, Equals(leetcode_102::levelOrder(nullptr)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_102_TEST_HPP
