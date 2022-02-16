/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanoseeds

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_26_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_26_HPP

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
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_26_HPP
