//
// Created by lenovo on 2019/10/17.
//
#include <iostream>
#include <cmath>

using namespace std;

#define SQUARE_ARRAY 0
#define SQUARE_POINTER 1
#define SQUARE_POINTER_CONST 2

#define SQUARE SQUARE_POINTER

/* This method prints the square of each
 * of the elements of multidimensional array
 */
#if SQUARE == SQUARE_ARRAY
void square(int arr[2][3]){
    int temp;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            temp = arr[i][j];
            cout<<pow(temp, 2)<<"\t";
        }
        cout<<endl;
    }
}
#elif SQUARE == SQUARE_POINTER

void square(int (*arr)[3]) {
    int temp;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            temp = *(*(arr + i) + j);
            cout << pow(temp, 2) << "\t";
        }
        cout << endl;
    }
}

#elif SQUARE == SQUARE_POINTER_CONST
void square(const int (*arr)[3]){
    int temp;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            temp = arr[i][j];
            //arr[i][j] += 1;
            cout<<pow(temp, 2)<<"\t";
        }
        cout<<endl;
    }
}
#endif

int main() {
    int arr[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
    };
    square(arr);
    return 0;
}
