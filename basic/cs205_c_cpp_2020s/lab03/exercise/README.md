<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-06 23:00:00
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 08:57:13
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

# Lab03 Exercise Report : 2020_0306

## Preparations

For use unit test and avoid citing repeatability,

write the define of CandyBar in an single file named `CandyBar.h`

``` cpp
#ifndef _CANDYBAR_
#define _CANDYBAR_
#include <string>
struct CandyBar {
    std::string name;
    double weight;
    int calories;
};
#endif

```

## E1 Code & Result

+ Code

``` cpp
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include "CandyBar.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int sub_main_03_01();
#ifndef UNIT_TESTING_LAB_03
#define UNIT_TESTING_LAB_03
int main() {
    const int32_t will_return = sub_main_03_01();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !UNIT_TESTING_LAB_03
int sub_main_03_01() {
    CandyBar snack = { "Mocha Munch",2.3,350 };
    cout <<"Brand: "<<snack.name << endl;
    cout <<"Weight: " <<snack.weight << endl;
    cout <<"Calorie: " << snack.calories << endl;
    return 0;
}
```

+ Result

### Test Case #1

``` log
Input: No need
Output:
    Brand: Mocha Munch
    Weight: 2.3
    Calorie: 350
```

![picture_01](lab03_01.png)

## E2 Code & Result

+ Code

``` cpp
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include "CandyBar.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int sub_main_03_02();
#ifndef UNIT_TESTING_LAB_03
#define UNIT_TESTING_LAB_03
int main() {
    const int32_t will_return = sub_main_03_02();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !UNIT_TESTING_LAB_03
int sub_main_03_02() {
    char temp_name[1024];
    double weight = 0.0f;
    int calories = 0;
    cout << "Enter brand name of a Candy bar: ";
    cin.getline(temp_name,1024,'\n');
    cout << "Enter weight of the candy bar: ";
    cin >> weight;
    cout << "Enter calories(an integer value) in the Candy bar: ";
    cin >> calories;
    CandyBar cb_1 = { temp_name,weight,calories };
    cout << "Brand: " << cb_1.name << endl;
    cout << "Weight: " << cb_1.weight << endl;
    cout << "Calorie: " << cb_1.calories << endl;
    return 0;
}
```

+ Result

### Test Case #1

``` log
Input: 
"Super Candy Boss" "31.4" "159"
Output:
    Brand: Super Candy Boss
    Weight: 31.4
    Calorie: 159
```

![picture_02](lab03_02.png)

## E3 Code & Result

+ Code

``` cpp
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include "CandyBar.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int sub_main_03_03();
#ifndef UNIT_TESTING_LAB_03
#define UNIT_TESTING_LAB_03
int main() {
    const int32_t will_return = sub_main_03_03();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !UNIT_TESTING_LAB_03
int sub_main_03_03() {
    CandyBar cb_array[3];
    cb_array[0] = { "Mona coke",3,31 };
    cb_array[1] = { "Mona coke",11.2,45 };
    cb_array[2] = { "Mona coke",91.1,92 };
    for (auto i : cb_array) {
        cout << "Brand: " << i.name << endl;
        cout << "Weight: " << i.weight << endl;
        cout << "Calorie: " << i.calories << endl;
    }
    return 0;
}
```

+ Result

### Test Case #1

``` log
Input: No need
Output:
    Brand: Mona coke
    Weight: 3
    Calorie: 31
    Brand: Mona coke
    Weight: 11.2
    Calorie: 45
    Brand: Mona coke
    Weight: 91.1
    Calorie: 92
```

![picture_03](lab03_03.png)
