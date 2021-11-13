#include <iostream>

// function for adding two values
void sum(int x, int y) {
    int z;
    z = x + y;
    std::cout << z;
}

int main() {
    int a = 10;
    int b = 20;
    // calling the function with name 'sum'
    sum(a, b);
}