// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_589_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_589_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode_multi.hpp>
#include <stack>

namespace leetcode_589 {

using Node = TREE_NODE::TreeNodeMulti;
using std::stack;

struct leetcode_589 final {
    static vector<int32_t> preorder(const Node *root);

    static vector<int32_t> preorderIter(const Node *root);
};

TEST_CASE("test_case 1 [test_589]", "[test_589]") {
    CHECK(true); // too simple
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_589_TEST_HPP
