// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2024 nanoseeds

*/

#include "leetcode_ringbuffer_queue.hpp"

namespace rbqueue {

ringbuffer_queue::ringbuffer_queue(size_t size) : vec(vector<int32_t>(size, 0)) {
    csize = size;
}

bool ringbuffer_queue::isFull() const {
    if (write - read == csize) {
        return true;
    } else if (read - write == csize) {
        return true;
    }
    return false;
}

bool ringbuffer_queue::isEmpty() const {
    return read == write; // if read == write, it must be empty
}

void ringbuffer_queue::push(int32_t value) {
    if (isFull()) {
        return;
    }
    vec[write % csize] = value;
    write = (write + 1) % (csize << 1);
}

void ringbuffer_queue::pop() {
    if (isEmpty()) {
        return;
    }
    read = (read + 1) % (csize << 1);
}

int32_t ringbuffer_queue::front() {
    return vec[read % csize];
}

}
