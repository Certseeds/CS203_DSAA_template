<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-03-15 23:05:30
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-23 17:11:06
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

# CS205 C/C++ Assignment2

**Envirment**:Visual Studio 2019,MSVC

## Part 1-Analysis

1. The structure city contains four pointers, two char \*, one for the city name, one for the country name, and the
   other two double * for latitude and longitude. Use new in the constructor and delete in the destructor to ensure No
   memory leak.
2. The data read-in part uses ifstream, and all the city arrays are initialized in advance, all the data is read in the
   loop, and each row of data read is separated by a comma and initialized to city. During the reading process,
   Use `strlen ()` and a judgment statement to remind the array that it is too small to store city_name and country_name
   and cannot read the data, and use the judgment method at initialization to avoid memory out of bounds.
3. After reading the data, enter the loop, prompt the user to enter the city name, first enter all through the `trim ()`
   function to ensure that there are no spaces left and right, and then use the `strstr ()` with the input string and
   all city_name in the city array Judgment, if the length of the returned array is zero, continue to input, if the
   length is greater than 1, read the input to select, and directly end when the length is 1, after inputting, only by
   typing`Bye` (case-insensitive (Sensitive, use function judgment) before exiting.
4. Finally, use the distance calculation function in Assignment1 to calculate the distance.

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

### Test Case #1:file does not exist

```
Input:
    Do not exist world_cities.csv in ./
Output:
    "Notice for dont find file"
```

![picture_01](./picture_01.png)

### Test Case #2: Insufficient length

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

### Test Case #3: Normal operation_1

``` cpp
    constexpr int32_t LENGTH_OF_NAME = 35;
    constexpr int32_t LENGTH_OF_ARRAY = 1000;
    The following LENGTH_OF_NAME and LENGTH_OF_ARRAY are all the above definitions, and will not be described again.
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

### Test Case #4: Normal operation-city dont found

``` cpp
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

### Test Case #5: Normal operation_ length is too short

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

### Test Case #6: Normal operation-multiple match

``` cpp
Input:
    Fort
    3
      Can  
    1
      Bye
Output:
    Distance between Fort-de-France and Cancç…¤n is : 2818.77 km
```

![picture_06](./picture_06.png)

### Test Case #7: Normal operation-multiple cycles

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

### Test Case #8: Normal operation _ all conditions

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

### Test Case #9: Normal operation_ lower/ upper case

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

### Test Case #10: Normal operation_matching with input length

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

### Test Case #11: Normal operation-multiple match and out-of-range

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

Use pointers to manage objects and make dynamic memory allocations.

#### Solutions

Read the chapter about classes, store the city classes separately in an hpp file, and use destructors.