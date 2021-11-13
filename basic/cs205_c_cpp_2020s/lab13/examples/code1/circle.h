//
// Created by lenovo on 2019/12/4.
//
// Circle.h  -- Circles classes
#ifndef LAB13_CIRCLE2_H
#define LAB13_CIRCLE1_H

#define PI 3.1415

class circle {
public:
    circle(double radius);

    circle(circle &C);

    ~circle();

    double GetRadius();

    double GetArea() const;

    static int GetNumOfObj() { return numberOfObjects; }

    void Show();

private:
    static int numberOfObjects;
    double radius;
};


#endif //LAB13_CIRCLE2_H
