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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_653_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_653_HPP

#include <catch_main.hpp>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>


namespace leetcode_653 {

using TreeNode = TREE_NODE::TreeNode<int32_t>;
using TREE_NODE::numToTree;

struct leetcode_653 final {
    static TreeNode *lowestCommonAncestor(TreeNode *root, const TreeNode *p, const TreeNode *q);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_653]", "[test_653]") {
    const vector<int32_t> input{6,
                                2, 8,
                                0, 4, 7, 9,
                                TreeNode::No, TreeNode::No, 3, 5, TreeNode::No, TreeNode::No, TreeNode::No,
                                TreeNode::No,
    };
    vector<TreeNode *> numVecInput = numToTree<int32_t>(input);
    const TreeNodeLink link{numVecInput.front()};
    auto *const p = new TreeNode(2);
    auto *const q = new TreeNode(8);
    const TreeNodeLink link2{p}, link3{q};
    static constexpr const auto result{6};
    CHECK(result == leetcode_653::lowestCommonAncestor(numVecInput.front(), p, q)->val);
}

TEST_CASE("test_case 2 [test_653]", "[test_653]") {
    const vector<int32_t> input{6,
                                2, 8,
                                0, 4, 7, 9,
                                TreeNode::No, TreeNode::No, 3, 5, TreeNode::No, TreeNode::No, TreeNode::No,
                                TreeNode::No,
    };
    vector<TreeNode *> numVecInput = numToTree<int32_t>(input);
    const TreeNodeLink link{numVecInput.front()};
    auto *const p = new TreeNode(2);
    auto *const q = new TreeNode(4);
    const TreeNodeLink link2{p}, link3{q};
    static constexpr const auto result{2};
    CHECK(result == leetcode_653::lowestCommonAncestor(numVecInput.front(), p, q)->val);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_653_HPP
