// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_814_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_814_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_814 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_814 final {
    static TreeNode *pruneTree(TreeNode *root);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_814]", "[test_814]") {
    const TreeNodeLink input{1,
                             TreeNode::No, 0,
                             TreeNode::No, TreeNode::No, 0, 1
    };
    const vector<int32_t> result{1,
                                 TreeNode::No, 0,
                                 TreeNode::No, 1, TreeNode::No, TreeNode::No // 这里是一处缺陷,两个TreeNode::No本应在左边
    };
    const auto output = leetcode_814::pruneTree(input[0]);
    CHECK(TREE_NODE::judge_equal(output, result));
}
TEST_CASE("test_case 2 [test_814]", "[test_814]") {
    const TreeNodeLink input{1,
                             0, 0,
                             0, 0, 0, 1
    };
    const vector<int32_t> result{1,
                                 TreeNode::No, 0,
                                 TreeNode::No, 1, TreeNode::No, TreeNode::No // 这里是一处缺陷,两个TreeNode::No本应在左边
    };
    const auto output = leetcode_814::pruneTree(input[0]);
    CHECK(TREE_NODE::judge_equal(output, result));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_814_TEST_HPP
