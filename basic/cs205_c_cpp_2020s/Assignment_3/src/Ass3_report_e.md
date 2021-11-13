<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-04-12 00:54:22
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-04-12 00:59:28
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

# CS205 C/C++ Assignment3

**Enviorment**:WSL_1,gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04).

## Question 1:Dodging bullets

### Part 1 - Analysis

1. First read all the inputs and check the validity of the read. For example, the input cannot be non-positive, the
   input point cannot be out of bounds, and the input direction must be one of eight directions.
2. Then when reading, every time the point and direction are read, the filling is called once, and finally the
   statistics.
3. The filling function stops when it crosses the boundary, and fills all the points in the direction with `true`;

### Part 2 - Code

``` cpp
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int32_t sub_main_assignment_3_01();
void fill_grid(vector<vector<int8_t>> &grid, vector<int32_t> &bullet);
static const vector<vector<int32_t>> possibility = {
        {1,  1},
        {1,  0},
        {1,  -1},
        {0,  1},
        {0,  -1},
        {-1, 1},
        {-1, 0},
        {-1, -1}
};
#ifndef UNIT_TESTING_ASSIGNMENT_3
#define UNIT_TESTING_ASSIGNMENT_3
int main() {
    return sub_main_assignment_3_01();
    //for unit test, use macro
}
#endif // !UNIT_TESTING_ASSIGNMENT_3
int32_t sub_main_assignment_3_01() {
    int32_t basic[3];
    for (int & i : basic) {
        cin >> i;
        if (cin.fail() || i <= 0) {
            cout << "Error input,Please try once again." << endl;
            return -1;
        }
    }//read data
    vector<vector<int8_t>> grid(basic[0], vector<int8_t>(basic[1], 0));
    vector<vector<int32_t>> input(basic[2], vector<int32_t>(4, 0));
    for (int32_t i = 0; i < basic[2]; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> input[i][j];
            if (cin.fail()) {
                cout << "Error input, Please run once again." << endl;
                return -1;
            }
        }//read data
        if ((input[i][0] < 0 || input[i][0] >= basic[0]) ||
            (input[i][1] < 0 || input[i][1] >= basic[1])) {
            cout << "Error, input begin point out of range,Please run again." << endl;
            return -1;
        }// if size is output of range,it's error
        bool appear = false;
        for (const auto &k:possibility) {
            if (k[0] == input[i][2] && k[1] == input[i][3]) {
                appear = true;
            }
        }
        if (!appear) {
            cout << "Error, input direction is not allowed." << endl;
            //output should only be one of eight kind.
            return -1;
        }
        fill_grid(grid, input[i]);
        // fill a line.
    }
    int32_t count = 0;
    for (const auto &row:grid) {
        for (const auto &item:row) {
            count += (item == 0);
            //count numbers.
        }
    }
    cout << count << endl;
    return 0;
}
void fill_grid(vector<vector<int8_t>> &grid, vector<int32_t> &bullet) {
    //file the grid.
    int32_t begin_x = bullet[0];
    int32_t begin_y = bullet[1];
    while (true) {
        if (begin_x < 0 || begin_x >= static_cast<int32_t>(grid.size()) ||
            begin_y < 0 || begin_y >= static_cast<int32_t>(grid[0].size())) {
            return;
        }
        grid[begin_x][begin_y] = true;
        begin_x += bullet[2];
        begin_y += bullet[3];
    }
}
```

### Part 3 - Result & Verification

#### Test Case #1: Normal

```
Input:
    3 4 5
    1 1 1 -1
    1 1 -1 1
    0 3 1 0
    0 2 1 0
    0 0 -1 -1
Output:
    3
```

![picture_01](./Ass3_picture_01.png)

#### Test Case #2: Normal

```
Input:
    4 4 4 
    0 0 1 1
    0 1 0 1 
    1 0 1 0
    1 1 -1 1
Output:
    6
```

![picture_02](./Ass3_picture_02.png)

#### Test Case #3: illegal input

```
Input:
    abc
Output:
    Error input,Please try once again.
```

![picture_03](./Ass3_picture_03.png)

#### Test Case #4: illegal input

```
Input:
    -1 -2
Output:
    Error input,Please try once again.
```

![picture_04](./Ass3_picture_04.png)

#### Test Case #5: illegal input

```
Input:
    4 4 4 
    5 6 7 8
Output:
    Error, input begin point out of range,Please run again.
```

![picture_05](./Ass3_picture_05.png)

