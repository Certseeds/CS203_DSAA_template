#include <iostream>

using namespace std;

int main() {
    int num = 66;
    if (num < 50) {
        //This would run if above condition is true
        cout << "num is less than 50";
    } else {
        //This would run if above condition is false
        cout << "num is greater than or equal 50";
    }
    return 0;
}