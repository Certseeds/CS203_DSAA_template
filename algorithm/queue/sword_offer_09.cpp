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
#include "sword_offer_09_test.hpp"

namespace sword_offer_09 {
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

CQueue *sword_offer_09::pure() {
    return new StackQueue();
}

CQueue *sword_offer_09::effective() {
    return new StackQueue2();
}

}