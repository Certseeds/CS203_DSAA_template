<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-06 18:44:22
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-04-08 17:10:08
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

**Environment**: Visual Studio 2019,MSVC.

## Part 1 - Analysis

1. First, the entire process of this problem can be described as "read the first city name, latitude and longitude,
   second city name, latitude and longitude from the console, and calculate and output the distance between the two
   cities"
2. However, because The format input is uncertain, so the input needs to be discussed and analyzed in detail.
3. In order to facilitate the management of line breaks and other issues, use getline (buffer, 1024) to solve.
4. Since the city name cannot include special characters, use an auxiliary function Traversing the string to help judge
5. Since special characters cannot be included in latitude and longitude, two parameters (one precision and one
   latitude) are required, more than one `+ .-`, and latitude and longitude cannot be 0 (no latitude and longitude) The
   city is 0 and prevent misreading), must be a value that is in line with the actual logic, so it needs to be judged
   separately.
6. It is not possible to include special characters to use traversal judgment, two parameters are required to find the
   string after removing the space on both sides The way of internal space, there can be no extra `+-.` using
   the` std :: cout` function, the latitude and longitude cannot be 0 and the value range is directly judged, and the
   city name is read, and the longitude and latitude are set to A function that is called twice and uses the
   identification code for exception handling. The string is converted to a floating point number using the
   built-in `std :: stof`
7. Because catch2 is used for unit testing, macros are used to convert main ( ) The function is hidden, there is no test
   macro in normal operation, and the main () function is normal.
8. The mathematical principle refers to the formula given in the report
   ``` c 
   phi1 = 90 - latitude1;
   phi2 = 90 - latitude2;
   theta1 = longitude1;
   theta2 = longitude2;
   c = sin(phi1) * sin(phi2) * cos(theta1-theta2) +cos(phi1) * cos(phi2)
   d = R*cos(c)
   ```
   d is what we want.

## Part 2 - Code

``` cpp
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int sub_main();
int get_city_itude(vector<double>&dous,vector<string>&strs,const string& order,int num);
bool judge_legal(const string& s);
bool judge_legal2(const string& s);
string delete_space(string str);
int give_two_double(string s, vector<double>& num, int order);
bool check_double(const string& s);
double count_distance(vector<double>& dous);
const int max_length = 1024;
const int radius_earth = 6371;
const double PI = 3.1415926535;
//+ - . is legal
#ifndef UNIT_TESTING_ASSIGNMENT_1
#define UNIT_TESTING_ASSIGNMENT_1
int main() {
    const int32_t will_return = sub_main();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !UNIT_TESTING_ASSIGNMENT_1
int sub_main() {
    vector<double> dous(4, 0.0f);
    vector<string> strs(4, "");
    int return_value1 = get_city_itude(dous, strs, "first", 0);
    if (0 != return_value1) {
        return return_value1;
    }
    int return_value2 = get_city_itude(dous, strs, "second", 2);
    if (0 != return_value2) {
        return return_value2;
    }
    cout << "The distance between ";
    cout << strs[0] << " and ";
    cout << strs[2] << " is ";
    cout << count_distance(dous) << " km";
    return 0;
}
double count_distance(vector<double>& dous) {
    dous[0] = 90 - dous[0];
    dous[2] = 90 - dous[2];
    // data is la,lo ,la,lo
    double distance_1 =
        std::sin(std::abs(dous[0]) * PI / 180) *
        std::sin(std::abs(dous[2]) * PI / 180) *
        std::cos(std::abs(dous[1] - dous[3]) * PI / 180);
    double distance_2 =
        std::cos(std::abs(dous[0]) * PI / 180) *
        std::cos(std::abs(dous[2]) * PI / 180);
    double distance = radius_earth * std::acos(distance_1+distance_2);
    return distance;
}
int get_city_itude(
    vector<double>& dous, vector<string>& strs, const string& num, int order) {
    char first[1024] = { 0 };
    char itude[1024] = { 0 };
    cout << "The " << num << " city : ";
    cin.getline(first, max_length);
    strs[order] = first;
    if (!judge_legal(strs[order])) {
        cout << "City name should not contain special characters" << endl;
        return -1;
    }
    cout << "The latitude and longitude of " << num << " city: ";
    cin.getline(itude, max_length);
    strs[order + 1] = delete_space(itude);
    if (std::count(strs[order + 1].begin(), strs[order + 1].end(), ' ') == 0) {
        cout << "bad input,longitude or latitude's middle ";
        cout << "should be space and both of them is needed" << endl;
        return -2;
    }
    if(!judge_legal2(strs[order + 1])) {
        cout << "bad input,longitude or latitude should not contain special characters" << endl;
        return -3;
    }
    int double_return_value = give_two_double(strs[order + 1], dous, order);
    if (-1 == double_return_value) {
        cout << "longitude or latitude contain too much + . -  or" << endl;
        return -4;
    }
    if (-2 == double_return_value) {
        cout << "input should obey correct input format" << endl;
        return -5;
    }
    if (0.0f == dous[order] || 0.0f == dous[order + 1]) {
        cout << "longitude or latitude should not be zero" << endl;
        return -6;
    }
    if (std::abs(dous[order]) > 90 || std::abs(dous[order + 1]) > 180) {
        cout << "latitude should belong to [-90,+90]" << endl;
        cout << "longitude should belong to [-180,+180]" << endl;
        return -7;
    }
    return 0;
}
bool judge_legal(const string& s) {
    for (auto i : s) {
        if (!(static_cast<int>(' ') == i || static_cast<int>(',') == i ||
            (i >= static_cast<int>('A') && i <= static_cast<int>('Z')) || 
            (i >= static_cast<int>('a') && i <= static_cast<int>('z')))) {
            return false;
        }
    }
    return true;
}
bool judge_legal2(const string& s) {
    for (auto i : s) {
        if (!(static_cast<int>('+') == i || static_cast<int>('-') == i || 
            static_cast<int>(' ') == i || static_cast<int>('.') == i ||
            (i >= static_cast<int>('0') && i <= static_cast<int>('9')))) {
            return false;
        }
    }
    return true;
}
string delete_space(string str) {
    if (str.empty()) {
        return str;
    }
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    return str;
}
bool check_double(const string& s) {
    if (std::count(s.begin(), s.end(), '.') > 1 ||
        (std::count(s.begin(), s.end(), '+') +
        std::count(s.begin(), s.end(), '-') > 1)) {
        return false;
    }
    return true;
}
int give_two_double(string s,vector<double>& num,int order) {
    int middle = s.find_first_of(' ');
    string s1 = delete_space(s.substr(0, middle));
    string s2 = delete_space(s.substr(middle, s.size()));
    if (check_double(s1) == false || check_double(s2) == false) {
        return -1;
    }
    try {
        num[order] = std::stof(s1);
        num[order + 1] = std::stof(s2);
    } catch(std::invalid_argument e) {
        return -2;
    }
    return 0;
}
```

