<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-04-11 23:44:09
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-06-07 09:39:40
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

# CS205 C/C++ Assignment4

**环境**:WSL_1,gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04).C++17.

## Question 1

### Part 1 - Analysis

1. SID要随机在[2000,2020],所以用一对std::pair来存储begin和end
2. scores在0-5处随机,所以使用c++11中的random库生成SID与scores的随机数.
3. 读入一个数,使用unordered_map存储SID与scores之间的对应关系.

### Part 2 - Code

``` cpp
#include <vector>
#include <iostream>
#include <unordered_map>
#include <random>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
//  [2000,2020]
const std::pair<int32_t, int32_t> range(2000, 2020);
// lab number
const int32_t lab_number = 14;
int32_t question1();
int main() {
    question1();
    return 0;
}
int32_t question1() {
    // student-number
    uint32_t number = 0;
    // sid to vector
    unordered_map<int32_t, vector<int32_t>> umap;
    // randoms
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int32_t> year(range.first, range.second);
    std::uniform_int_distribution<int32_t> last(0, 9);
    std::uniform_int_distribution<int32_t> scores(0, 5);
    // read
    cout << "The Number of students" << endl;
    cin >> number;
    if (cin.fail()) {
        cout << "Bad input" << endl;
        return -1;
    }
    while (number != umap.size()) {
        // random produce until is enough
        int32_t id = year(e1);
        for (uint32_t j = 0; j < 4; ++j) {
            id = id * 10 + last(e1);
        }
        vector<int32_t> score(lab_number, 0);
        for (auto &j : score) {
            j = scores(e1);
        }
        umap[id] = score;
    }//output
    for (const auto &i:umap) {
        cout << i.first << ": ";
        for (uint32_t j = 0; j < i.second.size() - 1; ++j) {
            cout << i.second[j] << ", ";
        }
        cout << i.second.back() << endl;
    }
    return 0;
}
```

### Part 3 - Result & Verification

#### Test Case #1:

``` log
Input:
    10
Output:
    20079341: 4, 3, 0, 4, 1, 0, 2, 0, 0, 4, 4, 0, 3, 0
    20073827: 4, 1, 1, 3, 5, 4, 0, 4, 2, 5, 0, 5, 4, 2
    20109250: 0, 1, 1, 2, 0, 3, 0, 0, 4, 3, 4, 4, 2, 0
    20142026: 4, 4, 4, 5, 0, 0, 2, 2, 5, 4, 3, 4, 3, 4
    20065499: 0, 1, 5, 1, 2, 0, 4, 4, 0, 0, 4, 5, 4, 4
    20088494: 4, 0, 1, 0, 5, 1, 1, 5, 3, 2, 1, 5, 1, 1
    20135150: 2, 2, 2, 3, 5, 3, 0, 5, 1, 3, 5, 5, 3, 4
    20117045: 4, 2, 4, 0, 5, 2, 2, 3, 4, 5, 5, 1, 4, 5
    20100838: 5, 5, 0, 3, 2, 3, 4, 5, 3, 5, 4, 1, 3, 4
    20098492: 3, 0, 2, 2, 4, 3, 4, 3, 3, 1, 0, 4, 0, 2 
```

![picture_01](./Ass4_picture_01.png)

#### Test Case #2:

