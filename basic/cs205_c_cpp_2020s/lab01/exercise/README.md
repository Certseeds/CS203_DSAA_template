<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-06-08 08:15:29
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 08:58:04
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

**Environment**: MSVC2019.

# lab01 Exercise Report

## E1 Code & Result

### Code

``` cpp
#include <iostream>
using std::cout;
using std::endl;
int main(){1
    cout << "Hello world" << endl;
    cout << "hello world" << endl;
    return 0;
}
/*
 * g++ -c hello.cpp
 * g++ hello.o -o hello
 */
```

### Result

#### Test Case

``` log
Input: 
    no need input 
Output: 
    Hello world
    Hello world
```

![picture_01](./lab01_01.png)

## E2 Code & Result

### Code

``` cpp
#include <iostream>
using std::cout;
using std::endl;
void smile();
int main(){
    for(int i = 0;i<3;i++){
        for(int j = 3;j>i;j--){
            smile();
        }cout<<endl;
    }   
}
void smile(){
    cout << "Smile!";
}
```

### Result

#### Test Case

``` log
Input: 
    no input
Output:
    Smile!Smile!Smile!
    Smile!Smile!
    Smile!
```

![picture_02](./lab01_02.png)
