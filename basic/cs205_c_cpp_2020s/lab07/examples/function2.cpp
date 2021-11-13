//
// Created by lenovo on 2019/8/27.
//
#include <iostream>

using namespace std;

//declaring the function
int sum(int x, int y);

int main() {
    int a = 10;
    int b = 20;
    int c = sum(a, b);    //calling the function
    cout << c;
}

//defining the function
int sum(int x, int y) {
    return (x + y);
}
