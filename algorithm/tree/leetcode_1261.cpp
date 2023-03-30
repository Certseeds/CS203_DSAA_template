// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_1261_test.hpp"

#include <stack>

namespace leetcode_1261 {
class tree : public findElements {
private:
    TreeNode *const root;
public:
    explicit tree(TreeNode *root_) : root(root_) {
        TreeNode *node = root;
        node->val = 0;
        for (std::stack<TreeNode *> sta{{node}}; !sta.empty();) {
            TreeNode *const top = sta.top();
            sta.pop();
            if (top != nullptr) {
                if (top->left != nullptr) {
                    top->left->val = (top->val * 2) + 1;
                    sta.push(top->left);
                }
                if (top->right != nullptr) {
                    top->right->val = (top->val * 2) + 2;
                    sta.push(top->right);
                }
            }
        }
    }

    [[nodiscard]] bool find(int32_t target) const override {
        std::stack<uint8_t> sta;
        for (int32_t temp{target}; temp != 0;) {
            if (temp % 2 == 0) {
                sta.push(1); // means right
                temp = (temp - 2) / 2;
            } else {
                sta.push(0);
                temp = (temp - 1) / 2;
            }
        }
        // 15: (1,7),(1,3),(1,1),(1,0)
        // 30: (0,14),(0,6),(0,2),(0,0)
        const TreeNode *base{root};
        while (!sta.empty()) {
            const auto v = sta.top();
            sta.pop();
            if (base == nullptr) {
                return false;
            }
            if (v == 1) {
                base = base->right;
            } else {
                base = base->left;
            }
        }
        return (base != nullptr);
    }
};


std::unique_ptr<findElements> init(TreeNode *root) {
    return std::make_unique<tree>(root);
}

}
