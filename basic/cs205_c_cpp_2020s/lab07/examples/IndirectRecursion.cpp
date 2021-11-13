//
// Created by lenovo on 2019/10/16.
//

#include <iostream>

using namespace std;

int factorial_a(int);

int factorial_b(int);

int factorial_a(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial_b(n - 1);
}

int factorial_b(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial_a(n - 1);
}

int main() {
    int num = 5;
    cout << factorial_a(num);
    return 0;
}