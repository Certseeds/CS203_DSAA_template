// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1261_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1261_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <memory>

namespace leetcode_1261 {
using TreeNode = TREE_NODE::TreeNode<int32_t>;

constexpr const auto junk{-1};

class findElements {
public:
    [[nodiscard]] virtual bool find(int target) const = 0;

    virtual ~findElements() = default;
};

std::unique_ptr<findElements> init(TreeNode *root);

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1 [test_1261]", "[test_1261]") {
    const TreeNodeLink input{
            junk,
            TreeNode::No, junk,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
    };
    const auto tree{init(input[0])};
    CHECK(tree->find(0));
    CHECK_FALSE(tree->find(1));
    CHECK(tree->find(2));
    CHECK_FALSE(tree->find(3));
    CHECK_FALSE(tree->find(4));
}

TEST_CASE("test_case 2 [test_1261]", "[test_1261]") {
    const TreeNodeLink input{
            junk,
            junk, junk,
            junk, junk, TreeNode::No, TreeNode::No,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
            TreeNode::No,
    };
    const auto tree{init(input[0])};
    CHECK(tree->find(0));
    CHECK(tree->find(1));
    CHECK(tree->find(2));
    CHECK(tree->find(3));
    CHECK(tree->find(4));
    CHECK_FALSE(tree->find(5));
    CHECK_FALSE(tree->find(6));
    CHECK_FALSE(tree->find(7));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1261_TEST_HPP
