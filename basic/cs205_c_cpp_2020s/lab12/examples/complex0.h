
// Complex.h -- Complex class before operator overloading
#ifndef LAB12_COMPLEX_H
#define LAB12_COMPLEX_H

class Complex {
public:
    Complex();

    Complex(double re, double im);

    Complex Sum(const Complex &data);

    void Show() const;


private:
    double imag;
    double real;

};


#endif //LAB12_COMPLEX_H
