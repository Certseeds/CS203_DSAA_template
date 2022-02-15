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
//@description 中序遍历

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_112_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_112_HPP

#include <catch_main.hpp>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_112 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_112 {
    static bool hasPathSum(TreeNode *root, int targetSum);
};

using Catch::Matchers::Equals;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_112]", "[test_112]") {
    const vector<int32_t> input{5,
                                4, 8,
                                11, TreeNode::No, 13, 4,
                                7, 2, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 1
    };
    static constexpr const auto target{22};
    const vector<TreeNode *> numVecInput = TREE_NODE::numToTree<int32_t>(input);
    const TreeNodeLink link{numVecInput[0]};
    CHECK(leetcode_112::hasPathSum(numVecInput[0], target));
}

TEST_CASE("test_case 2 [test_112]", "[test_112]") {
    const vector<int32_t> input{1,
                                2, 3};
    static constexpr const auto target{5};
    const vector<TreeNode *> numVecInput = TREE_NODE::numToTree<int32_t>(input);
    const TreeNodeLink link{numVecInput[0]};
    CHECK_FALSE(leetcode_112::hasPathSum(numVecInput[0], target));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_112_HPP
