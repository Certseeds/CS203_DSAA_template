// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 剑指OfferII-I Day07
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_26_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_26_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_so_26 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_so_26 final {
    static bool isSubStructure(TreeNode *A, TreeNode *B);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1 [test_so_26]", "[test_so_26]") {
    const vector<int32_t> input{3, 4, 5, 1, 2}, input2{4, 1};
    const vector<TreeNode *> numVecInput = numToTree<int32_t>(input), numVecInput2 = numToTree<int32_t>(input2);
    const TreeNodeLink link{numVecInput[0]}, link2{numVecInput2[0]};
    CHECK(leetcode_so_26::isSubStructure(numVecInput.front(), numVecInput2.front()));
}

TEST_CASE("test_case 2 [test_so_26]", "[test_so_26]") {
    const vector<int32_t> input{1, 0, 1, -4, -3}, input2{1, -4};
    const vector<TreeNode *> numVecInput = numToTree<int32_t>(input), numVecInput2 = numToTree<int32_t>(input2);
    const TreeNodeLink link{numVecInput[0]}, link2{numVecInput2[0]};
    CHECK_FALSE(leetcode_so_26::isSubStructure(numVecInput.front(), numVecInput2.front()));
}

TEST_CASE("test_case 3 [test_so_26]", "[test_so_26]") {
    const vector<int32_t> input{1, 2, 3, 4}, input2{3};
    const vector<TreeNode *> numVecInput = numToTree<int32_t>(input), numVecInput2 = numToTree<int32_t>(input2);
    const TreeNodeLink link{numVecInput[0]}, link2{numVecInput2[0]};
    CHECK(leetcode_so_26::isSubStructure(numVecInput.front(), numVecInput2.front()));
}

TEST_CASE("test_case 4 [test_so_26]", "[test_so_26]") {
    const vector<int32_t> input{10, 12, 6, 8, 3, 11}, input2{10, 12, 6, 8};
    const vector<TreeNode *> numVecInput = numToTree<int32_t>(input), numVecInput2 = numToTree<int32_t>(input2);
    const TreeNodeLink link{numVecInput[0]}, link2{numVecInput2[0]};
    CHECK(leetcode_so_26::isSubStructure(numVecInput.front(), numVecInput2.front()));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_26_TEST_HPP
