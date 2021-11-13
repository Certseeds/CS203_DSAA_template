//
// Created by lenovo on 2019/10/16.
//
#include <iostream>

using namespace std;

int factorial(int);

int main() {
    int fact, value;
    while (true) {
        cout << "Enter a positive integer:";
        cin >> value;
        if (value < 0)
            cout << "The input value must be greater than 0" << endl;
        else
            break;
    }
    fact = factorial(value);
    cout << "Factorial of " << value << " = " << fact << endl;
    return 0;
}

int factorial(int n) {
    if (n < 1)
        return (1);  /*Terminating condition*/
    else {
        return (n * factorial(n - 1));
    }
}