``` log
Input:
    18
Output:
    20118251: 3, 5, 5, 5, 2, 2, 5, 4, 4, 1, 4, 2, 5, 5
    20028937: 2, 3, 3, 0, 1, 3, 4, 3, 3, 1, 0, 5, 4, 4
    20106043: 0, 1, 1, 0, 4, 2, 3, 0, 2, 5, 2, 0, 3, 1
    20204252: 4, 0, 3, 4, 1, 5, 0, 3, 5, 0, 0, 1, 4, 5
    20185128: 2, 5, 0, 0, 5, 5, 5, 5, 0, 1, 2, 4, 2, 3
    20187469: 3, 1, 4, 0, 0, 0, 1, 0, 4, 1, 1, 2, 3, 3
    20159560: 5, 4, 0, 2, 3, 0, 0, 5, 4, 2, 2, 1, 0, 0
    20000534: 3, 4, 0, 0, 2, 1, 5, 3, 4, 1, 3, 1, 3, 1
    20164890: 2, 0, 1, 4, 0, 5, 3, 4, 1, 1, 2, 2, 4, 2
    20160857: 0, 4, 5, 1, 4, 2, 5, 3, 4, 0, 0, 3, 4, 1
    20047785: 3, 3, 1, 4, 2, 4, 3, 0, 0, 3, 3, 0, 1, 0
    20064731: 1, 2, 1, 4, 0, 2, 5, 1, 1, 1, 3, 3, 5, 5
    20154012: 0, 5, 5, 3, 0, 4, 1, 3, 4, 5, 3, 3, 5, 0
    20100880: 5, 3, 5, 5, 5, 3, 1, 3, 0, 5, 4, 3, 5, 2
    20180134: 1, 2, 0, 5, 4, 1, 0, 0, 1, 1, 4, 0, 0, 5
    20193388: 1, 5, 0, 5, 0, 1, 3, 4, 5, 1, 5, 2, 0, 0
    20098662: 5, 5, 5, 0, 5, 4, 0, 3, 2, 1, 1, 1, 5, 4
    20183859: 2, 3, 0, 0, 1, 4, 3, 1, 1, 4, 5, 3, 0, 3
```

![picture_02](./Ass4_picture_02.png)

### Part 4 - Difficulties & Solutions

#### Difficulties

rand(),srand()比较难用.

#### Solutions

使用C++11的随机数生成库random.

## Question 2:

### Part 1 - Analysis

1. 在1的基础上,遍历每个sid对应的vector,有两个及两个以上为零的输出.

### Part 2 - Code

``` cpp
#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
//  [2000,2020]
const std::pair<int32_t, int32_t> range(2000, 2020);
// lab number
const int32_t lab_number = 14;
// sid to vector
unordered_map<int32_t, vector<int32_t>> umap;
int32_t question1();
int32_t question2();
int main() {
    question1();
    question2();
    return 0;
}
int32_t question1() {
    // student-number
    uint32_t number = 0;
    // randoms
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int32_t> year(range.first, range.second);
    std::uniform_int_distribution<int32_t> last(0, 9);
    std::uniform_int_distribution<int32_t> scores(0, 5);
    cout << "The Number of students" << endl;
    // read
    cin >> number;
    if (cin.fail()) {
        cout << "Bad input" << endl;
        return -1;
    }
    // random produce until is enough
    while (number != umap.size()) {
        int32_t id = year(e1);
        for (uint32_t j = 0; j < 4; ++j) {
            id = id * 10 + last(e1);
        }
        vector<int32_t> score(lab_number, 0);
        for (int &j : score) {
            j = scores(e1);
        }
        umap[id] = score;
    }
    //  output
    for (const auto &i:umap) {
        cout << i.first << ": ";
        for (uint32_t j = 0; j < i.second.size() - 1; ++j) {
            cout << i.second[j] << ", ";
        }
        cout << i.second.back() << endl;
    }
    return 0;
}
int32_t question2() {
    // output
    for (const auto &i:umap) {
        // int32_t times = ;
        if (std::count(i.second.begin(), i.second.end(), 0) >= 2) {
            // cout << i.first << " " << "Absent " << times << " times" << endl;
            cout << i.first << endl;
        }
    }
    return 0;
}
```

### Part 3 - Result & Verification

#### Test Case #1:

``` log
Input:
    10
Output:
    20033899: 2, 0, 3, 1, 0, 0, 2, 4, 1, 0, 2, 0, 0, 5
    20069324: 1, 2, 2, 1, 0, 5, 5, 5, 0, 2, 5, 1, 1, 4
    20089491: 2, 2, 0, 5, 3, 0, 4, 1, 3, 3, 0, 0, 4, 2
    20036544: 5, 2, 0, 0, 3, 3, 2, 4, 3, 0, 4, 3, 4, 2
    20014101: 1, 0, 4, 4, 0, 1, 5, 4, 2, 3, 0, 3, 2, 5
    20125434: 5, 1, 3, 0, 5, 0, 3, 2, 2, 3, 5, 2, 0, 4
    20029639: 5, 3, 0, 5, 5, 2, 1, 4, 1, 0, 3, 3, 1, 0
    20079338: 1, 2, 5, 0, 1, 1, 0, 0, 1, 4, 5, 4, 1, 2
    20018928: 5, 0, 1, 4, 5, 4, 0, 2, 5, 3, 2, 0, 1, 2
    20014234: 1, 4, 4, 0, 4, 4, 0, 2, 5, 2, 3, 0, 0, 0
    20033899
    20069324
    20089491
    20036544
    20014101
    20125434
    20029639
    20079338
    20018928
    20014234
```

