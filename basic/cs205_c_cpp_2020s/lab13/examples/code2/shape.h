//
// Created by lenovo on 2019/12/4.
//
// Shape.h  -- Shape classes
#ifndef LAB13_SHAPE_H
#define LAB13_SHAPE_H

#include <iostream>

// formatting stuff
struct Formatting {
    std::ios_base::fmtflags flag;
    std::streamsize pr;
};

class shape {
public:
    shape() {
        numberOfObjects++;
    }

    static int GetNumOfObj() { return numberOfObjects; }

protected:
    //methods for formatting
    Formatting SetFormat() const;

    void Restore(Formatting &f) const;

private:
    static int numberOfObjects;
};


#endif //LAB13_SHAPE_H
