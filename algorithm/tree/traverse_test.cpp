/*
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2020-07-30 10:30:53
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-30 18:18:53
 */
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

#include "traverse.cpp"

namespace Tree_Traverse {

TEST_CASE("traverse basic", "[tree traverse]") {
    static constexpr const std::array<const char *const, 4> name{"", "pre order", "in order", "post order"};
    static constexpr const int32_t tree_nodes{32};
    static int32_t count = 0;
    vector<int32_t> vec(tree_nodes);
    std::iota(vec.begin(), vec.end(), 0);
    vector<TreeNode *> numvec = TREE_NODE::numToTree<int32_t>(vec);
    const TreeNode *head = numvec[0];
    static vector<int32_t> last(tree_nodes);
    vector<int32_t> res;
    auto func2 = [&res](const TreeNode *tn) -> void { res.push_back(tn->val); };
    SECTION("pre_rec") {
        count++;
        rec::pre(head, func2);
    }SECTION("iter::pre1") {
        iter::pre1(head, func2);
        CHECK_THAT(res, Equals(last));
    }SECTION("pre_iter2") {
        iter::pre2(head, func2);
        CHECK_THAT(res, Equals(last));
    }SECTION("pre_iter3") {
        iter::pre3(head, func2);
        CHECK_THAT(res, Equals(last));
    }
    INFO("pre order finish");
    SECTION("in_rec") {
        count++;
        rec::in(head, func2);
    }SECTION("in_iter") {
        iter::in(head, func2);
        CHECK_THAT(res, Equals(last));
    }SECTION("in_iter2") {
        iter::in2(head, func2);
        CHECK_THAT(res, Equals(last));
    }
    INFO("in order finish");
    SECTION("post_iter") {
        count++;
        iter::post(head, func2);
    }SECTION("post_rec") {
        rec::post(head, func2);
        CHECK_THAT(res, Equals(last));
    }
    std::copy(std::begin(res), std::end(res), std::begin(last));
    std::copy(std::begin(res), std::end(res), std::ostream_iterator<int>{std::cout, " "});
    std::for_each(std::begin(numvec), std::end(numvec), [](TreeNode *node) { delete node; });
    cout << name[count] << end;
    res.clear();
}
}