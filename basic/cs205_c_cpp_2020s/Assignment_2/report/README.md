<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-15 21:28:57
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-06-22 10:46:24
 * @License: CC-BY-NC-SA_V4_0 or any later version
 -->

# CS205 C/C++ Assignment2

**环境**:Visual Studio 2019,MSVC

## Part 1 - Analysis

1. 结构体city含有四个指针,分别为两个char\*,一个存储城市名,一个存储国家名,另外两个double*存储经纬度.并在构造函数内使用new,析构函数内delete,确保不内存泄漏.
2. 数据读入部分使用ifstream,并提前将city数组全部初始化,在循环中读取所有数据,并将读取到的每行数据以逗号分隔,并初始化为city.在读取的过程中,使用`strlen()`
   和判断语句来提醒数组过小无法存储完city_name与country_name和无法读取完数据,并使用初始化时判断的方式避免内存越界.
3. 读取完数据后,进入循环,提示用户输入城市名,首先输入全部经过`trim()`函数保证左右无空格,然后将输入的字符串与city数组中的所有city_name使用`strstr()`
   进行判断,若返回数组长度为零,则继续输入,若长度大于1,则读取输入进行选择,当长度为1时才直接结束,输入完毕后,只有通过输入`Bye`(大小写不敏感,使用函数判断)才会退出.
4. 最后,使用Assignment1中的计算距离函数,进行距离的计算.

## Part 2 - Code

1. city.hpp( the header file for city class)

``` cpp
#ifndef _ASSIGNMENT_2_CITY_
#define _ASSIGNMENT_2_CITY_
#include <string.h>
#include <algorithm>
constexpr int32_t LENGTH_OF_NAME = 25;
struct city {
    char* city_name;
    char* country_name;
    double* latitude;
    double* longitude;
    city() {
        city_name = new char[LENGTH_OF_NAME+1];
        country_name = new char[LENGTH_OF_NAME+1];
        latitude = new double;
        longitude = new double;
        memset(city_name, '\0', LENGTH_OF_NAME*sizeof(char));
        memset(country_name, '\0', LENGTH_OF_NAME * sizeof(char));
    }
    city(char* ci_name,char* coun_name, double la, double lo) {
        city_name = new char[LENGTH_OF_NAME+1];
        country_name = new char[LENGTH_OF_NAME+1];
        latitude = new double;
        longitude = new double;
        memset(city_name, '\0', LENGTH_OF_NAME+1);
        memset(country_name, '\0', LENGTH_OF_NAME+1);
        memcpy(city_name, ci_name, 
        std::min(LENGTH_OF_NAME,static_cast<int>(strlen(ci_name)) )* sizeof(char));
        memcpy(country_name, coun_name, 
        std::min(LENGTH_OF_NAME, static_cast<int>(strlen(coun_name))) * sizeof(char));
        (*latitude) = la;
        (*longitude) = lo;
    }
    ~city() {
        delete[] city_name;
        delete[] country_name;
        delete latitude;
        delete longitude;
    }
};
#endif
```

2. Assignment_2.cpp