## Part 3 - Result & Verification

#### Test case #1:Illegal city name

```
Input:Wrong City  or 1=1 #
Output:return and output
"City name should not contain special characters"
```

![picture_01](./picture_01.png)

#### Test Case #2:Too few parameters

```
Input:
Hong Kong,CN
22.22113.167
Output:return and output
"bad input,longitude or latitude's middle should be space and both of them is needed"
```

![picture_02](./picture_02.png)

#### Test Case #3:Illegal characters in latitude and longitude

```
Input:
HongtKong,CN
@22.22 @113.167
Output:return and output
"bad input,longitude or latitude should not contain special characters"
```

![picture_03](./picture_03.png)

#### Test Case #4:Too many latitudes and longitudes +-.

```
Input:
HongtKong,CN
+-22.2.2 -.113.167
Output:return and output
"longitude or latitude contain too much + . -  or"
```

![picture_04](./picture_04.png)

#### Test Case #5:Malformed latitude and longitude

```
Input:
HongtKong,CN
.+0 0.-0
Output:return and output
"input should obey correct input format"
```

![picture_05](./picture_05.png)

#### Test Case #6:Latitude and longitude is 0

```
Input:
HongtKong,CN
.0 0
Output:return and output
"longitude or latitude should not be zero"
```

![picture_06](./picture_06.png)

#### Test Case #7:Latitude and longitude range

```
Input:
HongtKong,CN
114 514
Output:return and output
"latitude should belong to [-90,+90]"
"longitude should belong to [-180,+180]"
```

![picture_07](./picture_07.png)

#### Test Case #8:Normal input and output

```
Input:
Shenzhen
22.55 114.1
Beijing
39.9139 116.3917
Output:
"The distance between Shenzhen and Beijing is 1942.84 km"
```

![picture_08](./picture_08.png)

#### Test Case #9:Normal input and output

```
Input:
New York, USA
40.7127 -74.0059
London, UK
51.5072 -0.1275
Output:
"The distance between New York, USA and London, UK is 5570.25 km"
```

![picture_09](./picture_09.png)

#### Test Case #10:Normal input and output

```
Input:
Rio de Janeiro, Brazi
-22.9083 -43.1964
San Francisco, USA
37.7833 -122.4167
Output:
"The distance between Rio de Janeiro, Brazi and San Francisco, USA is 10660.6 km"
```

![picture_10](./picture_10.png)

#### Test Case #11:Normal input and output

```
Input:
Test City One
+.114 -0.514
Test City Two
-11.23 .91
Output:
"The distance between Test City One and Test City Two is 1271.17 km"
```

![picture_11](./picture_11.png)

## Part 4 - Difficulties & Solutions

1. There are many input possibilities, and there are many states that need to be combed.
2. Catch2 needs to use a macro to hide main () to meet the test conditions, and found a long time solution.