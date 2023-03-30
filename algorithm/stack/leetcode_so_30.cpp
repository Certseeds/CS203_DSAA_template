// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_so_30_test.hpp"
#include <stack>

namespace leetcode_so_30 {
using std::stack;

struct MinStackPure : MinStack {
private:
    stack<int32_t> sta1, sta2;
public:
    MinStackPure() : MinStack() {};

    void push(int x) override final {
        sta1.push(x);
        if (sta2.empty()) {
            sta2.push(x);
        } else {
            const auto minV = std::min(x, sta2.top());
            sta2.push(minV);
        }
    }

    void pop() override final {
        sta1.pop();
        sta2.pop();
    }

    int top() override final {
        return sta1.top();
    }

    int min() override final {
        return sta2.top();
    }
};

struct MinStackEffective : MinStack {
private:
    stack<int32_t> sta1, sta2;
public:
    MinStackEffective() : MinStack() {};

    void push(int x) final {
        if (sta2.empty()) {
            sta2.push(x);
        } else {
            if (sta2.top() >= x) {
                sta2.push(x);
            }
        }
        sta1.push(x);
    }

    void pop() final {
        if (sta1.empty()) {
            return;
        }
        const auto top = this->top();
        sta1.pop();
        if (!sta2.empty() && top == this->min()) {
            sta2.pop();
        }
    }

    int top() final {
        return sta1.top();
    }

    int min() final {
        return sta2.top();
    }
};

MinStack *leetcode_so_30::pure() {
    return new MinStackPure();
}

MinStack *leetcode_so_30::effective() {
    return new MinStackEffective();
}

}
