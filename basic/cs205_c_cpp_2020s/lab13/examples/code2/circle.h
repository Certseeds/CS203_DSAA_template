//
// Created by lenovo on 2019/12/4.
//
// Circle.h  -- Circles classes
#ifndef LAB13_CIRCLE2_H
#define LAB13_CIRCLE1_H

#define PI 3.1415

#include "shape.h"

class circle : public shape {
public:
    circle(double radius);

    circle(circle &C);

    ~circle();

    double GetRadius();

    double GetArea() const;

    void Show();

private:
    double radius;
};


#endif //LAB13_CIRCLE2_H
