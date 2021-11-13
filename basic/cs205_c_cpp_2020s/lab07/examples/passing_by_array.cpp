//
// Created by lenovo on 2019/10/17.
//
#include <iostream>

using namespace std;
/* This function adds the corresponding
 * elements of both the arrays and
 * displays it.
 */
#define SUM_ARRAY 0
#define SUM_POINTER 1
#define SUM_POINTER_CONST 2

#define SUM SUM_ARRAY

#if  SUM == SUM_ARRAY

void sum(int arr1[], int arr2[]) {
    int temp[5];
    for (int i = 0; i < 5; i++) {
        temp[i] = arr1[i] + arr2[i];
        arr1[i] = temp[i];
        cout << temp[i] << " ";
    }
}

#elif SUM == SUM_POINTER
void sum(int* arr1, int* arr2){
    int temp[5];
    for(int i=0; i<5; i++){
        temp[i] = arr1[i]+arr2[i];
        arr1[i] = temp[i];
        cout<<temp[i]<<" ";
    }
}
#elif SUM == SUM_POINTER_CONST
void sum(const int* arr1, const int* arr2){
    int temp[5];
    for(int i=0; i<5; i++){
        temp[i] = arr1[i]+arr2[i];
        arr1[i] = temp[i];
        cout<<temp[i]<<" ";
    }
}
#endif

int main() {
    int a[5] = {10, 20, 30, 40, 50};
    int b[5] = {1, 2, 3, 4, 5};
    //Passing arrays to function
    sum(a, b);
    return 0;
}
