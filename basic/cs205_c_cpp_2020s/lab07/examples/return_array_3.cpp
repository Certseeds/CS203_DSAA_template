//
// Created by jyh on 2019/10/22.
//
//Using struct
#include <stdio.h>

struct arrWrap {
    int arr[5];
};

struct arrWrap fun() {
    struct arrWrap x;

    x.arr[0] = 10;
    x.arr[1] = 20;

    return x;
}

int main() {
    struct arrWrap x = fun();
    printf("%d %d", x.arr[0], x.arr[1]);
    return 0;
}