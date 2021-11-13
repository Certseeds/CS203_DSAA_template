//
// Created by lenovo on 2019/9/14.
//
#include <iostream>

using namespace std;

int Max(int x, int y) {
    return (x > y) ? x : y;
}

double Max(double x, double y) {
    return (x > y) ? x : y;
}


template<typename T>
T Max(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    cout << Max<int>(3, 7) << endl;
    cout << Max<char>('g', 'e') << endl;
    cout << Max<double>(3.1, 7.1) << endl;

    return 0;
}