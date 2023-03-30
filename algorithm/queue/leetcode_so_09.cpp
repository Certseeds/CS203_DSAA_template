// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_so_09_test.hpp"
#include <stack>

namespace leetcode_so_09 {
using std::stack;

struct StackQueue : CQueue {
private:
    stack<int32_t> sta1, sta2;
public:
    StackQueue() : CQueue() {};

    void appendTail(int32_t value) override {
        sta1.push(value);
    }

    int deleteHead() override {
        while (!sta1.empty()) {
            sta2.push(sta1.top());
            sta1.pop();
        }
        if (sta2.empty()) {
            return -1;
        }
        const auto top = sta2.top();
        sta2.pop();
        while (!sta2.empty()) {
            sta1.push(sta2.top());
            sta2.pop();
        }
        return top;
    }
};

struct StackQueue2 : CQueue {
private:
    stack<int32_t> sta1, sta2;
public:
    StackQueue2() : CQueue() {};

    void appendTail(int32_t value) override {
        sta1.push(value);
    }

    int deleteHead() override {
        if (sta2.empty()) {
            if (sta1.empty()) {
                return -1;
            } else {
                while (!sta1.empty()) {
                    sta2.push(sta1.top());
                    sta1.pop();
                }
            }
        }
        const auto top = sta2.top();
        sta2.pop();
        while (!sta2.empty()) {
            sta1.push(sta2.top());
            sta2.pop();
        }
        return top;
    }
};

CQueue *leetcode_so_09::pure() {
    return new StackQueue();
}

CQueue *leetcode_so_09::effective() {
    return new StackQueue2();
}

}
