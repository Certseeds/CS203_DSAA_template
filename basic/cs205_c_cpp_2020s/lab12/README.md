<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-06-09 08:47:28
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-06-09 08:53:03
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

## CS205_C_CPP_Lab12

1. Continue improving the Complex class and adding more operations for it, such as: -,*,~,==,!= etc. Make the following
   program run correctly.

``` cpp
#include <iostream>
#include "Complex.h"
using namespace std;
int main() {
    Complex a(3.0, 4.0);
    Complex b(2.0, 6.0);
    cout << "b is " << b << endl;
    cout << "~b is " << ~b << endl;
    cout << "a is " << a << endl;
    cout << "a + b is " << a + b << endl;
    cout << "a - b is " << a - b << endl;
    cout << "a * b is " << a * b << endl;
    cout << "2 * b is " << 2 * b << endl;
    Complex c = b;
    cout << "b==c is " << (b == c) << endl;
    cout << "b!=c is" << (b != c) << endl;
    cout << "a==c is" << (a == c) << endl << endl;
    Complex d;
    cout << "Enter a complex number : " << endl;
    cin >> d;
    cout << "d is " << d << endl;
    return 0;
}
```

Note that you have to overload the << and >> operators. Use const whenever warranted. H0ere is a sample run of the
program:

``` log
    b is 2+6i
    ~b is 2+-6i
    a is 3+4i
    a + b is 5+10i
    a - b is 1+-2i
    a * b is -18+26i
    2 * b is 4+12i
    b==c is 1
    b!=c is0
    a==c is0
    Enter a complex number :
    real: 4
    imaginary: 6
    d is 4+6i
```

2. Design a class named Number that stores a number which is integer and private to the class. The default constructor
   should set the number to 0. Add another constructor that allows the caller to set the number. Finally, overload the
   prefix and postfix ++ and -- operators to make the following program run correctly.

``` cpp
#include <iostream>
using namespace std;
int main() {
    Number n1(20);
    Number n2 = n1++;
    cout << n1 << endl;
    cout << n2 << endl;
    Number n3 = n2--;
    cout << n2 << endl;
    cout << n3 << endl;
    Number n4 = ++n3;
    cout << n3 << endl;
    cout << n4 << endl;
    Number n5 = --n4;
    cout << n4 << endl;
    cout << n5 << endl;
    return 0;
}
```

Note that you have to overload the << **operators**. Use const whenever warranted. Here is a sample run of the program:

``` log
x = 21
x = 20
x = 19
x = 20
x = 21
x = 21
x = 20
x = 20
```

Hips:
Syntax for overloading postfix increment operator is as follows:

``` cpp
return_type operator ++(int)
{
//Body of function
...
}
```

The syntax for overloading prefix increment and decrement operators is as follows:

``` cpp
return_type operator ++()
{
//Body of the function
...
}
```