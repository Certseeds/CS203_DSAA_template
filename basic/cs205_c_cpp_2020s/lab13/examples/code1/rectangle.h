//
// Created by lenovo on 2019/12/4.
//
// Rectangle.h  -- Rectangle classes
#ifndef LAB13_RECTANGLE2_H
#define LAB13_RECTANGLE1_H


class rectangle {

public:
    rectangle(rectangle &rectangle);

    rectangle(double width, double height);

    rectangle() {
        numberOfObjects++;
    }

    static int GetNumOfObj() { return numberOfObjects; }

    double GetArea() const;

    void Show();

private:
    static int numberOfObjects;
    double width;
    double height;
};

#endif //LAB13_RECTANGLE2_H
