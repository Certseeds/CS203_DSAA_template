<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-04-27 23:07:31
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-07-02 20:54:12
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

# CS205 C/C++ Assignment5

**环境**:WSL_1,gcc version 7.5.0 (Ubuntu 7.5.0-3,ubuntu1~18.04),C++17,Catch v2.12.1.

## Part 1 - Analysis

1. 函数整体存储的就是一个string,其他的方法都由string的方法配合utf8.h去完成,所以要把内部的string设置为private.
2. 因为涉及到使用`replace(const char* c1,const char* c2)`->`replace(const UTF8string& s1,const UTF8string& s2)`
   的隐式转换,所以不能在构造函数前加`explicit`.
3. 因为不涉及到复制构造函数和移动赋值符,所以显式禁止使用.
4. 重载`<<`要返回ostream.
5. 重载-/要添加足够的const,同时不能返回&.
6. 重载`*`要考虑到顺序问题,`int*UTF8string`和`UTF8string*int`都要考虑.
7. 重载+=要注意修改原值.
8. 重载!也不能修改原值.

## Part 2 - Code

1. `UTF8string.hpp`

``` cpp
#ifndef CS205_C_CPP_ASSIGNMENT_5_SRC_UTF8STRING_HPP
#define CS205_C_CPP_ASSIGNMENT_5_SRC_UTF8STRING_HPP
#include "utf8.h"
#ifdef __cplusplus
extern "C" {
#endif
extern int utf8_charlen(unsigned char *p);
extern int utf8_bytes_to_charpos(unsigned char *s, int pos);
// extern ...
#ifdef __cplusplus
}
#endif
#include <iostream>
#include <string>
#include <vector>
using std::string;
class UTF8string {
private:
    string str;
public:
    const string & get_str() const;
    // Constructor
    // if add explicit ,need use .replace(UTF8string("1"),UTF8string("2"))
    UTF8string(const char *ch);
    // 拷贝构造函数 Copy Constructor
    UTF8string(const UTF8string &s);
    //Copy Assignment operator
    UTF8string &operator=(const UTF8string &) = delete;
    //Move Assignment operator
    UTF8string &operator=(UTF8string &&data) = delete;
    int32_t length();
    int32_t bytes();
    int32_t find(const string &substr);
    int32_t replace(const UTF8string &to_remove, const UTF8string &replacement);
    UTF8string operator+(const UTF8string &str1) const;
    UTF8string operator*(int32_t times);
    friend UTF8string operator*(int32_t times,UTF8string &str);
    UTF8string &operator+=(const UTF8string &str1);
    friend std::ostream &operator<<(std::ostream &output, const UTF8string &str);
    UTF8string operator!();
};
#endif //CS205_C_CPP_ASSIGNMENT_5_SRC_UTF8STRING_HPP
```

2. `UTF8string.cpp`

``` cpp
#include "UTF8string.hpp"
// Constructor
UTF8string::UTF8string(const char *ch) {
    this->str = string(ch);
}
// 拷贝构造函数 Copy Constructor
UTF8string::UTF8string(const UTF8string &s) {
    this->str = string(s.str);
}
// return bytes
int32_t UTF8string::bytes() {
    return str.size();
}
// use
int32_t UTF8string::length() {
    const int32_t will_return = 0;
    int32_t bytes_in_char = 0;
    for (uint32_t i = 0; i < str.size(); i += bytes_in_char) {
        utf8_to_codepoint(reinterpret_cast<const unsigned char *>(&str[i]), &bytes_in_char);
        will_return++;
        //  强制类型转换,search and count
    }
    return will_return;
}
int32_t UTF8string::find(const string &sub_str) {
    const int32_t will_return = 0;
    int32_t bytes_in_char = 0;
    for (uint32_t i = 0; i <= str.size() - sub_str.size(); i += bytes_in_char) {
        utf8_to_codepoint(reinterpret_cast<const unsigned char *>(&str[i]), &bytes_in_char);
        if (str.substr(i, sub_str.size()) == sub_str) {
            return will_return;
        }
        will_return++;
        //  强制类型转换,search and count
    }
    return -1;
}
int32_t UTF8string::replace(const UTF8string &to_remove, const UTF8string &replacement) {
    int32_t bytes_in_char = 0;
    std::vector<int32_t> positions;
    for (uint32_t i = 0; i <= str.size() - to_remove.str.size(); i += bytes_in_char) {
        utf8_to_codepoint(reinterpret_cast<const unsigned char *>(&str[i]), &bytes_in_char);
        if (str.substr(i, to_remove.str.size()) == to_remove.str) {
            positions.push_back(i);
        }
        //  强制类型转换,search and count
    }
    for (auto it = positions.rbegin(); it != positions.rend(); ++it) {
        this->str.replace(*it, to_remove.str.size(), replacement.str);
    }//逆序遍历
    // return 0 replace成功,return 1,不成功.
    return !positions.empty();
}
std::ostream &operator<<(std::ostream &output, const UTF8string &str) {
    output << str.str;
    return output;
}
UTF8string UTF8string::operator+(const UTF8string &str1) const {
    UTF8string will_return(this->str.c_str());
    will_return.str.append(str1.str);
    return will_return;
}
UTF8string &UTF8string::operator+=(const UTF8string &str1) {
    this->str.append(str1.str);
    return (*this);
}
UTF8string UTF8string::operator*(int32_t times) {
    UTF8string will_return("");
    string temp = this->str;
    for (int32_t i = 0; i < times; ++i) {
        will_return.str.append(temp);
    }
    return will_return;
}
UTF8string operator*(int32_t times,UTF8string &str) {
    return str * times;
}
UTF8string UTF8string::operator!() {
    UTF8string will_return("");
    std::vector<std::pair<int32_t, int32_t>> positions;
    int32_t bytes_in_char = 0;
    for (uint32_t i = 0; i < str.size(); i += bytes_in_char) {
        utf8_to_codepoint(reinterpret_cast<const unsigned char *>(&str[i]), &bytes_in_char);
        positions.emplace_back(i, bytes_in_char);
        //  强制类型转换,search and count
    }
    for (auto it = positions.rbegin(); it != positions.rend(); ++it) {
        will_return.str.append(this->str.substr(it->first, it->second));
    }
    return will_return;
}
const string & UTF8string::get_str() const {
    return this->str;
}
```

