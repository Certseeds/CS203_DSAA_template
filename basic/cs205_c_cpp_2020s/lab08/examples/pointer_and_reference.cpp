//
// Created by lenovo on 2019/9/12.
//
// C++ program to demonstrate differences between pointer
// and reference.
#include <iostream>

using namespace std;
struct demo {
    int a;
};

int main() {
    int x = 5;
    int y = 6;
    demo d;

    int *p;
    p = &x;
    p = &y;                     // 1. Pointer reintialization allowed

    int &r = x;
    // &r = y;				 // 1. Compile Error
    r = y;                     // 1. x value becomes 6

    p = NULL;
    // &r = NULL;			 // 2. Compile Error

    p++;                     // 3. Points to next memory location
    r++;                     // 3. x values becomes 7
    p = &x;
    cout << &p << " " << &x << endl; // 4. Different address
    cout << &r << " " << &x << endl; // 4. Same address

    demo *q = &d;
    demo &qq = d;
    q->a = 8;
    // q.a = 8;				 // 5. Compile Error
    qq.a = 8;
    // qq->a = 8;			 // 5. Compile Error

    cout << p << endl;     // 6. Prints the address
    cout << r << endl;     // 6. Print the value of x

    return 0;
}

