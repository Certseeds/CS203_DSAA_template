//
// Created by lenovo on 2019/11/20.
//
#include <iostream>
#include "box.h"

using namespace std;

// Main function for the program
int main() {
    box box1;   // Declare Box1 of type Box
    box box2(5.0, 6.0, 9.0); // Declare Box2 of type Box

    box box3 = box2;
    double volume = 0.0; // Store the volume of a box here


    // volume of box 1
    volume = box1.getVolume();
    cout << "Volume of Box1 : " << volume << endl;

    // volume of box 2
    volume = box2.getVolume();
    cout << "Volume of Box2 : " << volume << endl;

    // volume of box 3
    volume = box3.getVolume();
    cout << "Volume of Box3 : " << volume << endl;
    return 0;
}