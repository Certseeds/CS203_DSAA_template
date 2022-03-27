// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 数据结构入门 Day13
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_700_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_700_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_700 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_700 final {
    static TreeNode *searchBST(TreeNode *root, int32_t val);

    static TreeNode *searchBSTiter(TreeNode *root, int32_t val);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_700]", "[test_700]") {
    const TreeNodeLink input{4,
                             2, 7,
                             1, 3, TreeNode::No, TreeNode::No,
                             TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
    };
    static constexpr const auto search{2};
    CHECK(search == leetcode_700::searchBST(input[0], search)->val);
    CHECK(search == leetcode_700::searchBSTiter(input[0], search)->val);
}

TEST_CASE("test_case 2 [test_700]", "[test_700]") {
    const TreeNodeLink input{4,
                             2, 7,
                             1, 3, TreeNode::No, TreeNode::No,
                             TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
    };
    static constexpr const auto search{5};

    CHECK(nullptr == leetcode_700::searchBST(input[0], search));
    CHECK(nullptr == leetcode_700::searchBSTiter(input[0], search));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_700_TEST_HPP
