//
// Created by lenovo on 2019/8/23.
//
#include <iostream>

using namespace std;

int main() {
    //int num=5;
    int num;
    cout << "Enter an integer number between 1 & 10: ";
    cin >> num;
    switch (num) {
        case 1:
            cout << "Case1 " << endl;
            break;
        case 2:
            cout << "Case2 " << endl;
            break;
        case 3:
            cout << "Case3 " << endl;
            break;
        case 4:
            cout << "Case4 " << endl;
            break;
        default:
            cout << "Default " << endl;
    }
    return 0;
}
