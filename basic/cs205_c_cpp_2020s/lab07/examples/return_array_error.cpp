//
// Created by jyh on 2019/10/22.
//
#include <iostream>

using namespace std;

int *fun() {
    int arr[5];

    /* Some operations on arr[] */
    arr[0] = 10;
    arr[1] = 20;

    return arr;
}

int main() {
    int *ptr = fun();
    cout << ptr[0] << " " << ptr[1];
    return 0;
}