// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
//@Tag DFS
//@Tag 深度优先遍历
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_559_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_559_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode_multi.hpp>
#include <stack>

namespace leetcode_559 {

using Node = TREE_NODE::TreeNodeMulti;
using std::stack;

struct leetcode_559 {
    static int maxDepth(Node *root);
};

TEST_CASE("test_case 1 [test_559]", "[test_559]") {
    CHECK(true); // too simple
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_559_TEST_HPP