3. catch_test_file.

``` cpp
#include "./catch.hpp"
#include "UTF8string.hpp"

using std::cout;
using std::endl;
using Catch::Matchers::Equals;
TEST_CASE("test1") {
    UTF8string test1 = UTF8string("Mais où sont les neiges d'antan?");
    cout << test1 << endl;
    CHECK(33 == test1.bytes());
    CHECK(32 == test1.length());
    CHECK(8 == test1.find("sont"));
    test1 += UTF8string("!!!");
    CHECK_THAT(test1.get_str(), 
            Equals("Mais où sont les neiges d'antan?!!!"));
}
TEST_CASE("test 2") {
    UTF8string test1 = UTF8string("Mais où sont les neiges d'antan?");
    UTF8string test2 = UTF8string("Всё хорошо́, что хорошо́ конча́ется");
    CHECK_THAT(test2.get_str(), 
            Equals("Всё хорошо́, что хорошо́ конча́ется"));
    test2.replace("хорошо́", "просто");
    CHECK_THAT(test2.get_str(), 
            Equals("Всё просто, что просто конча́ется"));
    CHECK_THAT((test1 + test2).get_str(),
               Equals("Mais où sont les neiges d'antan?Всё просто, что просто конча́ется"));
}
TEST_CASE("test 3") {
    UTF8string test3("hip ");
    CHECK_THAT((test3 * 3 + UTF8string("hurray")).get_str(),
               Equals("hip hip hip hurray"));
    CHECK_THAT(test3.get_str(), Equals("hip "));
    test3 * 3;
    CHECK_THAT(test3.get_str(), Equals("hip "));
    3 * test3;
    CHECK_THAT(test3.get_str(), Equals("hip "));
}
TEST_CASE("test 4") {
    UTF8string test4("Никола́й Васи́льевич Го́голь");
    CHECK_THAT((!test4).get_str(),
               Equals("ьлоѓоГ чивеьл́исаВ й́алокиН"));
}
TEST_CASE("test 5") {
    UTF8string test5 = UTF8string("静中有山口记者");
    CHECK(7 == test5.length());
}
TEST_CASE("test 6") {
    UTF8string test6 = UTF8string("星と僕らと -piano version-");
    CHECK(21 == test6.length());
}
TEST_CASE("test 7") {
    UTF8string test7 = UTF8string("Knight Artorias");
    CHECK(7 == test7.find("Artorias"));
}
TEST_CASE("test 8") {
    UTF8string test8 = UTF8string("薬師エマ - Emma The Physician");
    test8.replace("Emma The Physician", "Sekiro");
    CHECK_THAT(test8.get_str(), Equals("薬師エマ - Sekiro"));
}
TEST_CASE("test 9") {
    UTF8string test9 = UTF8string("Floating Dust");
    test9.replace("Floating", "Sherlock: Music");
    CHECK_THAT(test9.get_str(), Equals("Sherlock: Music Dust"));
}
TEST_CASE("test 10") {
    UTF8string test10 =
            UTF8string("PERSONA5 THE ROYAL STRAIGHT FLUSH EDITION Original Soundtrack ");
    test10.replace(" ROYAL ", "");
    CHECK_THAT(test10.get_str(),
               Equals("PERSONA5 THESTRAIGHT FLUSH EDITION Original Soundtrack "));
}
TEST_CASE("test 11") {
    UTF8string test11 =
            UTF8string("ジョジョの奇妙な冒険 スターダストクルセイダース");
    test11.replace("ジョ", "JO");
    CHECK_THAT(test11.get_str(),
               Equals("JOJOの奇妙な冒険 スターダストクルセイダース"));
}
TEST_CASE("test 12") {
    UTF8string test12("空は高く風は歌う");
    CHECK(0 == test12.find("空"));
    CHECK(3 == test12.find("く"));
    CHECK(7 == test12.find("う"));
}
```

## Part 3 - Result & Verification

### Test Case #1: examples

``` log
Input:
    No input
Output:
    test contains: Mais où sont les neiges d'antan?
    length in bytes of test: 33
    number of characters (one 2-byte character): 32
    position of "sont": 8
    test2 before replacement: Всё хорошо́, что хорошо́ конча́ется
    test2 after replacement: Всё просто, что просто конча́ется
    test + test2: Mais où sont les neiges d'antan?Всё просто, что просто конча́ется
    Appending !!! to test
    Result: Mais où sont les neiges d'antan?!!!
    Testing operator *: hip hip hip hurray
    Testing operator !: Никола́й Васи́льевич Го́голь -> ьлоѓоГ чивеьл́исаВ й́алокиН
```

![picture_01](./Ass5_picture_01.png)

### Test Case #2: Catch2 tests.

``` log
Input:
    No input
Output:
    All tests passed (22 assertions in 12 test cases)
```

![picture_02](./Ass5_picture_02.png)

## Part 4 - Difficulties & Solutions

### Difficulties

`explicit`会禁止隐式类型转换

### Solutions

不使用`explicit`