#### Test Case #6: illegal input

```
Input:
    4 4 4 
    2 2 -2 3
Output:
    Error, input direction is not allowed.
```

![picture_06](./Ass3_picture_06.png)

### Part 4 - Difficulties & Solutions

#### Difficulties

Implicit conversion will have warning

#### Solutions

Use static_cast <> conversion to avoid warning.

## Question 2:Spiral array

### Part 1 - Analysis

1. Read two parameters first. It must be a positive integer.
2. Then calculate the total number of matrices to get the length of the formatted output at the end of the output.
3. Then call the function to get the matrix.
4. The idea of the function is to fill the top and left of the matrix, and then recursively call the sub-matrix with two
   dimensions of -1, and fill the sub-matrix back to itself.

### Part 2 - Code

``` cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int32_t sub_main_assignment_3_02();
void spiral(vector<vector<int32_t>> &matrix, int32_t begin);
#ifndef UNIT_TESTING_ASSIGNMENT_3
#define UNIT_TESTING_ASSIGNMENT_3
int main() {
    return sub_main_assignment_3_02();
    //for unit test, use macro
}
#endif // !UNIT_TESTING_ASSIGNMENT_3
int32_t sub_main_assignment_3_02() {
    int32_t sizes[2] = {0, 0};
    for (int &size : sizes) {
        cin >> size;
        if (cin.fail() || size <= 0) {
            cout << "Please ensure the input is integer that bigger than 0" << endl;
            return -1;
        }
    }//read row and column size
    int32_t size = sizes[0] * sizes[1];
    int32_t length = 0;
    while (size > 0) {
        size /= 10;
        length++;
    }//get the format of output time
    vector<vector<int32_t>> matrix(sizes[0], vector<int32_t>(sizes[1], 0));
    spiral(matrix, 1);

    for (const auto &i:matrix) {
        for (const auto &j:i) {
            cout << std::setw(length + 1) << std::left << j;
        }
        cout << endl;
    }//output
    return 0;
}
void spiral(vector<vector<int32_t>> &matrix, int32_t begin) {
    if (matrix.size() <= 0 || matrix[0].size() <= 0) {
        return;
        // illegal input or final of rec, should return
    } else if (1 == matrix.size() && matrix[0].size() > 1) {
        for (int32_t i = matrix[0].size() - 1; i >= 0; i--) {
            matrix[0][i] = begin;
            begin++;
        }
        return;
        //for one line matrix
    } else if (matrix.size() > 1 && 1 == matrix[0].size()) {
        for (int32_t i = 0; i < static_cast<int32_t>(matrix.size()); ++i) {
            matrix[i][0] = begin;
            begin++;
        }
        return;
        //for one column matrix
    } else if (1 == matrix.size() && 1 == matrix[0].size()) {
        matrix[0][0] = begin;
        return;
        // for matrix that just have one moment;
    }
    int32_t row = matrix.size();
    int32_t column = matrix[0].size();
    int32_t count = begin;
    for (int i = column - 1; i >= 0; i--, count++) {
        matrix[0][i] = count;
    }
    for (int i = 1; i < row; ++i, count++) {
        matrix[i][0] = count;
    }
    // fill the first row and first column in order
    vector<vector<int32_t>> submatrix(row - 1, vector<int32_t>(column - 1, 0));
    spiral(submatrix, count);
    std::reverse(submatrix.begin(), submatrix.end());
    for (auto &i: submatrix) {
        std::reverse(i.begin(), i.end());
    }
    //create submatrix, recurrence and reverse in row and column
    for (int32_t i = 0; i < static_cast<int32_t>(submatrix.size()); ++i) {
        for (int32_t j = 0; j < static_cast<int32_t>(submatrix[0].size()); ++j) {
            matrix[i + 1][j + 1] = submatrix[i][j];
        }
    }
    // fill other part from submatrix;
}
```

### Part 3 - Result & Verification

#### Test Case #1: illegal input

```
Input:
    -1 -2
Output:
    Please ensure the input is integer that bigger than 0
```

![picture_07](./Ass3_picture_07.png)

#### Test Case #2: $1*2$

```
Input:
    1 2
Output:
    2 1
```

![picture_09](./Ass3_picture_09.png)

#### Test Case #3: $2*1$

```
Input:
    2 1
Output:
    1
    2
```

![picture_10](./Ass3_picture_10.png)

#### Test Case #3: $2*2$

