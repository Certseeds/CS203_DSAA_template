//
// Created by lenovo on 2019/11/20.
//
#include <iostream>
#include "box.h"

using namespace std;

// Main function for the program
int main() {
    box box1;  // Declare Box1 of type Box

    // volume of box 1
    double volume = box1.getVolume();
    cout << "Volume of Box1 : " << volume << endl;

    return 0;
}