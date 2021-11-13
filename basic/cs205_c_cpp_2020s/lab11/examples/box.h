//
// Created by lenovo on 2019/11/20.
//
#ifndef EXAMPLE_BOX_H
#define EXAMPLE_BOX_H

class box {
private:
    double length;         // Length of a box
    double breadth;        // Breadth of a box
    double height;         // Height of a box
public:
    // Default Constructor
    box();

    //Parameterized Constructor
    box(int, int, int);

    //copy constructor
    box(const box &b);

    // This is the destructor: declaration
    ~box();

    // Member functions declaration
    double getVolume(void);

    void setLength(double len);

    void setBreadth(double bre);

    void setHeight(double hei);
};

#endif //EXAMPLE_BOX_H