![picture_03](./Ass4_picture_03.png)

### Part 4 - Difficulties & Solutions

#### Difficulties

1. umap不能放在question1内

#### Solutions

2. 放在外面

## Question 3:Count Unicode Langauge

### Part 1 - Analysis

1. 使用ofstream,将umap中的内容写入.

### Part 2 - Code

``` cpp
#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
//  [2000,2020]
const std::pair<int32_t, int32_t> range(2000, 2020);
// lab number
const int32_t lab_number = 14;
// sid to vector
unordered_map<int32_t, vector<int32_t>> umap;
int32_t question1();
int32_t question2();
int32_t question3();
int main() {
    question1();
    question2();
    question3();
    return 0;
}
int32_t question1() {
    // student-number
    uint32_t number = 0;
    // randoms
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int32_t> year(range.first, range.second);
    std::uniform_int_distribution<int32_t> last(0, 9);
    std::uniform_int_distribution<int32_t> scores(0, 5);
    cout << "The Number of students" << endl;
    // read
    cin >> number;
    if (cin.fail()) {
        cout << "Bad input" << endl;
        return -1;
    }
    // random produce until is enough
    while (number != umap.size()) {
        int32_t id = year(e1);
        for (uint32_t j = 0; j < 4; ++j) {
            id = id * 10 + last(e1);
        }
        vector<int32_t> score(lab_number, 0);
        for (int &j : score) {
            j = scores(e1);
        }
        umap[id] = score;
    }
    //  output
    for (const auto &i:umap) {
        cout << i.first << ": ";
        for (uint32_t j = 0; j < i.second.size() - 1; ++j) {
            cout << i.second[j] << ", ";
        }
        cout << i.second.back() << endl;
    }
    return 0;
}
int32_t question2() {
    for (const auto &i:umap) {
        // int32_t times = ;
        if (std::count(i.second.begin(), i.second.end(), 0) >= 2) {
            // cout << i.first << " " << "Absent " << times << " times" << endl;
            cout << i.first << endl;
        }
    }
    return 0;
}
int32_t question3() {
    // file
    std::ofstream file("./lab_records.csv");
    if (!file.is_open()) {
        cout << "Open file failed" << endl;
        return 0;
    }
    // write
    for (const auto &i:umap) {
        file << i.first << ",";
        for (uint32_t j = 0; j < i.second.size() - 1; ++j) {
            file << i.second[j] << ",";
        }
        file << i.second.back() << endl;
    }
    // close
    file.close();
    return 0;
}
```

### Part 3 - Result & Verification

#### Test Case #1: script output

``` log
Input:
    12
Output:
    20191951: 5, 1, 5, 4, 0, 4, 1, 4, 4, 5, 5, 5, 0, 5
    20133657: 3, 2, 0, 4, 4, 0, 4, 5, 5, 0, 0, 3, 1, 2
    20009951: 5, 4, 1, 2, 3, 2, 2, 0, 2, 4, 4, 5, 1, 1
    20118900: 1, 5, 2, 5, 5, 4, 0, 1, 0, 0, 5, 4, 5, 4
    20127254: 2, 0, 4, 5, 4, 0, 4, 3, 4, 4, 1, 4, 0, 3
    20084620: 2, 3, 3, 0, 2, 0, 0, 1, 1, 2, 0, 4, 5, 2
    20015096: 1, 5, 4, 5, 5, 3, 3, 4, 3, 4, 4, 4, 4, 5
    20062815: 1, 4, 0, 5, 1, 0, 1, 4, 5, 2, 2, 3, 1, 5
    20140607: 5, 2, 5, 2, 2, 0, 3, 4, 4, 3, 4, 2, 2, 1
    20090929: 1, 3, 2, 0, 3, 2, 0, 2, 0, 0, 2, 4, 3, 4
    20028419: 2, 2, 0, 1, 1, 4, 4, 0, 4, 2, 2, 3, 2, 5
    20204560: 0, 2, 3, 5, 2, 5, 1, 4, 5, 2, 1, 4, 4, 3
    20191951
    20133657
    20118900
    20127254
    20084620
    20062815
    20090929
    20028419
```

