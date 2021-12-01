/*
MIT License

CS203_DSAA_template

Copyright (C) 2021  nanoseeds

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

#ifndef CS203_DSAA_TEMPLATE_INCLUDE_CLASS_HELPER_NONABLE_HPP
#define CS203_DSAA_TEMPLATE_INCLUDE_CLASS_HELPER_NONABLE_HPP

class noncopyable {
protected:
    // 默认的构造函数和析构函数是 protected，
    // 不允许创建 noncopyable 实例，但允许子类创建实例
    // （即允许派生类构造和析构）。
    noncopyable() = default;

    ~noncopyable() = default;

private:
    // 使用 delete 关键字禁止编译器自动产生复制构造函数和复制赋值操作符。
    noncopyable(const noncopyable &) = delete;

    const noncopyable &operator=(const noncopyable &) = delete;
};

class nonmoveable {
protected:
    nonmoveable() = default;

    ~nonmoveable() = default;

private:
    nonmoveable(nonmoveable &&) = delete;

    const nonmoveable &operator=(nonmoveable &&) = delete;
};

class nonCopyMoveAble : private noncopyable, nonmoveable {
protected:
    nonCopyMoveAble() = default;

    ~nonCopyMoveAble() = default;

public:
};

#endif //CS203_DSAA_TEMPLATE_INCLUDE_CLASS_HELPER_NONABLE_HPP
