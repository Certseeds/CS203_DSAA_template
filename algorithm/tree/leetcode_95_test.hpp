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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_95_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_95_HPP

#include <catch_main.hpp>
#include <tree/TreeNode.hpp>
#include <tree/TreeNodeLink.hpp>
#include <vector>

namespace leetcode_95 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using Catch::Matchers::Equals;
struct leetcode_95 {
    static vector<TreeNode *> generateTrees(int32_t n);
};
TEST_CASE("test_case 1 [test_95]", "[test_95]") {
    const auto three = leetcode_95::generateTrees(0);
    CHECK_THAT(three, Equals<TreeNode *>({}));
    const TreeNodeLink link1{three};
}

TEST_CASE("test_case 2 [test_95]", "[test_95]") {
    const vector<vector<int32_t>> result{
            {1, TreeNode::No, 2,  TreeNode::No, 3,  TreeNode::No, TreeNode::No},
            {1, TreeNode::No, 3,  2,  TreeNode::No, TreeNode::No, TreeNode::No},
            {2, 1,  3,  TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No},
            {3, 1,  TreeNode::No, TreeNode::No, 2,  TreeNode::No, TreeNode::No},
            {3, 2,  TreeNode::No, 1,  TreeNode::No, TreeNode::No, TreeNode::No},
    };
    const auto three = leetcode_95::generateTrees(3);
    CHECK(three.size() == 5);
    for (int32_t i{0}; i < 5; ++i) {
        CHECK(TREE_NODE::judge_equal(three[i], result[i]));
    }
    const TreeNodeLink link1{three};
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_95_HPP
