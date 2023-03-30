// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_965_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_965_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>

namespace leetcode_965 {
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_965 final {
    static bool isUnivalTreeRec(TreeNode *root);

    static bool isUnivalTreeIter(TreeNode *root);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_965]", "[test_965]") {
    const TreeNodeLink input{
            1,
            1, 1,
            1, 1, TreeNode::No, 2
    };
    CHECK_FALSE(leetcode_965::isUnivalTreeRec(input[0]));
    CHECK_FALSE(leetcode_965::isUnivalTreeIter(input[0]));
}

TEST_CASE("test_case 2 [test_965]", "[test_965]") {
    const TreeNodeLink input{
            1,
            1, 1,
            1, 1, 1, 1,
            1, TreeNode::No, 1
    };
    CHECK(leetcode_965::isUnivalTreeRec(input[0]));
    CHECK(leetcode_965::isUnivalTreeIter(input[0]));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_965_TEST_HPP
