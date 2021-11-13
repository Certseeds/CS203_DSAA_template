#include <iostream>

using namespace std;

int main() {
    int num = 90;
    /* Nested if statement. An if statement
     * inside another if body
     */
    if (num < 100) {
        cout << "number is less than 100" << endl;
        if (num > 50) {
            cout << "number is greater than 50";
        }
    }
    return 0;
}