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
#include "leetcode_so_30_test.hpp"

namespace leetcode_so_30 {
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