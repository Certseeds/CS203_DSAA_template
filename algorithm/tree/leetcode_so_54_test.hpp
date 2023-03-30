// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 剑指OfferII-I Day15
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_54_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_54_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_so_54 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_so_54 final {
    static int32_t kthLargest(TreeNode *root, int32_t k);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1 [test_so_54]", "[test_so_54]") {
    const TreeNodeLink input{3,
                             1, 4,
                             TreeNode::No, 2};
    static constexpr const auto k{1};
    static constexpr const auto output{4};
    CHECK(output == leetcode_so_54::kthLargest(input[0], k));
}

TEST_CASE("test_case 2 [test_so_54]", "[test_so_54]") {
    const TreeNodeLink input{5,
                             3, 6,
                             2, 4, TreeNode::No, TreeNode::No,
                             1};
    static constexpr const auto k{3};
    static constexpr const auto output{4};
    CHECK(output == leetcode_so_54::kthLargest(input[0], k));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_54_TEST_HPP
