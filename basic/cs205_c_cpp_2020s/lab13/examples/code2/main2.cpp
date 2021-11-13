//main.cpp the main program
#include <iostream>
#include "circle.h"
#include "rectangle.h"
#include "shape.h"

using namespace std;

int main() {
    double r;
    circle circle1(3);
    circle1.Show();

    rectangle rectangle1(4, 4);
    rectangle rectangle2(3.5, 35.9);
    rectangle1.Show();
    rectangle2.Show();

    cout << "This program generates " << shape::GetNumOfObj() << " objects";
    return 0;
}

