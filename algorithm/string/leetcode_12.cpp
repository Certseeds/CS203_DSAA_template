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
#include "leetcode_12_test.hpp"

namespace leetcode_12 {
string leetcode_12::intToRoman_2(int num) {
    if (num > 1000) {
        return "M" + intToRoman(num - 1000);
    } else if (num > 100) {
        static const array<string, 11> hundres = {
                "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"};
        return hundres[num / 100] + intToRoman(num % 100);
    } else if (num > 10) {
        static const array<string, 11> tens = {
                "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"};
        return tens[num / 10] + intToRoman(num % 10);
    } else if (num <= 10) {
        static const array<string, 11> ones = {
                "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
        return ones[num];
    }
    return "should reach there";
}

string leetcode_12::intToRoman(int num) {
    static const array<string, 11> hundres =
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"};
    static const array<string, 11> tens =
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"};
    static const array<string, 11> ones =
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
    string will_return = string((num / 1000), 'M');
    will_return.reserve(sizeof(char) * 16);
    num = num % 1000;
    will_return += hundres[num / 100];
    num = num % 100;
    will_return += tens[num / 10];
    num = num % 10;
    will_return += ones[num];
    return will_return;
}
}