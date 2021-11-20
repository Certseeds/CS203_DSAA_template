<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-06-08 09:15:06
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-06-22 20:27:05
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

## CS205_C_CPP_Lab07

1. Write a program that will display the calculator menu. The program will prompt the user to choose the operation
   choice (from 1 to 5). Then it asks the user to input two integer values for the calculation. See the sample below.
   The program also asks the user to decide whether he/she wants to continue the operation. If he/she input ‘y’ , the
   program will prompt the user to choose the operation gain. Otherwise, the program will terminate.

``` log
====================================================
                          MENU
====================================================
   1.Add
   2.Subtract
   3.Multiply
   4.Divide
   5.Modulus

Enter your choice(1-5): 1
Enter your two integer numbers: 13 14

Result: 27
Press y or Y to continue:y
```

PS: frame is provided

``` cpp
#include <iostream>
using namespace std;
void displaymenu(){
    //complete code here
}
int Add(int a,int b){
    //complete code here
}
int Substract(int a, int b){
    //complete code here
}
int Multiply(int a, int b){
    //complete code here
}
float Divide(int a,int b){
    //complete code here
}
int Modulus(int a, int b){
    //complete code here
}
```

``` cpp
int main(int argc, char *argv[]) {
    //show menu
    displaymenu();
    int yourchoice;
    int a;
    int b;
    char confirm;
    do{
    cout<<"Enter your choice(1-5):";
    cin>>yourchoice;
    cout<<"Enter your two integer numbers:";
    cin>>a>>b;
    cout<<"\n";
    switch(yourchoice){
          //complete code here
    }
    cout<<"\nPress y or Y to continue:";
    cin>>confirm;
    }while(confirm=='y'||confirm=='Y');
    return EXIT_SUCCESS;
   }
```

2. Here is a structure declaration:

``` cpp
struct box
{
char maker[40];
float height;
float width;
float length;
float volume;
};
```

+ Write a function that passes a box structure by value and that displays the value of each member.
+ Write a function that passes the address of a box structure and that sets the volume member to the product of the
  other three dimensions.
+ Write a simple program that uses these two functions. A sample run might look like this:.

``` log
    Before setting valume by value
    Maker: ShanDong University
    Height: 11.4
    Width: 51.4
    Length: 19.19
    Volume: 0
    Before setting valume by address
    Maker: JinNan College
    Height: 20
    Width: 26
    Length: 18
    Volume: 0
    After setting valume by value
    Maker: ShanDong University
    Height: 11.4
    Width: 51.4
    Length: 19.19
    Volume: 0
    After setting valume by address
    Maker: JinNan College
    Height: 20
    Width: 26
    Length: 18
    Volume: 9360
```

3. Write a program that uses the following functions:

+ `int Fill_array(double arr [], int size)` prompts the user to enter double values to be entered in the array. It
  ceases taking input when the array is full or when the user enters non-numeric input, and it returns the actual number
  of entries.
+ `void Show_array(double *arr, int size)` displays the contents of the array.
+ `void Reverse_array(double *arr, int size)` is a recursive function ,it reverses the order of the values stored in the
  array .
+ The program should use these functions to fill an array, show the array, reverse the array, show the array, reverse
  all but the first and last elements of the array, and then show the array.A sample run might look like this:.

``` logs
Enter the size of the array: 6
Enter value #1: 1
Enter value #2: 2
Enter value #3: 3
Enter value #4: 4
Enter value #5: 5
Enter value #6: 6
The outputis as follows:
1 2 3 4 5 6
6 5 4 3 2 1
6 2 3 4 5 1
```
