/*
MIT License

CS203_DSAA_template

Copyright (C) 2022 nanoseeds

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
#include "leetcode_so_54_test.hpp"
#include "traverse.cpp"

namespace leetcode_so_54 {
using namespace Tree_Traverse;

int32_t leetcode_so_54::kthLargest(TreeNode *root, int32_t k) {
    vector<int32_t> countVec;
    const auto functionPre = [&countVec](const TreeNode *tn) -> void {
        countVec.push_back(tn->val);
    };
    iter::in(root, functionPre);
    const auto netElements = countVec.size();
    vector<int32_t> element;
    static size_t count{0};
    const auto function = [&element, k, netElements](const TreeNode *tn) -> void {
        ++count;
        if (count + k == netElements + 1) { element.push_back(tn->val); }
    };
    iter::in(root, function);
    count = 0;
    return element.front();
}

}