``` cpp
#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include "./city.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int sub_main_assignment_2();
city* get_city(char* line);
int input_city(string th, char* temp, city** cities);
vector<int> matches(char* str, city** cities);
bool judgement_equal_bye(string str);
double count_distance(vector<double>& dous);
string trim(string str);
const string FILE_NAME = "./../../../Assignment_2/src/world_cities.csv";
constexpr int32_t LENGTH_OF_ARRAY = 1000;
constexpr int32_t location_length = 5;
constexpr int32_t longitude_max = 90;
constexpr int32_t latitude_max = 180;
constexpr int32_t max_length = 1024;
constexpr int32_t min_length = 3;
constexpr int32_t radius_earth = 6371;
constexpr double_t PI = 3.1415926535f;
#ifndef UNIT_TESTING_ASSIGNMENT_2
#define UNIT_TESTING_ASSIGNMENT_2
int main() {
    const int32_t will_return = sub_main_assignment_2();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !UNIT_TESTING_ASSIGNMENT_2
int sub_main_assignment_2() {
    std::ifstream read_file(FILE_NAME);
    char temp[max_length];
    city* cities[LENGTH_OF_ARRAY];
    city* choose_city[2];
    choose_city[0] = nullptr;
    choose_city[1] = nullptr;
    for (int i = 0; i < LENGTH_OF_ARRAY; i++) {
        cities[i] = new city();
    }
    if (!read_file.is_open()) {
        cout << "Warning! fail to find file!" << endl;
        return -1;
    }
    int32_t count = 0;
    memset(temp, '0', max_length * sizeof(char));
    while (read_file.getline(temp, max_length) && temp[0] != '\0') {
        if (LENGTH_OF_ARRAY == count) {
            cout << "Warning! Array Too Small! Some Data do not loaded" << endl;
            break;
        }
        delete cities[count];
        cities[count] = get_city(temp);
        memset(temp, '\0', max_length * sizeof(char));
        count++;
    }
    int32_t order = -1;
    read_file.close();
    while (true) {
        order = -1;
        while (order < 0) {
            order = input_city("first", temp, cities);
            memset(temp, '\0', max_length * sizeof(char));
        }
        choose_city[0] = cities[order];
        order = -1;
        while (order < 0) {
            order = input_city("second", temp, cities);
            memset(temp, '\0', max_length * sizeof(char));
        }
        choose_city[1] = cities[order];
        cout << choose_city[0]->city_name << " " << choose_city[1]->city_name << endl;
        cout << "Input Bye to output" << endl;
        cin.getline(temp, max_length);
        if (judgement_equal_bye(trim(temp))) {
            break;
        }
        memset(temp, '\0', max_length * sizeof(char));
    }
    vector<double> lang_long = 
    { (*choose_city[0]->latitude),(*choose_city[0]->longitude),
    (*choose_city[1]->latitude),(*choose_city[1]->longitude) };
    cout << "Distance between " << choose_city[0]->city_name << " and ";
    cout << choose_city[1]->city_name << " is : " << count_distance(lang_long) << " km " << endl;
    for (auto& i : cities) {
        delete i;
    }
    return 0;
}
city* get_city(char* line) {
    char* location[location_length];
    memset(location, 0, sizeof(char*) * location_length);
    uint32_t length = strlen(line);
    uint32_t count = 1;
    for (int i = 0; i < length; i++) {
        location[0] = line;
        if (',' == (*(line + i))) {
            location[count] = (line + i + 1);
            (*(line + i)) = '\0';
            count++;
        }
    }
    if (strlen(location[0]) > LENGTH_OF_NAME ||
        strlen(location[2]) > LENGTH_OF_NAME) {
        cout << "Warning! city name or country name is too long, it will be truncated." << endl;
    }
    city* will_return = new city(location[0], location[2],
     std::atof(location[3]),std::atof(location[4]));
    return will_return;
}
int input_city(string th,char* temp,city** cities) {
    cout << "input "<< th <<" city name, longer than or equal than 3 letter : ";
    cin.getline(temp, max_length);
    string trim_temp = trim(temp);
    memset(temp, '\0', max_length);
    memcpy(temp, &trim_temp[0], trim_temp.size());
    if (strlen(temp) < min_length) {
        cout << " please input city name longer than 3 letter" << endl;
        return -1;
    }
    vector<int> list = matches(temp,cities);
    if (list.size()>1) {
        cout << "More than one city matches,";
        cout << " please choose one from those cities using numbers begin at 0" << endl;
        for (int i = 0; i < list.size(); i++) {
            cout << cities[list[i]]->city_name <<" , " << cities[list[i]]->country_name<< endl;
        }
        cin.getline(temp, max_length);
        string trim_temp = trim(temp);
        memset(temp, '\0', max_length);
        memcpy(temp, &trim_temp[0], trim_temp.size());
        int count = std::atoi(temp);
        memset(temp, '\0', max_length);
        if (count >= 0 && count < list.size()) {
            return list[count];
        }
        cout << "Out of range,Please input once again." << endl;
        return -2;
    }
    else if (0 == list.size()) {
        cout << "No city matches, please input once again " << endl;
        return -3;
    }
    else{
        cout << "matches city " << cities[list[0]]->city_name << endl;
        return list[0];
    }
}
vector<int> matches(char* str,city** cities) {
    vector<int> will_return = {};
    for (int i = 0; i < LENGTH_OF_ARRAY; i++) {
        if (nullptr != strstr(cities[i]->city_name, str)) {
            will_return.push_back(i);
        }
    }
    return will_return;
}
string trim(string str) {
    if (str.empty()) {
        return str;
    }
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    return str;
}
bool judgement_equal_bye(string str) {
    if (str.size() == min_length &&
        ('b' == str[0] || 'B' == str[0]) &&
        ('y' == str[1] || 'Y' == str[1]) &&
        ('e' == str[2] || 'E' == str[2])
        ) {
        return true;
    }
    return false;
}
double count_distance(vector<double>& dous) {
    dous[0] = longitude_max - dous[0];
    dous[2] = longitude_max - dous[2];
    // data is la,lo ,la,lo
    double distance_1 =
        std::sin(std::abs(dous[0]) * PI / latitude_max) *
        std::sin(std::abs(dous[2]) * PI / latitude_max) *
        std::cos(std::abs(dous[1] - dous[3]) * PI / latitude_max);
    double distance_2 =
        std::cos(std::abs(dous[0]) * PI / latitude_max) *
        std::cos(std::abs(dous[2]) * PI / latitude_max);
    double distance = radius_earth * std::acos(distance_1 + distance_2);
    return distance;
}
```

