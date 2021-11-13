//
// Created by lenovo on 2019/10/16.
//
#include <iostream>

using namespace std;

int factorial(int);

int main() {
    int num = 5;
    cout << factorial(num);
    return 0;
}

int factorial(int n) {
    if (n < 1)
        return (1);  /*Terminating condition*/
    else {
        return (n * factorial(n - 1));
    }
}

