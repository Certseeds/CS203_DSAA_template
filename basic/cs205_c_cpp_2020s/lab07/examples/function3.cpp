//
// Created by lenovo on 2019/8/27.
//
#include <iostream>

using namespace std;


int sum(int x, int y);

int main() {
    int a = 10;
    int b = 20;
    int c = sum(a, b);    //Actual parameters: a and b
    cout << c;
}


int sum(int x, int y)//Formal parameters: x and y
{
    int sum = x + y;
    return sum;
}