```
Input:
    2 2
Output:
    2 1
    3 4
```

![picture_11](./Ass3_picture_11.png)

#### Test Case #4: $2*3$

```
Input:
    2 3
Output:
    3 2 1
    4 5 6
```

![picture_12](./Ass3_picture_12.png)

#### Test Case #5: $3*2$

```
Input:
    3 2
Output:
    2 1
    3 6
    4 5
```

![picture_13](./Ass3_picture_13.png)

#### Test Case #6: $3*3$

```
Input:
    3 3
Output:
    3 2 1
    4 9 8
    5 6 7
```

![picture_14](./Ass3_picture_14.png)

#### Test Case #7: $3*4$

```
Input:
    3 4
Output:
    4 3  2  1 
    5 12 11 10
    6 7  8  9
```

![picture_15](./Ass3_picture_15.png)

#### Test Case #8: $4*3$

```
Input:
    4 3
Output:
    3  2  1  
    4  11 10 
    5  12 9  
    6  7  8  
```

![picture_16](./Ass3_picture_16.png)

#### Test Case #9: $4*5$

```
Input:
    4 4
Output:
    4  3  2  1  
    5  14 13 12 
    6  15 16 11 
    7  8  9  10 
```

![picture_17](./Ass3_picture_17.png)

#### Test Case #10: $5*3$

```
Input:
    4 5
Output:
    3  2  1  
    4  13 12 
    5  14 11   
    6  15 10 
    7  8  9  
```

![picture_18](./Ass3_picture_18.png)

#### Test Case #11: $2*9$

```
Input:
    2 9
Output:
    9  8  7  6  5  4  3  2  1  
    10 11 12 13 14 15 16 17 18 
```

![picture_19](./Ass3_picture_19.png)

### Part 4 - Difficulties & Solutions

#### Difficulties

Using loops is not very good at designing models.

#### Solutions

Use recursion.

## Question 3: Count Unicode Langauge

### Part 1-Analysis

1. Design struct, according to Blocks.txt, three variables are needed, one begin, int32_t; one end, int32_t; and one
   name, char [100];
2. Then read the content from Blocks.txt, the commented, the line content is too small can be screened out, and then use
   a function to convert a line of string into unicode_block struct.
3. Then read the string from stdin, and then through forced type conversion, use `utf8_to_codepoint` to read the
   code_point value and byte length. Then do a search for the code_point value corresponding to each byte.
4. Finally traverse the array, get the maximum value, and output.

### Part 2 - Code

``` cpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "utf8.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
struct unicode_block {
    uint32_t begin;
    uint32_t end;
    char part[100];
};
//struct
int32_t sub_main_assignment_3_03();
void string_to_block(string s, unicode_block *bl);
string trim(string str);
int32_t hex_string_to_int32_t(const string &s);
int32_t find_alphabeta(unicode_block *bl, int32_t length_of_blocks, int32_t ch);
const int32_t unicode_part_number = 300;
#ifndef UNIT_TESTING_ASSIGNMENT_3
#define UNIT_TESTING_ASSIGNMENT_3
int main() {
    return sub_main_assignment_3_03();
}
#endif // !UNIT_TESTING_ASSIGNMENT_3
int32_t sub_main_assignment_3_03() {
    std::ifstream read_file("./Blocks.txt", std::ios::in);
    string line;
    if (!read_file.is_open()) {
        cout << "Can not find Blocks.txt " << endl;
        read_file.close();
        return -1;
    }//read blocks
    unicode_block blocks[unicode_part_number];
    int32_t chars_count[unicode_part_number];
    //声明变量
    memset(chars_count, 0, unicode_part_number * sizeof(int32_t));
    int32_t block_count = 0;
    while (getline(read_file, line)) {
        if (line.size() <= 1 || '#' == line[0]) {
            continue;
        }
        string_to_block(line, &blocks[block_count]);
        block_count++;
        //读取,跳过或者由string -> struct
    }
    read_file.close();
    string file_content;
    string temp;
    while (!cin.eof()) {
        getline(cin, temp);
        file_content.append(temp);
    }
    // read form stdin
    int32_t bytes_in_char;
    for (int i = 0; i < static_cast<int32_t>(file_content.size()); i += bytes_in_char) {
        int32_t code_point =
                utf8_to_codepoint(reinterpret_cast<const unsigned char *>(&file_content[i]), &bytes_in_char);
        chars_count[find_alphabeta(blocks, block_count, code_point)]++;
        //  强制类型转换,search and count
    }
    int32_t max_v = INT32_MIN / 2;
    int32_t max_posi = 0;
    for (int i = 0; i < unicode_part_number; ++i) {
        if (chars_count[i] > max_v) {
            max_v = chars_count[i];
            max_posi = i;
        }
    }
    // find max
    cout << blocks[max_posi].part << endl;
    return 0;
}
void string_to_block(string s, unicode_block *bl) {
    string begin = trim(s.substr(0, s.find_first_of('.')));
    string end = trim(s.substr(s.find_last_of('.') + 1, s.find(';') - s.find_last_of('.') - 1));
    string name = trim(s.substr(s.find(';') + 1));
    bl->begin = hex_string_to_int32_t(begin);
    bl->end = hex_string_to_int32_t(end);
    std::memcpy(bl->part, &name[0], name.size());
    // string -> struct values
}
string trim(string str) {
    if (str.empty()) {
        return str;
    }
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
    // trim
}
int32_t hex_string_to_int32_t(const string &s) {
    int32_t number = 0;
    std::stringstream ss;
    ss << std::hex << s;
    ss >> number;
    return number;
    // use stringstream to hex -> int32_t
}
int32_t find_alphabeta(unicode_block *bl, int32_t length_of_blocks, int32_t ch) {
    for (int32_t i = 0; i < length_of_blocks; ++i) {
        if (bl[i].begin <= static_cast<uint32_t>(ch) && static_cast<uint32_t>(ch) <= bl[i].end) {
            return i;
        }
    }
    // search one by one.
    return -1; // should not reach there.
}
```

