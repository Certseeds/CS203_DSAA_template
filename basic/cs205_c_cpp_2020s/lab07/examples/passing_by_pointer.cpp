//
// Created by lenovo on 2019/8/27.
//
// pass by pointer.
#include <iostream>

using namespace std;

void swap(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}

int main() {
    int a = 45, b = 35;
    cout << "Before Swap\n";
    cout << "a = " << a << " b = " << b << "\n";

    swap(&a, &b);

    cout << "After Swap with pass by pointer\n";
    cout << "a = " << a << " b = " << b << "\n";
}
