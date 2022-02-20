/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanoseeds

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