## Part 3 - Result & Verification

### Test Case #1:文件不存在

``` log
Input:
    Do not exist world_cities.csv in ./
Output:
    "Notice for dont find file"
```

![picture_01](./picture_01.png)

### Test Case #2: 长度不足

``` cpp
    constexpr int32_t LENGTH_OF_NAME = 25;
    constexpr int32_t LENGTH_OF_ARRAY = 800;
Input:
    London
    manc
    mach
    ma
    man
    0
    Bye
Output:
    a lot of warnning, but can still run
    finally output Distance between London and Amman is : 3642.16 km
```

![picture_02](./picture_02.png)

### Test Case #3: 正常运行_1

``` cpp
    constexpr int32_t LENGTH_OF_NAME = 35;
    constexpr int32_t LENGTH_OF_ARRAY = 1000;
    下面的LENGTH_OF_NAME与LENGTH_OF_ARRAY全都为上面的定义,不再赘述.
Input:
    Chiang
    0
    Frot
    frot
    Fort
    3
    Bye
Output:
    Distance between Chiang Mai and Fort-de-France is : 15708 km
```

![picture_03](./picture_03.png)

### Test Case #4: 正常运行_找不到城市

``` log
Input:
    Cangzhou
    Zhaoxian
    Heze
    Jinjiang
    Shijiazhuang
    Feiji
    Miandian
    Yuenan
    Guangzhou
       Bye
Output:
    Distance between Shijiazhuang and Guangzhou is : 1662.84 km
```

![picture_04](./picture_04.png)

### Test Case #5: 正常运行_长度过短

``` cpp
Input:
    as
    rt
    fj
    da
    or
    j
    Bei
    1
    Fo
    En
    Bo
        bos
      Bost
      Bye
Output:
    Distance between Beirut and Boston is : 8721.79 km
```

![picture_05](./picture_05.png)

### Test Case #6: 正常运行_匹配多项

``` cpp
Input:
    Fort
    3
      Can  
    1
      Bye
Output:
    Distance between Fort-de-France and Canc煤n is : 2818.77 km
```

![picture_06](./picture_06.png)

### Test Case #7: 正常运行_多次循环

``` cpp
Input:
    Cana
     Jana
    Jan
    No!!!
    Shiji
    Beiji
    NO!!!!
    Hefei
    Shenzhen
    Guangzhou
      Bye
Output:
    Distance between Shenzhen and Guangzhou is : 107.187 km
```

![picture_07](./picture_07.png)

### Test Case #8: 正常运行_所有情况

``` cpp
Input:
    Cangzhou
    Guangdongsheng
       as   
        jr
       ass
    10
    Bobo
    Heze
    ZHaoxian
       pp
       iiw
       Guangdong
    Guang
    NO!!!
    Jin
       ls
        cd 
        cat
       Bye
Output:
    Distance between Jinan and Muscat is : 5710.21 km
```

![picture_08](./picture_08.png)

### Test Case #9: 正常运行_大小写

``` cpp
Input:
    beijing
    Beijing
    Guangzhou
    bYe
Output:
    Distance between Beijing and Guangzhou is : 1887.55 km
```

![picture_09](./picture_09.png)

### Test Case #10: 正常运行_匹配与输入长度

``` cpp
Input:
    Ko
    Kot
    0
    Ku
    Kuchi
    bye
Output:
    Distance between Kota Bharu and Kuching is : 1031.94 km
```

![picture_10](./picture_10.png)

### Test Case #11: 正常运行_模糊匹配与越界

``` cpp
Input:
    King
    3
    King
    1
    Victoria
    0
    Bye
Output:
    Distance between Kingston and Victoria is : 11912.3 km
```

![picture_11](./picture_11.png)

## Part 4 - Difficulties & Solutions

#### Difficulties

使用指针管理对象与进行动态内存分配.

#### Solutions

阅读了关于class的章节,将city类单独存放在一个hpp文件中,并使用了析构函数.