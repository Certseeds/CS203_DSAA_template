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
#include "leetcode_617_test.hpp"
#include "traverse.cpp"

namespace leetcode_617 {
using namespace Tree_Traverse;

int32_t returnValueOfNode(TreeNode *t1, TreeNode *t2) {
    int willreturn{0};
    for (const auto i: {t1, t2}) {
        if (i != nullptr) {
            willreturn += i->val;
        }
    }
    return willreturn;
}

TreeNode *mergeTreesRec(TreeNode *t1, TreeNode *t2, const std::function<void(TreeNode *)> &func) {
    if (t1 == nullptr) {
        return t2;
    } else if (t2 == nullptr) {
        return t1;
    }
    auto *const willreturn = new TreeNode{returnValueOfNode(t1, t2)};
    func(willreturn);
    //cout << willreturn->val << endl;
    willreturn->left = mergeTreesRec(t1->left, t2->left, func);
    willreturn->right = mergeTreesRec(t1->right, t2->right, func);
    return willreturn;
}

std::pair<TreeNode *, vector<TreeNode *>> leetcode_617::mergeTrees(TreeNode *t1, TreeNode *t2) {
    vector<TreeNode *> will_return{};
    const auto func = [&will_return](TreeNode *node) { will_return.push_back(node); };
    const auto result = mergeTreesRec(t1, t2, func);
    return {result, will_return};
}


}