编译指令:
`g++ Assignment_3_03.cpp utf8.c -o ass3_03.out -Wall -Wextra`
samll test program为

``` sh
#!/bin/bash
set -eou pipefail
language=("Armenian" "Georgian" "Lao" "Malayalam" "Devanagari" "Georgian")
if [[ -f ass3_03.out ]]; then
    rm ass3_03.out
fi
g++ Assignment_3_03.cpp utf8.c -o ass3_03.out -Wall -Wextra
for (( i = 1,j=0; i < 7; i++,j++ )); do
    output=$(./ass3_03.out < "./../test/sample${i}.txt")
    if [[ ${output} != ${language[${j}]} ]]; then
        echo "${i} error";
        exit 1;
    fi
done
echo "no error"
```

### Part 3 - Result & Verification

#### Test Case #1: script output

```
Input:
    ./test_3_03.sh
Output:
    no error
```

![picture_20](./Ass3_picture_20.png)

#### Test Case #2: sample1

```
Input:
    g++ ./Assignment_3_03.cpp utf8.c -o ass3_03.out -Wall -Wextra | ./ass3_03.out < ./../test/sample1.txt
Output:
    Armenian
```

![picture_21](./Ass3_picture_21.png)

#### Test Case #3: sample2

```
Input:
    g++ ./Assignment_3_03.cpp utf8.c -o ass3_03.out -Wall -Wextra | ./ass3_03.out < ./../test/sample2.txt
Output:
    Georgian
```

![picture_22](./Ass3_picture_22.png)

#### Test Case #4: sample3

```
Input:
    g++ ./Assignment_3_03.cpp utf8.c -o ass3_03.out -Wall -Wextra | ./ass3_03.out < ./../test/sample3.txt
Output:
    Lao
```

![picture_23](./Ass3_picture_23.png)

#### Test Case #5: sample4

```
Input:
    g++ ./Assignment_3_03.cpp utf8.c -o ass3_03.out -Wall -Wextra | ./ass3_03.out < ./../test/sample4.txt
Output:
    Lao
```

![picture_24](./Ass3_picture_24.png)

#### Test Case #6: sample5

```
Input:
    g++ ./Assignment_3_03.cpp utf8.c -o ass3_03.out -Wall -Wextra | ./ass3_03.out < ./../test/sample5.txt
Output:
    Devanagari
```

![picture_25](./Ass3_picture_25.png)

#### Test Case #7: sample6

```
Input:
    g++ ./Assignment_3_03.cpp utf8.c -o ass3_03.out -Wall -Wextra | ./ass3_03.out < ./../test/sample6.txt
Output:
    Georgian
```

![picture_26](./Ass3_picture_26.png)

### Part 4 - Difficulties & Solutions

#### Difficulties

Need to read data from stdin, so you can't directly debug with ide.

#### Solutions

Use command line and shell scripts for debugging.