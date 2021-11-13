//
// Created by lenovo on 2019/11/20.
//
#include <iostream>

using namespace std;
struct A {
    int a{'a'};
};

class B {
public: // unless compile fail
    int b{'b'};
};

// Main function for the program
int main() {
    A ac{};
    B bc{};
    cout << ac.a << " " << bc.b << endl;
    return 0;
}
