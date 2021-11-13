//
// Created by lenovo on 2019/9/14.
//
// Purpose:   Demonstrate multiple parameter overloading

#include <iostream>

using namespace std;

// overloaded functions
void add(int i, int j);

void add(int i, double j);

void add(double j, int i);

void add(int i, int j, int k);

int main(void) {
    int a = 1, b = 2, c = 3;
    double d = 1.1;
    // Overloaded functions
    // with different type and
    // number of parameters
    add(a, b); //  1 + 2 => add prints 3
    add(a, d); //  1 + 1.1 => add prints 2.1
    add(d, a);
    add(a, b, c); // 1 + 2 + 3 => add prints 6
}

void add(int i, int j) {
    cout << "Result: " << i + j << endl;
}

void add(int i, double j) {
    cout << "Result: " << i + j << endl;
}

void add(int i, int j, int k) {
    cout << "Result: " << i + j + k << endl;
}

void add(double i, int j) {
    cout << "Result: " << i + j << endl;
}