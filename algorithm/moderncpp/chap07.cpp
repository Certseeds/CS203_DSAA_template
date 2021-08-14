/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanos
 * @Date: 2021-06-13 20:15:43
 * @LastEditors: nanos
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

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
#include <atomic>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>


namespace moderncpp::chap07 {
using std::cout, std::thread;

class ThreadPool {
private:
    int max{0};
public:
    explicit ThreadPool(int32_t v);

    // enqueue new thread task
    template<typename F, typename ... Args>
    decltype(auto) enqueue(F &&f, Args &&... args);

    // destroy thread pool and all created threads
    ~ThreadPool() = default;
};

ThreadPool::ThreadPool(int32_t v) : max(v) {}

static int value = 0, value3 = 100;

void main2() {
    static std::mutex mtx{};
    std::lock_guard<std::mutex> lock{mtx};  // if without this line , maybe output is 0,1,0,2
    std::cout << value << std::endl;
    value += 1;
    std::cout << value << std::endl;
}

void main3() {
    static std::mutex mtx{};
    std::unique_lock<std::mutex> lock{mtx};  // if without this line , maybe output is 0,1,0,2
    std::cout << value3 << std::endl;
    value3 += 1;
    std::cout << value3 << std::endl;
    lock.unlock();
    std::cout << value3 << std::endl;
    value3 += 1;
    std::cout << value3 << std::endl;
}


int main() {
    std::thread t{[]() {
        std::cout << "hello world." << std::endl;
        std::cout << std::this_thread::get_id() << std::endl;
    }};
    t.join();
    std::thread t2{main2}, t3{main2};
    t3.join();
    t2.join();
    std::thread t4{main3}, t5{main3};
    t5.join();
    t4.join();
    return 0;
}
}

int main() {
    return moderncpp::chap07::main();
}