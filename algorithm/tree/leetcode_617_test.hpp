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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_617_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_617_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_617 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_617 final {
    static std::pair<TreeNode *, vector<TreeNode *>> mergeTrees(TreeNode *root1, TreeNode *root2);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_617]", "[test_617]") {
    const vector<int32_t> input1{1, 3, 2, 5, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
                                 TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No};
    const vector<int32_t> input2{2, 1, 3, TreeNode::No, 4, TreeNode::No, 7, TreeNode::No, TreeNode::No, TreeNode::No,
                                 TreeNode::No, TreeNode::No, TreeNode::No};
    const vector<int32_t> result{3, 4, 5, 5, 4, TreeNode::No, 7, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
                                 TreeNode::No, TreeNode::No};
    const vector<TreeNode *> numVecInput = numToTree<int32_t>(input1), numVecInput2 = numToTree<int32_t>(input2);
    const TreeNodeLink link{numVecInput}, link2{numVecInput2};
    const auto[resultPtr, resultNodes] = leetcode_617::mergeTrees(numVecInput[0], numVecInput2[0]);
    CHECK(TREE_NODE::judge_equal(resultPtr, result));
    const TreeNodeLink link3{resultNodes};
// 内存不太好管理,停掉测试
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_617_TEST_HPP