`cat ./lab_records.csv`

``` csv
20191951,5,1,5,4,0,4,1,4,4,5,5,5,0,5
20133657,3,2,0,4,4,0,4,5,5,0,0,3,1,2
20009951,5,4,1,2,3,2,2,0,2,4,4,5,1,1
20118900,1,5,2,5,5,4,0,1,0,0,5,4,5,4
20127254,2,0,4,5,4,0,4,3,4,4,1,4,0,3
20084620,2,3,3,0,2,0,0,1,1,2,0,4,5,2
20015096,1,5,4,5,5,3,3,4,3,4,4,4,4,5
20062815,1,4,0,5,1,0,1,4,5,2,2,3,1,5
20140607,5,2,5,2,2,0,3,4,4,3,4,2,2,1
20090929,1,3,2,0,3,2,0,2,0,0,2,4,3,4
20028419,2,2,0,1,1,4,4,0,4,2,2,3,2,5
20204560,0,2,3,5,2,5,1,4,5,2,1,4,4,3

```

![picture_04](./Ass4_picture_04.png)

### Part 4 - Difficulties & Solutions

#### Difficulties

1. 使用ide时,lab_records.csv会在输出目录出现.

#### Solutions

2. 使用命令行.

## Question 4

### Part 1 - Analysis

1. 使用fstream读取文件,一行一行读取后,使用atoi等解析其中的内容.
2. 最后计算总分,计算不到平均分的lab ID,输出.

### Part 2 - Code

``` cpp
#include <vector>
#include <numeric>
#include <fstream>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
// lab number
const int32_t lab_number = 14;
int32_t question4();
std::pair<int32_t, vector<int32_t>> str_to_scores(const std::string &str_in);
int main() {
    question4();
    return 0;
}
int32_t question4() {
    // file path
    std::fstream file("./lab_records.csv");
    // read
    if (!file.is_open()) {
        cout << "open file fail " << endl;
        return -1;
    }
    std::string line;
    vector<int32_t> lab_scores(lab_number, 0);
    // read
    while (!file.eof()) {
        getline(file, line);
        if (line.empty()) {
            continue;
        }
        //cout << line << endl;
        auto temp = str_to_scores(line);
        // count scores.
        for (uint32_t i = 0; i < temp.second.size(); ++i) {
            lab_scores[i] += temp.second[i];
        }
    }
    // output
    int score_sum = std::accumulate(lab_scores.begin(), lab_scores.end(), 0);
    for (int32_t i = 0; i < lab_number; i++) {
        if (lab_scores[i] * lab_number < score_sum) {
            cout << (i + 1) << endl;
        }
    }
    return 0;
}
std::pair<int32_t, vector<int32_t>> str_to_scores(const std::string &str_in) {
    // transfer string to scores.
    std::string str(str_in);
    vector<int32_t> will_return;
    int32_t id = std::atoi(str.substr(0, str.find_first_of(',')).c_str());
    str = str.substr(str.find_first_of(',') + 1);
    while (0 != std::count(str.begin(), str.end(), ',')) {
        //cout << str.find_first_of(',') << endl;
        will_return.push_back(std::atoi(str.substr(0, str.find_first_of(',')).c_str()));
        str = str.substr(str.find_first_of(',') + 1);
    }
    will_return.push_back(std::atoi(str.c_str()));
    return std::make_pair(id, will_return);
}
```

### Part 3 - Result & Verification

#### Test Case #1:

``` log
Input:
    No input.
Output:
    3
    4
    5
    7
    9
    10
    11
    13
    14
```

