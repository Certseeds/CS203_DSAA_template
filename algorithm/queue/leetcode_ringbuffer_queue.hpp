// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2024 nanoseeds

*/

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_RINGBUFFER_QUEUE_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_RINGBUFFER_QUEUE_HPP

#include <catch_main.hpp>

#include <optional>
#include <cstdint>
#include <queue>

namespace rbqueue {

class ringbuffer_queue {
private:
    std::vector<int32_t> vec;
    size_t read{0}, write{0};
    size_t csize{};
public:
    explicit ringbuffer_queue(size_t size);

    bool isFull() const;

    bool isEmpty() const;

    void push(int32_t value);

    void pop();

    int32_t front();
};

TEST_CASE("test case pure-1 [test_rbqueue_09]", "[test_rbqueue_09]") {
    ringbuffer_queue rbq(3);
    CHECK(rbq.isEmpty());
    rbq.push(1);
    CHECK_FALSE(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 1);
    CHECK(rbq.front() == 1);
    rbq.push(2);
    CHECK_FALSE(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 1);
    rbq.push(3);
    CHECK_FALSE(rbq.isEmpty());
    CHECK(rbq.isFull());
    CHECK(rbq.front() == 1);
    rbq.pop();
    CHECK_FALSE(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 2);
    rbq.pop();
    CHECK_FALSE(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 3);
    rbq.pop();

    CHECK(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    rbq.push(4);
    CHECK_FALSE(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 4);
    rbq.pop();
    CHECK(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 2);
    rbq.push(6);
    CHECK_FALSE(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    rbq.pop();
    CHECK(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 3);
    rbq.pop();
    CHECK(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 3);
    rbq.pop();
    CHECK(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 3);
}
}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_RINGBUFFER_QUEUE_HPP
