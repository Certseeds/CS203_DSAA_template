// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_100_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_100_TEST_HPP

#include <catch_main.hpp>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_100 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

struct leetcode_100 {
    static bool isSameTree(TreeNode *p, TreeNode *q);
};

TEST_CASE("test_case 1 [test_100]", "[test_100]") {
    const vector<int32_t> vec{1, 2};
    const vector<int32_t> vec2{1, TreeNode::No, 2};
    vector<TreeNode *> numvec = numToTree<int32_t>(vec);
    vector<TreeNode *> numvec2 = numToTree<int32_t>(vec2);
    CHECK_FALSE(leetcode_100::isSameTree(numvec[0], numvec2[0]));
    const TreeNodeLink link{numvec[0]};
    const TreeNodeLink link2{numvec2[0]};
}

TEST_CASE("test_case 2 [test_100]", "[test_100]") {
    const vector<int32_t> vec{1, 2, 3};
    const vector<int32_t> vec2{1, 2, 3};
    vector<TreeNode *> numvec = numToTree<int32_t>(vec);
    vector<TreeNode *> numvec2 = numToTree<int32_t>(vec2);
    CHECK(leetcode_100::isSameTree(numvec[0], numvec2[0]));
    const TreeNodeLink link{numvec[0]};
    const TreeNodeLink link2{numvec2[0]};
}

TEST_CASE("test_case 3 [test_100]", "[test_100]") {
    const vector<int32_t> vec{1, 2, 1};
    const vector<int32_t> vec2{1, 1, 2};
    vector<TreeNode *> numvec = numToTree<int32_t>(vec);
    vector<TreeNode *> numvec2 = numToTree<int32_t>(vec2);
    CHECK_FALSE(leetcode_100::isSameTree(numvec[0], numvec2[0]));
    const TreeNodeLink link{numvec[0]};
    const TreeNodeLink link2{numvec2[0]};
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_100_TEST_HPP
