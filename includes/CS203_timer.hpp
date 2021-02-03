/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-15 21:42:36
 * @LastEditors: nanoseeds
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021 nanoseeds

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
#ifndef CS203_DSAA_TEMPLATE_INCLUDES_CS203_TIMER_H
#define CS203_DSAA_TEMPLATE_INCLUDES_CS203_TIMER_H

#include <iostream>
#include <chrono>

std::chrono::milliseconds get_ms() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch());
}

class CS203_timer {
private:
    std::chrono::milliseconds ms{get_ms()};
public:
    CS203_timer() = default;

    CS203_timer(const CS203_timer &timer) = delete;

    CS203_timer(CS203_timer &&timer) = delete;

    CS203_timer &operator=(const CS203_timer &timer) = delete;

    CS203_timer &operator=(CS203_timer &&mat) = delete;

    ~CS203_timer() {
        std::cout << "cost " << get_ms().count() - ms.count() << " ms\n";
    }

};

#endif //CS203_DSAA_TEMPLATE_INCLUDES_CS203_TIMER_H