![picture_05](./Ass4_picture_05.png)

data in lab_records.csv

``` log
20195943,4,5,4,0,3,0,2,3,1,2,4,4,0,4
20183025,3,2,3,3,1,5,0,3,0,4,5,1,1,3
20199067,1,5,3,0,1,5,0,5,4,2,0,5,3,3
20162252,3,2,1,4,1,2,4,5,5,3,4,1,2,4
20054582,4,2,0,5,2,3,3,5,2,5,2,2,3,2
20004989,1,5,1,2,4,5,1,4,2,3,0,1,3,4
20151478,4,0,3,0,4,2,2,1,5,3,1,5,4,2
20098742,1,2,5,1,0,1,4,0,1,3,2,5,5,2
20041537,2,4,0,4,1,4,1,5,1,2,1,3,1,3
20186054,0,5,4,3,4,1,5,3,5,0,4,5,3,1
20101044,4,5,0,3,2,5,5,0,0,1,2,3,3,2
20001407,3,2,1,4,1,5,1,1,3,3,0,5,1,1
20069679,5,5,3,1,4,1,4,3,3,1,5,5,1,0
20074839,1,3,0,4,4,5,4,1,1,0,3,5,4,4
20005744,3,3,3,2,0,2,0,0,0,5,2,5,3,0
```

![picture_06](./Ass4_picture_06.png)

### Part 4 - Difficulties & Solutions

#### Difficulties

csv格式中,不能忽略空格

#### Solutions

不在csv格式中使用非必要的空格.

## Question 5

### Part 1 - Analysis

1. 使用一个循环,等待读入,并将读入转化的字符switch到对应的输出.
2. 使用recieve_input,对读入进行转换,转换成int32_t.
3. 使用trim将字符串前后的空白抹去.
4. 使用str_lower将字符串转换为小写.

### Part 2 - Code

``` cpp
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
int32_t recieve_input();
int32_t question5();
std::string str_lower(std::string str);
std::string trim(std::string str);
// commands
const std::vector <std::string> command = {"start", "stop", "restart", "reload", "status", "exit"};
const int32_t exit_n = 5;
const int32_t illegal = 6;
int main() {
    question5();
    return 0;
}
int32_t question5() {
    while (true) {
        std::cout << "<";
        // switch
        int32_t temp = recieve_input();
        // std::cout << temp << std::endl;
        switch (temp) {
            case exit_n: {
                std::cout << "exit" << std::endl;
                return 0;
            }
            case illegal: {
                std::cout << "Invalid command" << std::endl;
                break;
            }
            default: {
                std::cout << "command " << command[temp] << " recognized" << std::endl;
                break;
            }
        }
    }
    return 0;
}
int32_t recieve_input() {
    // recieve input and return order.
    std::string input;
    std::cin >> input;
    input = trim(input);
    input = str_lower(input);
    return std::distance(command.begin(), std::find(command.begin(), command.end(), input));
}
// 给分的时候,虽然没写要处理大小写,但是还是扣分了.
std::string str_lower(std::string str) {
    for (auto &item : str) {
        if (item >= 'A' && item <= 'Z'){
            item = item - ('A'-'a');
        }
    }
    return str;
}
std::string trim(std::string str) {
    // delete spaces
    if (str.empty()) {
        return str;
    }
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
}
```

### Part 3 - Result & Verification

#### Test Case #1:

``` log
Input:
    start
    stop
    restart
    reload
    status
    shenmi
    exit
Output:
    command start recognized
    command stop recognized
    command restart recognized
    command reload recognized
    command status recognized
    Invalid command
    exit
```

![picture_07](./Ass4_picture_07.png)

#### Test Case #2:

``` log
Input:
    START
    StOp
    ReStaRt
    shenmi
    rEloaD
    sTatuS
    exIT
Output:
    command start recognized
    command stop recognized
    command restart recognized
    Invalid command
    command reload recognized
    command status recognized
    exit
```

![picture_08](./Ass4_picture_08.png)

### Part 4 - Difficulties & Solutions

#### Difficulties

循环判断相等不够优雅

#### Solutions

使用algorithm库中的find函数.
