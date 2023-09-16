// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1367_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1367_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <list/listnode.hpp>

namespace leetcode_1367 {
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using LISTNODE::ListNode;
using LISTNODE::ListNodeLink;

namespace leetcode_1367 {
bool isSubPath(ListNode *head, TreeNode *root);
}

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1 [test_1367]", "[test_1367]") {
    const ListNodeLink vec1{4, 2, 8};
    const TreeNodeLink vec2{
            1,
            4, 4,
            TreeNode::No, 2, 2, TreeNode::No,
            TreeNode::No, TreeNode::No, 1, TreeNode::No, 6, 8, TreeNode::No, TreeNode::No,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, \
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 1, 3
    };
    CHECK(leetcode_1367::isSubPath(vec1[0], vec2[0]));
}

TEST_CASE("test_case 2 [test_1367]", "[test_1367]") {
    const ListNodeLink vec1{1, 4, 2, 6};
    const TreeNodeLink vec2{
            1,
            4, 4,
            TreeNode::No, 2, 2, TreeNode::No,
            TreeNode::No, TreeNode::No, 1, TreeNode::No, 6, 8, TreeNode::No, TreeNode::No,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, \
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 1, 3
    };
    CHECK(leetcode_1367::isSubPath(vec1[0], vec2[0]));
}


TEST_CASE("test_case 3 [test_1367]", "[test_1367]") {
    const ListNodeLink vec1{1, 4, 2, 6, 8};
    const TreeNodeLink vec2{
            1,
            4, 4,
            TreeNode::No, 2, 2, TreeNode::No,
            TreeNode::No, TreeNode::No, 1, TreeNode::No, 6, 8, TreeNode::No, TreeNode::No,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, \
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 1, 3
    };
    CHECK_FALSE(leetcode_1367::isSubPath(vec1[0], vec2[0]));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1367_TEST_HPP
