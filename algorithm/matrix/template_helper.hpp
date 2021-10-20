/*  CS205_C_CPP
    Copyright (C) 2020  nanoseeds

    CS205_C_CPP is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    CS205_C_CPP is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */
/**
 * @Github: https://github.com/Certseeds/CS205_C_CPP
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-05-24 17:56:20
 * @LastEditors  : nanoseeds
 */
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_CS205_PROJECT_2020S_SRC_TEMPLATE_HELPER_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_CS205_PROJECT_2020S_SRC_TEMPLATE_HELPER_HPP

#include <type_traits>
#include <concepts>

using std::type_identity;
using std::is_same;
using std::is_same_v;

template<typename T>
concept is_complex = requires(T f) {
    f.real();
    f.imag();
    std::conj(f);
    f /= 1.0f;
    std::constructible_from<T, typename T::value_type, typename T::value_type>;
    std::same_as<std::complex<typename T::value_type>, T>;
};
template<typename T>
struct complex_inside : type_identity<T> {
};
template<typename T>
struct complex_inside<std::complex<T>> : type_identity<T> {
};

template<typename T>
using complex_inside_t = typename complex_inside<T>::type;

template<typename T1, typename T2>
struct Minus_Result : type_identity<decltype(std::declval<T1>() - std::declval<T2>())> {
};

template<typename T1, typename T2>
using Minus_Result_t = typename Minus_Result<T1, T2>::type;

template<typename T1, typename T2>
concept operatable = requires(T1 f1, T2 f2) {
    f1 + f2;
    f2 + f1;
    f1 - f2;
    f2 - f1;
    f1 / f2;
    f2 / f1;
    f1 * f2;
    f2 * f1;
};

template<typename T1, typename T2> requires operatable<T1, T2>
struct Add_Result : type_identity<decltype(std::declval<T1>() + std::declval<T2>())> {
};

template<typename T1, typename T2>
using Add_Result_t = typename Add_Result<T1, T2>::type;


template<typename T1, typename T2> requires operatable<T1, T2>
struct Multiply_Result : type_identity<decltype(std::declval<T1>() * std::declval<T2>())> {
};

template<typename T1, typename T2>
using Multiply_Result_t = typename Multiply_Result<T1, T2>::type;

template<typename T1>
using divide_t = decltype(std::declval<T1>() / std::declval<double>());


template<typename T>
concept has_conj = requires(T f) { f.conj(); };

template<typename T>
T from_char_array(unsigned char const *buffer) {
    T will_return;
    auto *dp = reinterpret_cast<unsigned char *>(&will_return);
    std::copy(buffer, buffer + sizeof(T), dp);
    return will_return;
}

// Primary template
template<typename T, typename... Us>
struct is_any_of;

// #1 匹配集合中的第一个类型
template<typename T, typename... U1_to_Un>
struct is_any_of<T, T, U1_to_Un...> : std::true_type {
};

// #2 第一个类型不匹配
template<typename T, typename U0, typename... U1_to_Un>
struct is_any_of<T, U0, U1_to_Un...> : is_any_of<T, U1_to_Un...> {
};

// #3 集合为空集
template<typename T>
struct is_any_of<T> : std::false_type {
};
template<typename T>
concept opencv_type = requires(T f) {
    1 == 1;
};
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_CS205_PROJECT_2020S_SRC_TEMPLATE_HELPER_HPP
