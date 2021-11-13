//
// Created by lenovo on 2019/11/20.
//
#include <iostream>

using namespace std;

class box {
public:
    double length;   // Length of a box
    double breadth;  // Breadth of a box
    double height;   // Height of a box
};

int main() {
    box box;        // Declare box of type Box
    double volume = 0.0;     // Store the volume of a box here

    // box 1 specification
    box.height = 5.0;
    box.length = 6.0;
    box.breadth = 7.0;

    // volume of box
    volume = box.height * box.length * box.breadth;
    cout << "Volume of Box1 : " << volume << endl;

    return 0;
}
