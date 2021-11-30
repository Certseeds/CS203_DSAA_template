//
// Created by nanos on 2021/11/30.
//

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
    // 使用 delete 关键字禁止编译器自动产生复制构造函数和复制赋值操作符。
    nonmoveable(nonmoveable &&) = delete;

    const nonmoveable &operator=(nonmoveable &&) = delete;
};

class nonCopyMoveAble : private noncopyable, nonmoveable {
};

#endif //CS203_DSAA_TEMPLATE_INCLUDE_CLASS_HELPER_NONABLE_HPP
