// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Tag 单调栈

#include "leetcode_232_test.hpp"
#include <stack>

namespace leetcode_232 {
using std::stack;

class Queue : public leetcode_232::MyQueue {
private:
    stack<int32_t> sta1{}, sta2{};
public:
    Queue() = default;

    void push(int x) override {
        sta1.push(x);
    }

    int pop() override {
        const auto head = this->peek();
        sta2.pop();
        return head;
    }

    int peek() override {
        if (sta2.empty()) {
            while (!sta1.empty()) {
                sta2.push(sta1.top());
                sta1.pop();
            }
        }
        return sta2.top();
    }

    bool empty() const override { return sta1.empty() && sta2.empty(); }
};

leetcode_232::MyQueue *leetcode_232::pure() {
    return new Queue();
}


}
