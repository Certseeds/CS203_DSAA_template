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
//@Plan 剑指OfferII-I Day06
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_32_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_32_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_so_32 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_so_32 final {
    static vector<int32_t> levelOrderFst(TreeNode *root);

    // static vector<int> levelOrderSnd(TreeNode *root); // same with 102
    static vector<vector<int32_t>> levelOrderTrd(TreeNode *root);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1-1 [test_so_32]", "[test_so_32]") {
    const vector<int32_t> input{3,
                                9, 20,
                                TreeNode::No, TreeNode::No, 15, 7,};
    const vector<TreeNode *> numVecInput = numToTree<int32_t>(input);
    const TreeNodeLink link{numVecInput[0]};
    const vector<int32_t> results{3, 9, 20, 15, 7};
    CHECK_THAT(results, Equals(leetcode_so_32::levelOrderFst(numVecInput[0])));
}

TEST_CASE("test_case 3-1 [test_so_32]", "[test_so_32]") {
    const vector<int32_t> input{3,
                                9, 20,
                                TreeNode::No, TreeNode::No, 15, 7,};
    const vector<TreeNode *> numVecInput = numToTree<int32_t>(input);
    const TreeNodeLink link{numVecInput[0]};
    const vector<vector<int32_t>> results{{3},
                                          {20, 9},
                                          {15, 7}};
    CHECK_THAT(results, Equals(leetcode_so_32::levelOrderTrd(numVecInput[0])));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_32_TEST_HPP
