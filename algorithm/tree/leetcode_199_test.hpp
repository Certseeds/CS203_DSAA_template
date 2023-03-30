// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag tree
//@Tag 树
//@description 层序遍历

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_199_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_199_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_199 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_199 {
    static vector<int> rightSideView(const TreeNode *root);
};

using Catch::Matchers::Equals;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_199]", "[test_199]") {
    const TreeNodeLink input{1,
                                1, 4,
                                5, 1, TreeNode::No, 4,
                                1, TreeNode::No, 9
    };
    const vector<int32_t> result{1, 4, 4, 9};
    CHECK_THAT(result, Equals(leetcode_199::rightSideView(input[0])));
}

TEST_CASE("test_case 2 [test_199]", "[test_199]") {
    const vector<int32_t> result{};
    CHECK_THAT(result, Equals(leetcode_199::rightSideView(nullptr)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_199_TEST_HPP
