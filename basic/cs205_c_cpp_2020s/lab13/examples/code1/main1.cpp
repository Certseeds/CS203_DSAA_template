
//main.cpp the main program
#include <iostream>
#include "circle.h"
#include "rectangle.h"

using namespace std;
// formatting stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

//methods for formatting
format setFormat();

void restore(format f, precis p);

int main() {
    double r;
    circle circle1(3);
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(3);
    circle1.Show();
    // Restore original format
    restore(initialState, prec);

    // set up ###.## format
    initialState = setFormat();
    prec = cout.precision(3);
    rectangle rectangle1(4, 4);
    rectangle rectangle2(3.5, 35.9);
    rectangle1.Show();
    rectangle2.Show();
    // Restore original format
    restore(initialState, prec);

    cout << "This program generates " << circle::GetNumOfObj() + rectangle::GetNumOfObj() << " objects";
    return 0;
}

void restore(format f, precis p) {
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}

format setFormat() {
    // set up ###.## format
    return cout.setf(std::ios_base::fixed,
                     std::ios_base::floatfield);
}