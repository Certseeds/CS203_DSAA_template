/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_100_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_100_HPP

#include <catch_main.hpp>
#include <tree/TreeNode.hpp>
#include <tree/TreeNodeLink.hpp>
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
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_100_HPP
