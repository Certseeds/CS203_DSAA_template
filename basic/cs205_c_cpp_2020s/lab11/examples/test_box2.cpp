
#include <iostream>
#include "box.h"

using namespace std;

// Main function for the program
int main() {
    box box;                // Declare box of type Box
    double volume = 0.0;     // Store the volume of a box here
    // box  specification
    box.setLength(6.0);
    box.setBreadth(7.0);
    box.setHeight(5.0);

    // volume of box
    volume = box.getVolume();
    cout << "Volume of Box1 : " << volume << endl;


    return 0;
}