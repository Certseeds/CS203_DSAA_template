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
#include <catch_main.hpp>
#include <string>
#include <utility>

using std::string;

struct TextBlock {
    const char &operator[](std::size_t position) const {
        std::cout << "invoke const []" << std::endl;
        return text[position];
    }

    char &operator[](size_t position) {
        std::cout << "invoke normal []" << std::endl;
        return text[position];
    }

    const char &operator()(std::size_t position) const {
        std::cout << "invoke const ()" << std::endl;
        return text[position];
    }

    char &operator()(size_t position) {
        std::cout << "invoke normal ()" << std::endl;
        return const_cast<char &>(
                static_cast<const TextBlock &>(*this)(position)
        );
    }
    explicit TextBlock(string text) : text(std::move(text)) {}

private:
    string text;
};

static void print(const TextBlock &ctb) {
    ctb[0];
}

int main() {
    TextBlock tb{"tb"};
    const TextBlock ctb{"tb2"};
    tb[0];
    ctb[0];
    print(ctb);
    tb[0] = '?'; // can
    // ctb[0] ='?'; // can not compile
    ctb(0);
    tb(0)='?'; // can compile
}
