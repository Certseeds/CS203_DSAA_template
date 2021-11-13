//main.cpp the main program
#include <iostream>
#include "circle.h"
#include "rectangle.h"
#include "shape.h"

using namespace std;

#define NUM_OF_SHAPE 3

int main() {
    shape *p_shape[NUM_OF_SHAPE];

    int ch = 0;
    for (int i = 0; i < NUM_OF_SHAPE; i++) {
        cout << "Enter 1 for Circle or 2 for Rectangle:";

        while (cin >> ch && (ch != 1 && ch != 2))
            cout << "Enter either 1 or 2:";
        if (ch == 1) {

            cout << "Please enter the radius of the circle:";
            double r;
            cin >> r;
            p_shape[i] = new circle(r);
        } else {
            cout << "Please enter the width and height of the rectangle:";
            double w, h;
            cin >> w >> h;
            p_shape[i] = new rectangle(w, h);
        }
        while (cin.get() != '\n')
            continue;
    }
    for (int i = 0; i < NUM_OF_SHAPE; i++) {
        p_shape[i]->Show();
    }

    for (int i = 0; i < NUM_OF_SHAPE; i++) {
        delete p_shape[i];
    }
    cout << "This program generates " << shape::GetNumOfObj() << " objects";
    return 0;
}

