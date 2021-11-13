//
// Created by lenovo on 2019/12/4.
//

#ifndef LAB13_RECTANGLE2_H
#define LAB13_RECTANGLE1_H

#include "shape.h"

class rectangle : public shape {

public:
    rectangle(rectangle &rectangle);

    rectangle(double width, double height);

    rectangle() {}

    double GetArea() const;

    void Show();

private:

    double width;
    double height;
};

#endif //LAB13_RECTANGLE2_H
